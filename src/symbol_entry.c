//
// Created by joao on 24/11/21.
//

#include "symbol_entry.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

entry_t * create_entry(char * name, char * type, int role) {
    entry_t * new_entry = (entry_t *) malloc(sizeof(entry_t));

    strcpy(new_entry->name, name);
    strcpy(new_entry->type, type);
    new_entry->next = NULL;

    return new_entry;
}

void print_entry(entry_t * entry) {
    printf("%s\t%s%d\n", entry->name, entry->type, entry->role);
}