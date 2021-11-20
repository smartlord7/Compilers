#include "abstract_syntax_tree.h"
#include <stdlib.h>

struct tree_node_t * create_node(int type, void * data) {
    struct tree_node_t * new_node = (struct tree_node_t *) malloc(sizeof(struct tree_node_t));

    new_node->data = data;
    new_node->type = type;

    return new_node;
}
