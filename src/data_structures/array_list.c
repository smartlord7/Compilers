#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "array_list.h"

static array_list_t * _init_array_list() {
    array_list_t * array_list = (array_list_t *) calloc(1, sizeof(array_list_t));
    assert(array_list != NULL);
}

static array_t * _init_array(int initial_capacity, size_t elem_size) {
    array_t array = calloc(initial_capacity, elem_size);
    assert(array != NULL);

    return array;
}

static array_t * _expand_array(array_list_t * array_list) {
    assert(array_list != NULL && array_list->array != NULL && array_list->size != 0);
    int new_capacity = ARRAY_LIST_GROWTH_FACTOR * array_list->capacity;

    array_t * array = realloc(array_list->array, new_capacity * array_list->elem_size);
    assert(array != NULL);
    array_list->capacity = new_capacity;

    return array;
}

/*array_list_t * new_array_list(int initial_capacity, size_t elem_size) {
    array_list_t * array_list = _init_array_list();
    array_list->elem_size = elem_size;
    array_list->array = _init_array(initial_capacity, elem_size);
    array_list->capacity = initial_capacity;

    return array_list;
}*/

array_list_t * new_array_list(size_t elem_size) {
    array_list_t * array_list = _init_array_list();
    array_list->elem_size = elem_size;

    return array_list;
}

elem_t get(array_list_t * array_list, int index) {
    assert(array_list != NULL);
    char * array = NULL;

    if (index <= 0 || index >= array_list->capacity) {
        return NULL;
    }

    array = (char *) array_list->array;

    return (elem_t) &array[array_list->elem_size * index];
}

void add(array_list_t * array_list, elem_t elem) {
    assert(array_list != NULL && elem != NULL);
    char * array = NULL;

    if (array_list->size == 0) {
        array_list->array = _init_array(ARRAY_LIST_PRED_INITIAL_CAPACITY, array_list->elem_size);
    } else {
        array_list->array = _expand_array(array_list);
        array = (char *) array_list->array;
        memcpy(&array[array_list->elem_size * array_list->size], elem, array_list->elem_size);
    }
}
