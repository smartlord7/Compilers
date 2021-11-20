%{
#include "util/error_handling.h"
#include "util/token_type.h"
#include <stdio.h>
#include <stdlib.h>
#include "data_structures/abstract_syntax_tree.h"

int yylex (void);
void yyerror(char* s);

int yydebug = 1;

struct tree_node_t * my_program;
struct tree_node_t * create_node(int type, void * data);

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
%token BLANK_ID
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
%type <program> Program

%union{
	char * strlit, * id, * reallit, * intlit;
	void * program;
}

// Operator precedence order definition -> See Go language specification
%right ASSIGN
%left OR
%left AND
%left LT GT LE GE EQ NE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT

%%
    Program:
    	PACKAGE ID SEMICOLON Declarations										{;}
    	|
    	PACKAGE ID SEMICOLON												{;}
    ;

    Declarations:
    	VarDeclaration SEMICOLON											{;}
    	|
    	VarDeclaration SEMICOLON Declarations										{;}
    	|
    	FuncDeclaration SEMICOLON											{;}
    	|
    	FuncDeclaration SEMICOLON Declarations										{;}
    	;

    VarDeclaration:
    	VAR VarSpec                                                                       				{;}
    	|
    	VAR LPAR VarSpec SEMICOLON RPAR											{;}
    	;

    VarSpec:
    	ID VarSpec_1													{;}
    	;

    VarSpec_1:
    	Type														{;}
    	|
     	COMMA ID VarSpec_1												{;}
     	;

    Type:
    	INT														{;}
    	|
    	FLOAT32														{;}
    	|
    	BOOL														{;}
    	|
    	STRING                                                                     					{;}
	;

    FuncDeclaration:
    	FUNC ID LPAR RPAR FuncBody											{;}
    	|
    	FUNC ID LPAR Parameters RPAR FuncBody										{;}
    	|
    	FUNC ID LPAR RPAR Type FuncBody											{;}
    	|
    	FUNC ID LPAR Parameters RPAR Type FuncBody									{;}
    	;

    Parameters:
    	ID Type														{;}
    	|
    	ID Type Parameters_1                                                                 				{;}
	;

    Parameters_1:
    	COMMA ID Type													{;}
    	|
    	COMMA ID Type Parameters_1											{;}
    	;

    FuncBody:
    	LBRACE RBRACE													{;}
    	|
    	LBRACE VarsAndStatements RBRACE                      								{;}
    	;

    VarsAndStatements:
    	SEMICOLON													{;}
    	|
    	VarDeclaration SEMICOLON											{;}
    	|
    	Statement SEMICOLON												{;}
    	|
    	SEMICOLON VarsAndStatements 											{;}
    	|
    	VarDeclaration SEMICOLON VarsAndStatements 									{;}
    	|
    	Statement SEMICOLON VarsAndStatements  										{;}
    	;

    Statement:
    	ID ASSIGN Expr                                                                               			{;}
    	;

    Statement:
    	LBRACE RBRACE													{;}
    	|
    	LBRACE Statement_1 RBRACE                                                      					{;}
    	;

    Statement_1:
    	Statement SEMICOLON												{;}
    	|
    	Statement SEMICOLON Statement_1											{;}
    	;

    Statement:
    	// IF Expr LBRACE RBRACE 											{;}
    	// |
     	IF Expr LBRACE Statement_rep RBRACE OPT_ELSE									{;}
     	// IF Expr LBRACE RBRACE ELSE LBRACE RBRACE 									{;}
     	// |
     	// IF Expr LBRACE RBRACE ELSE LBRACE Statement_rep RBRACE 							{;}
     	// |
     	// IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE RBRACE 							{;}
     	// |
     	;
	OPT_ELSE: 
		ELSE LBRACE Statement_rep RBRACE {39;}
		| 
		/*epsilon*/												{;}
		;

    Statement_rep:
    	/*epsilon*/													{;}
		|
		Statement SEMICOLON Statement_rep									{;}
    	;

    Statement:
	FOR LBRACE Statement_rep RBRACE 										{;}
	|
	FOR Expr LBRACE Statement_rep RBRACE 										{;}
	;

    Statement:
    	RETURN														{;}
    	|
    	RETURN Expr                                                                   					{;}
    	;

    Statement:
    	FuncInvocation													{;}
    	|
    	ParseArgs                                                                   					{;}
    	;

    Statement:
    	PRINT LPAR Expr RPAR 												{;}
    	|
    	PRINT LPAR STRLIT RPAR                                                          				{;}
    	;

    Statement:
    	error														{;}
    	;

    ParseArgs:
    	ID COMMA BLANK_ID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                              			{;}
    	;

    ParseArgs:
    	ID COMMA BLANK_ID ASSIGN PARSEINT LPAR error RPAR								{;}
    	;

    FuncInvocation:
    	ID LPAR RPAR 													{;}
    	|
	ID LPAR Expr RPAR 												{;}
	|
	ID LPAR Expr FuncInvocation_rep RPAR										{;}
	;

    FuncInvocation_rep:
    	COMMA Expr													{;}
    	|
    	COMMA Expr FuncInvocation_rep											{;}
    	;

    FuncInvocation:
    	ID LPAR error RPAR												{;}
    	;

    Expr:
    	Expr OR Expr 													{;}
    	|
    	Expr AND Expr                                                							{;}
    	;

    Expr:
    	Expr LT 													{;}
    	|
    	Expr GT 													{;}
    	|
    	Expr LE 													{;}
    	|
    	Expr GE 													{;}
    	|
    	Expr EQ 													{;}
    	|
    	Expr NE														{;}
    	;

    Expr:
    	Expr PLUS Expr													{;}
    	|
    	Expr MINUS Expr													{;}
    	|
    	Expr STAR Expr													{;}
    	|
    	Expr DIV Expr													{;}
    	|
    	Expr MOD Expr                             									{;}
    	;

    Expr:
    	NOT Expr													{;}
    	|
    	MINUS Expr %prec NOT												{;}
    	|
    	PLUS Expr %prec NOT /*unary minus/plus has the same priority as the not operator */				{;}
    	;

    Expr:
    	INTLIT 														{;}
    	|
    	REALLIT 													{;}
    	|
    	ID 														{;}
    	|
    	FuncInvocation 													{;}
    	|
    	LPAR Expr RPAR                                           							{;}
    	;

    Expr:
    	LPAR error RPAR   												{;}
    	;
%%

