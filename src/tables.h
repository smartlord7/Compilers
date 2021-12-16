#ifndef COMPILERS_SYMBOL_TABLE_H
#define COMPILERS_SYMBOL_TABLE_H

#include "symbol_entry.h"
#include "data_types.h"

typedef struct entry_t entry_t;

struct local_table_t{
    char * name;
    entry_t * entries;
    entry_t * return_;
};

typedef enum {
    T_FUNC_HEADER,
    T_FUNC_PARAM,
    T_FUNC_BODY,
} table_phase_t;

typedef enum {
    TABLE_,
    GLOBAL_VAR_,
} global_entry_type;

typedef enum {
    SYMBOL_NOT_FOUND,
    SYMBOL_FOUND,
    SYMBOL_REPEATED,
} symbol_check_t;

typedef enum {
    SYMBOL_DECL,
    SYMBOL_USAGE,
} symbol_check_mode_t;

typedef enum {
    FATHER_VOID,
    FATHER_VAR_DECL,
    FATHER_PARAM_DECL,
    FATHER_CALL,
} symbol_father_t;

typedef struct global_entry_data_t global_entry_data_t;

struct global_entry_t {
    global_entry_data_t * data;
    global_entry_type type;
    int used;
    struct global_entry_t * next;
};

typedef struct local_table_t local_table_t;

struct global_entry_data_t {
    local_table_t * table;
    entry_t * var;
};

typedef struct global_entry_t global_entry_t;

struct global_table_t {
    char * name;
    global_entry_t * entries;
};

typedef enum {
    FIRST_PASSAGE,
    SECOND_PASSAGE,
} passage_t;

typedef struct global_table_t global_table_t;
typedef struct tree_node_t tree_node_t;
typedef enum data_type_t data_type_t;

extern local_table_t * init_table(char * name);
extern void push_entry(local_table_t * table, entry_t * entry);
extern char * get_func_args(local_table_t * table);
extern void print_table(local_table_t * table);
extern char * get_func_args(local_table_t * table);
extern char * str_append(char * dest, char * src);
extern global_entry_t * init_global_entry(int type, local_table_t * table, entry_t * var);
extern global_table_t * my_global_table;
extern global_table_t * init_global_table(void);
extern void push_global_entry(global_table_t * global_table, global_entry_t * entry);
extern void print_global_table(global_table_t * global_table);
extern void build_global_table(global_table_t * global_table, tree_node_t * tree_root, passage_t passage);
extern entry_t * get_var(global_table_t * global_table, local_table_t * local_table, char * var_name, symbol_check_mode_t mode, symbol_check_t * feedback);
extern local_table_t * get_func(global_table_t * global_table, char * func_name, symbol_check_mode_t mode, symbol_check_t * feedback);
extern void check_unused_global_symbols(global_table_t * global_table);

#endif //COMPILERS_SYMBOL_TABLE_H
