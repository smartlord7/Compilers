%{
	#include <stdlib.h>
	#include <stdio.h>
%}

semicolon 		";"
colon			","
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
other			"."

letter			[a-zA-Z]
digit			[0-9]

id			({letter}|{blank_id})({letter}|{digit}+|{blank_id})*
int_lit		(0?{digit}*)|(0[xX][{digit}a-fA-F]*)


%%

{semicolon} 		{printf("SEMICOLON");}
{colon}			{printf("COLON");}
{blank_id}		{printf("BLANKID");}
{assign}		{printf("ASSIGN");}
{star}			{printf("STAR");}
{div}			{printf("DIV");}
{minus}			{printf("MINUS");}
{plus}			{printf("PLUS");}
{eq}			{printf("EQ");}
{ge}			{printf("GE");}
{gt}			{printf("GT");}
{lbrace}		{printf("LBRACE");}
{le}			{printf("LE");}
{lpar}			{printf("LPAR");}
{lsq}			{printf("LSQ");}
{lt}			{printf("LT");}
{mod}			{printf("MOD");}
{ne}			{printf("NE");}
{not} 			{printf("NOT");}
{and}			{printf("AND");}
{or}			{printf("OR");}
{rbrace}		{printf("RBRACE");}
{rpar}			{printf("RPAR");}
{rsq}			{printf("RSQ");}

{package}		{printf("PACKAGE");}
{return} 		{printf("RETURN");}
{else}			{printf("ELSE");}
{for}			{printf("FOR");}
{if}			{printf("IF");}
{var}			{printf("VAR");}
{int}			{printf("INT");}
{float32}		{printf("FLOAT32");}
{bool}			{printf("BOOL");}
{string}		{printf("STRING");}
{print}			{printf("PRINT");}
{parse_int}		{printf("PARSEINT");}
{func}			{printf("FUNC");}
{cmdargs}		{printf("CMDARGS");}

{id}			{printf("ID(%s)\n", yytext);}
{whitespaces}		{;}
{other}		{;}


%%

int main(int argc, char * argv[]) {
	
	yylex();
	
	return EXIT_SUCCESS;
}

int yywrap() {

	return 1;
}

