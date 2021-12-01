#ifndef COMPILERS_ABSTRACT_SYNTAX_TREE_H
#define COMPILERS_ABSTRACT_SYNTAX_TREE_H

#include "linked_list.h"

typedef enum {d_program, d_var_dec, d_func_dec} node_type_t;

struct tree_node_t{
    char * id, * annotation;
    int type, level, line, column;
    struct list_node_t * children, * siblings;
};

typedef enum {
    A_PROGRAM,
    A_FUNC_DECL,
    A_VAR_DECL,
    A_INT,
    A_FLOAT32,
    A_BOOL,
    A_STRING,
    A_ID,
    A_FUNC_PARAMS,
    A_FUNC_HEADER,
    A_PARAM_DECL,
    A_FUNC_BODY,
    A_INVALID_NODE,
    A_ASSIGN,
    A_BLOCK,
    A_IF,
    A_FOR,
    A_RETURN,
    A_PRINT,
    A_PARSE_ARGS,
    A_CALL,
    A_OR,
    A_AND,
    A_LT,
    A_GT,
    A_LE,
    A_GE,
    A_EQ,
    A_NE,
    A_ADD,
    A_SUB,
    A_MUL,
    A_DIV,
    A_MOD,
    A_NOT,
    A_PLUS,
    A_MINUS,
    A_PROB_BLOCK,
    A_STRLIT,
    A_INTLIT,
    A_REALLIT,
} ast_node_types;

struct tree_node_t * create_node(int type, char * id);
extern struct tree_node_t * root;

void print_tree();

#endif //COMPILERS_ABSTRACT_SYNTAX_TREE_H
