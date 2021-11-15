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

%%                  
    Program: PACKAGE ID SEMICOLON Program_1                                                              {;}
    Program_1: Declarations | /*epsilon*/
    Declarations: VarDeclaration SEMICOLON Declarations | FuncDeclaration SEMICOLON Declarations | /*epsilon*/                                {;}
    VarDeclaration: VAR VarSpec                                                                             {;}
    VarDeclaration: VAR LPAR VarSpec SEMICOLON RPAR                                                         {;}
    VarSpec: ID '{'COMMA ID'}' Type                                                                         {;}
    Type: INT | FLOAT32 | BOOL | STRING                                                                     {;}
    FuncDeclaration: FUNC ID LPAR '['Parameters']' RPAR '['Type']' FuncBody                                 {;}
    Parameters: ID Type '{'COMMA ID Type'}'                                                                 {;}
    FuncBody: LBRACE VarsAndStatements RBRACE                                                               {;}
    VarsAndStatements: VarsAndStatements '['VarDeclaration | Statement']' SEMICOLON | /*epsilon*/           {;}
    Statement: ID ASSIGN Expr                                                                               {;}
    Statement: LBRACE '{'Statement SEMICOLON'}' RBRACE                                                      {;}
    Statement:  IF Expr LBRACE '{'Statement SEMICOLON'}' RBRACE '['ELSE LBRACE '{'Statement SEMICOLON'}' RBRACE']'  {;}
    Statement: FOR '['Expr']' LBRACE '{'Statement SEMICOLON'}' RBRACE                                       {;}
    Statement: RETURN '['Expr']'                                                                            {;}
    Statement: FuncInvocation | ParseArgs                                                                   {;}
    Statement: PRINT LPAR '('Expr | STRLIT')' RPAR                                                          {;}
    ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR                              {;}
    FuncInvocation: ID LPAR '['Expr '{'COMMA Expr'}'']' RPAR                                                  {;}
    Expr: Expr '('OR | AND')' Expr                                                                          {;}
    Expr: Expr '('LT | GT | EQ | NE | LE | GE')' Expr                                                       {;}
    Expr: Expr '('PLUS | MINUS | STAR | DIV | MOD')' Expr                                                   {;}
    Expr: '('NOT | MINUS | PLUS')' Expr                                                                     {;}
    Expr: INTLIT | REALLIT | ID | FuncInvocation | LPAR Expr RPAR                                           {;}

%%

int main() {
    yyparse();

    return 0;
}
