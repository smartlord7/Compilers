//
// Created by joao on 24/11/21.
//

#include "symbol_entry.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

entry_t * init_entry(char * name, char * return_type, char * arg_type) {
    entry_t * new_entry = (entry_t *) malloc(sizeof(entry_t));

    new_entry->name = (char *) malloc(sizeof(name));
    strcpy(new_entry->name, name);

    if(return_type != NULL) {
        new_entry->return_type = (char *) malloc(sizeof(return_type));
        strcpy(new_entry->return_type, return_type);
    } else {
        new_entry->return_type = NULL;
    }

    if(arg_type != NULL) {
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
    }

}