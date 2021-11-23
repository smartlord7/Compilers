#include "abstract_syntax_tree.h"
#include <stdio.h>
#include <stdlib.h>

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
    if(to_print->data->type == A_PROB_BLOCK) {
        int count = to_print->data->children->size;
        struct list_node_t * next = to_print->data->children->next;

        while(next != NULL) {
            count += next->data->siblings->size;
            next = next->next;
        }

        if(count >= 2)
            sub_print_node(to_print->data, level);
        else
            block = 0;
    } else {
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

