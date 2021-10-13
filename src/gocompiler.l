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
package		"package"
return 		"return"
else			"else"
for			"for"
if			"if"
var			"var"
int			"int"
float32		"float32"
bool			"bool"
string			"string"
print			"fmt.Println"
parse_int		"strconv.Atoi"
func			"func"
cmdargs		"os.Args"
whitespaces		\r|\n|\t|\f|" "
other			"."

letter			[a-zA-Z]
digit			[0-9]

id			({letter}|{blank_id})({letter}|{digit}+|{blank_id})*
int_lit		(0?{digit}*)|(0[xX][{digit}a-fA-F]*)


%%

{package}		{printf("PACKAGE");}
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

