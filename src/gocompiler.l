%{
	#include "y.tab.h"
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdarg.h>
	#include "util/error_handling.h"
	#include "util/token_type.h"

	#define show_error(err_type, curr_column) error(err_type, curr_column, yytext);

	int	start = 0,
		str_error = 0,
		last_token = 0,
		comment_line = 0,
		comment_column = 0,
		verbose = 0,
		buf_counter = 0;
	char buf[BUF_SIZE];
	
	static void handle_token(token_type type);
	static void auto_semicolon();

%}

%X STATE_STRING STATE_LINE_COMMENT STATE_GENERAL_COMMENT OCTAL

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
whitespaces							\r|\n|\t|\f
new_line							\r|\r?\n
space								" "|"\t"
other								.

dec_digit							[0-9]
hex_digit 							[0-9a-fA-F]
octal_digit							[0-7]
dec_lit								"0"|([1-9]{dec_digit}*)
hex_lit								"0"[xX]{hex_digit}+
octal_lit							"0"{octal_digit}+
invalid_octal_lit					"0"{dec_digit}+
int_lit								{dec_lit}|{hex_lit}|{octal_lit}

exponent							(e|E)({minus}|{plus})?{dec_digit}+
real_lit1							{dec_digit}+"."{dec_digit}*{exponent}?
real_lit2							"."{dec_digit}+({exponent})?
real_lit3							{dec_digit}+{exponent}
real_lit							{real_lit1}|{real_lit2}|{real_lit3}	
						
letter								[a-zA-Z]
id									({letter}|{blank_id})({letter}|{dec_digit}+|{blank_id})*


reserved							"break"|"case"|"chan"|"const"|"continue"|"default"|"defer"|"fallthrough"|"func"|"go"|"goto"|"import"|"interface"|"map"|"range"|"select"|"struct"|"switch"|"type"|{plus}{plus}|{minus}{minus}

%%

{semicolon} 						{handle_token(SEMICOLON_);}
{comma}								{handle_token(COMMA_);}
{blank_id}							{handle_token(BLANK_ID_);}
{assign}							{handle_token(ASSIGN_);}
{star}								{handle_token(STAR_);}
{div}								{handle_token(DIV_);}
{minus}								{handle_token(MINUS_);}
{plus}								{handle_token(PLUS_);}
{eq}								{handle_token(EQ_);}
{ge}								{handle_token(GE_);}
{gt}								{handle_token(GT_);}
{lbrace}							{handle_token(LBRACE_);}
{le}								{handle_token(LE_);}
{lpar}								{handle_token(LPAR_);}
{lsq}								{handle_token(LSQ_);}
{lt}								{handle_token(LT_);}
{mod}								{handle_token(MOD_);}
{ne}								{handle_token(NE_);}
{not} 								{handle_token(NOT_);}
{and}								{handle_token(AND_);}
{or}								{handle_token(OR_);}
{rbrace}							{handle_token(RBRACE_);}
{rpar}								{handle_token(RPAR_);}
{rsq}								{handle_token(RSQ_);}

{package}							{handle_token(PACKAGE_);}
{return} 							{handle_token(RETURN_);}
{else}								{handle_token(ELSE_);}
{for}								{handle_token(FOR_);}
{if}								{handle_token(IF_);}
{var}								{handle_token(VAR_);}
{int}								{handle_token(INT_);}
{float32}							{handle_token(FLOAT32_);}
{bool}								{handle_token(BOOL_);}
{string}							{handle_token(STRING_);}
{print}								{handle_token(PRINT_);}
{parse_int}							{handle_token(PARSE_INT_);}
{func}								{handle_token(FUNC_);}
{cmdargs}							{handle_token(CMDARGS_);}

{new_line}							{handle_token(NEW_LINE_);}
{reserved}							{handle_token(RESERVED_);}
{id}								{handle_token(ID_);}
{int_lit}							{handle_token(INT_LIT_);}
{invalid_octal_lit}					{show_error(INVALID_OCTAL_CONST, current_column); current_column += yyleng;}
{real_lit}							{handle_token(REAL_LIT_);}
{space}								{current_column++;}

\"																	{buf[0] = '\0'; buf_counter = 0; str_error = 0; BEGIN STATE_STRING; start = current_column++;}
<STATE_STRING>\"													{BEGIN 0; if (!str_error) handle_token(STRING_LIT_);}
<STATE_STRING>{new_line}											{BEGIN 0; show_error(UNTERMINATED_STR_LIT, start); current_line++; current_column = 1;}
<STATE_STRING><<EOF>>												{BEGIN 0; show_error(UNTERMINATED_STR_LIT, start); current_line++; current_column = 1;}
<STATE_STRING>"\\\\"|"\\\""|"\\t"|"\\n"|"\\r"|"\\f"					{buf[buf_counter++] = yytext[0]; buf[buf_counter++] = yytext[1]; current_column += 2;}
<STATE_STRING>\\[^\n\r]?											{show_error(INVALID_ESCAPE_SEQ, current_column); current_column += yyleng;  str_error = 1;}
<STATE_STRING>.														{buf[buf_counter++] = yytext[0]; current_column++;}

"//"																{BEGIN STATE_LINE_COMMENT; handle_token(LINE_COMMENT_START_);}
<STATE_LINE_COMMENT>{new_line}										{handle_token(IGNORE_NEW_LINE_); BEGIN 0;}						
<STATE_LINE_COMMENT>.												{handle_token(IGNORE_);}

"/*"																{BEGIN STATE_GENERAL_COMMENT; comment_line = current_line; comment_column = current_column; current_column += 2;}
<STATE_GENERAL_COMMENT>"*/"											{BEGIN 0; current_column += 2;}
<STATE_GENERAL_COMMENT>{new_line}									{handle_token(IGNORE_NEW_LINE_);}
<STATE_GENERAL_COMMENT><<EOF>>										{current_line = comment_line; show_error(UNTERMINATED_COMMENT, comment_column); return 0;}
<STATE_GENERAL_COMMENT>.											{handle_token(IGNORE_);}

{whitespaces}														{;}
{other}																{show_error(ILLEGAL_CHAR, current_column); current_column += yyleng;}


%%

int main(int argc, char * argv[]) {
	if (argc > 1 && strcmp(argv[1], "-l") == 0) {
		verbose = 1;
	}

	while(yyparse() == 0) {
	    printf("sucesso\n");
    }
	printf("insucesso\n");

	return EXIT_SUCCESS;
}

int yywrap() {
	auto_semicolon();

	return 1;
}

void handle_token(token_type tok_type) {
	char * tok = yytext;
	current_column += yyleng;
	
	switch (tok_type) {
		case ID_:
		case INT_LIT_:
		case REAL_LIT_:
		case RESERVED_:
		if (verbose) {
			printf("%s(%s)\n", token_types[tok_type], tok);
		}
			break;
		case STRING_LIT_:
			buf[buf_counter] = '\0';
			if (verbose) {
				printf("%s(\"%s\")\n", token_types[STRING_LIT_], buf);
			}
			buf[0] = '\0'; 
			buf_counter = 0;
			break;
		case NEW_LINE_:
		case IGNORE_NEW_LINE_:
			current_line++;
			current_column = 1;
		case LINE_COMMENT_START_:
			auto_semicolon();
			break;
		case IGNORE_:
			break;
		default:
			if (verbose) {
				printf("%s\n", token_types[tok_type]);	
			}
	}

	last_token = tok_type;
}

void auto_semicolon() {
	if (verbose) {
		switch(last_token) {
			case INT_LIT_:
			case REAL_LIT_:
			case STRING_LIT_:
			case ID_:
			case RETURN_:
			case RPAR_:
			case RSQ_:
			case RBRACE_:
				printf("%s\n", token_types[SEMICOLON_]);
				break;
			default:
				break;
		}
	}
}

void yyerror (char * s) {
    printf ("Line %d, column %d: %s: %s\n", current_line, current_column, s, yytext);
}