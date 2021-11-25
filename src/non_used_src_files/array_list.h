#ifndef GOCOMPILER_L_ARRAY_LIST_H
#define GOCOMPILER_L_ARRAY_LIST_H

#define ARRAY_LIST_GROWTH_FACTOR 2
#define ARRAY_LIST_PRED_INITIAL_CAPACITY 1

typedef void * array_t;
typedef void * elem_t;

typedef struct {
    int size, capacity;
    size_t elem_size;
    array_t * array;
} array_list_t;

extern array_list_t * new_array_list(size_t elem_size);
extern void add(array_list_t * array_list, elem_t elem);
extern elem_t get(array_list_t * array_list, int index);

#endif //GOCOMPILER_L_ARRAY_LIST_H
