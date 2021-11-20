#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct list_node_t * create_node(void * new_data, int type) {
    struct list_node_t * new_node = (struct list_node_t*) malloc(sizeof(struct list_node_t));

    new_node->data = new_data;
    new_node->next = NULL;
    new_node->type = type;

    return new_node;
}

struct list_node_t * push(struct list_node_t * head, void * new_data, int type) {

    struct list_node_t * new_node = create_node(new_data, type);

    if(head == NULL) {
        return new_node;
    }

    struct list_node_t * tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_node;

    return head;
}

void printInt(void * n) {
    printf("%d\n", *(int *)n);
}

void printFloat(void * f) {
    printf("%f\n", *(float *)f);
}

void printChar(void * c) {
    printf("%c\n", *(char *)c);
}

void printString(void * s) {
    printf("%s\n", *(char **)s);
}

void printCustom(void * custom_value) {
    struct custom_t * custom = (struct custom_t *) custom_value;
    printf("%s -> %d\n", custom->custom_string ,custom->custom_int);
}

void print_node(struct list_node_t * node) {

    switch (node->type) {
        case d_int:
            printInt(node->data);
            break;
        case d_float:
            printFloat(node->data);
            break;
        case d_char:
            printChar(node->data);
            break;
        case d_string:
            printString(node->data);
            break;
        case d_custom:
            printCustom(node->data);
            break;
    }
}

void print_list(struct list_node_t * head) {
    if(head == NULL) {
        return;
    }

    struct list_node_t * tmp;
    for(tmp = head; tmp; tmp = tmp->next) {
        print_node(tmp);
    }
}