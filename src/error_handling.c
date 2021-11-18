#include <stdarg.h>
#include <stdio.h>
#include "error_handling.h"

int current_line = 1,
        current_column = 1;

const char * error_msgs[] = {
        "illegal character (%s)",
        "unterminated comment",
        "invalid octal constant (%s)",
        "unterminated string literal",
        "invalid escape sequence (%s)"
};

void error_inner(error_type err_type, int curr_column, ...) {
    va_list args;

    va_start(args, curr_column);
    char buffer[BUF_SIZE], buffer2[BUF_SIZE];
    snprintf(buffer, BUF_SIZE, ERROR_GENERIC_MSG, current_line, curr_column);
    vsnprintf(buffer2, BUF_SIZE, error_msgs[err_type], args);

    printf("%s%s\n", buffer, buffer2);

    va_end(args);
}

void error(error_type err_type, int curr_column, char * text) {
    error_inner(err_type, curr_column, text);
}
