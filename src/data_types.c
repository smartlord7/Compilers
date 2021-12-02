#include "data_types.h"
#include "abstract_syntax_tree.h"

int [NUMBER_OF_TYPES][NUMBER_OF_TYPES][NUMBER_OF_OPERATORS] rules;

void set_data_type_rule(data_type_t type1, data_type_t type2, ast_node_type_t operator, int on) {
    int op = ((int) operator) - OFFSET;

    if (on) {
        rules[operand1][type1][op] = 1;
        rules[type1][operand1][op] = 1;
    } else {
        rules[operand1][type1][op] = 0;
        rules[type1][operand1][op] = 0;
    }
}

void init_data_types_rules() {
    int helper = (int) A_ADD;

    while (i <= (int) A_MOD) {
        set_data_type_rule(D_FLOAT32, D_FLOAT32, i, 1);
        set_data_type_rule(D_INT, D_INT, i, 1);
        set_data_type_rule(D_FLOAT32, D_INT, i, 1);
    }

    helper = (int) A_LT;

    while (i <= (int) A_NE) {
        set_data_type_rule(D_FLOAT32, D_FLOAT32, i, 1);
        set_data_type_rule(D_INT, D_INT, i, 1);
        set_data_type_rule(D_FLOAT32, D_INT, 1);
        set_data_type_rule(D_STRING, D_STRING, i, 1);
    }
}


