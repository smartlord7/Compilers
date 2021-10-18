%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdarg.h>
	
	#define ERROR_GENERIC_MSG "Line %d, column %d "
	
	static int current_column = 1;
	
	typedef enum {
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
		OTHER
	} token_type;
		
	typedef enum {
		ILLEGAL_CHAR,
		INVALID_OCTAL_CONST,
		UNTERMINATED_COMMENT,
		UNTERMINATED_STR_LIT,
		INVALID_ESCAPE_SEQ
	} error_type;
	
	const char * token_types[] = {
		"SEMICOLON",	
		"COMMA",
		"BLANKID",
		"ASSIGN",
		"STAR",
		"DIV",
		"MINUS",
		"PLUS",
		"EQ",
		"GE",
		"GT",
		"LBRACE",
		"LE",
		"LPAR",
		"LSQ",
		"LT",
		"MOD",
		"NE",
		"NOT",
		"AND",
		"OR",
		"RBRACE",
		"RPAR",
		"RSQ",
		"PACKAGE",
		"RETURN",
		"ELSE",
		"FOR",
		"IF",
		"VAR",
		"INT",
		"FLOAT32",
		"BOOL",
		"STRING",
		"PRINT",
		"PARSEINT",
		"FUNC",
		"CMDARGS",
		"RESERVED",
		"ID",
		"INTLIT",
		"OTHER"
	};
	
	const char * error_types[] = {
		"illegal character (%c)",
		"invalid octal constant",
		"untermianted constant",
		"unterminated string literal",
		"invalid escape sequence"
	};
	
	static void handle_token(token_type type);

%}

%X STRING LINE_COMMENT GENERAL_COMMENT

semicolon 							";"
comma								","
blank_id							"_"
assign								"="
star								"*"
div									"/"
minus								"-"
plus								"+"
eq									"=="
ge									">="
gt									">"
lbrace								"{"
le									"<="
lpar								"("
lsq									"["
lt									"<"
mod									"%"
ne									"!="
not 								"!"
and									"&&"
or									"||"
rbrace								"}"
rpar								")"
rsq									"]"
package								"package"
return 								"return"
else								"else"
for									"for"
if									"if"
var									"var"
int									"int"
float32								"float32"
bool								"bool"
string								"string"
print								"fmt.Println"
parse_int							"strconv.Atoi"
func								"func"
cmdargs								"os.Args"
whitespaces							\r|\n|\t|\f|" "
new_line							\r|\r?\n
other								.

letter								[a-zA-Z]
digit								[0-9]

id									({letter}|{blank_id})({letter}|{digit}+|{blank_id})*
int_lit								(0?{digit}*)|(0[xX][{digit}a-fA-F]*)
real_lit							({digit}*"."({digit}+|(e|E)({minus}|{plus})?{digit}+))|{digit}+(e|E)({minus}|{plus})?{digit}+
reserved							"case"|"chan"|"const"|"continue"|"default"|"defer"|"fallthrough"|"func"|"go"|"goto"|"import"|"interface"|"map"|"range"|"select"|"struct"|"switch"type"|{plus}{plus}|{minus}{minus}


%%

{semicolon} 						{handle_token(SEMICOLON);}
{comma}								{handle_token(COMMA);}
{blank_id}							{handle_token(BLANK_ID);}
{assign}							{handle_token(ASSIGN);}
{star}								{handle_token(STAR);}
{div}								{handle_token(DIV);}
{minus}								{handle_token(MINUS);}
{plus}								{handle_token(PLUS);}
{eq}								{handle_token(EQ);}
{ge}								{handle_token(GE);}
{gt}								{handle_token(GT);}
{lbrace}							{handle_token(LBRACE);}
{le}								{handle_token(LE);}
{lpar}								{handle_token(LPAR);}
{lsq}								{handle_token(LSQ);}
{lt}								{handle_token(LT);}
{mod}								{handle_token(MOD);}
{ne}								{handle_token(NE);}
{not} 								{handle_token(NOT);}
{and}								{handle_token(AND);}
{or}								{handle_token(OR);}
{rbrace}							{handle_token(RBRACE);}
{rpar}								{handle_token(RPAR);}
{rsq}								{handle_token(RSQ);}

{package}							{handle_token(PACKAGE);}
{return} 							{handle_token(RETURN);}
{else}								{handle_token(ELSE);}
{for}								{handle_token(FOR);}
{if}								{handle_token(IF);}
{var}								{handle_token(VAR);}
{int}								{handle_token(INT);}
{float32}							{handle_token(FLOAT32);}
{bool}								{handle_token(BOOL);}
{string}							{handle_token(STRING);}
{print}								{handle_token(PRINT);}
{parse_int}							{handle_token(PARSE_INT);}
{func}								{handle_token(FUNC);}
{cmdargs}							{handle_token(CMDARGS);}

{id}								{handle_token(ID);}
{int_lit}							{handle_token(INT_LIT);}
{real_lit}							{printf("REALLIT(%s)\n", yytext);}
{whitespaces}						{;}

\"									{BEGIN STRING;}
<STRING>\"							{BEGIN 0;}
<STRING>\f|\t|\\					{;}
<STRING>\n|\\n|\\r|\r|\".\"|\.|\\.	{printf("erro");}		//TODO: Call error function

{other}		{;}


%%

int main(int argc, char * argv[]) {
	yylex();
	
	return EXIT_SUCCESS;
}

int yywrap() {

	return 1;
}

void handle_token(token_type tok_type) {
	char * tok = yytext;
	current_column += strlen(tok);
	
	switch (tok_type) {
		case ID:
		case INT_LIT:
			printf("%s(%s)\n", token_types[tok_type], tok);
			break;
		case OTHER:
			
		default:
			printf("%s\n", token_types[tok_type]);	
	}
}

void show_lex_error_wrap(error_type err_type, ...) {
	va_list args;
   
   	va_start(args, err_type);
	vprintf(strcat(strcat(ERROR_GENERIC_MSG, error_types[err_type]), "\n"), args);
	
   	va_end(args);
}

void show_lex_error(error_type err_type) {
	show_lex_error_wrap(err_type, yylineno, current_column, yytext[0]);
}

