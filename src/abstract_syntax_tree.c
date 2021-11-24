#include "abstract_syntax_tree.h"
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

    return new_node;
}

void sub_print_node(struct tree_node_t * node, int level) {

    if(node->type == A_INVALID_NODE) {
        return;
    }

    for(int i = 0; i < level; i++) {
        printf("..");
    }
    printf("%s\n", node->id);
}

void sub_print(struct list_node_t * to_print, int level) {
    int block = 1;

    //printf("\tnode: %s\n", to_print->data->id);

    if(to_print->data->type == A_PROB_BLOCK) {
        int count = to_print->data->children->size;
        struct list_node_t * next = to_print->data->children->next;

        //printf("\ta_prob_block\n");

        while(next != NULL) {
            if(next->data->type != A_INVALID_NODE) {
                //printf("\tnot_a_invalid_node\n");
                count += next->data->siblings->size;
            }
            next = next->next;
        }

        if(count >= 2 && check_block(to_print) >= 2) {
            //printf("\tcount >= 2\n");
            sub_print_node(to_print->data, level);
            //printf("%d\n", check_block(to_print));
        }
        else
            //printf("\tcount < 2\n");
            block = 0;
    } else {
            //printf("\tnot_a_prob_block\n");
            sub_print_node(to_print->data, level);
    }

    struct list_node_t * next = to_print->data->children->next;

    while(next != NULL) {
        sub_print(next, level + block);
        next = next->next;
    }

    next = to_print->data->siblings->next;
    while(next != NULL) {
        sub_print(next, level);
        next = next->next;
    }
}

void print_tree() {
    printf("%s\n", root->id);
    if(root->children->next == NULL) {
        return;
    }
    sub_print(root->children->next, 1);
}

int check_block(struct list_node_t * block) {
    int count = block->data->children->size, aux;
    struct list_node_t * next = block->data->children->next;

    //printf("block: %s || count: %d\n", block->data->id, count);

    if(block->data->children == NULL) {
        //printf("there is no child\n");
    }

    while(next != NULL) {
        //printf("child: %s\n", next->data->id);
        if(next->data->type == A_PROB_BLOCK) {
            count += check_block(next);
        }
        else if(next->data->type != A_INVALID_NODE) {
            count += next->data->siblings->size;
        }
        next = next->next;
    }

    return count;
}

