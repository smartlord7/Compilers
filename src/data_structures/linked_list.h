#ifndef COMPILERS_LINKED_LIST_H
#define COMPILERS_LINKED_LIST_H

struct custom_t {
    char * custom_string;
    int custom_int;
};

typedef enum {d_int, d_float, d_char, d_string, d_custom} type_t;

struct list_node_t {
    void * data;
    int type, level;
    struct list_node_t * next;
};

struct list_node_t * push(struct list_node_t * head, void * new_data, int type);
void print_list(struct list_node_t * head);
#endif //COMPILERS_LINKED_LIST_H
