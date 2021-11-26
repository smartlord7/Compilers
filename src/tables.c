#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tables.h"

void push_entry(symbol_table_t * table, entry_t * entry) {
    symbol_table_t * new_table = (symbol_table_t *) malloc(sizeof(symbol_table_t));

    strcpy(new_table->name, name);
    new_table->entries = NULL;
    new_table->return_ = NULL;

    return new_table;
}

void push_entry(symbol_table_t * table, entry_t * entry) {

    if(table->entries == NULL) {
        table->entries = entry;
        return;
    }

    entry_t * tmp = table->entries;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = entry;
}

void print_table(symbol_table_t * table) {

    printf("==== ");

}

global_entry_t * init_global_entry(int type, symbol_table_t * table, entry_t * var) {
    global_entry_t * new_global_entry = (global_entry_t *) malloc(sizeof(global_entry_t));

    return new_global_entry;
}

global_table_t * init_global_table(void) {
    global_table_t * new_table = (global_table_t *) malloc(sizeof(global_table_t));

    strcpy(new_table->name, "Global");
    new_table->tables = NULL;

    return new_table;
}

void push_global_entry(global_table_t * global_table, global_entry_t * entry) {

    if(global_table->entries == NULL) {
        global_table->entries = entry;
        return;
    }

    global_entry_t * tmp = global_table->entries;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = entry;
}

void print_global_table(global_table_t * global_table) {

    printf("===== Global Symbol Table =====\n");

    global_entry_t * tmp = global_table->entries;
    while(tmp != NULL) {

        switch (tmp->type) {
            case TABLE_:
                printf("table\n");
                break;
            case GLOBAL_VAR_:
                printf("global var");
                break;
        }

        tmp = tmp->next;
    }
}