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
    Program: PACKAGE ID SEMICOLON Program_1                                                             		{;}
    Program_1: Declarations | /*epsilon*/										{;}
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
    FuncBody: LBRACE VarsAndStatements RBRACE                                                               		{;}
    VarsAndStatements: VarsAndStatements VarsAndStatements_1 | /*epsilon*/           					{;}
    VarsAndStatements_1: SEMICOLON | VarsAndStatements_2 SEMICOLON							{;}
    VarsAndStatements_2: VarDeclaration | Statement									{;}
    Statement: ID ASSIGN Expr                                                                               		{;}
    Statement: LBRACE '{'Statement SEMICOLON'}' RBRACE                                                      		{;}
    Statement: IF Expr LBRACE '{'Statement SEMICOLON'}' RBRACE '['ELSE LBRACE '{'Statement SEMICOLON'}' RBRACE']'  	{;}
    Statement: FOR '['Expr']' LBRACE '{'Statement SEMICOLON'}' RBRACE                                       		{;}
    Statement: RETURN '['Expr']'                                                                   			{;}
    Statement: FuncInvocation | ParseArgs                                                                   		{;}
    Statement: PRINT LPAR '('Expr | STRLIT')' RPAR                                                          		{;}
    ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                              		{;}
    FuncInvocation: ID LPAR '['Expr '{'COMMA Expr'}'']' RPAR                                                  		{;}
    Expr: Expr '('OR | AND')' Expr                                                					{;}
    Expr: Expr '('LT | GT | LE | GE | EQ | NE')'									{;}
    Expr: Expr '('PLUS | MINUS | STAR | DIV | MOD')' Expr                                                   		{;}
    Expr: '('NOT')' Expr |
          '('MINUS | PLUS')' Expr %prec NOT /*unary minus/plus has the same priority as the not operator */		{;}
    Expr: INTLIT | REALLIT | ID | FuncInvocation | LPAR Expr RPAR                                           		{;}

%%

int main() {
    yyparse();

    return 0;
}
