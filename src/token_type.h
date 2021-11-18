#ifndef GOCOMPILER_L_TOKEN_TYPE_H
#define GOCOMPILER_L_TOKEN_TYPE_H

typedef enum {
    NEW_LINE,
    SEMICOLON,
    COMMA,
    BLANK_ID,
    ASSIGN,
    STAR,
    DIV,
    MINUS,
    PLUS,
    EQ,
    GE,
    GT,
    LBRACE,
    LE,
    LPAR,
    LSQ,
    LT,
    MOD,
    NE,
    NOT,
    AND,
    OR,
    RBRACE,
    RPAR,
    RSQ,
    PACKAGE,
    RETURN,
    ELSE,
    FOR,
    IF,
    VAR,
    INT,
    FLOAT32,
    BOOL,
    STRING,
    PRINT,
    PARSE_INT,
    FUNC,
    CMDARGS,
    RESERVED,
    ID,
    INT_LIT,
    REAL_LIT,
    STRING_LIT,
    OTHER,
    STRING_START,
    STRING_END,
    LINE_COMMENT_START,
    GENERAL_COMMENT_START,
    GENERAL_COMMENT_END,
    IGNORE,
    IGNORE_NEW_LINE,
} token_type;

extern const char * token_types[];

#endif //GOCOMPILER_L_TOKEN_TYPE_H
