%{
#include "util/error_handling.h"
#include "util/token_type.h"
#include <stdio.h>
#include <stdlib.h>

int yylex (void);
void yyerror(char* s);

int yydebug = 1;

%}


%token <package> PACKAGE
%token ID
%token SEMICOLON
%token VAR
%token LPAR
%token RPAR
%token COMMA
%token INT
%token FLOAT32
%token BOOL
%token STRING
%token RBRACE
%token LBRACE
%token ASSIGN
%token IF
%token ELSE
%token RETURN
%token FOR
%token PRINT
%token STRLIT
%token BLANKID
%token PARSEINT
%token CMDARGS
%token LSQ
%token RSQ
%token OR
%token AND
%token LT
%token GT
%token EQ
%token NE
%token LE
%token GE
%token PLUS
%token MINUS
%token STAR
%token DIV
%token MOD
%token NOT
%token INTLIT
%token REALLIT
%token FUNC

%union{
	char * strlit, * id, * reallit, * intlit;
}

// Operator precedence order definition -> See Go language specification
%left OR
%left AND
%left LT GT LE GE EQ NE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT

%%
    Program:
    	PACKAGE ID SEMICOLON Declarations										{printf("1\n");}
    	|
    	PACKAGE ID SEMICOLON												{;}
    ;

    Declarations:
    	VarDeclaration SEMICOLON											{printf("3\n");}
    	|
    	VarDeclaration SEMICOLON Declarations										{printf("4\n");}
    	|
    	FuncDeclaration SEMICOLON											{printf("5\n");}
    	|
    	FuncDeclaration SEMICOLON Declarations										{printf("6\n");}
    	;

    VarDeclaration:
    	VAR VarSpec                                                                       				{printf("7\n");}
    	|
    	VAR LPAR VarSpec SEMICOLON RPAR											{printf("8\n");}
    	;

    VarSpec:
    	ID VarSpec_1													{printf("9\n");}
    	;

    VarSpec_1:
    	Type														{printf("10\n");}
    	|
     	COMMA ID VarSpec_1												{printf("11\n");}
     	;

    Type:
    	INT														{printf("12\n");}
    	|
    	FLOAT32														{printf("13\n");}
    	|
    	BOOL														{printf("14\n");}
    	|
    	STRING                                                                     					{printf("15\n");}
	;

    FuncDeclaration:
    	FUNC ID LPAR RPAR FuncBody											{printf("16\n");}
    	|
    	FUNC ID LPAR Parameters RPAR FuncBody										{printf("17\n");}
    	|
    	FUNC ID LPAR RPAR Type FuncBody											{printf("18\n");}
    	|
    	FUNC ID LPAR Parameters RPAR Type FuncBody									{printf("19\n");}
    	;

    Parameters:
    	ID Type														{printf("20\n");}
    	|
    	ID Type Parameters_1                                                                 				{printf("21\n");}
	;

    Parameters_1:
    	COMMA ID Type													{printf("22\n");}
    	|
    	COMMA ID Type Parameters_1											{printf("23\n");}
    	;

    FuncBody:
    	LBRACE RBRACE													{printf("24\n");}
    	|
    	LBRACE VarsAndStatements RBRACE                      								{printf("25\n");}
    	;

    VarsAndStatements:
    	SEMICOLON													{printf("26\n");}
    	|
    	VarDeclaration SEMICOLON											{printf("27\n");}
    	|
    	Statement SEMICOLON												{printf("28\n");}
    	|
    	VarsAndStatements SEMICOLON 											{printf("29\n");}
    	|
    	VarsAndStatements VarDeclaration SEMICOLON									{printf("30\n");}
    	|
    	VarsAndStatements Statement SEMICOLON  										{printf("31\n");}
    	;

    Statement:
    	ID ASSIGN Expr                                                                               			{printf("32\n");}
    	;

    Statement:
    	LBRACE RBRACE													{printf("33\n");}
    	|
    	LBRACE Statement_1 RBRACE                                                      					{printf("34\n");}
    	;

    Statement_1:
    	Statement SEMICOLON												{printf("35\n");}
    	|
    	Statement SEMICOLON Statement_1											{printf("36\n");}
    	;

    Statement:
    	IF Expr LBRACE RBRACE 												{printf("37\n");}
    	|
     	IF Expr LBRACE Statement_rep RBRACE 										{printf("38\n");}
     	|
     	IF Expr LBRACE RBRACE ELSE LBRACE RBRACE 									{printf("39\n");}
     	|
     	IF Expr LBRACE RBRACE ELSE LBRACE Statement_rep RBRACE 								{printf("40\n");}
     	|
     	IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE RBRACE 								{printf("41\n");}
     	|
     	IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE Statement_rep RBRACE 						{printf("42\n");}
     	;

    Statement_rep:
    	Statement SEMICOLON												{printf("43\n");}
    	;

    Statement:
    	FOR LBRACE RBRACE 												{printf("44\n");}
    	|
	FOR LBRACE Statement_rep RBRACE 										{printf("45\n");}
	|
	FOR Expr LBRACE RBRACE 												{printf("46\n");}
	|
	FOR Expr LBRACE Statement_rep RBRACE 										{printf("47\n");}
	;

    Statement:
    	RETURN														{printf("48\n");}
    	|
    	RETURN Expr                                                                   					{printf("49\n");}
    	;

    Statement:
    	FuncInvocation													{printf("50\n");}
    	|
    	ParseArgs                                                                   					{printf("51\n");}
    	;

    Statement:
    	PRINT LPAR Expr RPAR 												{printf("52\n");}
    	|
    	PRINT LPAR STRLIT RPAR                                                          				{printf("53\n");}
    	;

    Statement:
    	error														{printf("54\n");}
    	;

    ParseArgs:
    	ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                              			{printf("55\n");}
    	;

    ParseArgs:
    	ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR								{printf("56\n");}
    	;

    FuncInvocation:
    	ID LPAR RPAR 													{printf("57\n");}
    	|
	ID LPAR Expr RPAR 												{printf("58\n");}
	|
	ID LPAR Expr FuncInvocation_rep RPAR										{printf("59\n");}
	;

    FuncInvocation_rep:
    	COMMA Expr													{printf("60\n");}
    	|
    	COMMA Expr FuncInvocation_rep											{printf("61\n");}
    	;

    FuncInvocation:
    	ID LPAR error RPAR												{printf("62\n");}
    	;

    Expr:
    	Expr OR Expr 													{printf("63\n");}
    	|
    	Expr AND Expr                                                							{printf("64\n");}
    	;

    Expr:
    	Expr LT 													{printf("65\n");}
    	|
    	Expr GT 													{printf("66\n");}
    	|
    	Expr LE 													{printf("67\n");}
    	|
    	Expr GE 													{printf("68\n");}
    	|
    	Expr EQ 													{printf("69\n");}
    	|
    	Expr NE														{printf("70\n");}
    	;

    Expr:
    	Expr PLUS Expr													{printf("71\n");}
    	|
    	Expr MINUS Expr													{printf("72\n");}
    	|
    	Expr STAR Expr													{printf("73\n");}
    	|
    	Expr DIV Expr													{printf("74\n");}
    	|
    	Expr MOD Expr                             									{printf("75\n");}
    	;

    Expr:
    	NOT Expr													{printf("76\n");}
    	|
    	MINUS Expr %prec NOT												{printf("77\n");}
    	|
    	PLUS Expr %prec NOT /*unary minus/plus has the same priority as the not operator */				{printf("78\n");}
    	;

    Expr:
    	INTLIT 														{printf("79\n");}
    	|
    	REALLIT 													{printf("80\n");}
    	|
    	ID 														{printf("81\n");}
    	|
    	FuncInvocation 													{printf("82\n");}
    	|
    	LPAR Expr RPAR                                           							{printf("83\n");}
    	;

    Expr:
    	LPAR error RPAR   												{printf("84\n");}
    	;
%%

