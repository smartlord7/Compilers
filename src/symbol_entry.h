
//
// Created by joao on 24/11/21.
//

#ifndef COMPILERS_SYMBOL_ENTRY_H
#define COMPILERS_SYMBOL_ENTRY_H

#include "linked_list.h"

struct entry_t {
    char * name, * return_type, * arg_type;
    struct entry_t * next;
};

typedef struct entry_t entry_t;

entry_t * init_entry(char * name, char * return_type, char * arg_type);

typedef enum {
    D_INT,
    D_BOOL,
    D_FLOAT32,
    D_STRING,
} data_type_t;

extern char * data_type_text_t[];

typedef enum {
    RETURN_ENTRY_,
    VAR_ENTRY_,
    NULL_RETURN_ENTRY_,
    FUNC_RETURN_ENTRY_,
    FUNC_VAR_ENTRY_,
} entry_types;

typedef struct {
    char * var_name;
    char * var_type;
} var_data_t;

typedef struct list_node_t list_node_t;

extern var_data_t * init_var_data(list_node_t * container);
extern void print_entry(int type, entry_t * entry);
extern char * trim_value(char * original_value);

#endif //COMPILERS_SYMBOL_ENTRY_H
