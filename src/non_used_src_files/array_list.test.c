#include <stdio.h>
#include <stdlib.h>
//#include "../data_structures/array_list.h"
#include "linked_list.h"

int main(void) {
    /*int array[] = {1, 2, 3, 4, 5};
    array_list_t * array_list = new_array_list(sizeof(int));

    for(int i = 0; i < 5; i++){
        add(array_list, array[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("%s\n", get(array_list, i));
    }*/

    int array[] = {1, 2, 3, 4, 5};

    struct list_node_t * head = NULL;

    for(int i = 0; i < 5; i++) {
        head = push(head, (void *) &array[i], d_int);
    }

    float arrayf[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for(int i = 0; i < 5; i++) {
        head = push(head, (void *) &arrayf[i], d_float);
    }

    char arrayc[] = {'a', 'b', 'c', 'd', 'f'};
    for(int i = 0; i < 5; i++) {
        head = push(head, (void *) &arrayc[i], d_char);
    }

    char * string = "hello world";
    head = push(head, (void *) &string, d_string);

    struct custom_t custom;
    custom.custom_string = "int";
    custom.custom_int = 1;
    head = push(head, (void*) &custom, d_custom);

    print_list(head);

    return EXIT_SUCCESS;
}