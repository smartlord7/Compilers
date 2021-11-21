%{
	#include "y.tab.h"
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdarg.h>
	#include "error_handling.h"
	#include "token_type.h"

	#define show_error(err_type, curr_column) error(err_type, curr_column, yytext);

	int	start = 0,
		str_error = 0,
		last_token = 0,
		comment_line = 0,
		comment_column = 0,
		last_token_line = 0,
		last_token_column = 0,
		verbose = 0,
		buf_counter = 0;
	int flag = 0, semicolon_flag = 0, eligible_token = 0;
	char buf[BUF_SIZE], buf2[BUF_SIZE_2];

	static char * handle_token(token_type type);
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
space								(" "|"\t")+

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

str_lit								\"([^\n\r\"\\]|\\f|\\t|\\\\|\\\"|\\n)*\"
 // unterminated_str_lit				\"({new_line}|<<EOF>>)
 // invalid_scape_seq					\"\\[^\n\r\f\t\\\"]?

letter								[a-zA-Z]
id									({letter}|{blank_id})({letter}|{dec_digit}+|{blank_id})*

reserved							"break"|"case"|"chan"|"const"|"continue"|"default"|"defer"|"fallthrough"|"func"|"go"|"goto"|"import"|"interface"|"map"|"range"|"select"|"struct"|"switch"|"type"|{plus}{plus}|{minus}{minus}

%%

{semicolon} 						{handle_token(SEMICOLON_); return SEMICOLON;}
{comma}								{handle_token(COMMA_); return COMMA;}
{blank_id}							{handle_token(BLANK_ID_); return BLANKID;}
{assign}							{handle_token(ASSIGN_); return ASSIGN;}
{star}								{handle_token(STAR_); return STAR;}
{div}								{handle_token(DIV_); return DIV;}
{minus}								{handle_token(MINUS_); return MINUS;}
{plus}								{handle_token(PLUS_); return PLUS;}
{eq}								{handle_token(EQ_); return EQ;}
{ge}								{handle_token(GE_); return GE;}
{gt}								{handle_token(GT_); return GT;}
{lbrace}							{handle_token(LBRACE_); return LBRACE;}
{le}								{handle_token(LE_); return LE;}
{lpar}								{handle_token(LPAR_); return LPAR;}
{lsq}								{handle_token(LSQ_); return LSQ;}
{lt}								{handle_token(LT_); return LT;}
{mod}								{handle_token(MOD_); return MOD;}
{ne}								{handle_token(NE_); return NE;}
{not} 								{handle_token(NOT_); return NOT;}
{and}								{handle_token(AND_); return AND;}
{or}								{handle_token(OR_); return OR;}
{rbrace}							{handle_token(RBRACE_); return RBRACE;}
{rpar}								{handle_token(RPAR_); return RPAR;}
{rsq}								{handle_token(RSQ_); return RSQ;}

{package}							{handle_token(PACKAGE_); return PACKAGE;}
{return} 							{handle_token(RETURN_); return RETURN;}
{else}								{handle_token(ELSE_); return ELSE;}
{for}								{handle_token(FOR_); return FOR;}
{if}								{handle_token(IF_); return IF;}
{var}								{handle_token(VAR_); return VAR;}
{int}								{handle_token(INT_); return INT;}
{float32}							{handle_token(FLOAT32_); return FLOAT32;}
{bool}								{handle_token(BOOL_); return BOOL;}
{string}							{handle_token(STRING_); return STRING;}
{print}								{handle_token(PRINT_); return PRINT;}
{parse_int}							{handle_token(PARSE_INT_); return PARSEINT;}
{func}								{handle_token(FUNC_); return FUNC;}
{cmdargs}							{handle_token(CMDARGS_); return CMDARGS;}

{new_line}							{handle_token(NEW_LINE_); if(semicolon_flag == 1) {semicolon_flag = 0; return SEMICOLON;};}
{reserved}							{handle_token(RESERVED_); return RESERVED_;}
{id}								{yylval.id = handle_token(ID_); return ID;}
{int_lit}							{yylval.intlit = handle_token(INT_LIT_); return INTLIT;}
{invalid_octal_lit}					{show_error(INVALID_OCTAL_CONST, current_column); current_column += yyleng;}
{real_lit}							{yylval.reallit = handle_token(REAL_LIT_); return REALLIT;}
{space}								{current_column++;}

{str_lit}							{printf("yytext->%s\n", yytext);yylval.strlit = strdup(yytext); handle_token(STRING_LIT_); return STRLIT;}

\"																	{buf[0] = '\0'; buf_counter = 0; str_error = 0; BEGIN STATE_STRING; start = current_column++;}
<STATE_STRING>\"													{BEGIN 0; handle_token(STRING_LIT_);}
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

{whitespaces}														{handle_token(NOTHING_);}
{other}																{show_error(ILLEGAL_CHAR, current_column); current_column += yyleng;}
<<EOF>>                                                             {if (semicolon_flag) {semicolon_flag = 0; return SEMICOLON;} else {return 0;};}

%%

int main(int argc, char * argv[]) {
	if (argc > 1 && strcmp(argv[1], "-l") == 0) {
		verbose = 1;
	}

	if(yyparse() == 0) {
	    printf("sucesso\n");
    } else printf("insucesso\n");

	return EXIT_SUCCESS;
}

int yywrap() {

    auto_semicolon();

	return 1;
}

char * handle_token(token_type tok_type) {

	last_token_line = current_line;
	last_token_column = current_column;

	char * tok = yytext;
	current_column += yyleng;


	switch (tok_type) {
		case ID_:
		case INT_LIT_:
		case REAL_LIT_:
		case RESERVED_:
		snprintf(buf2, BUF_SIZE_2, "%s(\"%s\")\n", token_types[tok_type], tok);
            if (verbose) {
                printf("%s", buf2);
            }
		    last_token = tok_type;
		    return buf2;
			break;
		case STRING_LIT_:
			buf[buf_counter] = '\0';

			snprintf(buf2, BUF_SIZE_2, "%s(\"%s\")\n", token_types[STRING_LIT_], buf);
			if (verbose) {
				printf("%s", buf2);
			}
			buf[0] = '\0';
			buf_counter = 0;
            last_token = tok_type;
			return buf2;
			break;
		case NEW_LINE_:
		case IGNORE_NEW_LINE_:
			current_line++;
			current_column = 1;
		case LINE_COMMENT_START_:
			auto_semicolon();
			return buf2;
			break;
		case IGNORE_:
			break;
        case SEMICOLON_:
			flag = 0;
			semicolon_flag = 0;
			last_token = SEMICOLON_;
			break;
		case RETURN_:
		case RPAR_:
		case RSQ_:
		case RBRACE_:
		    // eligible_token = 1;

		    if (verbose) {
                printf("%s\n", token_types[tok_type]);
            }
			last_token = tok_type;
            return token_types[tok_type];
            break;
		case NOTHING_:
			break;
		default:
			last_token = tok_type;
			semicolon_flag = 0;
			if (verbose) {
				printf("%s\n", token_types[tok_type]);
			}
			return token_types[tok_type];
	}
	return NULL;
}

void auto_semicolon() {
    if(last_token != SEMICOLON_) {
        switch(last_token) {
            case INT_LIT_:
            case REAL_LIT_:
            case STRING_LIT_:
            case ID_:
            case RETURN_:
            case RPAR_:
            case RSQ_:
            case RBRACE_:
                snprintf(buf2, BUF_SIZE_2, "%s\n", token_types[SEMICOLON_]);

                if (verbose) {
                    printf("%s\n", token_types[SEMICOLON_]);
                }

                semicolon_flag = 1;
                flag = 1;

                last_token = SEMICOLON_;
                break;
            default:
                semicolon_flag = 0;
                break;
        }
   }
}

void yyerror (char * s) {
    printf ("Line %d, column %d: %s: %s\n", last_token_line, last_token_column, s, yytext);
}