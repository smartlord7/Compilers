#include "symbol_entry.h"
#include "data_types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char * data_type_text_t[] = {
        "int",
        "bool",
        "float32",
        "string",
        "",
        "param",
};

entry_t * init_entry(char * name, data_type_t return_type, data_type_t arg_type) {
    entry_t * new_entry = (entry_t *) calloc(1, sizeof(entry_t));

    new_entry->name = (char *) malloc(sizeof(name));
    strcpy(new_entry->name, name);

    new_entry->return_type = return_type;
    new_entry->arg_type = arg_type;

    new_entry->next = NULL;

    return new_entry;
}

void print_entry(int type, entry_t * entry) {
    switch (type) {
        case RETURN_ENTRY_:
            if(entry->return_type == D_NONE) {
                printf("%s\t%s\t%s\n", entry->name, data_type_text_t[entry->arg_type], data_type_text_t[entry->return_type]);
            } else {
                printf("%s\t%s\tnone\n", entry->name, data_type_text_t[entry->return_type]);
            }
            break;
        case VAR_ENTRY_:
            printf("%s\t\t%s\n", entry->name, data_type_text_t[entry->return_type]);
            break;
        case NULL_RETURN_ENTRY_:
            printf("return\t\tnone\n");
            break;
        case FUNC_RETURN_ENTRY_:
            printf("%s\t\t%s\n", entry->name, data_type_text_t[entry->return_type]);
            break;
        case FUNC_VAR_ENTRY_:
            printf("%s\t%s\t%s\n", entry->name, data_type_text_t[entry->arg_type], data_type_text_t[entry->return_type]);
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
    int i;

    src = (char *) malloc((strlen(src_string) + 1) * sizeof(char));

    for(i = 0; i < strlen(src_string); i++) {
        src[i] = tolower((unsigned char) src_string[i]);
    }
    src[i] = '\0';

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
