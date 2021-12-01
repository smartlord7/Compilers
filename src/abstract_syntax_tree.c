#include "abstract_syntax_tree.h"
#include "tables.h"
#include <stdio.h>
#include <stdlib.h>

int check_block(struct list_node_t * block);

struct tree_node_t * create_node(int type, char * id) {
    struct tree_node_t * new_node = (struct tree_node_t *) malloc(sizeof(struct tree_node_t));

    new_node->id = id;
    new_node->type = type;
    new_node->children = (struct list_node_t *) malloc(sizeof(struct list_node_t));
    new_node->children->next = NULL;
    new_node->siblings = (struct list_node_t *) malloc(sizeof(struct list_node_t));
    new_node->siblings->next = NULL;
    new_node->line = 0;
    new_node->column = 0;

    return new_node;
}

void print_ast_node(struct tree_node_t * node, int level, int is_annotated) {

    if (node->type == A_INVALID_NODE) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("..");
    }

    // TODO MISSING LINE AND COLUMN
    printf("%s", node->id);

    if (is_annotated && node->annotation != NULL) {
        printf(" - %s", node->annotation);
    }

    printf("\n");

}

void sub_print_tree(struct list_node_t * to_print, int level, int is_annotated) {
    int block = 1;
    if (to_print->data->type == A_PROB_BLOCK) {
        struct list_node_t * next = to_print->data->children->next;

        int count = 0;

        while(next != NULL) {
            if (next->data->type != A_INVALID_NODE) {
                count++;
            }
            next = next->data->siblings->next;
        }

        if (count >= 2) {
            print_ast_node(to_print->data, level, is_annotated);
        } else {
            block = 0;
        }
    } else {
        print_ast_node(to_print->data, level, is_annotated);
    }

    struct list_node_t * next = to_print->data->children->next;

    while (next != NULL) {
        sub_print_tree(next, level + block, is_annotated);
        next = next->next;
    }

    next = to_print->data->siblings->next;
    while (next != NULL) {
        sub_print_tree(next, level, is_annotated);
        next = next->next;
    }
}

int handle_blocks(struct list_node_t * current) {
    if (current->data->type == A_INVALID_NODE) {
        return 0;
    }

    int valids = 0;

    struct list_node_t * next = current->data->children->next;
    while (next != NULL) {
        valids += handle_blocks(next);
        next = next->next;
    }

    next = current->data->siblings->next;
    while (next != NULL) {
        valids += handle_blocks(next);
        next = next->data->siblings->next;
    }

    if (current->data->type == A_PROB_BLOCK && valids < 2) {
        current->data->type = A_INVALID_NODE;
    } else {
        valids++;
    }

    return valids;
}

void print_tree(struct tree_node_t * node, int is_annotated) {
    printf("%s\n", node->id);

    if (node->children->next == NULL) {
        return;
    }

    if (!is_annotated) {
        handle_blocks(node->children->next);
    }

    sub_print_tree(node->children->next, 1, is_annotated);
}

void sub_annotate_tree(struct list_node_t * node, global_table_t * global_table, global_entry_t * global_entry) {
    struct list_node_t * child = NULL;

    switch (node->data->type) {
        case A_FUNC_DECL:
            if (global_entry == NULL) {
                global_entry = global_table->entries;

                while (global_entry->type != TABLE_) {
                    global_entry = global_entry->next;
                }
            } else {
                global_entry = global_entry->next;

                while (global_entry->type != TABLE_) {
                    global_entry = global_entry->next;
                }
            }
            break;
        case A_VAR_DECL:
            
            break;
        case A_EQ:
        case A_NE:
        case A_LT:
        case A_LE:
        case A_GT:
        case A_GE:
        case A_NOT:
        case A_AND:
        case A_OR:
            node->data->annotation = ANNOTATION_BOOL;
            break;
        case A_ADD:
        case A_MINUS:
        case A_MUL:
        case A_DIV:
        case A_MOD:
            switch (node->data->children->next->type) {

            }
    }

    child = node->data->children->next;
    while (child != NULL) {
        sub_annotate_tree(child, global_table, global_entry);
        child = child->next;
    }

    child = node->data->siblings->next;
    while (child != NULL) {
        sub_annotate_tree(child, global_table, global_entry);
        child = child->next;
    }
}

void annotate_tree(struct tree_node_t * node, global_table_t * global_table, global_entry_t * global_entry) {
    struct list_node_t * child = NULL;

    child = node->children->next;
    sub_annotate_tree(child, global_table, global_entry);
}
