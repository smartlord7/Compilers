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
    if(node->type == -5) return;
    for(int i = 0; i < level; i++)
        printf("..");
    printf("%s\n", node->id);
}

void sub_print(struct list_node_t * to_print, int level) {
    if(to_print->data->type == 5) {
        int count = to_print->data->children->size;
        struct list_node_t * next = to_print->data->children->next;

        while(next != NULL) {
            count += next->data->siblings->size;
            next = next->next;
        }

        if(count < 2) return;
    }
    sub_print_node(to_print->data, level);
    struct list_node_t * next = to_print->data->children->next;

    while(next != NULL) {
        sub_print(next, level + 1);
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
    sub_print(root->children->next, 1);
}
