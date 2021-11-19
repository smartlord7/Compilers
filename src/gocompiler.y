%{

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
    ;

    Declarations:
    	VarDeclaration SEMICOLON Declarations										{printf("1\n");}
    	|
    	FuncDeclaration SEMICOLON Declarations										{printf("1\n");}
    	|
    	/*epsilon*/													{printf("1\n");}
    	;

    VarDeclaration:
    	VAR VarDeclaration_1                                                                       			{printf("1\n");}
    	;

    VarDeclaration_1:
    	VarSpec														{printf("1\n");}
    	|
    	LPAR VarSpec SEMICOLON RPAR											{printf("1\n");}
    	;

    VarSpec:
    	ID VarSpec_1                                                                         				{printf("1\n");}
    	;

    VarSpec_1:
    	Type														{printf("1\n");}
    	|
     	COMMA ID VarSpec_1												{printf("1\n");}
     	;

    Type:
    	INT														{printf("1\n");}
    	|
    	FLOAT32														{printf("1\n");}
    	|
    	BOOL														{printf("1\n");}
    	|
    	STRING                                                                     					{printf("1\n");}
	;

    FuncDeclaration:
    	FUNC ID LPAR FuncDeclaration_1											{printf("1\n");}
	;

    FuncDeclaration_1:
  	RPAR FuncDeclaration_2												{printf("1\n");}
  	|
  	Parameters RPAR FuncDeclaration_2										{printf("1\n");}
	;

    FuncDeclaration_2:
    	FuncBody													{printf("1\n");}
    	|
    	Type FuncBody													{printf("1\n");}
	;

    Parameters:
    	ID Type														{printf("1\n");}
    	|
    	ID Type Parameters_1                                                                 				{printf("1\n");}
	;

    Parameters_1:
    	COMMA ID Type													{printf("1\n");}
    	|
    	COMMA ID Type Parameters_1											{printf("1\n");}
    	;

    FuncBody:
    	LBRACE RBRACE													{printf("1\n");}
    	|
    	LBRACE VarsAndStatements RBRACE                      								{printf("1\n");}
    	;

    VarsAndStatements:
    	SEMICOLON													{printf("1\n");}
    	|
    	VarDeclaration SEMICOLON											{printf("1\n");}
    	|
    	Statement SEMICOLON												{printf("1\n");}
    	|
    	SEMICOLON VarsAndStatements											{printf("1\n");}
    	|
    	VarDeclaration SEMICOLON VarsAndStatements									{printf("1\n");}
    	|
    	Statement SEMICOLON VarsAndStatements 										{printf("1\n");}
    	;

    Statement:
    	ID ASSIGN Expr                                                                               			{printf("1\n");}
    	;

    Statement:
    	LBRACE RBRACE													{printf("1\n");}
    	|
    	LBRACE Statement_1 RBRACE                                                      					{printf("1\n");}
    	;

    Statement_1:
    	Statement SEMICOLON												{printf("1\n");}
    	|
    	Statement SEMICOLON Statement_1											{printf("1\n");}
    	;

    Statement:
    	IF Expr LBRACE RBRACE 												{printf("1\n");}
    	|
     	IF Expr LBRACE Statement_rep RBRACE 										{printf("1\n");}
     	|
     	IF Expr LBRACE RBRACE ELSE LBRACE RBRACE 									{printf("1\n");}
     	|
     	IF Expr LBRACE RBRACE ELSE LBRACE Statement_rep RBRACE 								{printf("1\n");}
     	|
     	IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE RBRACE 								{printf("1\n");}
     	|
     	IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE Statement_rep RBRACE 						{printf("1\n");}
     	;

    Statement_rep:
    	Statement SEMICOLON												{printf("1\n");}
    	;

    Statement:
    	FOR LBRACE RBRACE 												{printf("1\n");}
    	|
	FOR LBRACE Statement_rep RBRACE 										{printf("1\n");}
	|
	FOR Expr LBRACE RBRACE 												{printf("1\n");}
	|
	FOR Expr LBRACE Statement_rep RBRACE 										{printf("1\n");}
	;

    Statement:
    	RETURN														{printf("1\n");}
    	|
    	RETURN Expr                                                                   					{printf("1\n");}
    	;

    Statement:
    	FuncInvocation													{printf("1\n");}
    	|
    	ParseArgs                                                                   					{printf("1\n");}
    	;

    Statement:
    	PRINT LPAR Expr RPAR 												{printf("1\n");}
    	|
    	PRINT LPAR STRLIT RPAR                                                          				{printf("1\n");}
    	;

    Statement:
    	error														{printf("1\n");}
    	;

    ParseArgs:
    	ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                              			{printf("1\n");}
    	;

    ParseArgs:
    	ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR								{printf("1\n");}
    	;

    FuncInvocation:
    	ID LPAR RPAR 													{printf("1\n");}
    	|
	ID LPAR Expr RPAR 												{printf("1\n");}
	|
	ID LPAR Expr FuncInvocation_rep RPAR										{printf("1\n");}
	;

    FuncInvocation_rep:
    	COMMA Expr													{printf("1\n");}
    	|
    	COMMA Expr FuncInvocation_rep											{printf("1\n");}
    	;

    FuncInvocation:
    	ID LPAR error RPAR												{printf("1\n");}
    	;

    Expr:
    	Expr OR Expr 													{printf("1\n");}
    	|
    	Expr AND Expr                                                							{printf("1\n");}
    	;

    Expr:
    	Expr LT 													{printf("1\n");}
    	|
    	Expr GT 													{printf("1\n");}
    	|
    	Expr LE 													{printf("1\n");}
    	|
    	Expr GE 													{printf("1\n");}
    	|
    	Expr EQ 													{printf("1\n");}
    	|
    	Expr NE														{printf("1\n");}
    	;

    Expr:
    	Expr PLUS Expr													{printf("1\n");}
    	|
    	Expr MINUS Expr													{printf("1\n");}
    	|
    	Expr STAR Expr													{printf("1\n");}
    	|
    	Expr DIV Expr													{printf("1\n");}
    	|
    	Expr MOD Expr                             									{printf("1\n");}
    	;

    Expr:
    	NOT Expr													{printf("1\n");}
    	|
    	MINUS Expr %prec NOT												{printf("1\n");}
    	|
    	PLUS Expr %prec NOT /*unary minus/plus has the same priority as the not operator */				{printf("1\n");}
    	;

    Expr:
    	INTLIT 														{printf("1\n");}
    	|
    	REALLIT 													{printf("1\n");}
    	|
    	ID 														{printf("1\n");}
    	|
    	FuncInvocation 													{printf("1\n");}
    	|
    	LPAR Expr RPAR                                           							{printf("1\n");}
    	;

    Expr:
    	LPAR error RPAR   												{printf("1\n");}
    	;
%%

int main() {
    yyparse();

    return 0;
}
