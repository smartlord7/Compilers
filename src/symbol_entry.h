#ifndef COMPILERS_SYMBOL_ENTRY_H
#define COMPILERS_SYMBOL_ENTRY_H

#include "linked_list.h"
#include "data_types.h"

typedef enum {
    RETURN_ENTRY_,
    VAR_ENTRY_,
    NULL_RETURN_ENTRY_,
    FUNC_RETURN_ENTRY_,
    FUNC_VAR_ENTRY_,
} entry_type;

typedef enum data_type_t data_type_t;

struct entry_t {
    char * name;
    data_type_t return_type, arg_type;
    int used;
    struct entry_t * next;
};
typedef struct entry_t entry_t;

typedef struct {
    char * var_name;
    char * var_type;
} var_data_t;

typedef struct list_node_t list_node_t;

extern entry_t * init_entry(char * name, data_type_t return_type, data_type_t arg_type);
extern var_data_t * init_var_data(list_node_t * container);
extern void print_entry(int type, entry_t * entry);

#endif //COMPILERS_SYMBOL_ENTRY_H
