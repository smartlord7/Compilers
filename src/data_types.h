#ifndef COMPILERS_DATA_TYPES_H
#define COMPILERS_DATA_TYPES_H

#define NUMBER_OF_OPERATORS 16
#define NUMBER_OF_TYPES 5
#define OFFSET 21

enum data_type_t{
    D_INT,
    D_BOOL,
    D_FLOAT32,
    D_STRING,
    D_NONE, // used also for unary operators
    D_PARAM,
};

typedef enum data_type_t data_type_t;

extern int rules[NUMBER_OF_TYPES][NUMBER_OF_TYPES][NUMBER_OF_OPERATORS];

#endif //COMPILERS_DATA_TYPES_H
