
//
// Created by joao on 24/11/21.
//

#ifndef COMPILERS_SYMBOL_ENTRY_H
#define COMPILERS_SYMBOL_ENTRY_H

struct entry_t {
    char * name, * type;
    int role;
    struct entry_t * next;
};
typedef struct entry_t entry_t;

entry_t * create_entry(char * name, char * type, int role);

void print_entry(entry_t * entry);

#endif //COMPILERS_SYMBOL_ENTRY_H
