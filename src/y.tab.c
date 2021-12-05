/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gocompiler.y"

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


#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 80 "gocompiler.y"

	struct tree_node_t * node;

#line 232 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   431

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,    99,   103,   105,   108,   111,   117,   119,
     123,   151,   153,   159,   161,   163,   165,   169,   172,   176,
     180,   187,   193,   197,   204,   208,   215,   217,   222,   224,
     226,   228,   230,   233,   240,   246,   248,   253,   255,   260,
     267,   270,   274,   276,   283,   288,   296,   298,   303,   305,
     309,   312,   317,   321,   328,   332,   335,   339,   346,   348,
     353,   357,   361,   367,   371,   375,   379,   383,   387,   393,
     397,   401,   405,   409,   415,   418,   421,   426,   428,   430,
     432,   434,   438,   442
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PACKAGE", "ID", "SEMICOLON", "VAR",
  "LPAR", "RPAR", "COMMA", "INT", "FLOAT32", "BOOL", "STRING", "RBRACE",
  "LBRACE", "ASSIGN", "IF", "ELSE", "RETURN", "FOR", "PRINT", "STRLIT",
  "BLANKID", "PARSEINT", "CMDARGS", "LSQ", "RSQ", "OR", "AND", "LT", "GT",
  "EQ", "NE", "LE", "GE", "PLUS", "MINUS", "STAR", "DIV", "MOD", "NOT",
  "INTLIT", "REALLIT", "FUNC", "UNARY", "$accept", "Program",
  "Declarations", "VarDeclaration", "VarSpec", "VarSpec_1", "Type",
  "FuncHeader", "FuncDeclaration", "Parameters", "Parameters_1",
  "FuncBody", "VarsAndStatements", "Statement", "Statement_1", "OPT_ELSE",
  "Statement_rep", "ParseArgs", "FuncInvocation", "FuncInvocation_rep",
  "Expr", "Error_1", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,     2,    14,    13,   -66,    -5,    12,    16,   -66,    27,
      20,    35,    48,    37,   -66,    36,    -5,   283,   -66,    -5,
      45,   -66,   -66,   -66,   -66,   -66,   -66,    47,     3,   -66,
     -66,    21,   304,   -66,   354,   129,   129,   114,    46,    60,
      54,    66,   -66,   -66,   -66,   -66,    48,    65,   148,   148,
      68,    62,    71,   129,   -66,   -66,    86,    81,    93,   105,
     129,   129,   129,   -66,   -66,   -66,   217,   391,   375,   243,
      89,   325,   -66,   346,   -66,   -66,    98,   -66,   148,   -66,
     145,   100,    94,   391,   383,   -66,   159,   111,   -66,   -66,
     -66,   375,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   122,   120,   375,   127,   178,
     -66,   -66,   124,   -66,   -66,   -66,   129,   130,   -66,   113,
     -66,   -66,   -66,   125,   204,   229,    77,    77,    77,    77,
      77,    77,    84,    84,   -66,   -66,   -66,   375,   -66,   131,
     -66,   -66,   148,   191,   -66,   137,   134,   -66,   -66,    98,
     -66,     4,   147,   -66,   -66,   123,   155,   375,   129,   -66,
     150,   378,   -66,   160,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     2,     0,
       0,     0,     0,     0,     8,     0,     4,     0,    21,     6,
       0,    13,    14,    15,    16,    10,    11,     0,     0,     5,
      83,     0,     0,    26,     0,     0,    46,     0,     0,     0,
       0,     0,    49,    48,    52,     7,     0,     0,     0,    17,
       0,     0,     0,     0,    31,    35,     0,     0,    79,     0,
       0,     0,     0,    77,    78,    80,     0,    47,     0,     0,
       0,     0,    27,     0,    12,     9,    22,    19,    18,    55,
       0,     0,     0,    34,     0,    36,     0,     0,    76,    75,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,    23,    20,    56,     0,     0,    60,     0,
      38,    81,    82,     0,    61,    62,    63,    64,    67,    68,
      65,    66,    69,    70,    71,    72,    73,     0,    44,     0,
      51,    50,     0,    58,    57,     0,    41,    43,    45,    24,
      59,     0,     0,    39,    25,     0,     0,     0,     0,    54,
       0,     0,    40,     0,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,    15,     8,   156,   157,   -45,   -66,   -66,   -66,
      52,   -66,   -23,    -9,   118,   -66,   -65,   -66,   -17,    61,
     -15,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    39,    14,    25,    26,    10,    11,    50,
     113,    18,    40,   105,    57,   153,   106,    42,    65,   117,
      66,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,     6,    81,    76,    77,    30,     3,    48,    41,    54,
      87,    49,     1,     9,     4,    43,    12,    43,     5,    13,
      15,    67,    69,    41,     9,    56,   123,     9,    51,   155,
      52,    29,    16,   114,    45,    17,    80,    53,    83,     7,
      19,    12,   139,    28,    86,    88,    89,    90,   110,    46,
     111,    43,    47,    70,    43,   109,    43,    20,    21,    22,
      23,    24,    41,    30,    41,    71,    58,    43,    72,    59,
      79,    73,   147,    75,    43,    56,    78,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
      43,    84,   160,    58,    82,    85,    59,   149,    60,    61,
      51,   143,   156,    62,    63,    64,    30,   112,   118,    58,
     119,   108,    59,   100,   101,   102,   103,   104,    58,   122,
      43,    59,   102,   103,   104,    60,    61,   137,   142,    68,
      62,    63,    64,    58,   138,   140,    59,   145,   144,   146,
      43,    60,    61,   161,   151,   148,    62,    63,    64,   158,
      60,    61,   152,   115,   116,    62,    63,    64,    21,    22,
      23,    24,   157,   159,   162,    60,    61,   121,   164,    27,
      62,    63,    64,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   141,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     116,   154,   120,    74,   150,     0,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    91,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   107,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    30,     0,     0,    31,    32,     6,
       0,     0,     0,     0,     0,     0,     0,    33,    34,     0,
      35,     0,    36,    37,    38,    30,     0,     0,    31,    32,
       6,     0,     0,     0,     0,     0,     0,     0,   -28,    34,
       0,    35,     0,    36,    37,    38,    30,     0,     0,    31,
      32,     6,     0,     0,     0,     0,     0,     0,     0,   -29,
      34,     0,    35,     0,    36,    37,    38,    30,     0,     0,
      31,    32,     6,     0,     0,    30,     0,     0,    31,     0,
     -30,    34,     0,    35,     0,    36,    37,    38,    55,    34,
       0,    35,     0,    36,    37,    38,    30,     0,     0,    31,
       0,     0,     0,     0,    30,     0,     0,    31,     0,   -42,
      34,     0,    35,     0,    36,    37,    38,   -37,    34,     0,
      35,     0,    36,    37,    38,   163,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104
};

static const yytype_int16 yycheck[] =
{
      17,     6,    51,    48,    49,     1,     4,     4,    17,    32,
      59,     8,     3,     5,     0,    32,     4,    34,     5,     7,
       4,    36,    37,    32,    16,    34,    91,    19,     7,    25,
       9,    16,     5,    78,    19,    15,    51,    16,    53,    44,
       5,     4,   107,     7,    59,    60,    61,    62,    71,     4,
      73,    68,     5,     7,    71,    70,    73,     9,    10,    11,
      12,    13,    71,     1,    73,     5,     4,    84,    14,     7,
       8,     5,   137,     8,    91,    84,     8,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     107,     5,   157,     4,    23,    14,     7,   142,    36,    37,
       7,   116,   151,    41,    42,    43,     1,     9,     8,     4,
      16,    22,     7,    36,    37,    38,    39,    40,     4,     8,
     137,     7,    38,    39,    40,    36,    37,     5,     4,    15,
      41,    42,    43,     4,    14,     8,     7,    24,     8,    14,
     157,    36,    37,   158,     7,    14,    41,    42,    43,    26,
      36,    37,    18,     8,     9,    41,    42,    43,    10,    11,
      12,    13,    15,     8,    14,    36,    37,     8,     8,    13,
      41,    42,    43,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     8,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       9,   149,    84,    46,   143,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    15,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    15,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     1,    -1,    -1,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,
      17,    -1,    19,    20,    21,     1,    -1,    -1,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      -1,    17,    -1,    19,    20,    21,     1,    -1,    -1,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    -1,    17,    -1,    19,    20,    21,     1,    -1,    -1,
       4,     5,     6,    -1,    -1,     1,    -1,    -1,     4,    -1,
      14,    15,    -1,    17,    -1,    19,    20,    21,    14,    15,
      -1,    17,    -1,    19,    20,    21,     1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,     1,    -1,    -1,     4,    -1,    14,
      15,    -1,    17,    -1,    19,    20,    21,    14,    15,    -1,
      17,    -1,    19,    20,    21,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,     4,     0,     5,     6,    44,    48,    49,
      53,    54,     4,     7,    50,     4,     5,    15,    57,     5,
       9,    10,    11,    12,    13,    51,    52,    50,     7,    48,
       1,     4,     5,    14,    15,    17,    19,    20,    21,    49,
      58,    59,    63,    64,    67,    48,     4,     5,     4,     8,
      55,     7,     9,    16,    58,    14,    59,    60,     4,     7,
      36,    37,    41,    42,    43,    64,    66,    66,    15,    66,
       7,     5,    14,     5,    51,     8,    52,    52,     8,     8,
      66,    67,    23,    66,     5,    14,    66,    67,    66,    66,
      66,    15,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    59,    62,    15,    22,    66,
      58,    58,     9,    56,    52,     8,     9,    65,     8,    16,
      60,     8,     8,    62,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,     5,    14,    62,
       8,     8,     4,    66,     8,    24,    14,    62,    14,    52,
      65,     7,    18,    61,    56,    25,    67,    15,    26,     8,
      62,    66,    14,    27,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    52,    52,    53,    53,    53,
      53,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    59,
      61,    61,    62,    62,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    63,    63,    64,    64,    64,    65,    65,
      64,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     3,     2,     5,
       2,     1,     3,     1,     1,     1,     1,     4,     5,     5,
       6,     2,     2,     3,     3,     4,     2,     3,     1,     2,
       2,     2,     3,     3,     3,     2,     3,     2,     3,     6,
       4,     0,     0,     3,     4,     5,     1,     2,     1,     1,
       4,     4,     1,    11,     8,     3,     4,     5,     2,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     1,     1,     1,
       1,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 96 "gocompiler.y"
                                                                                                                        {(yyval.node) = root = create_node(A_PROGRAM, "Program");
    															push((yyval.node)->children, (yyvsp[0].node));}
#line 1575 "y.tab.c"
    break;

  case 3:
#line 99 "gocompiler.y"
                                                                                                                        {(yyval.node) = root = create_node(A_PROGRAM, "Program");}
#line 1581 "y.tab.c"
    break;

  case 4:
#line 103 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1587 "y.tab.c"
    break;

  case 5:
#line 105 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-2].node);
    															push((yyval.node)->siblings, (yyvsp[0].node));}
#line 1594 "y.tab.c"
    break;

  case 6:
#line 108 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_FUNC_DECL, "FuncDecl");
    															push((yyval.node)->children, (yyvsp[-1].node));}
#line 1601 "y.tab.c"
    break;

  case 7:
#line 111 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_FUNC_DECL, "FuncDecl");
    															push((yyval.node)->children, (yyvsp[-2].node));
    															push((yyval.node)->siblings, (yyvsp[0].node));}
#line 1609 "y.tab.c"
    break;

  case 8:
#line 117 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1615 "y.tab.c"
    break;

  case 9:
#line 119 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-2].node);}
#line 1621 "y.tab.c"
    break;

  case 10:
#line 123 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_VAR_DECL, "VarDecl");
    															push((yyval.node)->children, create_node(A_ID, (yyvsp[-1].node)->id));
    															push((yyval.node)->children, (yyvsp[0].node));

															struct list_node_t * father = (yyval.node)->children->next->next;
															while(1) {
																if(father->data->children->next == NULL) break;
																father = father->data->children->next->next;
															}
															struct tree_node_t * help = father->data;

															father = (yyval.node)->children->next->next;
															while(1) {
																if(father->data->children->next == NULL) break;
																struct tree_node_t * new_node = create_node(A_VAR_DECL, "VarDecl");
																push(new_node->children, help);
																push(new_node->children, create_node(A_ID, father->data->children->next->data->id));

																push((yyval.node)->siblings, new_node);
																father = father->data->children->next->next;
															}

															(yyval.node)->children->next->next->data = (yyval.node)->children->next->data;
															(yyval.node)->children->next->data = help;
															}
#line 1651 "y.tab.c"
    break;

  case 11:
#line 151 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1657 "y.tab.c"
    break;

  case 12:
#line 153 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_VAR_DECL, "VarDecl");
     															push((yyval.node)->children, create_node(A_ID, (yyvsp[-1].node)->id));
     															push((yyval.node)->children, (yyvsp[0].node));}
#line 1665 "y.tab.c"
    break;

  case 13:
#line 159 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_INT, "Int");}
#line 1671 "y.tab.c"
    break;

  case 14:
#line 161 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_FLOAT32, "Float32");}
#line 1677 "y.tab.c"
    break;

  case 15:
#line 163 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_BOOL, "Bool");}
#line 1683 "y.tab.c"
    break;

  case 16:
#line 165 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_STRING, "String");}
#line 1689 "y.tab.c"
    break;

  case 17:
#line 169 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_ID, (yyvsp[-2].node)->id);
															push((yyval.node)->siblings, create_node(A_FUNC_PARAMS, "FuncParams"));}
#line 1696 "y.tab.c"
    break;

  case 18:
#line 172 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_ID, (yyvsp[-3].node)->id);
    															push((yyval.node)->siblings, create_node(A_FUNC_PARAMS, "FuncParams"));
															push((yyval.node)->siblings->next->data->children, (yyvsp[-1].node));}
#line 1704 "y.tab.c"
    break;

  case 19:
#line 176 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_ID, (yyvsp[-3].node)->id);
    															push((yyval.node)->siblings, (yyvsp[0].node));
    															push((yyval.node)->siblings, create_node(A_FUNC_PARAMS, "FuncParams"));}
#line 1712 "y.tab.c"
    break;

  case 20:
#line 180 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_ID, (yyvsp[-4].node)->id);
															push((yyval.node)->siblings, (yyvsp[0].node));
															push((yyval.node)->siblings, create_node(A_FUNC_PARAMS, "FuncParams"));
															push((yyval.node)->siblings->next->next->data->children, (yyvsp[-2].node));}
#line 1721 "y.tab.c"
    break;

  case 21:
#line 187 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_FUNC_HEADER, "FuncHeader");
    															push((yyval.node)->children, (yyvsp[-1].node));
    															push((yyval.node)->siblings, (yyvsp[0].node));}
#line 1729 "y.tab.c"
    break;

  case 22:
#line 193 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_PARAM_DECL, "ParamDecl");
    															push((yyval.node)->children, (yyvsp[0].node));
    															push((yyval.node)->children, create_node(A_ID, (yyvsp[-1].node)->id));}
#line 1737 "y.tab.c"
    break;

  case 23:
#line 197 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_PARAM_DECL, "ParamDecl");
    															push((yyval.node)->children, (yyvsp[-1].node));
    															push((yyval.node)->children, create_node(A_ID, (yyvsp[-2].node)->id));
    															push((yyval.node)->siblings, (yyvsp[0].node));}
#line 1746 "y.tab.c"
    break;

  case 24:
#line 204 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_PARAM_DECL, "ParamDecl");
    															push((yyval.node)->children, (yyvsp[0].node));
    															push((yyval.node)->children, create_node(A_ID, (yyvsp[-1].node)->id));}
#line 1754 "y.tab.c"
    break;

  case 25:
#line 208 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_PARAM_DECL, "ParamDecl");
    															push((yyval.node)->children, (yyvsp[-1].node));
    															push((yyval.node)->children, create_node(A_ID, (yyvsp[-2].node)->id));
    															push((yyval.node)->siblings, (yyvsp[0].node));}
#line 1763 "y.tab.c"
    break;

  case 26:
#line 215 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_FUNC_BODY, "FuncBody");}
#line 1769 "y.tab.c"
    break;

  case 27:
#line 217 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_FUNC_BODY, "FuncBody");
    															push((yyval.node)->children, (yyvsp[-1].node));}
#line 1776 "y.tab.c"
    break;

  case 28:
#line 222 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_INVALID_NODE, "NO");}
#line 1782 "y.tab.c"
    break;

  case 29:
#line 224 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1788 "y.tab.c"
    break;

  case 30:
#line 226 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1794 "y.tab.c"
    break;

  case 31:
#line 228 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1800 "y.tab.c"
    break;

  case 32:
#line 230 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-2].node);
    															push((yyval.node)->siblings, (yyvsp[0].node));}
#line 1807 "y.tab.c"
    break;

  case 33:
#line 233 "gocompiler.y"
                                                                                                                        {if(!yacc_error){
    																(yyval.node) = (yyvsp[-2].node);
    																push((yyval.node)->siblings, (yyvsp[0].node));
    															};}
#line 1816 "y.tab.c"
    break;

  case 34:
#line 240 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_ASSIGN, "Assign");
    															push((yyval.node)->children, create_node(A_ID, (yyvsp[-2].node)->id));
    															push((yyval.node)->children, (yyvsp[0].node));}
#line 1824 "y.tab.c"
    break;

  case 35:
#line 246 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_INVALID_NODE, "Block");}
#line 1830 "y.tab.c"
    break;

  case 36:
#line 248 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_PROB_BLOCK, "Block");
    															push((yyval.node)->children, (yyvsp[-1].node));}
#line 1837 "y.tab.c"
    break;

  case 37:
#line 253 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1843 "y.tab.c"
    break;

  case 38:
#line 255 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-2].node);
    															push((yyvsp[-2].node)->siblings, (yyvsp[0].node));}
#line 1850 "y.tab.c"
    break;

  case 39:
#line 260 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_IF, "If");
		 													push((yyval.node)->children, (yyvsp[-4].node));
		 													push((yyval.node)->children, create_node(A_BLOCK, "Block"));
		 													push((yyval.node)->children->next->next->data->children, (yyvsp[-2].node));
		 													push((yyval.node)->children, (yyvsp[0].node));}
#line 1860 "y.tab.c"
    break;

  case 40:
#line 267 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_BLOCK, "Block");
															push((yyval.node)->children, (yyvsp[-1].node));}
#line 1867 "y.tab.c"
    break;

  case 41:
#line 270 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_BLOCK, "Block");}
#line 1873 "y.tab.c"
    break;

  case 42:
#line 274 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_INVALID_NODE, "NO");}
#line 1879 "y.tab.c"
    break;

  case 43:
#line 276 "gocompiler.y"
                                                                                                                        {if(!yacc_error){
															(yyval.node) = (yyvsp[-2].node);
															push((yyvsp[-2].node)->siblings, (yyvsp[0].node));
															};}
#line 1888 "y.tab.c"
    break;

  case 44:
#line 283 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_FOR, "For");
															push((yyval.node)->children, create_node(A_BLOCK, "Block"));
															push((yyval.node)->children->next->data->children, (yyvsp[-1].node));
															}
#line 1897 "y.tab.c"
    break;

  case 45:
#line 288 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_FOR, "For");
															push((yyval.node)->children, (yyvsp[-3].node));
															push((yyval.node)->children, create_node(A_BLOCK, "Block"));
															push((yyval.node)->children->next->next->data->children, (yyvsp[-1].node));
															}
#line 1907 "y.tab.c"
    break;

  case 46:
#line 296 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_RETURN, "Return");}
#line 1913 "y.tab.c"
    break;

  case 47:
#line 298 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_RETURN, "Return");
    															push((yyval.node)->children, (yyvsp[0].node));}
#line 1920 "y.tab.c"
    break;

  case 48:
#line 303 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1926 "y.tab.c"
    break;

  case 49:
#line 305 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1932 "y.tab.c"
    break;

  case 50:
#line 309 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_PRINT, "Print");
    															push((yyval.node)->children, (yyvsp[-1].node));}
#line 1939 "y.tab.c"
    break;

  case 51:
#line 312 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_PRINT, "Print");
    															push((yyval.node)->children, create_node(A_STRLIT, (yyvsp[-1].node)->id));}
#line 1946 "y.tab.c"
    break;

  case 52:
#line 317 "gocompiler.y"
                                                                                                                        {;}
#line 1952 "y.tab.c"
    break;

  case 53:
#line 321 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_PARSE_ARGS, "ParseArgs");
															push((yyval.node)->children, create_node(A_ID, (yyvsp[-10].node)->id));
															push((yyval.node)->children, (yyvsp[-2].node));
															}
#line 1961 "y.tab.c"
    break;

  case 54:
#line 328 "gocompiler.y"
                                                                                                                        {;}
#line 1967 "y.tab.c"
    break;

  case 55:
#line 332 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_CALL, "Call");
    															push((yyval.node)->children, create_node(A_ID, (yyvsp[-2].node)->id));}
#line 1974 "y.tab.c"
    break;

  case 56:
#line 335 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_CALL, "Call");
															push((yyval.node)->children, create_node(A_ID, (yyvsp[-3].node)->id));
															push((yyval.node)->children, (yyvsp[-1].node));}
#line 1982 "y.tab.c"
    break;

  case 57:
#line 339 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_CALL, "Call");
															push((yyval.node)->children, create_node(A_ID, (yyvsp[-4].node)->id));
															push((yyval.node)->children, (yyvsp[-2].node));
															push((yyval.node)->children, (yyvsp[-1].node));}
#line 1991 "y.tab.c"
    break;

  case 58:
#line 346 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1997 "y.tab.c"
    break;

  case 59:
#line 348 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);
    															push((yyval.node)->siblings, (yyvsp[0].node));}
#line 2004 "y.tab.c"
    break;

  case 60:
#line 353 "gocompiler.y"
                                                                                                                        {;}
#line 2010 "y.tab.c"
    break;

  case 61:
#line 357 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_OR, "Or");
    															push((yyval.node)->children, (yyvsp[-2].node));
    															push((yyval.node)->children, (yyvsp[0].node));}
#line 2018 "y.tab.c"
    break;

  case 62:
#line 361 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_AND, "And");
    															push((yyval.node)->children, (yyvsp[-2].node));
    															push((yyval.node)->children, (yyvsp[0].node));}
#line 2026 "y.tab.c"
    break;

  case 63:
#line 367 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_LT, "Lt");
    															push((yyval.node)->children, (yyvsp[-2].node));
    															push((yyval.node)->children, (yyvsp[0].node));}
#line 2034 "y.tab.c"
    break;

  case 64:
#line 371 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_GT, "Gt");
															push((yyval.node)->children, (yyvsp[-2].node));
															push((yyval.node)->children, (yyvsp[0].node));}
#line 2042 "y.tab.c"
    break;

  case 65:
#line 375 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_LE, "Le");
															push((yyval.node)->children, (yyvsp[-2].node));
															push((yyval.node)->children, (yyvsp[0].node));}
#line 2050 "y.tab.c"
    break;

  case 66:
#line 379 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_GE, "Ge");
															push((yyval.node)->children, (yyvsp[-2].node));
															push((yyval.node)->children, (yyvsp[0].node));}
#line 2058 "y.tab.c"
    break;

  case 67:
#line 383 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_EQ, "Eq");
															push((yyval.node)->children, (yyvsp[-2].node));
															push((yyval.node)->children, (yyvsp[0].node));}
#line 2066 "y.tab.c"
    break;

  case 68:
#line 387 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_NE, "Ne");
															push((yyval.node)->children, (yyvsp[-2].node));
															push((yyval.node)->children, (yyvsp[0].node));}
#line 2074 "y.tab.c"
    break;

  case 69:
#line 393 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_ADD, "Add");
															push((yyval.node)->children, (yyvsp[-2].node));
															push((yyval.node)->children, (yyvsp[0].node));}
#line 2082 "y.tab.c"
    break;

  case 70:
#line 397 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_SUB, "Sub");
															push((yyval.node)->children, (yyvsp[-2].node));
															push((yyval.node)->children, (yyvsp[0].node));}
#line 2090 "y.tab.c"
    break;

  case 71:
#line 401 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_MUL, "Mul");
															push((yyval.node)->children, (yyvsp[-2].node));
															push((yyval.node)->children, (yyvsp[0].node));}
#line 2098 "y.tab.c"
    break;

  case 72:
#line 405 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_DIV, "Div");
															push((yyval.node)->children, (yyvsp[-2].node));
															push((yyval.node)->children, (yyvsp[0].node));}
#line 2106 "y.tab.c"
    break;

  case 73:
#line 409 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_MOD, "Mod");
    															push((yyval.node)->children, (yyvsp[-2].node));
    															push((yyval.node)->children, (yyvsp[0].node));}
#line 2114 "y.tab.c"
    break;

  case 74:
#line 415 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_NOT, "Not");
    															push((yyval.node)->children, (yyvsp[0].node));}
#line 2121 "y.tab.c"
    break;

  case 75:
#line 418 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_MINUS, "Minus");
    															push((yyval.node)->children, (yyvsp[0].node));}
#line 2128 "y.tab.c"
    break;

  case 76:
#line 421 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_PLUS, "Plus");
    															push((yyval.node)->children, (yyvsp[0].node));}
#line 2135 "y.tab.c"
    break;

  case 77:
#line 426 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_INTLIT, (yyvsp[0].node)->id);}
#line 2141 "y.tab.c"
    break;

  case 78:
#line 428 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_REALLIT, (yyvsp[0].node)->id);}
#line 2147 "y.tab.c"
    break;

  case 79:
#line 430 "gocompiler.y"
                                                                                                                        {(yyval.node) = create_node(A_ID, (yyvsp[0].node)->id);}
#line 2153 "y.tab.c"
    break;

  case 80:
#line 432 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 2159 "y.tab.c"
    break;

  case 81:
#line 434 "gocompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2165 "y.tab.c"
    break;

  case 82:
#line 438 "gocompiler.y"
                                                                                                                        {;}
#line 2171 "y.tab.c"
    break;

  case 83:
#line 442 "gocompiler.y"
                                                                                                                        {;}
#line 2177 "y.tab.c"
    break;


#line 2181 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 444 "gocompiler.y"

