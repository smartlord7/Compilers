#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tables.h"
#include "abstract_syntax_tree.h"
#include "linked_list.h"

symbol_table_t * init_table(char * name) {

    symbol_table_t * new_table = (symbol_table_t *) calloc(1, sizeof(symbol_table_t));
    new_table->name = (char *) malloc(sizeof(name));
    strcpy(new_table->name, name);

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
    printf("===== Function %s(%s) Symbol Table =====\n", table->name, get_func_args(table));

    if(table->return_ == NULL) {
        print_entry(NULL_RETURN_ENTRY_, table->return_);
    } else {
        print_entry(FUNC_RETURN_ENTRY_, table->return_);
    }

    entry_t * entry = table->entries;
    while (entry != NULL) {
        print_entry(FUNC_VAR_ENTRY_, entry);
        entry = entry->next;
    }

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

    global_table_t * new_table = (global_table_t *) malloc(sizeof(global_table_t));

    new_table->name = (char *) malloc(sizeof("Global"));
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

    printf("===== Global Symbol Table =====\n");

    global_entry_t * tmp = global_table->entries;
    while(tmp != NULL) {

        switch (tmp->type) {
            case TABLE_:
                if(tmp->data->table->return_ == NULL) {
                    printf("%s\t(%s)\tnone\n", tmp->data->table->name, get_func_args(tmp->data->table));
                } else {
                    printf("%s\t(%s)\t%s\n", tmp->data->table->name, get_func_args(tmp->data->table), tmp->data->table->return_->return_type);
                }

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
}

char * str_append(char * dest, char * src) {
    char * tmp = NULL;
    int i = 0, j = 0;

    tmp = (char *) malloc(sizeof(dest) + sizeof(src) - 1);

    while (i < strlen(dest)) {
        tmp[i] = dest[i];
        i++;
    }

    while (j < strlen(src)) {
        tmp[i] = src[j];
        i++;
        j++;
    }
    tmp[i] = '\0';

    return tmp;
}

char * get_func_args(symbol_table_t * table) {
    char * args = NULL;
    int first_append = 1;
    entry_t * entry = NULL;

    entry = table->entries;
    while (entry != NULL && strcasecmp(entry->return_type, "param") == 0) {
        if (first_append) {
            args = (char *) malloc(sizeof(entry->arg_type));
            strcat(args, entry->arg_type);
            first_append = 0;
        } else {
            args = str_append(args, ",");
            args = strcat(args, entry->arg_type);
        }
        entry = entry->next;
    }

    if (args == NULL) {
        return "";
    }

    return args;
}

void sub_build_local_table(symbol_table_t * table, struct list_node_t * node, int build_phase) {
    struct list_node_t * child = NULL;
    entry_t * new_entry = NULL;
    var_data_t * aux_var = NULL;
    char * name = NULL, * type = NULL;

    switch (node->data->type) {
        case A_FUNC_PARAMS:
            build_phase = T_FUNC_PARAM;
            break;
        case A_FUNC_BODY:
            build_phase = T_FUNC_BODY;
            break;
        case A_INT:
            if (build_phase == T_FUNC_HEADER) {
                table->return_ = init_entry("return", data_type_text_t[D_INT], NULL);
            }
            break;
        case A_FLOAT32:
            if (build_phase == T_FUNC_HEADER) {
                table->return_ = init_entry("return", data_type_text_t[D_FLOAT32], NULL);
            }
            break;
        case A_BOOL:
            if (build_phase == T_FUNC_HEADER) {
                table->return_ = init_entry("return", data_type_text_t[D_BOOL], NULL);
            }
            break;
        case A_STRING:
            if (build_phase == T_FUNC_HEADER) {
                table->return_ = init_entry("return", data_type_text_t[D_STRING], NULL);
            }
            break;
        case A_PARAM_DECL:

            aux_var = init_var_data(node);
            type = aux_var->var_type;
            name = aux_var->var_name;

            new_entry = init_entry(name, "param", type);
            push_entry(table, new_entry);
            break;
        case A_VAR_DECL:

            aux_var = init_var_data(node);
            type = aux_var->var_type;
            name = aux_var->var_name;

            new_entry = init_entry(name, type, "");
            push_entry(table, new_entry);
            break;
    }

    child = node->data->children->next;
    while (child != NULL) {
        sub_build_local_table(table, child, build_phase);
        child = child->next;
    }

    child = node->data->siblings->next;
    while (child != NULL) {
        sub_build_local_table(table, child, build_phase);
        child = child->next;
    }
}

void build_local_table(symbol_table_t * table, struct tree_node_t * table_root) {
    struct list_node_t * node = NULL;

    node = table_root->children->next;
    while (node != NULL) {
        sub_build_local_table(table, node, T_FUNC_HEADER);
        node = node->next;
    }
}

void sub_build_global_table(global_table_t * global_table, struct list_node_t * node) {
    struct list_node_t * child = NULL, * grandchild = NULL;
    symbol_table_t * new_table = NULL;
    entry_t * new_var = NULL;
    global_entry_t * new_entry = NULL;
    var_data_t * aux_var = NULL;
    char * var_name, * var_return_type, * func_name;

    if (node == NULL) {
        return;
    }

    printf("%s\n", node->data->id);

    switch (node->data->type) {
        case A_FUNC_DECL:
            printf("---- Func\n");

            child = node->data->children->next;

            break;
        case A_VAR_DECL:
            printf("---- Var\n");

            var_name = NULL;
            var_return_type = NULL;

            aux_var = init_var_data(node);
            var_return_type = aux_var->var_type;
            var_name = aux_var->var_name;

            new_var = init_entry(var_name, var_return_type, NULL);

            new_entry = init_global_entry(GLOBAL_VAR_, NULL, new_var);

            push_global_entry(global_table, new_entry);

            break;
        default:
            return;
    }

    child = node->data->children->next;
    while (child != NULL) {
        sub_build_global_table(global_table, child);
        child = child->next;
    }

    child = node->data->siblings->next;
    while (child != NULL) {
        sub_build_global_table(global_table, child);
        child = child->next;
    }
}

void build_global_table(global_table_t * global_table, struct tree_node_t * tree_root) {
    struct list_node_t * node = tree_root->children->next, * child = NULL, * grandchild = NULL;
    symbol_table_t * new_table = NULL;
    entry_t * new_var = NULL;
    global_entry_t * new_entry = NULL;
    var_data_t * aux_var = NULL;
    char * var_name, * var_return_type, * func_name;

    if (node == NULL) {
        return;
    }

    child = tree_root->children->next;
    while (child != NULL) {
        sub_build_global_table(global_table, child);
        child = child->next;
    }

    /*
    while (node != NULL) {
        switch (node->data->type) {
            case A_FUNC_DECL:
                child = node->data->children->next;

                while (child != NULL) {

                    switch (child->data->type) {
                        case A_FUNC_HEADER:
                            grandchild = child->data->children->next;
                            func_name = trim_value(grandchild->data->id);
                            new_table = init_table(func_name);
                            build_local_table(new_table, node->data);
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

                aux_var = init_var_data(node);
                var_return_type = aux_var->var_type;
                var_name = aux_var->var_name;

                new_var = init_entry(var_name, var_return_type, NULL);

                new_entry = init_global_entry(GLOBAL_VAR_, NULL, new_var);

                push_global_entry(global_table, new_entry);

                break;
        }

        node = node->data->siblings->next;
    }*/
}
