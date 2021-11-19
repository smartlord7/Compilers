#include <stdio.h>
#include <stdlib.h>
#include "../data_structures/array_list.h"

int main(void) {
    int array[] = {1, 2, 3, 4, 5};
    array_list_t * array_list = new_array_list(sizeof(int));
    add(array_list, 1);


    return EXIT_SUCCESS;
}