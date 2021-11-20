#include "abstract_syntax_tree.h"
#include <stdlib.h>

tree_node_t * create_node(int type, void * data) {
    tree_node_t * new_node = (tree_node_t*) malloc(sizeof(tree_node_t));

    new_node->data = data;
    new_node->type = type;

    return new_node;
}