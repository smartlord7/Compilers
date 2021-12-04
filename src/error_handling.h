#ifndef GOCOMPILER_L_ERROR_HANDLING_H
#define GOCOMPILER_L_ERROR_HANDLING_H

#define ERROR_GENERIC_MSG "Line %d, column %d: "
#define BUF_SIZE 1024
#define BUF_SIZE_2 8192

#include "symbol_entry.h"

typedef enum {
    ILLEGAL_CHAR,
    UNTERMINATED_COMMENT,
    INVALID_OCTAL_CONST,
    UNTERMINATED_STR_LIT,
    INVALID_ESCAPE_SEQ,
    SYMBOL_ALREADY_DEFINED,
    SYMBOL_MISSING,
    OPERATOR_INVALID_1,
    OPERATOR_INVALID_2,
    INCOMPATIBLE_TYPE,
    SYMBOL_NEVER_USED,
} error_type;

extern const char * error_msgs[];
extern int current_line, current_column, last_token_line,
        last_token_column, yacc_error, semantic_error_flag;

extern void error(error_type err_type, int curr_column, char * text);
extern void semantic_error(error_type err_type, tree_node_t * token, data_type_t type_1, data_type_t type_2);

#endif //GOCOMPILER_L_ERROR_HANDLING_H
