%{

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
    Program: PACKAGE ID SEMICOLON Declarations								{;}
    Declarations: VarDeclaration SEMICOLON Declarations | FuncDeclaration SEMICOLON Declarations | /*epsilon*/		{;}
    VarDeclaration: VAR VarDeclaration_1                                                                       		{;}
    VarSpec: ID VarSpec_1                                                                         			{;}
    VarDeclaration_1: VarSpec | LPAR VarSpec SEMICOLON RPAR								{;}
    VarSpec_1: Type | COMMA ID VarSpec_1										{;}
    Type: INT | FLOAT32 | BOOL | STRING                                                                     		{;}
    FuncDeclaration: FUNC ID LPAR FuncDeclaration_1									{;}
    FuncDeclaration_1: RPAR FuncDeclaration_2 | Parameters RPAR FuncDeclaration_2					{;}
    FuncDeclaration_2: FuncBody | Type FuncBody										{;}
    Parameters: ID Type | ID Type Parameters_1                                                                 		{;}
    Parameters_1: COMMA ID Type | COMMA ID Type Parameters_1								{;}
    FuncBody: LBRACE RBRACE | LBRACE VarsAndStatements RBRACE                      					{;}
    VarsAndStatements: SEMICOLON | VarDeclaration SEMICOLON | Statement SEMICOLON |
    SEMICOLON VarsAndStatements | VarDeclaration SEMICOLON VarsAndStatements | Statement SEMICOLON VarsAndStatements 	{;}
    Statement: ID ASSIGN Expr                                                                               		{;}
    Statement: LBRACE RBRACE | LBRACE Statement_1 RBRACE                                                      		{;}
    Statement_1: Statement SEMICOLON | Statement SEMICOLON Statement_1
    Statement: 	IF Expr LBRACE RBRACE |
     		IF Expr LBRACE Statement_rep RBRACE |
     		IF Expr LBRACE RBRACE ELSE LBRACE RBRACE |
     		IF Expr LBRACE RBRACE ELSE LBRACE Statement_rep RBRACE |
     		IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE RBRACE |
     		IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE Statement_rep RBRACE 					{;}
    Statement_rep: Statement SEMICOLON											{;}
    Statement: 	FOR LBRACE RBRACE |
		FOR LBRACE Statement_rep RBRACE |
		FOR Expr LBRACE RBRACE |
		FOR Expr LBRACE Statement_rep RBRACE 									{;}
    Statement: RETURN | RETURN Expr                                                                   			{;}
    Statement: FuncInvocation | ParseArgs                                                                   		{;}
    Statement: PRINT LPAR Expr RPAR | PRINT LPAR STRLIT RPAR                                                          	{;}
    ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                              		{;}
    FuncInvocation: 	ID LPAR RPAR |
			ID LPAR Expr RPAR |
			ID LPAR Expr FuncInvocation_rep RPAR								{;}
    FuncInvocation_rep: COMMA Expr | COMMA Expr FuncInvocation_rep							{;}
    Expr: Expr OR Expr | Expr AND Expr                                                					{;}
    Expr: Expr LT | Expr GT | Expr LE | Expr GE | Expr EQ | Expr NE							{;}
    Expr: Expr PLUS Expr | Expr MINUS Expr | Expr STAR Expr | Expr DIV Expr | Expr MOD Expr                             {;}
    Expr: NOT Expr | MINUS Expr %prec NOT | PLUS Expr %prec NOT /*unary minus/plus has the same priority as the not operator */{;}
    Expr: INTLIT | REALLIT | ID | FuncInvocation | LPAR Expr RPAR                                           		{;}

%%

int main() {
    yyparse();

    return 0;
}
