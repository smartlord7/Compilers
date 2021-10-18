%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdarg.h>
	
	#define ERROR_GENERIC_MSG "Line %d, column %d: "
	#define BUF_SIZE 256
	
	static int current_line = 1, current_column = 1, last_token;
	
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
		IGNORE_NEW_LINE
	} token_type;
		
	typedef enum {
		ILLEGAL_CHAR,
		UNTERMINATED_COMMENT,
		INVALID_OCTAL_CONST,
		UNTERMINATED_STR_LIT,
		INVALID_ESCAPE_SEQ
	} error_type;
	
	const char * token_types[] = {
		"NEW_LINE",
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
		"REALLIT",
		"STRINGLIT"
		"OTHER"
		"STRING_START",
		"STRING_END",
		"LINE_COMMENT_START",
		"GENERAL_COMMENT_START",
		"GENERAL_COMMENT_END",
		"IGNORE",
		"IGNORE_NEW_LINE"
	};
	
	const char * error_msgs[] = {
		"illegal character (%c)",
		"unterminated comment",
		"invalid octal constant (%c)",
		"unterminated string literal",
		"invalid escape sequence (%c)"
	};
	
	static void handle_token(token_type type);
	static void lex_error(error_type err_type);

%}

%X STATE_STRING STATE_LINE_COMMENT STATE_GENERAL_COMMENT

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
reserved							"break"|"case"|"chan"|"const"|"continue"|"default"|"defer"|"fallthrough"|"func"|"go"|"goto"|"import"|"interface"|"map"|"range"|"select"|"struct"|"switch"|"type"|{plus}{plus}|{minus}{minus}

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

{new_line}							{handle_token(NEW_LINE);}
{reserved}							{handle_token(RESERVED);}
{id}								{handle_token(ID);}
{int_lit}							{handle_token(INT_LIT);}
{real_lit}							{handle_token(REAL_LIT);}
{whitespaces}						{;}

\"									{BEGIN STATE_STRING;}
<STATE_STRING>\"							{BEGIN 0;}
<STATE_STRING>\f|\t|\\					{;}
<STATE_STRING>\n|\\n|\\r|\r|\".\"|\.|\\.	{lex_error(UNTERMINATED_STR_LIT);}

"//"									{BEGIN STATE_LINE_COMMENT;}
<STATE_LINE_COMMENT>{new_line}			{handle_token(IGNORE_NEW_LINE); BEGIN 0;}						
<STATE_LINE_COMMENT>.					{handle_token(IGNORE);}

"/*"									{BEGIN STATE_GENERAL_COMMENT;}
<STATE_GENERAL_COMMENT>"*/"					{BEGIN 0;}
<STATE_GENERAL_COMMENT>{new_line}			{handle_token(IGNORE_NEW_LINE);}
<STATE_GENERAL_COMMENT><<EOF>>				{lex_error(UNTERMINATED_COMMENT); exit(EXIT_FAILURE);}
<STATE_GENERAL_COMMENT>.					{handle_token(IGNORE);}

{other}								{lex_error(ILLEGAL_CHAR);}


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
		case REAL_LIT:
		case RESERVED:
		case STRING_LIT:
			printf("%s(%s)\n", token_types[tok_type], tok);
			break;
		case NEW_LINE:
		case IGNORE_NEW_LINE:
			current_line++;
			current_column = 1;

			switch(last_token) {
				case INT_LIT:
				case REAL_LIT:
				case STRING_LIT:
				case ID:
				case RETURN:
				case RPAR:
				case RSQ:
				case RBRACE:
					handle_token(SEMICOLON);
					break;
				default:
					break;
			}

			break;
		case IGNORE:
			break;
		default:
			printf("%s\n", token_types[tok_type]);	
	}
	last_token = tok_type;
}

void lex_error_inner(error_type err_type, ...) {
	current_column += strlen(yytext);

	va_list args;
   
   	va_start(args, err_type);
	char buffer[BUF_SIZE], buffer2[BUF_SIZE];
	snprintf(buffer, BUF_SIZE, ERROR_GENERIC_MSG, current_line, current_column);
	vsnprintf(buffer2, BUF_SIZE, error_msgs[err_type], args);
	
	printf("%s%s\n", buffer, buffer2);
	
   	va_end(args);
}

void lex_error(error_type err_type) {
	lex_error_inner(err_type, yytext[0]);
}