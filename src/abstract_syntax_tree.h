#ifndef COMPILERS_ABSTRACT_SYNTAX_TREE_H
#define COMPILERS_ABSTRACT_SYNTAX_TREE_H

#include "linked_list.h"

typedef enum {d_program, d_var_dec, d_func_dec} node_type_t;

struct tree_node_t{
    char * id;
    int type, level;
    struct list_node_t * children, * siblings;
};

struct tree_node_t * create_node(int type, char * id);
extern struct tree_node_t * root;

void print_tree();

#endif //COMPILERS_ABSTRACT_SYNTAX_TREE_H
