//
// Created by joao on 24/11/21.
//

#include "symbol_entry.h"
#include "abstract_syntax_tree.h"

#ifndef COMPILERS_SYMBOL_TABLE_H
#define COMPILERS_SYMBOL_TABLE_H

typedef struct {
    char * name;
    entry_t * entries;
    entry_t * return_;
} symbol_table_t;

typedef enum {
    T_FUNC_HEADER,
    T_FUNC_PARAM,
    T_FUNC_BODY,
} table_phase_t;

symbol_table_t * init_table(char * name);

void push_entry(symbol_table_t * table, entry_t * entry);

char * get_func_args(symbol_table_t * table);

void print_table(symbol_table_t * table);

char * get_func_args(symbol_table_t * table);

char * str_append(char * dest, char * src);

typedef enum {
    TABLE_,
    GLOBAL_VAR_,
} global_entry_types;

struct global_entry_data_t {
    symbol_table_t * table;
    entry_t * var;
};
typedef struct global_entry_data_t global_entry_data_t;

struct global_entry_t {
    global_entry_data_t * data;
    struct global_entry_t * next;
    int type;
};
typedef struct global_entry_t global_entry_t;

global_entry_t * init_global_entry(int type, symbol_table_t * table, entry_t * var);

typedef struct {
    char * name;
    global_entry_t * entries;
} global_table_t;

extern global_table_t * my_global_table;

global_table_t * init_global_table(void);

void push_global_entry(global_table_t * global_table, global_entry_t * entry);

void print_global_table(global_table_t * global_table);

void build_global_table(global_table_t * global_table, struct tree_node_t * tree_root);

#endif //COMPILERS_SYMBOL_TABLE_H
