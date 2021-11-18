%{
#include "util/error_handling.h"
#include "util/token_type.h"
#include <stdio.h>
#include <stdlib.h>

int yylex (void);
void yyerror(char* s);

int yydebug = 1;

%}


%token PACKAGE
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

// Operator precedence order definition -> See Go language specification
%left OR
%left AND
%left LT GT LE GE EQ NE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT

%%
    Program:
    	PACKAGE ID SEMICOLON Declarations										{$$=$1; $$=$2; $$=$3; printf("1\n");}
    ;

    Declarations:
    	VarDeclaration SEMICOLON Declarations										{$$=$1; printf("1\n");}
    	|
    	FuncDeclaration SEMICOLON Declarations										{$$=$1; printf("1\n");}
    	|
    	/*epsilon*/													{printf("1\n");}
    	;

    VarDeclaration:
    	VAR VarDeclaration_1                                                                       			{$$=$1; printf("1\n");}
    	;

    VarDeclaration_1:
    	VarSpec														{$$=$1; printf("1\n");}
    	|
    	LPAR VarSpec SEMICOLON RPAR											{$$=$1; printf("1\n");}
    	;

    VarSpec:
    	ID VarSpec_1                                                                         				{$$=$1; printf("1\n");}
    	;

    VarSpec_1:
    	Type														{$$=$1; printf("1\n");}
    	|
     	COMMA ID VarSpec_1												{$$=$1; printf("1\n");}
     	;

    Type:
    	INT														{$$=$1; printf("1\n");}
    	|
    	FLOAT32														{$$=$1; printf("1\n");}
    	|
    	BOOL														{$$=$1; printf("1\n");}
    	|
    	STRING                                                                     					{$$=$1; printf("1\n");}
	;

    FuncDeclaration:
    	FUNC ID LPAR FuncDeclaration_1											{$$=$1; printf("1\n");}
	;

    FuncDeclaration_1:
  	RPAR FuncDeclaration_2												{$$=$1; printf("1\n");}
  	|
  	Parameters RPAR FuncDeclaration_2										{$$=$1; printf("1\n");}
	;

    FuncDeclaration_2:
    	FuncBody													{$$=$1; printf("1\n");}
    	|
    	Type FuncBody													{$$=$1; printf("1\n");}
	;

    Parameters:
    	ID Type														{$$=$1; printf("1\n");}
    	|
    	ID Type Parameters_1                                                                 				{$$=$1; printf("1\n");}
	;

    Parameters_1:
    	COMMA ID Type													{$$=$1; printf("1\n");}
    	|
    	COMMA ID Type Parameters_1											{$$=$1; printf("1\n");}
    	;

    FuncBody:
    	LBRACE RBRACE													{$$=$1; printf("1\n");}
    	|
    	LBRACE VarsAndStatements RBRACE                      								{$$=$1; printf("1\n");}
    	;

    VarsAndStatements:
    	SEMICOLON													{$$=$1; printf("1\n");}
    	|
    	VarDeclaration SEMICOLON											{$$=$1; printf("1\n");}
    	|
    	Statement SEMICOLON												{$$=$1; printf("1\n");}
    	|
    	SEMICOLON VarsAndStatements											{$$=$1; printf("1\n");}
    	|
    	VarDeclaration SEMICOLON VarsAndStatements									{$$=$1; printf("1\n");}
    	|
    	Statement SEMICOLON VarsAndStatements 										{$$=$1; printf("1\n");}
    	;

    Statement:
    	ID ASSIGN Expr                                                                               			{$$=$1; printf("1\n");}
    	;

    Statement:
    	LBRACE RBRACE													{$$=$1; printf("1\n");}
    	|
    	LBRACE Statement_1 RBRACE                                                      					{$$=$1; printf("1\n");}
    	;

    Statement_1:
    	Statement SEMICOLON												{$$=$1; printf("1\n");}
    	|
    	Statement SEMICOLON Statement_1											{$$=$1; printf("1\n");}
    	;

    Statement:
    	IF Expr LBRACE RBRACE 												{$$=$1; printf("1\n");}
    	|
     	IF Expr LBRACE Statement_rep RBRACE 										{$$=$1; printf("1\n");}
     	|
     	IF Expr LBRACE RBRACE ELSE LBRACE RBRACE 									{$$=$1; printf("1\n");}
     	|
     	IF Expr LBRACE RBRACE ELSE LBRACE Statement_rep RBRACE 								{$$=$1; printf("1\n");}
     	|
     	IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE RBRACE 								{$$=$1; printf("1\n");}
     	|
     	IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE Statement_rep RBRACE 						{$$=$1; printf("1\n");}
     	;

    Statement_rep:
    	Statement SEMICOLON												{$$=$1; printf("1\n");}
    	;

    Statement:
    	FOR LBRACE RBRACE 												{$$=$1; printf("1\n");}
    	|
	FOR LBRACE Statement_rep RBRACE 										{$$=$1; printf("1\n");}
	|
	FOR Expr LBRACE RBRACE 												{$$=$1; printf("1\n");}
	|
	FOR Expr LBRACE Statement_rep RBRACE 										{$$=$1; printf("1\n");}
	;

    Statement:
    	RETURN														{$$=$1; printf("1\n");}
    	|
    	RETURN Expr                                                                   					{$$=$1; printf("1\n");}
    	;

    Statement:
    	FuncInvocation													{$$=$1; printf("1\n");}
    	|
    	ParseArgs                                                                   					{$$=$1; printf("1\n");}
    	;

    Statement:
    	PRINT LPAR Expr RPAR 												{$$=$1; printf("1\n");}
    	|
    	PRINT LPAR STRLIT RPAR                                                          				{$$=$1; printf("1\n");}
    	;

    Statement:
    	error														{$$=$1; printf("1\n");}
    	;

    ParseArgs:
    	ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                              			{$$=$1; printf("1\n");}
    	;

    ParseArgs:
    	ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR								{$$=$1; printf("1\n");}
    	;

    FuncInvocation:
    	ID LPAR RPAR 													{$$=$1; printf("1\n");}
    	|
	ID LPAR Expr RPAR 												{$$=$1; printf("1\n");}
	|
	ID LPAR Expr FuncInvocation_rep RPAR										{$$=$1; printf("1\n");}
	;

    FuncInvocation_rep:
    	COMMA Expr													{$$=$1; printf("1\n");}
    	|
    	COMMA Expr FuncInvocation_rep											{$$=$1; printf("1\n");}
    	;

    FuncInvocation:
    	ID LPAR error RPAR												{$$=$1; printf("1\n");}
    	;

    Expr:
    	Expr OR Expr 													{$$=$1; printf("1\n");}
    	|
    	Expr AND Expr                                                							{$$=$1; printf("1\n");}
    	;

    Expr:
    	Expr LT 													{$$=$1; printf("1\n");}
    	|
    	Expr GT 													{$$=$1; printf("1\n");}
    	|
    	Expr LE 													{$$=$1; printf("1\n");}
    	|
    	Expr GE 													{$$=$1; printf("1\n");}
    	|
    	Expr EQ 													{$$=$1; printf("1\n");}
    	|
    	Expr NE														{$$=$1; printf("1\n");}
    	;

    Expr:
    	Expr PLUS Expr													{$$=$1; printf("1\n");}
    	|
    	Expr MINUS Expr													{$$=$1; printf("1\n");}
    	|
    	Expr STAR Expr													{$$=$1; printf("1\n");}
    	|
    	Expr DIV Expr													{$$=$1; printf("1\n");}
    	|
    	Expr MOD Expr                             									{$$=$1; printf("1\n");}
    	;

    Expr:
    	NOT Expr													{$$=$1; printf("1\n");}
    	|
    	MINUS Expr %prec NOT												{$$=$1; printf("1\n");}
    	|
    	PLUS Expr %prec NOT /*unary minus/plus has the same priority as the not operator */				{$$=$1; printf("1\n");}
    	;

    Expr:
    	INTLIT 														{$$=$1; printf("1\n");}
    	|
    	REALLIT 													{$$=$1; printf("1\n");}
    	|
    	ID 														{$$=$1; printf("1\n");}
    	|
    	FuncInvocation 													{$$=$1; printf("1\n");}
    	|
    	LPAR Expr RPAR                                           							{$$=$1; printf("1\n");}
    	;

    Expr:
    	LPAR error RPAR   												{$$=$1; printf("1\n");}
    	;
%%

