#include "data_types.h"
#include "abstract_syntax_tree.h"

static int rules[NUMBER_OF_TYPES][NUMBER_OF_TYPES][NUMBER_OF_OPERATORS][2];
static int offset = DEFAULT_OFFSET;

char * data_types[] = {
        "int",
        "bool",
        "float32",
        "string",
        "",
        "undef",
        "param",
};

char * operator_types[] = {
        "=",
        "||",
        "&&",
        "!",
        "<",
        ">",
        "<=",
        ">=",
        "==",
        "!=",
        "+",
        "-",
        "*",
        "/",
        "",
};

void set_data_type_rules_offset(int offset) {
    offset = offset;
}

void set_data_type_rule(data_type_t type1, data_type_t type2, ast_node_type_t operator, int on, data_type_t result_data_type) {
    int op = ((int) operator) - offset;

    if (on) {
        rules[type2][type1][op][0] = 1;
        rules[type2][type1][op][1] = (int) result_data_type;
        rules[type1][type2][op][0] = 1;
        rules[type1][type2][op][1] = (int) result_data_type;
    } else {
        rules[type2][type1][op][0] = 0;
        rules[type2][type1][op][1] = (int) result_data_type;
        rules[type1][type2][op][0] = 0;
        rules[type1][type2][op][1] = (int) result_data_type;
    }
}

data_type_t check_op_data_types(data_type_t type1, data_type_t type2, ast_node_type_t operator) {
    int * value = rules[type1][type2][operator];

    if (value[0]) {
        return value[1];
    }

    return DATATYPE_UNDEF;
}

void init_data_types_rules() {
    int i = (int) A_ADD;

    // allow binary arithmetic operations ("sub", "add", "mult", "div" and "mod") between float32's, int's, and float32 and int (same as int and float32)
    while (i <= (int) A_MOD) {
        set_data_type_rule(DATATYPE_FLOAT32, DATATYPE_FLOAT32, i, 1, DATATYPE_FLOAT32);
        set_data_type_rule(DATATYPE_INT, DATATYPE_INT, i, 1, DATATYPE_INT);
        set_data_type_rule(DATATYPE_FLOAT32, DATATYPE_INT, i, 1, DATATYPE_FLOAT32);

        i++;
    }

    // allow the equality comparison between bool's
    set_data_type_rule(DATATYPE_BOOL, DATATYPE_BOOL, A_EQ, 1, DATATYPE_BOOL);
    set_data_type_rule(DATATYPE_BOOL, DATATYPE_BOOL, A_NE, 1, DATATYPE_BOOL);

    i = (int) A_LT;

    // allow equality/comparisons between float32's, int's, float32 and int (sames as int and float32) and strings
    while (i <= (int) A_NE) {
        set_data_type_rule(DATATYPE_FLOAT32, DATATYPE_FLOAT32, i, 1, DATATYPE_BOOL);
        set_data_type_rule(DATATYPE_INT, DATATYPE_INT, i, 1, DATATYPE_BOOL);
        set_data_type_rule(DATATYPE_FLOAT32, DATATYPE_INT, i, 1, DATATYPE_BOOL);
        set_data_type_rule(DATATYPE_STRING, DATATYPE_STRING, i, 1, DATATYPE_BOOL);

        i++;
    }

    // allow the concatenations of strings
    set_data_type_rule(DATATYPE_STRING, DATATYPE_STRING, A_ADD, 1, DATATYPE_STRING);

    i = (int) A_PLUS;

    // allow the usage of the unary arithmetic operators ("plus" and "minus") with float32's and int's
    while (i <= A_MINUS) {
        set_data_type_rule(DATATYPE_INT, DATATYPE_NONE, i, 1, DATATYPE_INT);
        set_data_type_rule(DATATYPE_FLOAT32, DATATYPE_NONE, i, 1, DATATYPE_FLOAT32);

        i++;
    }

    i = (int) A_OR;

    // allow the usage of boolean operators between bool's
    while (i <= A_AND) {
        set_data_type_rule(DATATYPE_BOOL, DATATYPE_BOOL, i, 1, DATATYPE_BOOL);

        i++;
    }

    // allow the usage of the unary operator "not" with bools
    set_data_type_rule(DATATYPE_BOOL, DATATYPE_NONE, A_NOT, 1, DATATYPE_BOOL);
}

operator_t get_operator_type(ast_node_type_t node_type) {
    switch (node_type) {
        case A_ASSIGN:
            return O_ASSIGN;
        case A_OR:
            return O_OR;
        case A_AND:
            return O_AND;
        case A_NOT:
            return O_NOT;
        case A_LE:
            return O_LE;
        case A_GE:
            return O_GE;
        case A_LT:
            return O_LT;
        case A_GT:
            return O_GT;
        case A_EQ:
            return O_EQ;
        case A_NE:
            return O_NE;
        case A_ADD:
            return O_ADD;
        case A_SUB:
            return O_SUB;
        case A_MUL:
            return O_MUL;
        case A_DIV:
            return O_DIV;
        default:
            return O_NONE;
    }
}

data_type_t check_bool(ast_node_type_t type) {
    switch (type) {
        case A_BOOL:
        case A_ASSIGN:
        case A_OR:
        case A_AND:
        case A_NOT:
        case A_LT:
        case A_GT:
        case A_LE:
        case A_GE:
        case A_EQ:
        case A_NE:
            return DATATYPE_BOOL;
        default:
            return DATATYPE_UNDEF;


    }
}
