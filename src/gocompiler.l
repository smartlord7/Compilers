%{
	#include <stdlib.h>
	#include <stdio.h>
%}

%X STRING LINE_COMMENT GENERAL_COMMENT

semicolon 		";"
comma			","
blank_id		"_"
assign			"="
star			"*"
div			"/"
minus			"-"
plus			"+"
eq			"=="
ge			">="
gt			">"
lbrace			"{"
le			"<="
lpar			"("
lsq			"["
lt			"<"
mod			"%"
ne			"!="
not 			"!"
and			"&&"
or			"||"
rbrace			"}"
rpar			")"
rsq			"]"
package			"package"
return 			"return"
else			"else"
for			"for"
if			"if"
var			"var"
int			"int"
float32			"float32"
bool			"bool"
string			"string"
print			"fmt.Println"
parse_int		"strconv.Atoi"
func			"func"
cmdargs			"os.Args"
whitespaces		\r|\n|\t|\f|" "
other			.

letter			[a-zA-Z]
digit			[0-9]

id			({letter}|{blank_id})({letter}|{digit}+|{blank_id})*
int_lit		(0?{digit}*)|(0[xX][{digit}a-fA-F]*)
reserved		"case"|"chan"|"const"|"continue""|"default"|"defer"|
			"fallthrough"|"func"|"go"|"goto"|"import"|
            		"interface"|"map"|"range"|"select"|"struct"|"switch"|
            		"type"|{plus}{plus}|{minus}{minus}
real_lit		({digit}*"."({digit}+|(e|E)({minus}|{plus})?{digit}+)) | {digit}+(e|E)({minus}|{plus})?{digit}+


%%

{semicolon} 		{printf("SEMICOLON\n");}
{colon}			{printf("COMMA\n");}
{blank_id}		{printf("BLANKID\n");}
{assign}		{printf("ASSIGN\n");}
{star}			{printf("STAR\n");}
{div}			{printf("DIV\n");}
{minus}			{printf("MINUS\n");}
{plus}			{printf("PLUS\n");}
{eq}			{printf("EQ\n");}
{ge}			{printf("GE\n");}
{gt}			{printf("GT\n");}
{lbrace}		{printf("LBRACE\n");}
{le}			{printf("LE\n");}
{lpar}			{printf("LPAR\n");}
{lsq}			{printf("LSQ\n");}
{lt}			{printf("LT\n");}
{mod}			{printf("MOD\n");}
{ne}			{printf("NE\n");}
{not} 			{printf("NOT\n");}
{and}			{printf("AND\n");}
{or}			{printf("OR\n");}
{rbrace}		{printf("RBRACE\n");}
{rpar}			{printf("RPAR\n");}
{rsq}			{printf("RSQ\n");}

{package}		{printf("PACKAGE\n");}
{return} 		{printf("RETURN\n");}
{else}			{printf("ELSE\n");}
{for}			{printf("FOR\n");}
{if}			{printf("IF\n");}
{var}			{printf("VAR\n");}
{int}			{printf("INT\n");}
{float32}		{printf("FLOAT32\n");}
{bool}			{printf("BOOL\n");}
{string}		{printf("STRING\n");}
{print}		{printf("PRINT\n");}
{parse_int}		{printf("PARSEINT\n");}
{func}			{printf("FUNC\n");}
{cmdargs}		{printf("CMDARGS\n");}

{id}			{printf("ID(%s)\n", yytext);}
{int_lit}		{printf("INTLIT(%s)\n", yytext);}
{whitespaces}		{;}

\"			{begin STRING;}
<STRING>\"		{begin 0;}
<STRING>\f|\t|\\	{;}
<STRING>\n|\r|\.|\".\"	{;}		//TODO: Call error function

{other}		{;}


%%

int main(int argc, char * argv[]) {
	
	yylex();
	
	return EXIT_SUCCESS;
}

int yywrap() {

	return 1;
}

