#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data_types.h"
#include "strings.h"
#include "symbol_entry.h"

entry_t * init_entry(char * name, data_type_t return_type, data_type_t arg_type, tree_node_t * node) {
    entry_t * new_entry = (entry_t *) calloc(1, sizeof(entry_t));

    new_entry->name = (char *) calloc(1,sizeof(name));
    strcpy(new_entry->name, name);

    new_entry->node = node;
    new_entry->return_type = return_type;
    new_entry->arg_type = arg_type;

    new_entry->next = NULL;

    return new_entry;
}

void print_entry(int type, entry_t * entry) {
    switch (type) {
        case RETURN_ENTRY_:
            if(entry->return_type == DATATYPE_NONE) {
                printf("%s\t%s\t%s\n", entry->name, data_types[entry->arg_type], data_types[entry->return_type]);
            } else {
                printf("%s\t%s\tnone\n", entry->name, data_types[entry->return_type]);
            }
            break;
        case VAR_ENTRY_:
            printf("%s\t\t%s\n", entry->name, data_types[entry->return_type]);
            break;
        case NULL_RETURN_ENTRY_:
            printf("return\t\tnone\n");
            break;
        case FUNC_RETURN_ENTRY_:
            if(entry->return_type == DATATYPE_NONE) {
                printf("%s\t\tnone\n", entry->name);
            } else {
                printf("%s\t\t%s\n", entry->name, data_types[entry->return_type]);
            }
            break;
        case FUNC_VAR_ENTRY_:

            if(strcmp(data_types[entry->return_type], "param") == 0) {
                printf("%s\t\t%s\t%s\n", entry->name, data_types[entry->arg_type], data_types[entry->return_type]);
            } else {
                printf("%s\t%s\t%s\n", entry->name, data_types[entry->arg_type], data_types[entry->return_type]);
            }

            break;
    }
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
