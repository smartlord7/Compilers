#ifndef COMPILERS_DATA_TYPES_H
#define COMPILERS_DATA_TYPES_H

#define NUMBER_OF_OPERATORS 16
#define NUMBER_OF_TYPES 5
#define DEFAULT_OFFSET 21

typedef enum data_type_t{
    DATATYPE_INT,
    DATATYPE_BOOL,
    DATATYPE_FLOAT32,
    DATATYPE_STRING,
    DATATYPE_NONE, // used also for unary operators
    DATATYPE_UNDEF,
    DATA_PARAM,
} data_type_t;

typedef enum operator_t {
    O_ASSIGN,
    O_OR,
    O_AND,
    O_NOT,
    O_LT,
    O_GT,
    O_LE,
    O_GE,
    O_EQ,
    O_NE,
    O_ADD,
    O_SUB,
    O_MUL,
    O_DIV,
    O_NONE,
} operator_t;

#include "abstract_syntax_tree.h"

typedef enum ast_node_type_t ast_node_type_t;

extern char * data_types[];
extern char * operator_types[];

extern void set_data_type_rules_offset(int offset);
extern void set_data_type_rule(data_type_t type1, data_type_t type2, ast_node_type_t operator, int on, data_type_t result_data_type);
extern data_type_t check_op_data_types(data_type_t type1, data_type_t type2, ast_node_type_t operator);
extern void init_data_types_rules();
extern operator_t get_operator_type(ast_node_type_t node_type);
extern data_type_t check_bool(ast_node_type_t type);

#endif //COMPILERS_DATA_TYPES_H
