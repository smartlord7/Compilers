#include "data_types.h"
#include "abstract_syntax_tree.h"

static int rules[NUMBER_OF_TYPES][NUMBER_OF_TYPES][NUMBER_OF_OPERATORS];
static int offset = DEFAULT_OFFSET;

void set_data_type_rules_offset(int offset) {
    offset = offset;
}

void set_data_type_rule(data_type_t type1, data_type_t type2, ast_node_type_t operator, int on) {
    int op = ((int) operator) - offset;

    if (on) {
        rules[type2][type1][op] = 1;
        rules[type1][type2][op] = 1;
    } else {
        rules[type2][type1][op] = 0;
        rules[type1][type2][op] = 0;
    }
}

int check_op_data_types(data_type_t type1, data_type_t type2, ast_node_type_t operator) {
    return rules[type1][type2][operator];
}

void init_data_types_rules() {
    int i = (int) A_ADD;

    // allow binary arithmetic operations ("sub", "add", "mult", "div" and "mod") between float32's, int's, and float32 and int (same as int and float32)
    while (i <= (int) A_MOD) {
        set_data_type_rule(D_FLOAT32, D_FLOAT32, i, 1);
        set_data_type_rule(D_INT, D_INT, i, 1);
        set_data_type_rule(D_FLOAT32, D_INT, i, 1);

        i++;
    }

    // allow the equality comparison between bool's
    set_data_type_rule(D_BOOL, D_BOOL, A_EQ, 1);
    set_data_type_rule(D_BOOL, D_BOOL, A_NE, 1);

    i = (int) A_LT;

    // allow equality/comparisons between float32's, int's, float32 and int (sames as int and float32) and strings
    while (i <= (int) A_NE) {
        set_data_type_rule(D_FLOAT32, D_FLOAT32, i, 1);
        set_data_type_rule(D_INT, D_INT, i, 1);
        set_data_type_rule(D_FLOAT32, D_INT, i, 1);
        set_data_type_rule(D_STRING, D_STRING, i, 1);

        i++;
    }

    // allow the concatenations of strings
    set_data_type_rule(D_STRING, D_STRING, A_ADD, 1);

    i = (int) A_PLUS;

    // allow the usage of the unary arithmetic operators ("plus" and "minus") with float32's and int's
    while (i <= A_MINUS) {
        set_data_type_rule(D_INT, D_NONE, i, 1);
        set_data_type_rule(D_FLOAT32, D_NONE, i, 1);

        i++;
    }

    i = (int) A_OR;

    // allow the usage of boolean operators between bool's
    while (i <= A_AND) {
        set_data_type_rule(D_BOOL, D_BOOL, i, 1);

        i++;
    }

    // allow the usage of the unary operator "not" with bools
    set_data_type_rule(D_BOOL, D_NONE, A_NOT, 1);
}
