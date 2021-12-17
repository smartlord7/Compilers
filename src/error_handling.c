#include <stdarg.h>
#include <stdio.h>
#include "strings.h"
#include "error_handling.h"

int current_line = 1, current_column = 1,
    yacc_error = 0, semantic_error_flag = 0,
    last_token_line = 0, last_token_column = 0;

const char * error_msgs[] = {
        "illegal character (%s)",
        "unterminated comment",
        "invalid octal constant (%s)",
        "unterminated string literal",
        "invalid escape sequence (%s)",
        "Symbol %s already defined",
        "Cannot find symbol %s",
        "Cannot find symbol %s(%s)",
        "Operator %s cannot be applied to type %s",
        "Operator %s cannot be applied to types %s, %s",
        "Incompatible type %s in %s statement",
        "Symbol %s declared but never used",
};

void error_inner(error_type_t err_type, int curr_column, ...) {
    va_list args;

    va_start(args, curr_column);
    char buffer[BUF_SIZE], buffer2[BUF_SIZE];
    snprintf(buffer, BUF_SIZE, ERROR_GENERIC_MSG, current_line, curr_column);
    vsnprintf(buffer2, BUF_SIZE, error_msgs[err_type], args);

    printf("%s%s\n", buffer, buffer2);

    va_end(args);
}

void error_inner2(error_type_t err_type, int curr_line, int curr_column, ...) {
    va_list args;

    va_start(args, curr_column);
    char buffer[BUF_SIZE], buffer2[BUF_SIZE];
    snprintf(buffer, BUF_SIZE, ERROR_GENERIC_MSG, curr_line, curr_column);
    vsnprintf(buffer2, BUF_SIZE, error_msgs[err_type], args);

    printf("%s%s\n", buffer, buffer2);

    va_end(args);
}

void error(error_type_t err_type, int curr_column, char * text) {
    error_inner(err_type, curr_column, text);
}

extern void semantic_error(error_type_t err_type, tree_node_t * node, data_type_t type_1, data_type_t type_2, char * call_args) {
    char * aux = trim_value(node->id);
    semantic_error_flag = 1;

    switch (err_type) {
        case SYMBOL_ALREADY_DEFINED:
            error_inner2(err_type, node->line, node->column, aux, data_types[type_1], data_types[type_2]);
            break;
        case SYMBOL_MISSING:
            error_inner2(err_type, node->line, node->column, aux);
            break;
        case SYMBOL_MISSING_FUNC:
            error_inner2(err_type, node->line, node->column, aux, call_args);
            break;
        case OPERATOR_INVALID_1:
            error_inner2(err_type, node->line, node->column, operator_types[get_operator_type(node->type)], data_types[type_1]);
            break;
        case OPERATOR_INVALID_2:
            error_inner2(err_type, node->line, node->column, operator_types[get_operator_type(node->type)], data_types[type_1], data_types[type_2]);
            break;
        case INCOMPATIBLE_TYPE:
            error_inner2(err_type, node->line, node->column, data_types[type_1], to_lower(node->id));
            break;
        case SYMBOL_NEVER_USED:
            error_inner2(err_type, node->line, node->column, aux);
            break;
        default:
            break;
    }
}
