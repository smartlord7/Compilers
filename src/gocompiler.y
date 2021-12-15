%{
#include "error_handling.h"
#include "token_type.h"
#include <stdio.h>
#include <stdlib.h>
#include "abstract_syntax_tree.h"
#include "linked_list.h"

int yylex (void);
void yyerror(char* s);

int yydebug = 1;
extern struct tree_node_t * root;

%}

%token <node> PACKAGE
%token <node> ID
%token <node> SEMICOLON
%token <node> VAR
%token <node> LPAR
%token <node> RPAR
%token <node> COMMA
%token <node> INT
%token <node> FLOAT32
%token <node> BOOL
%token <node> STRING
%token <node> RBRACE
%token <node> LBRACE
%token <node> ASSIGN
%token <node> IF
%token <node> ELSE
%token <node> RETURN
%token <node> FOR
%token <node> PRINT
%token <node> STRLIT
%token <node> BLANKID
%token <node> PARSEINT
%token <node> CMDARGS
%token <node> LSQ
%token <node> RSQ
%token <node> OR
%token <node> AND
%token <node> LT
%token <node> GT
%token <node> EQ
%token <node> NE
%token <node> LE
%token <node> GE
%token <node> PLUS
%token <node> MINUS
%token <node> STAR
%token <node> DIV
%token <node> MOD
%token <node> NOT
%token <node> INTLIT
%token <node> REALLIT
%token <node> FUNC
%type <node> Program
%type <node> Declarations
%type <node> FuncDeclaration
%type <node> FuncHeader
%type <node> Type
%type <node> Parameters
%type <node> Parameters_1
%type <node> FuncBody
%type <node> VarsAndStatements
%type <node> VarDeclaration
%type <node> VarSpec
%type <node> VarSpec_1
%type <node> Statement
%type <node> Statement_1
%type <node> Statement_rep
%type <node> OPT_ELSE
%type <node> Expr
%type <node> ParseArgs
%type <node> FuncInvocation
%type <node> FuncInvocation_rep

%union{
	struct tree_node_t * node;
}

// Operator precedence order definition -> See Go language specification
%right ASSIGN
%left OR
%left AND
%left LT GT LE GE EQ NE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%nonassoc UNARY

%%
    Program:
    	PACKAGE ID SEMICOLON Declarations										{$$ = root = create_node(0, 0, A_PROGRAM, "Program");
    															push($$->children, $4);}
    	|
    	PACKAGE ID SEMICOLON												{ $$ = root = create_node(0, 0, A_PROGRAM, "Program");}
    ;

    Declarations:
    	VarDeclaration SEMICOLON											{$$ = $1;}
    	|
    	VarDeclaration SEMICOLON Declarations										{$$ = $1;
    															push($$->siblings, $3);}
    	|
    	FuncDeclaration SEMICOLON											{$$ = create_node(0, 0, A_FUNC_DECL, "FuncDecl");
    															push($$->children, $1);}
    	|
    	FuncDeclaration SEMICOLON Declarations										{$$ = create_node(0, 0, A_FUNC_DECL, "FuncDecl");
    															push($$->children, $1);
    															push($$->siblings, $3);}
    	;

    VarDeclaration:
    	VAR VarSpec                                                             					{$$ = $2;}
    	|
    	VAR LPAR VarSpec SEMICOLON RPAR											{$$ = $3;}
    	;

    VarSpec:
    	ID VarSpec_1													{$$ = create_node(0, 0, A_VAR_DECL, "VarDecl");
                                                                        push($$->children, create_node($1->line, $1->column, A_ID, $1->id));
                                                                        push($$->children, $2);

                                                                        struct list_node_t * father = $$->children->next->next;
                                                                        while(1) {
                                                                            if(father->data->children->next == NULL) break;
                                                                            father = father->data->children->next->next;
                                                                        }
                                                                        struct tree_node_t * help = father->data;

                                                                        father = $$->children->next->next;
                                                                        while(1) {
                                                                            if(father->data->children->next == NULL) break;
                                                                            struct tree_node_t * new_node = create_node(0, 0, A_VAR_DECL, "VarDecl");
                                                                            push(new_node->children, help);
                                                                            push(new_node->children, create_node(father->data->children->next->data->line, father->data->children->next->data->column, A_ID, father->data->children->next->data->id));

                                                                            push($$->siblings, new_node);
                                                                            father = father->data->children->next->next;
                                                                        }

                                                                        $$->children->next->next->data = $$->children->next->data;
                                                                        $$->children->next->data = help;
                                                                        }
	;

    VarSpec_1:
    	Type														{$$ = $1;}
    	|
     	COMMA ID VarSpec_1												{$$ = create_node(0, 0, A_VAR_DECL, "VarDecl");
     															push($$->children, create_node($2->line, $2->column, A_ID, $2->id));
     															push($$->children, $3);}
     	;

    Type:
    	INT														{$$ = create_node($1->line, $1->column, A_INT, "Int");}
    	|
    	FLOAT32														{$$ = create_node($1->line, $1->column, A_FLOAT32, "Float32");}
    	|
    	BOOL														{$$ = create_node($1->line, $1->column, A_BOOL, "Bool");}
    	|
	STRING                                                      							{$$ = create_node($1->line, $1->column, A_STRING, "String");}
	;

	FuncHeader:
		FUNC ID LPAR RPAR											{$$ = create_node($2->line, $2->column, A_ID, $2->id);
															push($$->siblings, create_node(0, 0, A_FUNC_PARAMS, "FuncParams"));}
    	|
    	FUNC ID LPAR Parameters RPAR											{$$ = create_node($2->line, $2->column, A_ID, $2->id);
    															push($$->siblings, create_node(0, 0, A_FUNC_PARAMS, "FuncParams"));
															push($$->siblings->next->data->children, $4);}
    	|
    	FUNC ID LPAR RPAR Type												{$$ = create_node($2->line, $2->column, A_ID, $2->id);
    															push($$->siblings, $5);
    															push($$->siblings, create_node(0, 0, A_FUNC_PARAMS, "FuncParams"));}
    	|
    	FUNC ID LPAR Parameters RPAR Type										{$$ = create_node($2->line, $2->column, A_ID, $2->id);
															push($$->siblings, $6);
															push($$->siblings, create_node(0, 0, A_FUNC_PARAMS, "FuncParams"));
															push($$->siblings->next->next->data->children, $4);}
		;

    FuncDeclaration:
    	FuncHeader FuncBody												{$$ = create_node(0, 0, A_FUNC_HEADER, "FuncHeader");
    															push($$->children, $1);
    															push($$->siblings, $2);}
    	;

    Parameters:
    	ID Type														{$$ = create_node(0, 0, A_PARAM_DECL, "ParamDecl");
    															push($$->children, $2);
    															push($$->children, create_node($1->line, $1->column, A_ID, $1->id));}
    	|
    	ID Type Parameters_1                                        							{$$ = create_node(0, 0, A_PARAM_DECL, "ParamDecl");
    															push($$->children, $2);
    															push($$->children, create_node($1->line, $1->column, A_ID, $1->id));
    															push($$->siblings, $3);}
	;

    Parameters_1:
    	COMMA ID Type													{$$ = create_node(0, 0, A_PARAM_DECL, "ParamDecl");
    															push($$->children, $3);
    															push($$->children, create_node($2->line, $2->column, A_ID, $2->id));}
    	|
    	COMMA ID Type Parameters_1											{$$ = create_node(0, 0, A_PARAM_DECL, "ParamDecl");
    															push($$->children, $3);
    															push($$->children, create_node($2->line, $2->column, A_ID, $2->id));
    															push($$->siblings, $4);}
    	;

    FuncBody:
    	LBRACE RBRACE													{$$ = create_node(0, 0, A_FUNC_BODY, "FuncBody");}
    	|
    	LBRACE VarsAndStatements RBRACE                      								{$$ = create_node(0, 0, A_FUNC_BODY, "FuncBody");
    															push($$->children, $2);}
    	;

    VarsAndStatements:
    	SEMICOLON													{$$ = create_node(0, 0, A_INVALID_NODE, "NO");}
    	|
    	VarDeclaration SEMICOLON											{$$ = $1;}
    	|
    	Statement SEMICOLON												{$$ = $1;}
    	|
    	SEMICOLON VarsAndStatements 											{$$ = $2;}
    	|
    	VarDeclaration SEMICOLON VarsAndStatements 									{$$ = $1;
    															push($$->siblings, $3);}
    	|
    	Statement SEMICOLON VarsAndStatements  										{if(!yacc_error){
    																$$ = $1;
    																push($$->siblings, $3);
    															};}
    	;

    Statement:
    	ID ASSIGN Expr                                                      						{$$ = create_node($2->line, $2->column, A_ASSIGN, "Assign");
    															push($$->children, create_node($1->line, $1->column, A_ID, $1->id));
    															push($$->children, $3);}
    	;

    Statement:
    	LBRACE RBRACE													{$$ = create_node(0, 0, A_INVALID_NODE, "Block");}
    	|
    	LBRACE Statement_1 RBRACE                                       						{$$ = create_node(0, 0, A_PROB_BLOCK, "Block");
    															push($$->children, $2);}
    	;

    Statement_1:
    	Statement SEMICOLON												{$$ = $1;}
    	|
    	Statement SEMICOLON Statement_1											{$$ = $1;
    															push($1->siblings, $3);}
    	;

    Statement:
     	IF Expr LBRACE Statement_rep RBRACE OPT_ELSE									{$$ = create_node($1->line, $1->column, A_IF, "If");
		 													push($$->children, $2);
		 													push($$->children, create_node(0, 0, A_BLOCK, "Block"));
		 													push($$->children->next->next->data->children, $4);
		 													push($$->children, $6);}
     	;
    OPT_ELSE:
	ELSE LBRACE Statement_rep RBRACE 										{$$ = create_node(0, 0, A_BLOCK, "Block");
															push($$->children, $3);}
	|
	/*epsilon*/													{$$ = create_node(0, 0, A_BLOCK, "Block");}
	;

    Statement_rep:
    	/*epsilon*/													{$$ = create_node(0, 0, A_INVALID_NODE, "NO");}
	|
	Statement SEMICOLON Statement_rep										{if(!yacc_error){
															$$ = $1;
															push($1->siblings, $3);
															};}
    	;

    Statement:
	FOR LBRACE Statement_rep RBRACE 										{$$ = create_node($1->line, $1->column, A_FOR, "For");
															push($$->children, create_node(0, 0, A_BLOCK, "Block"));
															push($$->children->next->data->children, $3);
															}
	|
	FOR Expr LBRACE Statement_rep RBRACE 										{$$ = create_node($1->line, $1->column, A_FOR, "For");
															push($$->children, $2);
															push($$->children, create_node(0, 0, A_BLOCK, "Block"));
															push($$->children->next->next->data->children, $4);
															}
	;

    Statement:
    	RETURN														{$$ = create_node($1->line, $1->column, A_RETURN, "Return");}
    	|
    	RETURN Expr                                                 							{$$ = create_node($1->line, $1->column, A_RETURN, "Return");
    															push($$->children, $2);}
    	;

    Statement:
    	FuncInvocation													{$$ = $1;}
    	|
    	ParseArgs                                                       						{$$ = $1;}
    	;

    Statement:
    	PRINT LPAR Expr RPAR 												{$$ = create_node($1->line, $1->column, A_PRINT, "Print");
    															push($$->children, $3);}
    	|
    	PRINT LPAR STRLIT RPAR                                          						{$$ = create_node($1->line, $1->column, A_PRINT, "Print");
    															push($$->children, create_node($3->line, $3->column, A_STRLIT, $3->id));}
    	;

    Statement:
    	Error_1														{;}
    	;

    ParseArgs:
    	ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                        				{/*might be wrong and be cmdargs*/$$ = create_node($5->line, $5->column, A_PARSE_ARGS, "ParseArgs");
															push($$->children, create_node($1->line, $1->column, A_ID, $1->id));
															push($$->children, $9);
															}
    	;

    ParseArgs:
    	ID COMMA BLANKID ASSIGN PARSEINT LPAR Error_1 RPAR								{;}
    	;

    FuncInvocation:
    	ID LPAR RPAR 													{$$ = create_node(0, 0, A_CALL, "Call");
    															push($$->children, create_node($1->line, $1->column, A_ID, $1->id));}
    	|
	ID LPAR Expr RPAR 												{$$ = create_node(0, 0, A_CALL, "Call");
															push($$->children, create_node($1->line, $1->column, A_ID, $1->id));
															push($$->children, $3);}
	|
	ID LPAR Expr FuncInvocation_rep RPAR										{$$ = create_node(0, 0, A_CALL, "Call");
															push($$->children, create_node($1->line, $1->column, A_ID, $1->id));
															push($$->children, $3);
															push($$->children, $4);}
	;

    FuncInvocation_rep:
    	COMMA Expr													{$$ = $2;}
    	|
    	COMMA Expr FuncInvocation_rep											{$$ = $2;
    															push($$->siblings, $3);}
    	;

    FuncInvocation:
    	ID LPAR Error_1 RPAR												{;}
    	;

    Expr:
    	Expr OR Expr 													{$$ = create_node($2->line, $2->column, A_OR, "Or");
    															push($$->children, $1);
    															push($$->children, $3);}
    	|
    	Expr AND Expr                                                							{$$ = create_node($2->line, $2->column, A_AND, "And");
    															push($$->children, $1);
    															push($$->children, $3);}
    	;

    Expr:
    	Expr LT Expr													{$$ = create_node($2->line, $2->column, A_LT, "Lt");
    															push($$->children, $1);
    															push($$->children, $3);}
    	|
    	Expr GT Expr													{$$ = create_node($2->line, $2->column, A_GT, "Gt");
															push($$->children, $1);
															push($$->children, $3);}
    	|
    	Expr LE Expr													{$$ = create_node($2->line, $2->column, A_LE, "Le");
															push($$->children, $1);
															push($$->children, $3);}
    	|
    	Expr GE Expr													{$$ = create_node($2->line, $2->column, A_GE, "Ge");
															push($$->children, $1);
															push($$->children, $3);}
    	|
    	Expr EQ Expr													{$$ = create_node($2->line, $2->column, A_EQ, "Eq");
															push($$->children, $1);
															push($$->children, $3);}
    	|
    	Expr NE	Expr													{$$ = create_node($2->line, $2->column, A_NE, "Ne");
															push($$->children, $1);
															push($$->children, $3);}
    	;

    Expr:
    	Expr PLUS Expr													{$$ = create_node($2->line, $2->column, A_ADD, "Add");
															push($$->children, $1);
															push($$->children, $3);}
    	|
    	Expr MINUS Expr													{$$ = create_node($2->line, $2->column, A_SUB, "Sub");
															push($$->children, $1);
															push($$->children, $3);}
    	|
    	Expr STAR Expr													{$$ = create_node($2->line, $2->column, A_MUL, "Mul");
															push($$->children, $1);
															push($$->children, $3);}
    	|
    	Expr DIV Expr													{$$ = create_node($2->line, $2->column, A_DIV, "Div");
															push($$->children, $1);
															push($$->children, $3);}
    	|
    	Expr MOD Expr                             									{$$ = create_node($2->line, $2->column, A_MOD, "Mod");
    															push($$->children, $1);
    															push($$->children, $3);}
    	;

    Expr:
    	NOT Expr													{$$ = create_node($1->line, $1->column, A_NOT, "Not");
    															push($$->children, $2);}
    	|
    	MINUS Expr %prec NOT												{$$ = create_node($1->line, $1->column, A_MINUS, "Minus");
    															push($$->children, $2);}
    	|
    	PLUS Expr %prec NOT /*unary minus/plus has the same priority as the not operator */				{$$ = create_node($1->line, $1->column, A_PLUS, "Plus");
    															push($$->children, $2);}
    	;

    Expr:
    	INTLIT 														{$$ = create_node($1->line, $1->column, A_INTLIT, $1->id);}
    	|
    	REALLIT 													{$$ = create_node($1->line, $1->column, A_REALLIT, $1->id);}
    	|
    	ID 														{$$ = create_node($1->line, $1->column, A_ID, $1->id);}
    	|
    	FuncInvocation 													{$$ = $1;}
    	|
    	LPAR Expr RPAR                                           							{$$ = $2;}
    	;

    Expr:
    	LPAR Error_1 RPAR   												{;}
    	;

    Error_1:
	error														{;}
	;
%%
