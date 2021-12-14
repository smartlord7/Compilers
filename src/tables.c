#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tables.h"
#include "strings.h"
#include "error_handling.h"

local_table_t * init_table(char * name) {

    local_table_t * new_table = (local_table_t *) calloc(1, sizeof(local_table_t));
    new_table->name = (char *) malloc((strlen(name) + 1) * sizeof(char));
    strcpy(new_table->name, name);

    return new_table;
}

void push_entry(local_table_t * table, entry_t * entry) {

    if (table->entries == NULL) {
        table->entries = entry;
        return;
    }

    entry_t * tmp = table->entries;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = entry;
}

void print_table(local_table_t * table) {
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

global_entry_t * init_global_entry(int type, local_table_t * table, entry_t * var) {
    global_entry_t * new_global_entry = (global_entry_t *) calloc(1, sizeof(global_entry_t));

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

    if (global_table->entries == NULL) {
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
    char * func_args = NULL;

    while(tmp != NULL) {

        switch (tmp->type) {
            case TABLE_:
                func_args = get_func_args(tmp->data->table);
                if(tmp->data->table->return_->return_type == DATATYPE_NONE) {
                    printf("%s\t(%s)\tnone\n", tmp->data->table->name, func_args);
                } else {
                    printf("%s\t(%s)\t%s\n", tmp->data->table->name, func_args, data_types[tmp->data->table->return_->return_type]);
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
            default:
                break;
        }

        tmp = tmp->next;
    }
}

char * str_append(char * dest, char * src) {
    char * tmp = NULL;

    tmp = (char *) malloc((strlen(dest) + strlen(src) + 1) * sizeof(char));

    memcpy(tmp, dest, strlen(dest));
    strcpy(tmp + strlen(dest), src);

    return tmp;
}

char * get_func_args(local_table_t * table) {
    char * args = NULL;
    int first_append = 1;
    entry_t * entry = NULL;

    entry = table->entries;
    while (entry != NULL && entry->return_type == DATA_PARAM) {
        if (first_append) {
            args = (char *) malloc(strlen(data_types[(entry->arg_type)] + 1) * sizeof(char));
            strcpy(args, data_types[entry->arg_type]);
            first_append = 0;
        } else {
            args = str_append(args, ",");
            args = str_append(args, data_types[entry->arg_type]);
        }
        entry = entry->next;
    }

    if (args == NULL) {
        return "";

    }
    args[strlen(args)] = '\0';

    return args;
}

data_type_t get_child_type(global_table_t * global_table, local_table_t * local_table, list_node_t * node) {
    char * value = NULL;
    local_table_t * aux_table = NULL;
    list_node_t * child = NULL;
    entry_t * aux_entry = NULL;
    symbol_check_t feedback;
    data_type_t result1, result2;

    switch (node->data->type) {
        case A_ADD:
        case A_SUB:
        case A_PLUS:
        case A_MINUS:
        case A_MUL:
        case A_DIV:
        case A_MOD:
        case A_ASSIGN:

            //get first child type
            child = node->data->children->next;
            result1 = get_child_type(global_table, local_table, child);

            child = child->next;
            if (child != NULL) {
                result2 = get_child_type(global_table, local_table, child);

                if (result1 == result2) {

                    switch (result1) {
                        case DATATYPE_INT:
                            node->data->annotation = ANNOTATION_INT;
                            break;
                        case DATATYPE_FLOAT32:
                            node->data->annotation = ANNOTATION_FLOAT32;
                            break;
                        case DATATYPE_BOOL:
                            node->data->annotation = ANNOTATION_BOOL;
                            break;
                        case DATATYPE_STRING:
                            node->data->annotation = ANNOTATION_STRING;
                            break;
                        default:
                            break;
                    }

                    return result1;
                } else if(node->data->errored == 0) {
                    node->data->errored = 1;
                    semantic_error(OPERATOR_INVALID_2, node->data, result1, result2);
                }

            } else {

                switch (result1) {
                    case DATATYPE_INT:
                        node->data->annotation = ANNOTATION_INT;
                        break;
                    case DATATYPE_FLOAT32:
                        node->data->annotation = ANNOTATION_FLOAT32;
                        break;
                    case DATATYPE_BOOL:
                        node->data->annotation = ANNOTATION_BOOL;
                        break;
                    case DATATYPE_STRING:
                        node->data->annotation = ANNOTATION_STRING;
                        break;
                    default:
                        break;
                }

                return result1;
            }

            break;
        case A_ID:
            value = trim_value(node->data->id);
            aux_entry = get_var(global_table, local_table, value, SYMBOL_USAGE, &feedback);

            if (feedback == SYMBOL_FOUND) {
                if (strcmp(data_types[aux_entry->return_type], data_types[DATA_PARAM]) == 0) {
                    return aux_entry->arg_type;
                } else {
                    return aux_entry->return_type;
                }

            } else if (feedback == SYMBOL_NOT_FOUND){
                if (!node->data->errored) {
                    semantic_error(SYMBOL_MISSING, node->data, 0, 0);
                    node->data->errored = 1;
                }
            }

            break;

        case A_CALL:
            child = node->data->children->next;

            if (child != NULL) {
                value = trim_value(child->data->id);
                aux_table = get_func(global_table, value, SYMBOL_USAGE, &feedback);

                if (feedback == SYMBOL_FOUND) {
                    if (aux_table->return_ != NULL) {
                        return aux_table->return_->return_type;
                    }
                } else if(feedback == SYMBOL_NOT_FOUND) {
                    printf("not found %s\n", value);
                }
            }

            break;

        case A_PARSE_ARGS:
            child = node->data->children->next;
            value = trim_value(child->data->id);
            aux_entry = get_var(global_table,local_table, value, SYMBOL_USAGE, &feedback);

            if (feedback == SYMBOL_FOUND) {
                if (aux_entry->return_type != DATATYPE_NONE) {
                    return aux_entry->return_type;
                }
            }

            break;
        case A_INTLIT:
            return DATATYPE_INT;
        case A_REALLIT:
            return DATATYPE_FLOAT32;
        case A_BOOL:
            return DATATYPE_BOOL;
        case A_STRING:
            return DATATYPE_STRING;
        case A_EQ:
        case A_NE:
        case A_LT:
        case A_LE:
        case A_GT:
        case A_GE:

            /*child = node->data->children->next;
            result1 = get_child_type(global_table, local_table, child);
            child = child->next;
            if(child != NULL) {
                result2 = get_child_type(global_table, local_table, child);

                if(result2 == DATATYPE_NONE) {
                    result2 = DATATYPE_UNDEF;
                }

                if(result1 != result2 && node->data->errored == 0) {
                    node->data->errored = 1;
                    semantic_error(OPERATOR_INVALID_2, node->data, result1, result2);
                }

            }*/
            node->data->annotation = ANNOTATION_BOOL;
            break;

        case A_NOT:
        case A_AND:
        case A_OR:
            /*child = node->data->children->next;
            result1 = get_child_type(global_table, local_table, child);
            child = child->next;
            if(child != NULL) {
                result2 = get_child_type(global_table, local_table, child);

                if((result1 != result2 || result1 != DATATYPE_BOOL || result2 != DATATYPE_BOOL) && node->data->errored == 0) {
                    node->data->errored = 1;
                    semantic_error(OPERATOR_INVALID_2, node->data, result1, result2);
                }
            }*/
            return DATATYPE_BOOL;
        default:
            break;
    }

    return DATATYPE_NONE;
}

void sub_build_local_table(global_table_t * global_table, local_table_t * table, struct list_node_t * node, table_phase_t build_phase, symbol_father_t flag, passage_t passage) {
    struct list_node_t * child = NULL;
    entry_t * new_entry = NULL, * aux_entry = NULL;
    local_table_t * aux_table = NULL;
    var_data_t * aux_var_data = NULL;
    symbol_check_t feedback = 0;
    data_type_t result1, result2;
    //data_type_t result0;
    char * name = NULL, * type = NULL, * value = NULL;

    switch (node->data->type) {
        case A_FUNC_PARAMS:
            build_phase = T_FUNC_PARAM;
            break;

        case A_FUNC_BODY:
            build_phase = T_FUNC_BODY;
            break;

        case A_INT:
            if (build_phase == T_FUNC_HEADER) {
                table->return_ = init_entry("return", DATATYPE_INT, DATATYPE_NONE);
            }
            break;

        case A_FLOAT32:
            if (build_phase == T_FUNC_HEADER) {
                table->return_ = init_entry("return", DATATYPE_FLOAT32, DATATYPE_NONE);
            }
            break;

        case A_BOOL:
            if (build_phase == T_FUNC_HEADER) {
                table->return_ = init_entry("return", DATATYPE_BOOL, DATATYPE_NONE);
            }
            break;

        case A_STRING:
            if (build_phase == T_FUNC_HEADER) {
                table->return_ = init_entry("return", DATATYPE_STRING, DATATYPE_NONE);
            }
            break;

        case A_PARAM_DECL:
            flag = FATHER_PARAM_DECL;

            aux_var_data = init_var_data(node);
            type = aux_var_data->var_type;
            name = aux_var_data->var_name;

            int var_type = 0;
            while (strcmp(type, data_types[var_type]) != 0) {
                var_type++;
            }

            new_entry = init_entry(name, DATA_PARAM, (data_type_t) var_type);
            push_entry(table, new_entry);
            break;

        case A_VAR_DECL:
            flag = FATHER_VAR_DECL;

            aux_var_data = init_var_data(node);
            type = aux_var_data->var_type;
            name = aux_var_data->var_name;

            var_type = 0;
            while (strcmp(type, data_types[var_type]) != 0) {
                var_type++;
            }

            aux_entry = get_var(global_table, table, name,SYMBOL_DECL, &feedback);

            new_entry = init_entry(name, (data_type_t) var_type, DATATYPE_NONE);
            push_entry(table, new_entry);
            break;

        case A_EQ:
        case A_NE:
        case A_LT:
        case A_LE:
        case A_GT:
        case A_GE:
            /*child = node->data->children->next;
            result1 = get_child_type(global_table, table, child);
            child = child->next;

            if(child != NULL) {
                result2 = get_child_type(global_table, table, child);

                if(result2 == DATATYPE_NONE) {
                    result2 = DATATYPE_UNDEF;
                }

                if(result1 != result2 && node->data->errored == 0) {
                    node->data->errored = 1;
                    semantic_error(OPERATOR_INVALID_2, node->data, result1, result2);
                }

            }*/
            node->data->annotation = ANNOTATION_BOOL;
            break;

        case A_NOT:

            /*child = node->data->children->next;
            result1 = get_child_type(global_table, table, child);

            if(result1 != DATATYPE_BOOL && !node->data->errored) {
                node->data->errored = 1;
                semantic_error(OPERATOR_INVALID_1, node->data, result1, 0);
            }*/

            node->data->annotation = ANNOTATION_BOOL;
            break;

        case A_AND:
        case A_OR:

            /*child = node->data->children->next;
            result1 = get_child_type(global_table, table, child);
            child = child->next;
            if(child != NULL) {
                result2 = get_child_type(global_table, table, child);

                if((result1 != result2 || result1 != DATATYPE_BOOL || result2 != DATATYPE_BOOL) && node->data->errored == 0) {
                    node->data->errored = 1;
                    semantic_error(OPERATOR_INVALID_2, node->data, result1, result2);
                }
            }*/

            node->data->annotation = ANNOTATION_BOOL;
            break;

        case A_ADD:
        case A_SUB:
        case A_PLUS:
        case A_MINUS:
        case A_MUL:
        case A_DIV:
        case A_MOD:
        case A_ASSIGN:
            child = node->data->children->next;

            while (child != NULL) {
                sub_build_local_table(global_table, table, child, build_phase, flag, passage);
                child = child->next;
            }

            child = node->data->children->next;
            result1 = get_child_type(global_table, table, child);

            child = child->next;
            if (child != NULL) {
                result2 = get_child_type(global_table, table, child);

                if (result1 == result2) {
                    switch (result1) {
                        case DATATYPE_INT:
                            node->data->annotation = ANNOTATION_INT;
                            break;
                        case DATATYPE_FLOAT32:
                            node->data->annotation = ANNOTATION_FLOAT32;
                            break;
                        case DATATYPE_BOOL:
                            node->data->annotation = ANNOTATION_BOOL;
                            break;
                        case DATATYPE_STRING:
                            node->data->annotation = ANNOTATION_STRING;
                            break;
                        default:
                            break;
                    }

                } else if(node->data->errored == 0) {
                    node->data->errored = 1;
                    semantic_error(OPERATOR_INVALID_2, node->data, result1, result2);
                }
            } else {
                switch (result1) {
                    case DATATYPE_INT:
                        node->data->annotation = ANNOTATION_INT;
                        break;
                    case DATATYPE_FLOAT32:
                        node->data->annotation = ANNOTATION_FLOAT32;
                        break;
                    case DATATYPE_BOOL:
                        node->data->annotation = ANNOTATION_BOOL;
                        break;
                    case DATATYPE_STRING:
                        node->data->annotation = ANNOTATION_STRING;
                        break;
                    default:
                        break;
                }

            }

            break;

        case A_STRLIT:
            node->data->annotation = ANNOTATION_STRING;
            break;

        case A_INTLIT:
            node->data->annotation = ANNOTATION_INT;
            break;

        case A_REALLIT:
            node->data->annotation = ANNOTATION_FLOAT32;
            break;

        case A_CALL:
            flag = FATHER_CALL;

            child = node->data->children->next;
            value = trim_value(child->data->id);
            aux_table = get_func(global_table, value, SYMBOL_USAGE, &feedback);

            if (feedback == SYMBOL_FOUND) {
                if (aux_table->return_ != NULL) {

                    switch (aux_table->return_->return_type) {
                        case DATATYPE_INT:
                            node->data->annotation = ANNOTATION_INT;
                            break;
                        case DATATYPE_FLOAT32:
                            node->data->annotation = ANNOTATION_FLOAT32;
                            break;
                        case DATATYPE_BOOL:
                            node->data->annotation = ANNOTATION_BOOL;
                            break;
                        case DATATYPE_STRING:
                            node->data->annotation = ANNOTATION_STRING;
                            break;
                        default:
                            break;
                    }
                }
            } else if(feedback == SYMBOL_NOT_FOUND) {
                printf("not found %s\n", value);
            }

            break;

        case A_PARSE_ARGS:
            child = node->data->children->next;
            value = trim_value(child->data->id);
            aux_entry = get_var(global_table,table, value, SYMBOL_USAGE, &feedback);

            if (feedback == SYMBOL_FOUND) {
                if (aux_entry->return_type != DATATYPE_NONE) {
                    node->data->annotation = data_types[aux_entry->return_type];
                }

            }

            break;

        case A_ID:
            value = trim_value(node->data->id);

            if (build_phase == T_FUNC_BODY) {
                if (flag == FATHER_CALL) {
                    aux_table = get_func(global_table, value, SYMBOL_USAGE, &feedback);

                    if (feedback == SYMBOL_FOUND) {
                        value = (char *) malloc((strlen("(") + 1) * sizeof(char));
                        strcpy(value, "(");
                        value = str_append(value, get_func_args(aux_table));
                        value = str_append(value, ")");

                        node->data->annotation = value;
                    } else if (feedback == SYMBOL_NOT_FOUND) {
                        if (!node->data->errored) {
                            semantic_error(SYMBOL_MISSING, node->data, 0, 0);
                            node->data->errored = 1;
                        }
                    }

                    flag = FATHER_VOID;
                } else if (flag == FATHER_VOID) {
                    aux_entry = get_var(global_table, table, value, SYMBOL_USAGE, &feedback);

                    if (feedback == SYMBOL_FOUND) {
                        if (strcmp(data_types[aux_entry->return_type], "param") == 0) {
                            node->data->annotation = data_types[aux_entry->arg_type];
                        } else {
                            node->data->annotation = data_types[aux_entry->return_type];
                        }

                    } else if (feedback == SYMBOL_NOT_FOUND) {
                        if (!node->data->errored) {
                            semantic_error(SYMBOL_MISSING, node->data, 0, 0);
                            node->data->errored = 1;
                        }
                    }
                }
            }

            break;
        case A_IF:
            /*child = node->data->children->next;
            result0 = get_child_type(global_table, table, child);

            if(result0 != DATATYPE_BOOL && !child->data->errored) {
                semantic_error(INCOMPATIBLE_TYPE, node->data, result0, 0);
            }*/

            break;
        case A_FOR:
            /*child = node->data->children->next;

            if(child->data->type == A_ID && !child->data->errored) {
                child->data->errored = 1;
                result0 = get_child_type(global_table, table, child);
                semantic_error(INCOMPATIBLE_TYPE, node->data, result0, 0);
            }*/

        default:
            break;
    }

    child = node->data->children->next;
    while (child != NULL) {
        sub_build_local_table(global_table, table, child, build_phase, flag, passage);
        if (flag == FATHER_CALL) {
            flag = FATHER_VOID;
        }
        child = child->next;
    }

    flag = FATHER_VOID;

    child = node->data->siblings->next;
    while (child != NULL) {
        sub_build_local_table(global_table, table, child, build_phase, flag, passage);
        child = child->next;
    }
}

void build_local_table(global_table_t * global_table, local_table_t * table, struct tree_node_t * table_root, passage_t passage) {
    struct list_node_t * node = NULL;

    node = table_root->children->next;
    while (node != NULL) {
        sub_build_local_table(global_table, table, node, T_FUNC_HEADER, 0, passage);
        node = node->next;
    }
}

void sub_build_global_table(global_table_t * global_table, struct list_node_t * node, passage_t passage) {
    struct list_node_t * child = NULL, * grandchild = NULL;
    local_table_t * new_table = NULL, * aux_local_table = NULL;
    entry_t * new_var = NULL;
    global_entry_t * new_entry = NULL;
    var_data_t * aux_var_data = NULL;
    symbol_check_t feedback = 0;
    char * var_name, * var_return_type, * func_name;

    if (node == NULL) {
        return;
    }

    switch (node->data->type) {
        case A_FUNC_DECL:
            child = node->data->children->next;

            while (child != NULL){
                switch (child->data->type) {
                    case A_FUNC_HEADER:
                        grandchild = child->data->children->next;
                        func_name = trim_value(grandchild->data->id);

                        if (passage == FIRST_PASSAGE) {
                            get_func(global_table, func_name, SYMBOL_DECL, &feedback);

                            if (feedback == SYMBOL_NOT_FOUND) {
                                get_var(global_table, NULL, func_name, SYMBOL_DECL, &feedback); // check if there is a variable with the same name as the function
                            }

                            switch (feedback) {
                                case SYMBOL_NOT_FOUND:
                                    new_table = init_table(func_name);

                                    grandchild = grandchild->data->siblings->next;

                                    switch (grandchild->data->type) {
                                        case A_FUNC_PARAMS:
                                            new_table->return_ = init_entry("return", DATATYPE_NONE, DATATYPE_NONE);
                                            break;
                                        case A_INT:
                                            new_table->return_ = init_entry("return", DATATYPE_INT, DATATYPE_NONE);
                                            break;

                                        case A_FLOAT32:
                                            new_table->return_ = init_entry("return", DATATYPE_FLOAT32, DATATYPE_NONE);
                                            break;

                                        case A_BOOL:
                                            new_table->return_ = init_entry("return", DATATYPE_BOOL, DATATYPE_NONE);
                                            break;

                                        case A_STRING:
                                            new_table->return_ = init_entry("return", DATATYPE_STRING, DATATYPE_NONE);
                                            break;
                                        default:
                                            break;
                                    }

                                    new_entry = init_global_entry(TABLE_, new_table, NULL);
                                    push_global_entry(global_table, new_entry);

                                    break;
                                case SYMBOL_REPEATED:
                                    if (!node->data->errored) {
                                        semantic_error(SYMBOL_ALREADY_DEFINED, node->data->children->next->data->children->next->data, 0, 0);
                                        node->data->errored = 1;
                                    }
                                    break;
                                default:
                                    break;
                            }

                        } else if (passage == SECOND_PASSAGE) {
                            aux_local_table = get_func(global_table, func_name, SYMBOL_USAGE, &feedback);

                            switch (feedback) {
                                case SYMBOL_FOUND:
                                    build_local_table(global_table, aux_local_table, node->data, passage);
                                    break;
                                default:
                                    break;
                            }
                        }
                        break;
                    default:
                        break;
                }

                child = child->data->siblings->next;
            }

            break;
        case A_VAR_DECL:
            var_name = NULL;
            var_return_type = NULL;

            aux_var_data = init_var_data(node);
            var_return_type = aux_var_data->var_type;
            var_name = aux_var_data->var_name;

            int var_type = 0;
            while (strcmp(var_return_type, data_types[var_type]) != 0) {
                var_type++;
            }

            if (passage == FIRST_PASSAGE) {
                get_var(global_table, NULL, var_name, SYMBOL_DECL, &feedback);

                if (feedback == SYMBOL_NOT_FOUND) {
                    get_func(global_table, var_name, SYMBOL_DECL, &feedback); // check if there is a function with the same name as the variable
                }

                switch (feedback) {
                    case SYMBOL_NOT_FOUND:
                        new_var = init_entry(var_name, (data_type_t) var_type, DATATYPE_NONE);
                        new_entry = init_global_entry(GLOBAL_VAR_, NULL, new_var);
                        push_global_entry(global_table, new_entry);

                        break;
                    case SYMBOL_REPEATED:
                        if (!node->data->errored) {
                            semantic_error(SYMBOL_ALREADY_DEFINED, node->data->children->next->next->data, 0, 0);
                            node->data->errored = 1;
                        }

                        break;
                    default:
                        break;
                }

            }

            break;
        default:
            return;
    }

    child = node->data->children->next;
    while (child != NULL) {
        sub_build_global_table(global_table, child, passage);
        child = child->next;
    }

    child = node->data->siblings->next;
    while (child != NULL) {
        sub_build_global_table(global_table, child, passage);
        child = child->next;
    }
}

void build_global_table(global_table_t * global_table, struct tree_node_t * tree_root, passage_t passage) {
    struct list_node_t * node = tree_root->children->next, * child = NULL;

    if (node == NULL) {
        return;
    }

    child = tree_root->children->next;
    while (child != NULL) {
        sub_build_global_table(global_table, child, passage);
        child = child->next;
    }
}

entry_t * get_var(global_table_t * global_table, local_table_t * local_table, char * var_name, symbol_check_mode_t mode, symbol_check_t * feedback) {
    global_entry_t * global_entry = NULL;
    entry_t * local_entry = NULL;
    * feedback = SYMBOL_NOT_FOUND;

    if (local_table != NULL) {
        local_entry = local_table->entries;
        while (local_entry != NULL) {

            if (strcmp(local_entry->name, var_name) == 0) {

                if (mode == SYMBOL_DECL) {
                    * feedback = SYMBOL_REPEATED;
                    return NULL;

                } else if (mode == SYMBOL_USAGE) {
                    local_entry->used = 1;
                    * feedback = SYMBOL_FOUND;
                    return local_entry;
                }
            }

            local_entry = local_entry->next;
        }

        if (mode == SYMBOL_USAGE) {
            global_entry = global_table->entries;
            while (global_entry != NULL) {

                if (global_entry->type == GLOBAL_VAR_ && strcmp(global_entry->data->var->name, var_name) == 0) {
                    global_entry->used = 1;
                    * feedback = SYMBOL_FOUND;
                    return global_entry->data->var;
                }

                global_entry = global_entry->next;
            }
        }

    } else {
        global_entry = global_table->entries;
        while (global_entry != NULL) {

            if(global_entry->type == GLOBAL_VAR_ && strcmp(global_entry->data->var->name, var_name) == 0) {
                * feedback = SYMBOL_REPEATED;
                return NULL;
            }

            global_entry = global_entry->next;
        }
    }

    return NULL;
}

local_table_t * get_func(global_table_t * global_table, char * func_name, symbol_check_mode_t mode, symbol_check_t * feedback) {
    global_entry_t * global_entry = NULL;
    * feedback = SYMBOL_NOT_FOUND;

    global_entry = global_table->entries;
    while (global_entry != NULL) {
        if (global_entry->type == TABLE_ && strcmp(global_entry->data->table->name, func_name) == 0) {
            if (mode == SYMBOL_DECL) {
                * feedback = SYMBOL_REPEATED;

                return NULL;
            } else if (mode == SYMBOL_USAGE) {

                global_entry->used = 1;
                * feedback = SYMBOL_FOUND;

                return global_entry->data->table;
            }
        }

        global_entry = global_entry->next;
    }


    return NULL;
}
