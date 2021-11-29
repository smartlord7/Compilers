
//
// Created by joao on 24/11/21.
//

#ifndef COMPILERS_SYMBOL_ENTRY_H
#define COMPILERS_SYMBOL_ENTRY_H

struct entry_t {
    char * name, * return_type, * arg_type;
    struct entry_t * next;
};
typedef struct entry_t entry_t;

entry_t * init_entry(char * name, char * return_type, char * arg_type);

typedef enum {
    RETURN_ENTRY_,
    VAR_ENTRY_,
} entry_types;

void print_entry(int type, entry_t * entry);

#endif //COMPILERS_SYMBOL_ENTRY_H
