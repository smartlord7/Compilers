/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PACKAGE = 258,
    ID = 259,
    SEMICOLON = 260,
    VAR = 261,
    LPAR = 262,
    RPAR = 263,
    COMMA = 264,
    INT = 265,
    FLOAT32 = 266,
    BOOL = 267,
    STRING = 268,
    RBRACE = 269,
    LBRACE = 270,
    ASSIGN = 271,
    IF = 272,
    ELSE = 273,
    RETURN = 274,
    FOR = 275,
    PRINT = 276,
    STRLIT = 277,
    BLANKID = 278,
    PARSEINT = 279,
    CMDARGS = 280,
    LSQ = 281,
    RSQ = 282,
    OR = 283,
    AND = 284,
    LT = 285,
    GT = 286,
    EQ = 287,
    NE = 288,
    LE = 289,
    GE = 290,
    PLUS = 291,
    MINUS = 292,
    STAR = 293,
    DIV = 294,
    MOD = 295,
    NOT = 296,
    INTLIT = 297,
    REALLIT = 298,
    FUNC = 299,
    UNARY = 300
  };
#endif
/* Tokens.  */
#define PACKAGE 258
#define ID 259
#define SEMICOLON 260
#define VAR 261
#define LPAR 262
#define RPAR 263
#define COMMA 264
#define INT 265
#define FLOAT32 266
#define BOOL 267
#define STRING 268
#define RBRACE 269
#define LBRACE 270
#define ASSIGN 271
#define IF 272
#define ELSE 273
#define RETURN 274
#define FOR 275
#define PRINT 276
#define STRLIT 277
#define BLANKID 278
#define PARSEINT 279
#define CMDARGS 280
#define LSQ 281
#define RSQ 282
#define OR 283
#define AND 284
#define LT 285
#define GT 286
#define EQ 287
#define NE 288
#define LE 289
#define GE 290
#define PLUS 291
#define MINUS 292
#define STAR 293
#define DIV 294
#define MOD 295
#define NOT 296
#define INTLIT 297
#define REALLIT 298
#define FUNC 299
#define UNARY 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 62 "gocompiler.y"

	char * strlit, * id, * reallit, * intlit;
	void * program;

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
