%{
#include "util/error_handling.h"
#include "util/token_type.h"
#include <stdio.h>

int yylex (void);
void yyerror(char* s);
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
    Program: PACKAGE ID SEMICOLON Declarations										{printf("1\n");}
    Declarations: VarDeclaration SEMICOLON Declarations | FuncDeclaration SEMICOLON Declarations | /*epsilon*/		{printf("2\n");}
    VarDeclaration: VAR VarDeclaration_1                                                                       		{printf("3\n");}
    VarSpec: ID VarSpec_1                                                                         			{printf("4\n");}
    VarDeclaration_1: VarSpec | LPAR VarSpec SEMICOLON RPAR								{printf("5\n");}
    VarSpec_1: Type | COMMA ID VarSpec_1										{printf("6\n");}
    Type: INT | FLOAT32 | BOOL | STRING                                                                     		{printf("7\n");}
    FuncDeclaration: FUNC ID LPAR FuncDeclaration_1									{printf("8\n");}
    FuncDeclaration_1: RPAR FuncDeclaration_2 | Parameters RPAR FuncDeclaration_2					{printf("9\n");}
    FuncDeclaration_2: FuncBody | Type FuncBody										{printf("10\n");}
    Parameters: ID Type | ID Type Parameters_1                                                                 		{printf("11\n");}
    Parameters_1: COMMA ID Type | COMMA ID Type Parameters_1								{printf("12\n");}
    FuncBody: LBRACE RBRACE | LBRACE VarsAndStatements RBRACE                      					{printf("13\n");}
    VarsAndStatements: SEMICOLON | VarDeclaration SEMICOLON | Statement SEMICOLON |
    SEMICOLON VarsAndStatements | VarDeclaration SEMICOLON VarsAndStatements | Statement SEMICOLON VarsAndStatements 	{printf("14\n");}
    Statement: ID ASSIGN Expr                                                                               		{printf("15\n");}
    Statement: LBRACE RBRACE | LBRACE Statement_1 RBRACE                                                      		{printf("16\n");}
    Statement_1: Statement SEMICOLON | Statement SEMICOLON Statement_1
    Statement: 	IF Expr LBRACE RBRACE |
     		IF Expr LBRACE Statement_rep RBRACE |
     		IF Expr LBRACE RBRACE ELSE LBRACE RBRACE |
     		IF Expr LBRACE RBRACE ELSE LBRACE Statement_rep RBRACE |
     		IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE RBRACE |
     		IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE Statement_rep RBRACE 					{printf("17\n");}
    Statement_rep: Statement SEMICOLON											{printf("18\n");}
    Statement: 	FOR LBRACE RBRACE |
		FOR LBRACE Statement_rep RBRACE |
		FOR Expr LBRACE RBRACE |
		FOR Expr LBRACE Statement_rep RBRACE 									{printf("19\n");}
    Statement: RETURN | RETURN Expr                                                                   			{printf("20\n");}
    Statement: FuncInvocation | ParseArgs                                                                   		{printf("21\n");}
    Statement: PRINT LPAR Expr RPAR | PRINT LPAR STRLIT RPAR                                                          	{printf("22\n");}
    Statement: error													{printf("23\n");}
    ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                              		{printf("24\n");}
    ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR								{printf("25\n");}
    FuncInvocation: 	ID LPAR RPAR |
			ID LPAR Expr RPAR |
			ID LPAR Expr FuncInvocation_rep RPAR								{printf("26\n");}
    FuncInvocation_rep: COMMA Expr | COMMA Expr FuncInvocation_rep							{printf("27\n");}
    FuncInvocation: ID LPAR error RPAR											{printf("28\n");}
    Expr: Expr OR Expr | Expr AND Expr                                                					{printf("29\n");}
    Expr: Expr LT | Expr GT | Expr LE | Expr GE | Expr EQ | Expr NE							{printf("30\n");}
    Expr: Expr PLUS Expr | Expr MINUS Expr | Expr STAR Expr | Expr DIV Expr | Expr MOD Expr                             {printf("31\n");}
    Expr: NOT Expr | MINUS Expr %prec NOT | PLUS Expr %prec NOT /*unary minus/plus has the same priority as the not operator */{printf("32\n");}
    Expr: INTLIT | REALLIT | ID | FuncInvocation | LPAR Expr RPAR                                           		{printf("33\n");}
    Expr: LPAR error RPAR   												{printf("34\n");}
%%

