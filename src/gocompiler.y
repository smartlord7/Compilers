%{
#include "util/error_handling.h"
#include "util/token_type.h"
#include <stdio.h>
#include <stdlib.h>
#include "data_structures/abstract_syntax_tree.h"
#include "data_structures/linked_list.h"

int yylex (void);
void yyerror(char* s);

int yydebug = 1;
struct tree_node_t * root;

%}


%token <package> PACKAGE
%token <id> ID
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
%token <strlit> STRLIT
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
%token <intlit> INTLIT
%token <reallit> REALLIT
%token FUNC
%type <tree_node> Program
%type <tree_node> Declarations
%type <tree_node> FuncDeclaration
%type <tree_node> FuncHeader
%type <tree_node> Type
%type <tree_node> Parameters
%type <tree_node> Parameters_1
%type <tree_node> FuncBody
%type <tree_node> VarsAndStatements
%type <tree_node> VarDeclaration
%type <tree_node> VarSpec
%type <tree_node> VarSpec_1 
%type <tree_node> Statement 
%type <tree_node> Statement_1
%type <tree_node> Statement_rep
%type <tree_node> OPT_ELSE 
%type <tree_node> Expr
%type <tree_node> ParseArgs
%type <tree_node> FuncInvocation
%type <tree_node> FuncInvocation_rep

%union{
	char * strlit, * id, * reallit, * intlit;
	struct tree_node_t * tree_node;
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
    	PACKAGE ID SEMICOLON Declarations										{$$ = root = create_node(-1, "Program"); push($$->children, $4);}
    	|
    	PACKAGE ID SEMICOLON												{$$ = root = create_node(-1, "Program");}
    ;

    Declarations:
    	VarDeclaration SEMICOLON											{printf("A\n");}
    	|
    	VarDeclaration SEMICOLON Declarations										{printf("B\n");}
    	|
    	FuncDeclaration SEMICOLON											{$$ = create_node(0, "FuncDecl"); push($$->children, $1);}
    	|
    	FuncDeclaration SEMICOLON Declarations										{$$ = create_node(0, "FuncDecl"); push($$->children, $1); push($$->siblings, $3);}
    	;

    VarDeclaration:
    	VAR VarSpec                                                             {$$ = $2;}
    	|
    	VAR LPAR VarSpec SEMICOLON RPAR											{$$ = $3;}
    	;

    VarSpec:
    	ID VarSpec_1													{$$ = create_node(0, "VarDecl"); push($$->children, create_node(0, $1)); push($$->children, $2);
		
			struct list_node_t * father = $$->children->next->next;
			while(1) {
				if(father->data->children->next == NULL) break;
				father = father->data->children->next->next;
			}
			struct tree_node_t * help = father->data;

			father = $$->children->next->next;
			while(1) {
				if(father->data->children->next == NULL) break;
				struct tree_node_t * new_node = create_node(0, "VarDecl");
				push(new_node->children, help);
				push(new_node->children, create_node(0, father->data->children->next->data->id));

				push($$->siblings, new_node);
				father = father->data->children->next->next;
			}

			$$->children->next->next->data = $$->children->next->data;
			$$->children->next->data = help;
		}
    	;

    VarSpec_1:
    	Type															{$$ = $1;}
    	|
     	COMMA ID VarSpec_1												{$$ = create_node(0, "VarDecl"); push($$->children, create_node(0, $2)); push($$->children, $3);}
     	;

    Type:
    	INT															{$$ = create_node(0, "Int");}
    	|
    	FLOAT32														{$$ = create_node(0, "Float32");}
    	|
    	BOOL														{$$ = create_node(0, "Bool");}
    	|
		STRING                                                      {$$ = create_node(0, "String");}
	;

	FuncHeader:
		FUNC ID LPAR RPAR													{$$ = create_node(0, $2); push($$->siblings, create_node(0, "FuncParams"));}
    	|
    	FUNC ID LPAR Parameters RPAR										{$$ = create_node(0, $2); push($$->siblings, create_node(0, "FuncParams"));
							push($$->siblings->next->data->children, $4);}
    	|
    	FUNC ID LPAR RPAR Type												{$$ = create_node(0, $2); push($$->siblings, $5); push($$->siblings, create_node(0, "FuncParams"));}
    	|
    	FUNC ID LPAR Parameters RPAR Type									{$$ = create_node(0, $2);
							push($$->siblings, $6); push($$->siblings, create_node(0, "FuncParams")); push($$->siblings->next->next->data->children, $4);}
		;

    FuncDeclaration:
    	FuncHeader FuncBody												{$$ = create_node(0, "FuncHeader"); push($$->children, $1); push($$->siblings, $2);}
    	;

    Parameters:
    	ID Type														{$$ = create_node(0, "ParamDecl"); push($$->children, $2); push($$->children, create_node(0, $1));}
    	|
    	ID Type Parameters_1                                        {$$ = create_node(0, "ParamDecl"); push($$->children, $2); push($$->children, create_node(0, $1)); push($$->siblings, $3);}
	;

    Parameters_1:
    	COMMA ID Type													{$$ = create_node(0, "ParamDecl"); push($$->children, $3); push($$->children, create_node(0, $2));}
    	|
    	COMMA ID Type Parameters_1											{$$ = create_node(0, "ParamDecl"); push($$->children, $3); push($$->children, create_node(0, $2)); push($$->siblings, $4);}
    	;

    FuncBody:
    	LBRACE RBRACE													{$$ = create_node(0, "FuncBody");}
    	|
    	LBRACE VarsAndStatements RBRACE                      			{$$ = create_node(0, "FuncBody"); push($$->children, $2);}
    	;

    VarsAndStatements:
    	SEMICOLON															{$$ = create_node(-5, "NO");}
    	|
    	VarDeclaration SEMICOLON											{$$ = $1;}
    	|
    	Statement SEMICOLON													{$$ = $1;}
    	|
    	SEMICOLON VarsAndStatements 										{$$ = $2;}
    	|
    	VarDeclaration SEMICOLON VarsAndStatements 							{$$ = $1; push($$->siblings, $3);}
    	|
    	Statement SEMICOLON VarsAndStatements  								{$$ = $1; push($$->siblings, $3);}
    	;

    Statement:
    	ID ASSIGN Expr                                                      {$$ = create_node(0, "Assign"); push($$->children, create_node(0, $1)); push($$->children, $3);}
    	;

    Statement:
    	LBRACE RBRACE													{$$ = create_node(-5, "NO");}
    	|
    	LBRACE Statement_1 RBRACE                                       {$$ = create_node(5, "Block"); push($$->children, $2);}
    	;

    Statement_1:
    	Statement SEMICOLON												{$$ = $1;}
    	|
    	Statement SEMICOLON Statement_1									{$$ = $1; push($1->siblings, $3);}
    	;

    Statement:
     	IF Expr LBRACE Statement_rep RBRACE OPT_ELSE					{$$ = create_node(0, "If");
		 push($$->children, $2); push($$->children, create_node(0, "Block")); push($$->children->next->next->data->children, $4); push($$->children, $6);}
     	;
	OPT_ELSE: 
		ELSE LBRACE Statement_rep RBRACE { $$ = create_node(0, "Block"); push($$->children, $3); }
		| 
		/*epsilon*/												{$$ = create_node(-5, "NO");}
		;

    Statement_rep:
    	/*epsilon*/													{$$ = create_node(-5, "NO");}
		|
		Statement SEMICOLON Statement_rep									{$$ = $1; push($1->siblings, $3);}
    	;

    Statement:
	FOR LBRACE Statement_rep RBRACE 										{
		$$ = create_node(0, "For");
		push($$->children, create_node(0, "Block"));
		push($$->children->next->data->children, $3);
	}
	|
	FOR Expr LBRACE Statement_rep RBRACE 									{
		$$ = create_node(0, "For");
		push($$->children, $2);
		push($$->children, create_node(0, "Block"));
		push($$->children->next->next->data->children, $4);
	}
	;

    Statement:
    	RETURN														{ $$ = create_node(0, "Return");}
    	|
    	RETURN Expr                                                 {$$ = create_node(0, "Return"); push($$->children, $2);}
    	;

    Statement:
    	FuncInvocation													{$$ = $1;}
    	|
    	ParseArgs                                                       {$$ = $1;}
    	;

    Statement:
    	PRINT LPAR Expr RPAR 											{$$ = create_node(0, "Print"); push($$->children, $3);}
    	|
    	PRINT LPAR STRLIT RPAR                                          {$$ = create_node(0, "Print"); push($$->children, create_node(0, $3));}
    	;

    Statement:
    	Error_1														{;}
    	;

    ParseArgs:
    	ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                        {
				$$ = create_node(0, "ParseArgs");
				push($$->children, create_node(0, $1));
				push($$->children, $9);
		}
    	;

    ParseArgs:
    	ID COMMA BLANKID ASSIGN PARSEINT LPAR Error_1 RPAR								{;}
    	;

    FuncInvocation:
    	ID LPAR RPAR 													{$$ = create_node(0, "Call"); push($$->children, create_node(0, $1));}
    	|
	ID LPAR Expr RPAR 												{$$ = create_node(0, "Call"); push($$->children, create_node(0, $1)); push($$->children, $3);}
	|
	ID LPAR Expr FuncInvocation_rep RPAR							{$$ = create_node(0, "Call"); push($$->children, create_node(0, $1)); push($$->children, $3);
																	 push($$->children, $4);}
	;

    FuncInvocation_rep:
    	COMMA Expr													{$$ = $2;}
    	|
    	COMMA Expr FuncInvocation_rep											{$$ = $2; push($$->siblings, $3);}
    	;

    FuncInvocation:
    	ID LPAR Error_1 RPAR												{;}
    	;

    Expr:
    	Expr OR Expr 													{$$ = create_node(0, "Or"); push($$->children, $1); push($$->children, $3);}
    	|
    	Expr AND Expr                                                	{$$ = create_node(0, "And"); push($$->children, $1); push($$->children, $3);}
    	;

    Expr:
    	Expr LT Expr													{$$ = create_node(0, "Lt"); push($$->children, $1); push($$->children, $3);}
    	|
    	Expr GT Expr													{$$ = create_node(0, "Gt"); push($$->children, $1); push($$->children, $3);}
    	|
    	Expr LE Expr													{$$ = create_node(0, "Le"); push($$->children, $1); push($$->children, $3);}
    	|
    	Expr GE Expr													{$$ = create_node(0, "Ge"); push($$->children, $1); push($$->children, $3);}
    	|
    	Expr EQ Expr													{$$ = create_node(0, "Eq"); push($$->children, $1); push($$->children, $3);}
    	|
    	Expr NE	Expr													{$$ = create_node(0, "Ne"); push($$->children, $1); push($$->children, $3);}
    	;

    Expr:
    	Expr PLUS Expr													{$$ = create_node(0, "Add"); push($$->children, $1); push($$->children, $3);}
    	|
    	Expr MINUS Expr													{$$ = create_node(0, "Sub"); push($$->children, $1); push($$->children, $3);}
    	|
    	Expr STAR Expr													{$$ = create_node(0, "Mul"); push($$->children, $1); push($$->children, $3);}
    	|
    	Expr DIV Expr													{$$ = create_node(0, "Div"); push($$->children, $1); push($$->children, $3);}
    	|
    	Expr MOD Expr                             						{$$ = create_node(0, "Mod"); push($$->children, $1); push($$->children, $3);}
    	;

    Expr:
    	NOT Expr																						{$$ = create_node(0, "Not"); push($$->children, $2);}
    	|
    	MINUS Expr %prec NOT																			{$$ = create_node(0, "Minus"); push($$->children, $2);}
    	|
    	PLUS Expr %prec NOT /*unary minus/plus has the same priority as the not operator */				{$$ = create_node(0, "Plus"); push($$->children, $2);}
    	;

    Expr:
    	INTLIT 														{$$ = create_node(0, $1);}
    	|
    	REALLIT 													{$$ = create_node(0, $1);}
    	|
    	ID 															{$$ = create_node(0, $1);}
    	|
    	FuncInvocation 													{$$ = $1;}
    	|
    	LPAR Expr RPAR                                           							{$$ = $2;}
    	;

    Expr:
    	LPAR Error_1 RPAR   												{;}
    	;

	Error_1:
		error								{;}
%%
