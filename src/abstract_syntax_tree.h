#ifndef COMPILERS_ABSTRACT_SYNTAX_TREE_H
#define COMPILERS_ABSTRACT_SYNTAX_TREE_H

#include "tables.h"

#define ANNOTATION_BOOL "bool"
#define ANNOTATION_INT "int"
#define ANNOTATION_FLOAT32 "float32"
#define ANNOTATION_STRING "string"

#define ANNOTATION_BOOL_F "(bool)"
#define ANNOTATION_INT_F "(int)"
#define ANNOTATION_FLOAT32_F "(float32)"
#define ANNOTATION_STRING_F "(string)"

 enum ast_node_type_t {
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
    A_NOT,
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
    A_PLUS,
    A_MINUS,
    A_PROB_BLOCK,
    A_STRLIT,
    A_INTLIT,
    A_REALLIT,
    A_DUMMY,
};

typedef enum ast_node_type_t ast_node_type_t;

struct tree_node_t{
    char * id, * annotation;
    ast_node_type_t type;
    int level, line, column;
    struct list_node_t * children, * siblings;
};

typedef struct tree_node_t tree_node_t;
typedef struct local_table_t local_table_t;
typedef struct global_table_t global_table_t;
typedef struct global_entry_t global_entry_t;

extern struct tree_node_t * create_node(int type, char * id);
extern void print_tree(struct tree_node_t * node, int is_annotated);
extern void annotate_tree(struct tree_node_t * node, global_table_t * global_table, global_entry_t * global_entry);

#endif //COMPILERS_ABSTRACT_SYNTAX_TREE_H
