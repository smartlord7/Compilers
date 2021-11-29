#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tables.h"
#include "abstract_syntax_tree.h"
#include "linked_list.h"
#include "ctype.h"

symbol_table_t * init_table(char * name) {

    symbol_table_t * new_table = (symbol_table_t *) malloc(sizeof(symbol_table_t));
    new_table->name = (char *) malloc(sizeof(name));
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
    printf("===== %s() Symbol Table =====\n", table->name);
}

global_entry_t * init_global_entry(int type, symbol_table_t * table, entry_t * var) {
    global_entry_t * new_global_entry = (global_entry_t *) malloc(sizeof(global_entry_t));

    new_global_entry->data = (global_entry_data_t *) malloc(sizeof(global_entry_data_t));
    new_global_entry->type = type;
    new_global_entry->data->table = table;
    new_global_entry->data->var = var;

    return new_global_entry;
}

global_table_t * init_global_table(void) {
    char * global_header = "Global";

    global_table_t * new_table = (global_table_t *) malloc(sizeof(global_table_t));

    new_table->name = (char *) malloc(sizeof(global_header));
    strcpy(new_table->name, "Global");

    new_table->entries = NULL;

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

    printf("\n===== Global Symbol Table =====\n");

    global_entry_t * tmp = global_table->entries;
    while(tmp != NULL) {

        switch (tmp->type) {
            case TABLE_:
                printf("%s\t(paramType)\tparam\n", tmp->data->table->name);
                break;
            case GLOBAL_VAR_:
                print_entry(VAR_ENTRY_, tmp->data->var);
                break;
        }

        tmp = tmp->next;
    }
    printf("\n");

    tmp = global_table->entries;
    while(tmp != NULL) {

        switch (tmp->type) {
            case TABLE_:
                print_table(tmp->data->table);
                printf("\n");
                break;
        }

        tmp = tmp->next;
    }
    printf("\n");
}

char * trim_value(char * original_value) {
    char * value, * aux;
    int i;

    aux = (char *) malloc(strlen(original_value) * sizeof(char));
    strncpy(aux, original_value, strlen(original_value));

    i = 0;
    while (aux[i] != '(') {
        i++;
    }
    i++;
    aux = (aux + i);

    i = strlen(aux);
    while (aux[i] != ')') {
        i--;
    }
    aux[i] = '\0';

    value = (char *) malloc(i * sizeof(char));
    strncpy(value, aux, i);

    aux = NULL;
    free(aux);
    return value;
}

char * to_lower(char * src_string) {
    char * src = NULL;

    src = (char *) malloc(strlen(src_string) * sizeof(char));

    for(int i = 0; i < strlen(src_string); i++) {
        src[i] = tolower((unsigned char) src_string[i]);
    }

    return src;
}

void build_table(symbol_table_t * table, struct tree_node_t * table_root) {
    printf("%s\n", table_root->id);
}

void build_tables(global_table_t * global_table, struct tree_node_t * tree_root) {
    struct list_node_t * node = tree_root->children->next, * child = NULL, * grandchild = NULL;
    symbol_table_t * new_table = NULL;
    entry_t * new_var = NULL;
    global_entry_t * new_entry = NULL;
    char * var_name, * var_return_type, * func_name;

    if(node == NULL) {
        return;
    }

    while(node != NULL) {

        switch (node->data->type) {
            case A_FUNC_DECL:
                child = node->data->children->next;

                while (child != NULL) {

                    switch (child->data->type) {
                        case A_FUNC_HEADER:
                            grandchild = child->data->children->next;
                            func_name = trim_value(grandchild->data->id);
                            new_table = init_table(func_name);
                            build_table(new_table, child->data);
                            new_entry = init_global_entry(TABLE_, new_table, NULL);
                            push_global_entry(global_table, new_entry);
                            break;
                    }

                    child = child->data->siblings->next;
                }

                break;
            case A_VAR_DECL:
                var_name = NULL;
                var_return_type = NULL;

                //get var type
                child = node->data->children->next;
                var_return_type = to_lower(child->data->id);

                //get var name
                child = child->next;
                var_name = trim_value(child->data->id);
                new_var = init_entry(var_name, var_return_type, NULL);
                new_entry = init_global_entry(GLOBAL_VAR_, NULL, new_var);
                push_global_entry(global_table, new_entry);

                break;
        }

        node = node->data->siblings->next;
    }
}