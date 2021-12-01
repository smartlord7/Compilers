//
// Created by joao on 24/11/21.
//

#include "symbol_entry.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char * data_type_text_t[] = {
        "int",
        "bool",
        "float32",
        "string",
};

entry_t * init_entry(char * name, char * return_type, char * arg_type) {
    entry_t * new_entry = (entry_t *) malloc(sizeof(entry_t));

    new_entry->name = (char *) malloc(sizeof(name));
    strcpy(new_entry->name, name);

    if (return_type != NULL) {
        new_entry->return_type = (char *) malloc(sizeof(return_type));
        strcpy(new_entry->return_type, return_type);
    } else {
        new_entry->return_type = NULL;
    }

    if (arg_type != NULL) {
        new_entry->arg_type = (char *) malloc(sizeof(arg_type));
        strcpy(new_entry->arg_type, arg_type);
    } else {
        new_entry->arg_type = NULL;
    }

    new_entry->next = NULL;

    return new_entry;
}

void print_entry(int type, entry_t * entry) {
    switch (type) {
        case RETURN_ENTRY_:
            if(entry->return_type == NULL) {
                printf("%s\t%s\t%s\n", entry->name, entry->arg_type, entry->return_type);
            } else {
                printf("%s\t%s\tnone\n", entry->name, entry->return_type);
            }
            break;
        case VAR_ENTRY_:
            printf("%s\t\t%s\n", entry->name, entry->return_type);
            break;
        case NULL_RETURN_ENTRY_:
            printf("return\t\tnone\n");
            break;
        case FUNC_RETURN_ENTRY_:
            printf("%s\t\t%s\n", entry->name, entry->return_type);
            break;
        case FUNC_VAR_ENTRY_:
            printf("%s\t%s\t%s\n", entry->name, entry->arg_type, entry->return_type);
            break;
    }
}

char * trim_value(char * original_value) {
    char * value, * aux;
    int i;

    while (original_value[0] != '(') {
        original_value++;
    }
    aux = ++original_value;

    i = 0;
    while (original_value[0] != ')') {
        original_value++;
        i++;
    }

    value = (char *) malloc((i + 1) * sizeof(char));
    strncpy(value, aux, i);
    value[i] = '\0';

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

var_data_t * init_var_data(struct list_node_t * container) {
    var_data_t * new_var = NULL;
    struct list_node_t * child = NULL;

    new_var = (var_data_t *) malloc(sizeof(var_data_t));

    child = container->data->children->next;
    new_var->var_type = to_lower(child->data->id);

    child = child->next;
    new_var->var_name = trim_value(child->data->id);

    return new_var;
}
