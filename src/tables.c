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
    int first_append = 1, size;
    entry_t * entry = NULL;

    entry = table->entries;
    while (entry != NULL && entry->return_type == DATA_PARAM) {
        if (first_append) {
            size = (strlen(data_types[(entry->arg_type)]) + 1) * sizeof(char);
            args = (char *) malloc(size);
            strncpy(args, data_types[entry->arg_type], size);
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

char * get_call_args(global_table_t * global_table, local_table_t * local_table, list_node_t * child, int * has_args) {
    char * call_args = NULL;
    data_type_t result;
    int not_first = 0;

    call_args = (char *) malloc(2 * sizeof(char));
    strcpy(call_args, "");

    while (child != NULL) {
        * has_args = 1;
        if(not_first) {
            call_args = str_append(call_args, ",");
        }
        result = get_child_type(global_table, local_table, child);
        call_args = str_append(call_args, data_types[result]);
        if(child->data->siblings->next != NULL) {
            child = child->data->siblings->next;
        } else {
            child = child->next;
        }
        not_first = 1;
    }

    return call_args;
}

data_type_t get_child_type(global_table_t * global_table, local_table_t * local_table, list_node_t * node) {
    char * value = NULL, * call_args = NULL;
    local_table_t * aux_table = NULL;
    list_node_t * child = NULL;
    entry_t * aux_entry = NULL;
    symbol_check_t feedback;
    data_type_t result1, result2;
    int has_args = 0;

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
                } else {}

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

            } else if (feedback == SYMBOL_NOT_FOUND){}

            break;

        case A_CALL:
            child = node->data->children->next;

            if (child != NULL) {
                /*get func name*/
                value = trim_value(child->data->id);

                /*get func passed args*/
                has_args = 0;
                call_args = get_call_args(global_table, local_table, child->next, &has_args);

                aux_table = get_func(global_table, value, call_args, SYMBOL_USAGE, &feedback);

                if (feedback == SYMBOL_FOUND) {
                    if (aux_table->return_ != NULL) {
                        return aux_table->return_->return_type;
                    }
                } else if(feedback == SYMBOL_NOT_FOUND) {}
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
        case A_STRING:
            return DATATYPE_STRING;
        case A_BOOL:
        case A_EQ:
        case A_NE:
        case A_LT:
        case A_LE:
        case A_GT:
        case A_GE:
        case A_NOT:
        case A_AND:
        case A_OR:
            return DATATYPE_BOOL;
        default:
            break;
    }

    return DATATYPE_NONE;
}

void sub_build_local_table(global_table_t * global_table, local_table_t * table, struct list_node_t * node, struct list_node_t * previous_node,table_phase_t build_phase, symbol_father_t flag, passage_t passage) {
    struct list_node_t * child = NULL;
    entry_t * new_entry = NULL, * aux_entry = NULL;
    local_table_t * aux_table = NULL;
    var_data_t * aux_var_data = NULL;
    symbol_check_t feedback = 0;
    data_type_t result1, result2, result3;
    int has_args = 0;
    char * name = NULL, * type = NULL, * value = NULL, * func_args = NULL;

    switch (node->data->type) {
        case A_FUNC_PARAMS:
            build_phase = T_FUNC_PARAM;
            break;

        case A_FUNC_BODY:
            if(passage == FIRST_PASSAGE) {
                return;
            }
            build_phase = T_FUNC_BODY;
            break;
        case A_PARAM_DECL:
            flag = FATHER_PARAM_DECL;

            if(passage == FIRST_PASSAGE) {
                aux_var_data = init_var_data(node);
                type = aux_var_data->var_type;
                name = aux_var_data->var_name;

                int var_type = 0;
                while (strcmp(type, data_types[var_type]) != 0) {
                    var_type++;
                }

                new_entry = init_entry(name, DATA_PARAM, (data_type_t) var_type, node->data->children->next->next->data);
                push_entry(table, new_entry);
            }
            break;

        case A_VAR_DECL:
            flag = FATHER_VAR_DECL;

            aux_var_data = init_var_data(node);
            type = aux_var_data->var_type;
            name = aux_var_data->var_name;

            int var_type = 0;
            while (strcmp(type, data_types[var_type]) != 0) {
                var_type++;
            }

            aux_entry = get_var(global_table, table, name,SYMBOL_DECL, &feedback);

            new_entry = init_entry(name, (data_type_t) var_type, DATATYPE_NONE, node->data->children->next->next->data);
            push_entry(table, new_entry);
            break;

        case A_EQ:
        case A_NE:
        case A_LT:
        case A_LE:
        case A_GT:
        case A_GE:

            child = node->data->children->next;
            result1 = get_child_type(global_table, table, child);
            child = child->next;

            if(child != NULL) {
                result2 = get_child_type(global_table, table, child);

                if(result2 == DATATYPE_NONE) {
                    result2 = DATATYPE_UNDEF;
                }

                if(result1 != result2 && node->data->errored == 0) {
                    node->data->errored = 1;
                    semantic_error(OPERATOR_INVALID_2, node->data, result1, result2, NULL);
                }

            }
            node->data->annotation = ANNOTATION_BOOL;
            break;

        case A_NOT:

            child = node->data->children->next;
            result1 = get_child_type(global_table, table, child);

            if(result1 != DATATYPE_BOOL && !node->data->errored) {
                node->data->errored = 1;
                semantic_error(OPERATOR_INVALID_1, node->data, result1, 0, NULL);
            }

            node->data->annotation = ANNOTATION_BOOL;
            break;

        case A_AND:
        case A_OR:

            child = node->data->children->next;
            result1 = get_child_type(global_table, table, child);
            child = child->next;
            if(child != NULL) {

                if(child->data->type == A_ID) {
                    aux_entry = get_var(global_table, table, trim_value(child->data->id), SYMBOL_USAGE, &feedback);

                    if(feedback == SYMBOL_FOUND) {

                        if(aux_entry->arg_type == DATATYPE_NONE) {
                            if(aux_entry->return_type != DATATYPE_BOOL) {
                                if (result1 != DATATYPE_BOOL && !child->data->errored) {
                                    child->data->errored = 1;
                                    semantic_error(OPERATOR_INVALID_2, node->data, result1, aux_entry->return_type, NULL);
                                }
                            }
                        } else {
                            if(aux_entry->arg_type != DATATYPE_BOOL) {
                                if (result1 != DATATYPE_BOOL && !child->data->errored) {
                                    child->data->errored = 1;
                                    semantic_error(OPERATOR_INVALID_2, node->data, result1, aux_entry->arg_type, NULL);
                                }
                            }
                        }

                    }
                } else if(child->data->type == A_CALL) {
                    /*get call args*/
                    has_args = 0;
                    func_args = get_call_args(global_table, table, child->data->children->next->next, &has_args);

                    aux_table = get_func(global_table, trim_value(child->data->id), func_args, SYMBOL_USAGE, &feedback);
                    if (feedback == SYMBOL_FOUND) {
                        if (aux_table->return_->return_type != DATATYPE_BOOL) {
                            if (result1 != DATATYPE_BOOL && !child->data->errored) {
                                child->data->errored = 1;
                                semantic_error(OPERATOR_INVALID_2, node->data, result1, aux_table->return_->return_type, NULL);
                            }
                        }
                    } else if (feedback == SYMBOL_NOT_FOUND) {}
                } else {
                    result2 = get_child_type(global_table, table, child);
                    if(result2 != DATATYPE_BOOL) {
                        result3 = check_bool(child->data->type);
                        if(result3 == DATATYPE_BOOL) {
                            result2 = result3;
                        }
                    }
                    if((result1 != result2 || result1 != DATATYPE_BOOL || result2 != DATATYPE_BOOL) && node->data->errored == 0) {
                        node->data->errored = 1;
                        semantic_error(OPERATOR_INVALID_2, node->data, result1, result2, NULL);
                    }
                }
            }

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

                } else {
                    if(result1 == DATATYPE_BOOL && check_bool(child->data->type) == DATATYPE_BOOL) {
                        node->data->annotation = ANNOTATION_BOOL;
                    } else {
                        if(!node->data->errored) {
                            node->data->errored = 1;

                            if(result2 == DATATYPE_NONE) {
                                result2 = DATATYPE_UNDEF;
                            }
                            semantic_error(OPERATOR_INVALID_2, node->data, result1, result2, NULL);
                        }
                    }
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

            /*get func name*/
            child = node->data->children->next;
            value = trim_value(child->data->id);

            /*get func args*/
            has_args = 0;
            func_args = get_call_args(global_table, table, child->next, &has_args);

            aux_table = get_func(global_table, value, func_args, SYMBOL_USAGE, &feedback);

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
            } else if(feedback == SYMBOL_NOT_FOUND) {}

            break;

        case A_PARSE_ARGS:
            child = node->data->children->next;
            value = trim_value(child->data->id);
            aux_entry = get_var(global_table,table, value, SYMBOL_USAGE, &feedback);

            child = node->data->children->next;
            child = child->next;

            if (feedback == SYMBOL_FOUND) {
                if (aux_entry->return_type != DATATYPE_NONE) {
                    node->data->annotation = data_types[aux_entry->return_type];
                }

                result1 = get_child_type(global_table, table, node->data->children->next);
                result2 = get_child_type(global_table, table, node->data->children->next->next);

                if(result1 != DATATYPE_INT || result2 != DATATYPE_INT) {
                    if(result2 != DATATYPE_BOOL) {
                        result3 = check_bool(child->data->type);
                        if(result3 == DATATYPE_BOOL) {
                            result2 = result3;
                        }
                    }

                    if(result2 == DATATYPE_NONE) {
                        result2 = DATATYPE_UNDEF;
                    }
                    if(!node->data->errored) {
                        semantic_error(OPERATOR_INVALID_2, node->data, result1, result2, NULL);
                        node->data->errored = 1;
                    }
                }

            }

            break;

        case A_ID:
            value = trim_value(node->data->id);

            if (build_phase == T_FUNC_BODY) {
                if (flag == FATHER_CALL) {

                    has_args = 0;
                    func_args = get_call_args(global_table, table, previous_node->data->children->next->next, &has_args);
                    aux_table = get_func(global_table, value, func_args, SYMBOL_USAGE, &feedback);

                    if (feedback == SYMBOL_FOUND) {
                        value = (char *) malloc((strlen("(") + 1) * sizeof(char));
                        strcpy(value, "(");
                        value = str_append(value, get_func_args(aux_table));
                        value = str_append(value, ")");
                        node->data->annotation = value;
                    } else if (feedback == SYMBOL_NOT_FOUND) {

                        if (!node->data->errored) {
                            if(has_args) {
                                semantic_error(SYMBOL_MISSING_FUNC, node->data, 0, 0, "undef");
                            } else {
                                semantic_error(SYMBOL_MISSING_FUNC, node->data, 0, 0, "");
                            }
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
                            semantic_error(SYMBOL_MISSING, node->data, 0, 0, NULL);
                            node->data->errored = 1;
                        }
                    }
                }
            }

            break;
        case A_IF:
        case A_FOR:
            child = node->data->children->next;

            if (child->data->type == A_ID) {
                aux_entry = get_var(global_table, table, trim_value(child->data->id), SYMBOL_USAGE, &feedback);

                if (feedback == SYMBOL_FOUND) {

                    if (aux_entry->arg_type == DATATYPE_NONE) { /*it's a function parameter*/

                        if (aux_entry->return_type != DATATYPE_BOOL && !child->data->errored) {
                            child->data->errored = 1;
                            semantic_error(INCOMPATIBLE_TYPE, child->data, aux_entry->return_type, 0, node->data->id);}
                        }
                    } else {

                        if (aux_entry->arg_type != DATATYPE_BOOL && !child->data->errored) {
                            child->data->errored = 1;
                            semantic_error(INCOMPATIBLE_TYPE, child->data, aux_entry->arg_type, 0, node->data->id);
                        }

                    }

            } else if(child->data->type == A_CALL) {
                has_args = 0;
                func_args = get_call_args(global_table, table, child->data->children->next->next, &has_args);
                aux_table = get_func(global_table, trim_value(child->data->id), func_args, SYMBOL_USAGE, &feedback);

                if (feedback == SYMBOL_FOUND) {

                    if (aux_table->return_->return_type != DATATYPE_BOOL && !child->data->errored) {
                        child->data->errored = 1;
                        semantic_error(INCOMPATIBLE_TYPE, child->data, aux_table->return_->return_type, 0, node->data->id);
                    }

                } else if(feedback == SYMBOL_NOT_FOUND) {}
            } else {
                result1 = check_bool(child->data->type);

                if (result1 != DATATYPE_BOOL && !child->data->errored) {
                    child->data->errored = 1;
                    semantic_error(INCOMPATIBLE_TYPE, child->data, result1, 0, node->data->id);
                }

            }

            break;

        default:
            break;
    }

    child = node->data->children->next;
    while (child != NULL) {
        sub_build_local_table(global_table, table, child, node, build_phase, flag, passage);
        if (flag == FATHER_CALL) {
            flag = FATHER_VOID;
        }
        child = child->next;
    }

    flag = FATHER_VOID;

    child = node->data->siblings->next;
    while (child != NULL) {
        sub_build_local_table(global_table, table, child, node, build_phase, flag, passage);
        child = child->next;
    }
}

void build_local_table(global_table_t * global_table, local_table_t * table, struct tree_node_t * table_root, passage_t passage) {
    struct list_node_t * node = NULL;

    node = table_root->children->next;
    while (node != NULL) {
        sub_build_local_table(global_table, table, node, NULL, T_FUNC_HEADER, 0, passage);
        node = node->next;
    }
}

void sub_build_global_table(global_table_t * global_table, struct list_node_t * node, passage_t passage) {
    struct list_node_t * child = NULL, * grandchild = NULL, * grand_grand_child = NULL;
    local_table_t * new_table = NULL, * aux_local_table = NULL;
    entry_t * new_var = NULL;
    global_entry_t * new_entry = NULL;
    var_data_t * aux_var_data = NULL;
    symbol_check_t feedback = 0;
    char * var_name, * var_return_type, * func_name, * func_args;

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
                            get_func(global_table, func_name, "",SYMBOL_DECL, &feedback);

                            if (feedback == SYMBOL_NOT_FOUND) {
                                get_var(global_table, NULL, func_name, SYMBOL_DECL, &feedback); // check if there is a variable with the same name as the function
                            }

                            switch (feedback) {
                                case SYMBOL_NOT_FOUND:
                                    new_table = init_table(func_name);

                                    grand_grand_child = grandchild->data->siblings->next;

                                    switch (grand_grand_child->data->type) { /*define return type*/
                                        case A_FUNC_PARAMS:
                                            new_table->return_ = init_entry("return", DATATYPE_NONE, DATATYPE_NONE, grand_grand_child->data);
                                            break;
                                        case A_INT:
                                            new_table->return_ = init_entry("return", DATATYPE_INT, DATATYPE_NONE, grand_grand_child->data);
                                            break;

                                        case A_FLOAT32:
                                            new_table->return_ = init_entry("return", DATATYPE_FLOAT32, DATATYPE_NONE, grand_grand_child->data);
                                            break;

                                        case A_BOOL:
                                            new_table->return_ = init_entry("return", DATATYPE_BOOL, DATATYPE_NONE, grand_grand_child->data);
                                            break;

                                        case A_STRING:
                                            new_table->return_ = init_entry("return", DATATYPE_STRING, DATATYPE_NONE, grand_grand_child->data);
                                            break;
                                        default:
                                            break;
                                    }

                                    build_local_table(global_table, new_table, node->data, passage);
                                    new_entry = init_global_entry(TABLE_, new_table, NULL);
                                    push_global_entry(global_table, new_entry);

                                    break;
                                case SYMBOL_REPEATED:
                                    if (!node->data->errored) {
                                        semantic_error(SYMBOL_ALREADY_DEFINED, node->data->children->next->data->children->next->data, 0, 0, NULL);
                                        node->data->errored = 1;
                                    }
                                    break;
                                default:
                                    break;
                            }

                        } else if (passage == SECOND_PASSAGE) {

                            //printf("--------------------->%s\n", get_func_params(child));
                            func_args = get_func_params(child);
                            aux_local_table = get_func(global_table, func_name, func_args, SYMBOL_USAGE, &feedback);

                            switch (feedback) {
                                case SYMBOL_FOUND:
                                    build_local_table(global_table, aux_local_table, node->data, passage);
                                    break;
                                case SYMBOL_NOT_FOUND:
                                    //printf("not found %s123\n", func_name);
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
                    get_func(global_table, var_name, "", SYMBOL_DECL, &feedback); // check if there is a function with the same name as the variable
                }

                switch (feedback) {
                    case SYMBOL_NOT_FOUND:
                        new_var = init_entry(var_name, (data_type_t) var_type, DATATYPE_NONE, node->data->children->next->next->data);
                        new_entry = init_global_entry(GLOBAL_VAR_, NULL, new_var);
                        push_global_entry(global_table, new_entry);

                        break;
                    case SYMBOL_REPEATED:
                        if (!node->data->errored) {
                            semantic_error(SYMBOL_ALREADY_DEFINED, node->data->children->next->next->data, 0, 0, NULL);
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

local_table_t * get_func(global_table_t * global_table, char * func_name, char * func_args, symbol_check_mode_t mode, symbol_check_t * feedback) {
    global_entry_t * global_entry = NULL;
    * feedback = SYMBOL_NOT_FOUND;

    global_entry = global_table->entries;
    while (global_entry != NULL) {
        if (global_entry->type == TABLE_ && strcmp(global_entry->data->table->name, func_name) == 0 &&
            strcmp(get_func_args(global_entry->data->table), func_args) == 0) {

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

char * get_func_params(list_node_t * node) {
    list_node_t * child = NULL, * grandchild = NULL, * grand_grand_child = NULL;
    char * func_params = NULL;

    if(node->data->type == A_FUNC_PARAMS) {
        //printf("---->reached func params\n");
        grandchild = node->data->children->next;

        func_params = (char *) malloc(2 * sizeof(char ));
        int not_first = 0;

        while (grandchild != NULL) {

            grand_grand_child = grandchild->data->children->next;
            if(grand_grand_child != NULL) {
                if(not_first) {
                    func_params = str_append(func_params, ",");
                }

                switch (grand_grand_child->data->type) {
                    case A_INT:
                        func_params = str_append(func_params, ANNOTATION_INT);
                        break;
                    case A_FLOAT32:
                        func_params = str_append(func_params, ANNOTATION_FLOAT32);
                        break;
                    case A_BOOL:
                        func_params = str_append(func_params, ANNOTATION_BOOL);
                        break;
                    case A_STRING:
                        func_params = str_append(func_params, ANNOTATION_STRING);
                        break;
                    default:
                        break;

                }
                not_first = 1;
            }

            grandchild = grandchild->data->siblings->next;
        }
        return func_params;
    }

    child = node->data->children->next;
    while (child != NULL) {
        func_params = get_func_params(child);
        if(func_params != NULL) {
            return func_params;
        }
        child = child->next;
    }

    child = node->data->siblings->next;
    while (child != NULL) {
        func_params = get_func_params(child);
        if(func_params != NULL) {
            return func_params;
        }
        child = child->next;
    }

    return func_params;
}

void check_unused_local_symbols(local_table_t * local_table) {
    entry_t * entry;

    entry = local_table->entries;
    while (entry != NULL) {
        if(entry->used == 0 && strcmp(data_types[entry->return_type], "param") != 0) {
            semantic_error(SYMBOL_NEVER_USED, entry->node, 0, 0, NULL);
        }
        entry = entry->next;
    }
}

void check_unused_global_symbols(global_table_t * global_table) {
    global_entry_t * entry;

    entry = global_table->entries;
    while (entry != NULL) {
        switch (entry->type) {
            case TABLE_:
                check_unused_local_symbols(entry->data->table);
                break;
            default:
                break;
        }
        entry = entry->next;
    }

}
