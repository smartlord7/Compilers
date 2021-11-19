#ifndef GOCOMPILER_L_ERROR_HANDLING_H
#define GOCOMPILER_L_ERROR_HANDLING_H

#define ERROR_GENERIC_MSG "Line %d, column %d: "
#define BUF_SIZE 1024
#define BUF_SIZE_2 2048

typedef enum {
    ILLEGAL_CHAR,
    UNTERMINATED_COMMENT,
    INVALID_OCTAL_CONST,
    UNTERMINATED_STR_LIT,
    INVALID_ESCAPE_SEQ
} error_type;

extern const char * error_msgs[];
extern int current_line, current_column;

extern void error(error_type err_type, int curr_column, char * text);

#endif //GOCOMPILER_L_ERROR_HANDLING_H
