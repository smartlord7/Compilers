/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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


#line 88 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PACKAGE = 258,                 /* PACKAGE  */
    ID = 259,                      /* ID  */
    SEMICOLON = 260,               /* SEMICOLON  */
    VAR = 261,                     /* VAR  */
    LPAR = 262,                    /* LPAR  */
    RPAR = 263,                    /* RPAR  */
    COMMA = 264,                   /* COMMA  */
    INT = 265,                     /* INT  */
    FLOAT32 = 266,                 /* FLOAT32  */
    BOOL = 267,                    /* BOOL  */
    STRING = 268,                  /* STRING  */
    RBRACE = 269,                  /* RBRACE  */
    LBRACE = 270,                  /* LBRACE  */
    ASSIGN = 271,                  /* ASSIGN  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    RETURN = 274,                  /* RETURN  */
    FOR = 275,                     /* FOR  */
    PRINT = 276,                   /* PRINT  */
    STRLIT = 277,                  /* STRLIT  */
    BLANKID = 278,                 /* BLANKID  */
    PARSEINT = 279,                /* PARSEINT  */
    CMDARGS = 280,                 /* CMDARGS  */
    LSQ = 281,                     /* LSQ  */
    RSQ = 282,                     /* RSQ  */
    OR = 283,                      /* OR  */
    AND = 284,                     /* AND  */
    LT = 285,                      /* LT  */
    GT = 286,                      /* GT  */
    EQ = 287,                      /* EQ  */
    NE = 288,                      /* NE  */
    LE = 289,                      /* LE  */
    GE = 290,                      /* GE  */
    PLUS = 291,                    /* PLUS  */
    MINUS = 292,                   /* MINUS  */
    STAR = 293,                    /* STAR  */
    DIV = 294,                     /* DIV  */
    MOD = 295,                     /* MOD  */
    NOT = 296,                     /* NOT  */
    INTLIT = 297,                  /* INTLIT  */
    REALLIT = 298,                 /* REALLIT  */
    FUNC = 299                     /* FUNC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 63 "gocompiler.y"

	char * strlit, * id, * reallit, * intlit;
	void * program;

#line 234 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PACKAGE = 3,                    /* PACKAGE  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_SEMICOLON = 5,                  /* SEMICOLON  */
  YYSYMBOL_VAR = 6,                        /* VAR  */
  YYSYMBOL_LPAR = 7,                       /* LPAR  */
  YYSYMBOL_RPAR = 8,                       /* RPAR  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_FLOAT32 = 11,                   /* FLOAT32  */
  YYSYMBOL_BOOL = 12,                      /* BOOL  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_RBRACE = 14,                    /* RBRACE  */
  YYSYMBOL_LBRACE = 15,                    /* LBRACE  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_PRINT = 21,                     /* PRINT  */
  YYSYMBOL_STRLIT = 22,                    /* STRLIT  */
  YYSYMBOL_BLANKID = 23,                   /* BLANKID  */
  YYSYMBOL_PARSEINT = 24,                  /* PARSEINT  */
  YYSYMBOL_CMDARGS = 25,                   /* CMDARGS  */
  YYSYMBOL_LSQ = 26,                       /* LSQ  */
  YYSYMBOL_RSQ = 27,                       /* RSQ  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_LT = 30,                        /* LT  */
  YYSYMBOL_GT = 31,                        /* GT  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_NE = 33,                        /* NE  */
  YYSYMBOL_LE = 34,                        /* LE  */
  YYSYMBOL_GE = 35,                        /* GE  */
  YYSYMBOL_PLUS = 36,                      /* PLUS  */
  YYSYMBOL_MINUS = 37,                     /* MINUS  */
  YYSYMBOL_STAR = 38,                      /* STAR  */
  YYSYMBOL_DIV = 39,                       /* DIV  */
  YYSYMBOL_MOD = 40,                       /* MOD  */
  YYSYMBOL_NOT = 41,                       /* NOT  */
  YYSYMBOL_INTLIT = 42,                    /* INTLIT  */
  YYSYMBOL_REALLIT = 43,                   /* REALLIT  */
  YYSYMBOL_FUNC = 44,                      /* FUNC  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_Program = 46,                   /* Program  */
  YYSYMBOL_Declarations = 47,              /* Declarations  */
  YYSYMBOL_VarDeclaration = 48,            /* VarDeclaration  */
  YYSYMBOL_VarSpec = 49,                   /* VarSpec  */
  YYSYMBOL_VarSpec_1 = 50,                 /* VarSpec_1  */
  YYSYMBOL_Type = 51,                      /* Type  */
  YYSYMBOL_FuncDeclaration = 52,           /* FuncDeclaration  */
  YYSYMBOL_Parameters = 53,                /* Parameters  */
  YYSYMBOL_Parameters_1 = 54,              /* Parameters_1  */
  YYSYMBOL_FuncBody = 55,                  /* FuncBody  */
  YYSYMBOL_VarsAndStatements = 56,         /* VarsAndStatements  */
  YYSYMBOL_Statement = 57,                 /* Statement  */
  YYSYMBOL_Statement_1 = 58,               /* Statement_1  */
  YYSYMBOL_OPT_ELSE = 59,                  /* OPT_ELSE  */
  YYSYMBOL_Statement_rep = 60,             /* Statement_rep  */
  YYSYMBOL_ParseArgs = 61,                 /* ParseArgs  */
  YYSYMBOL_FuncInvocation = 62,            /* FuncInvocation  */
  YYSYMBOL_FuncInvocation_rep = 63,        /* FuncInvocation_rep  */
  YYSYMBOL_Expr = 64                       /* Expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    81,    85,    87,    89,    91,    95,    97,
     101,   105,   107,   111,   113,   115,   117,   121,   123,   125,
     127,   131,   133,   137,   139,   143,   145,   149,   151,   153,
     155,   157,   159,   163,   167,   169,   173,   175,   181,   190,
     192,   196,   198,   202,   204,   208,   210,   214,   216,   220,
     222,   226,   230,   234,   238,   240,   242,   246,   248,   252,
     256,   258,   262,   264,   266,   268,   270,   272,   276,   278,
     280,   282,   284,   288,   290,   292,   296,   298,   300,   302,
     304,   308
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PACKAGE", "ID",
  "SEMICOLON", "VAR", "LPAR", "RPAR", "COMMA", "INT", "FLOAT32", "BOOL",
  "STRING", "RBRACE", "LBRACE", "ASSIGN", "IF", "ELSE", "RETURN", "FOR",
  "PRINT", "STRLIT", "BLANKID", "PARSEINT", "CMDARGS", "LSQ", "RSQ", "OR",
  "AND", "LT", "GT", "EQ", "NE", "LE", "GE", "PLUS", "MINUS", "STAR",
  "DIV", "MOD", "NOT", "INTLIT", "REALLIT", "FUNC", "$accept", "Program",
  "Declarations", "VarDeclaration", "VarSpec", "VarSpec_1", "Type",
  "FuncDeclaration", "Parameters", "Parameters_1", "FuncBody",
  "VarsAndStatements", "Statement", "Statement_1", "OPT_ELSE",
  "Statement_rep", "ParseArgs", "FuncInvocation", "FuncInvocation_rep",
  "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
#endif

#define YYPACT_NINF (-96)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,    -1,    22,    25,   -96,    -5,    65,    28,   -96,    32,
      42,    77,    48,   -96,    66,    -5,    -5,    72,   -96,   -96,
     -96,   -96,   -96,   -96,    75,    34,   -96,   -96,    77,    73,
     189,   134,    76,   -96,   -96,    74,   122,    79,   -96,   134,
      89,   -96,   -96,    44,   280,   -96,   330,   126,   126,    55,
      88,   100,    92,   102,   -96,   -96,   -96,    79,   -96,   189,
      67,    90,   126,   -96,   -96,   107,   103,   111,    78,   126,
     126,   126,   -96,   -96,   -96,   214,   367,   351,   240,   118,
     301,   -96,   322,   -96,    74,   116,   -96,   142,   113,   367,
     359,   -96,   123,   156,   -96,   -96,   -96,   351,   126,   126,
     -96,   -96,   -96,   -96,   -96,   -96,   126,   126,   126,   126,
     126,   127,   120,   351,   130,   175,   -96,   -96,   -96,   -96,
     -96,   126,   140,   128,   -96,   -96,   -96,   121,   201,   226,
      62,    62,   -96,   -96,   -96,   351,   -96,   139,   -96,   -96,
     188,   -96,   149,   147,   -96,   -96,   -96,     8,   143,   -96,
     158,   131,   351,   -96,   126,   184,   354,   -96,   259,   -96
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     2,     0,
       0,     0,     0,     8,     0,     4,     6,     0,    13,    14,
      15,    16,    10,    11,     0,     0,     5,     7,     0,     0,
       0,     0,     0,    12,     9,    21,     0,     0,    17,     0,
       0,    22,    51,     0,     0,    25,     0,     0,    45,     0,
       0,     0,     0,     0,    48,    47,    19,     0,    18,     0,
       0,     0,     0,    30,    34,     0,     0,    78,     0,     0,
       0,     0,    76,    77,    79,     0,    46,     0,     0,     0,
       0,    26,     0,    20,    23,     0,    54,     0,     0,    33,
       0,    35,     0,     0,    75,    74,    73,     0,     0,     0,
      62,    63,    66,    67,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,    24,    59,
      55,     0,     0,     0,    37,    81,    80,     0,    60,    61,
      68,    69,    70,    71,    72,     0,    43,     0,    50,    49,
      57,    56,     0,    40,    42,    44,    58,     0,     0,    38,
       0,     0,     0,    53,     0,     0,     0,    39,     0,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   -96,     0,    19,   270,   255,   -10,   -96,   -96,   203,
     -26,   -37,   -32,   198,   -96,   -95,   -96,   -36,   150,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,    51,    13,    22,    23,    10,    32,    41,
      38,    52,   111,    66,   149,   112,    54,    74,   122,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,     6,   127,     3,    53,    76,    78,    63,    55,   150,
      55,    56,    53,    58,    65,    26,    27,    87,   137,    89,
      35,    37,     4,     1,     9,    93,    94,    95,    96,    57,
       5,    83,    14,   151,     9,     9,   115,    15,    30,     7,
     144,    55,    31,   116,    55,   117,    55,    16,    53,    84,
      53,    60,    11,    61,    55,   128,   129,   155,    65,    67,
      62,    55,    68,   130,   131,   132,   133,   134,    85,    11,
      77,    67,    12,    25,    68,    86,    28,    55,   140,    92,
      29,    34,    67,    40,    39,    68,    17,    18,    19,    20,
      21,    69,    70,    59,    36,    79,    71,    72,    73,    55,
     108,   109,   110,    69,    70,    80,    81,    82,    71,    72,
      73,   156,    90,    88,    69,    70,    55,    91,    60,    71,
      72,    73,    67,    42,   119,    68,    43,    44,     6,   123,
      67,   125,   135,    68,   136,   143,    45,    46,   138,    47,
     114,    48,    49,    50,    18,    19,    20,    21,   141,    36,
     120,   121,   142,   145,    69,    70,   147,   154,   152,    71,
      72,    73,    69,    70,   126,   148,   153,    71,    72,    73,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   139,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   121,   157,    18,
      19,    20,    21,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    97,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   113,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   159,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    42,    24,    33,    43,    44,     6,   118,   124,     0,
     146,     0,     0,     0,   -27,    46,     0,    47,     0,    48,
      49,    50,    42,     0,     0,    43,    44,     6,     0,     0,
       0,     0,     0,     0,     0,   -28,    46,     0,    47,     0,
      48,    49,    50,    42,     0,     0,    43,    44,     6,     0,
       0,    42,     0,     0,    43,     0,   -29,    46,     0,    47,
       0,    48,    49,    50,    64,    46,     0,    47,     0,    48,
      49,    50,    42,     0,     0,    43,     0,     0,     0,     0,
      42,     0,     0,    43,     0,   -41,    46,     0,    47,     0,
      48,    49,    50,   -36,    46,     0,    47,     0,    48,    49,
      50,   158,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110
};

static const yytype_int16 yycheck[] =
{
      36,     6,    97,     4,    36,    48,    49,    44,    44,     1,
      46,    37,    44,    39,    46,    15,    16,    60,   113,    62,
      30,    31,     0,     3,     5,    68,    69,    70,    71,    39,
       5,    57,     4,    25,    15,    16,    79,     5,     4,    44,
     135,    77,     8,    80,    80,    82,    82,     5,    80,    59,
      82,     7,     4,     9,    90,    98,    99,   152,    90,     4,
      16,    97,     7,   106,   107,   108,   109,   110,     1,     4,
      15,     4,     7,     7,     7,     8,     4,   113,   121,     1,
       5,     8,     4,     9,     8,     7,     9,    10,    11,    12,
      13,    36,    37,     4,    15,     7,    41,    42,    43,   135,
      38,    39,    40,    36,    37,     5,    14,     5,    41,    42,
      43,   154,     5,    23,    36,    37,   152,    14,     7,    41,
      42,    43,     4,     1,     8,     7,     4,     5,     6,    16,
       4,     8,     5,     7,    14,    14,    14,    15,     8,    17,
      22,    19,    20,    21,    10,    11,    12,    13,     8,    15,
       8,     9,    24,    14,    36,    37,     7,    26,    15,    41,
      42,    43,    36,    37,     8,    18,     8,    41,    42,    43,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     8,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     9,    14,    10,
      11,    12,    13,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    15,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    15,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     8,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     1,    12,    28,     4,     5,     6,    84,    90,    -1,
     140,    -1,    -1,    -1,    14,    15,    -1,    17,    -1,    19,
      20,    21,     1,    -1,    -1,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    17,    -1,
      19,    20,    21,     1,    -1,    -1,     4,     5,     6,    -1,
      -1,     1,    -1,    -1,     4,    -1,    14,    15,    -1,    17,
      -1,    19,    20,    21,    14,    15,    -1,    17,    -1,    19,
      20,    21,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
       1,    -1,    -1,     4,    -1,    14,    15,    -1,    17,    -1,
      19,    20,    21,    14,    15,    -1,    17,    -1,    19,    20,
      21,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    46,     4,     0,     5,     6,    44,    47,    48,
      52,     4,     7,    49,     4,     5,     5,     9,    10,    11,
      12,    13,    50,    51,    49,     7,    47,    47,     4,     5,
       4,     8,    53,    50,     8,    51,    15,    51,    55,     8,
       9,    54,     1,     4,     5,    14,    15,    17,    19,    20,
      21,    48,    56,    57,    61,    62,    55,    51,    55,     4,
       7,     9,    16,    56,    14,    57,    58,     4,     7,    36,
      37,    41,    42,    43,    62,    64,    64,    15,    64,     7,
       5,    14,     5,    55,    51,     1,     8,    64,    23,    64,
       5,    14,     1,    64,    64,    64,    64,    15,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    57,    60,    15,    22,    64,    56,    56,    54,     8,
       8,     9,    63,    16,    58,     8,     8,    60,    64,    64,
      64,    64,    64,    64,    64,     5,    14,    60,     8,     8,
      64,     8,    24,    14,    60,    14,    63,     7,    18,    59,
       1,    25,    15,     8,    26,    60,    64,    14,    27,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    47,    47,    48,    48,
      49,    50,    50,    51,    51,    51,    51,    52,    52,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    58,    58,    57,    59,
      59,    60,    60,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    61,    61,    62,    62,    62,    63,    63,    62,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     3,     2,     5,
       2,     1,     3,     1,     1,     1,     1,     5,     6,     6,
       7,     2,     3,     3,     4,     2,     3,     1,     2,     2,
       2,     3,     3,     3,     2,     3,     2,     3,     6,     4,
       0,     0,     3,     4,     5,     1,     2,     1,     1,     4,
       4,     1,    11,     8,     3,     4,     5,     2,     3,     4,
       3,     3,     2,     2,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     2,     2,     2,     1,     1,     1,     1,
       3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Program: PACKAGE ID SEMICOLON Declarations  */
#line 79 "gocompiler.y"
                                                                                                                        {;}
#line 1436 "y.tab.c"
    break;

  case 3: /* Program: PACKAGE ID SEMICOLON  */
#line 81 "gocompiler.y"
                                                                                                                        {;}
#line 1442 "y.tab.c"
    break;

  case 4: /* Declarations: VarDeclaration SEMICOLON  */
#line 85 "gocompiler.y"
                                                                                                                        {;}
#line 1448 "y.tab.c"
    break;

  case 5: /* Declarations: VarDeclaration SEMICOLON Declarations  */
#line 87 "gocompiler.y"
                                                                                                                        {;}
#line 1454 "y.tab.c"
    break;

  case 6: /* Declarations: FuncDeclaration SEMICOLON  */
#line 89 "gocompiler.y"
                                                                                                                        {;}
#line 1460 "y.tab.c"
    break;

  case 7: /* Declarations: FuncDeclaration SEMICOLON Declarations  */
#line 91 "gocompiler.y"
                                                                                                                        {;}
#line 1466 "y.tab.c"
    break;

  case 8: /* VarDeclaration: VAR VarSpec  */
#line 95 "gocompiler.y"
                                                                                                                        {;}
#line 1472 "y.tab.c"
    break;

  case 9: /* VarDeclaration: VAR LPAR VarSpec SEMICOLON RPAR  */
#line 97 "gocompiler.y"
                                                                                                                        {;}
#line 1478 "y.tab.c"
    break;

  case 10: /* VarSpec: ID VarSpec_1  */
#line 101 "gocompiler.y"
                                                                                                                        {;}
#line 1484 "y.tab.c"
    break;

  case 11: /* VarSpec_1: Type  */
#line 105 "gocompiler.y"
                                                                                                                        {;}
#line 1490 "y.tab.c"
    break;

  case 12: /* VarSpec_1: COMMA ID VarSpec_1  */
#line 107 "gocompiler.y"
                                                                                                                        {;}
#line 1496 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 111 "gocompiler.y"
                                                                                                                        {;}
#line 1502 "y.tab.c"
    break;

  case 14: /* Type: FLOAT32  */
#line 113 "gocompiler.y"
                                                                                                                        {;}
#line 1508 "y.tab.c"
    break;

  case 15: /* Type: BOOL  */
#line 115 "gocompiler.y"
                                                                                                                        {;}
#line 1514 "y.tab.c"
    break;

  case 16: /* Type: STRING  */
#line 117 "gocompiler.y"
                                                                                                                        {;}
#line 1520 "y.tab.c"
    break;

  case 17: /* FuncDeclaration: FUNC ID LPAR RPAR FuncBody  */
#line 121 "gocompiler.y"
                                                                                                                        {;}
#line 1526 "y.tab.c"
    break;

  case 18: /* FuncDeclaration: FUNC ID LPAR Parameters RPAR FuncBody  */
#line 123 "gocompiler.y"
                                                                                                                        {;}
#line 1532 "y.tab.c"
    break;

  case 19: /* FuncDeclaration: FUNC ID LPAR RPAR Type FuncBody  */
#line 125 "gocompiler.y"
                                                                                                                        {;}
#line 1538 "y.tab.c"
    break;

  case 20: /* FuncDeclaration: FUNC ID LPAR Parameters RPAR Type FuncBody  */
#line 127 "gocompiler.y"
                                                                                                                        {;}
#line 1544 "y.tab.c"
    break;

  case 21: /* Parameters: ID Type  */
#line 131 "gocompiler.y"
                                                                                                                        {;}
#line 1550 "y.tab.c"
    break;

  case 22: /* Parameters: ID Type Parameters_1  */
#line 133 "gocompiler.y"
                                                                                                                        {;}
#line 1556 "y.tab.c"
    break;

  case 23: /* Parameters_1: COMMA ID Type  */
#line 137 "gocompiler.y"
                                                                                                                        {;}
#line 1562 "y.tab.c"
    break;

  case 24: /* Parameters_1: COMMA ID Type Parameters_1  */
#line 139 "gocompiler.y"
                                                                                                                        {;}
#line 1568 "y.tab.c"
    break;

  case 25: /* FuncBody: LBRACE RBRACE  */
#line 143 "gocompiler.y"
                                                                                                                        {;}
#line 1574 "y.tab.c"
    break;

  case 26: /* FuncBody: LBRACE VarsAndStatements RBRACE  */
#line 145 "gocompiler.y"
                                                                                                                        {;}
#line 1580 "y.tab.c"
    break;

  case 27: /* VarsAndStatements: SEMICOLON  */
#line 149 "gocompiler.y"
                                                                                                                        {;}
#line 1586 "y.tab.c"
    break;

  case 28: /* VarsAndStatements: VarDeclaration SEMICOLON  */
#line 151 "gocompiler.y"
                                                                                                                        {;}
#line 1592 "y.tab.c"
    break;

  case 29: /* VarsAndStatements: Statement SEMICOLON  */
#line 153 "gocompiler.y"
                                                                                                                        {;}
#line 1598 "y.tab.c"
    break;

  case 30: /* VarsAndStatements: SEMICOLON VarsAndStatements  */
#line 155 "gocompiler.y"
                                                                                                                        {;}
#line 1604 "y.tab.c"
    break;

  case 31: /* VarsAndStatements: VarDeclaration SEMICOLON VarsAndStatements  */
#line 157 "gocompiler.y"
                                                                                                                        {;}
#line 1610 "y.tab.c"
    break;

  case 32: /* VarsAndStatements: Statement SEMICOLON VarsAndStatements  */
#line 159 "gocompiler.y"
                                                                                                                        {;}
#line 1616 "y.tab.c"
    break;

  case 33: /* Statement: ID ASSIGN Expr  */
#line 163 "gocompiler.y"
                                                                                                                        {;}
#line 1622 "y.tab.c"
    break;

  case 34: /* Statement: LBRACE RBRACE  */
#line 167 "gocompiler.y"
                                                                                                                        {;}
#line 1628 "y.tab.c"
    break;

  case 35: /* Statement: LBRACE Statement_1 RBRACE  */
#line 169 "gocompiler.y"
                                                                                                                        {;}
#line 1634 "y.tab.c"
    break;

  case 36: /* Statement_1: Statement SEMICOLON  */
#line 173 "gocompiler.y"
                                                                                                                        {;}
#line 1640 "y.tab.c"
    break;

  case 37: /* Statement_1: Statement SEMICOLON Statement_1  */
#line 175 "gocompiler.y"
                                                                                                                        {;}
#line 1646 "y.tab.c"
    break;

  case 38: /* Statement: IF Expr LBRACE Statement_rep RBRACE OPT_ELSE  */
#line 181 "gocompiler.y"
                                                                                                                        {;}
#line 1652 "y.tab.c"
    break;

  case 39: /* OPT_ELSE: ELSE LBRACE Statement_rep RBRACE  */
#line 190 "gocompiler.y"
                                                 {39;}
#line 1658 "y.tab.c"
    break;

  case 40: /* OPT_ELSE: %empty  */
#line 192 "gocompiler.y"
                                                                                                                        {;}
#line 1664 "y.tab.c"
    break;

  case 41: /* Statement_rep: %empty  */
#line 196 "gocompiler.y"
                                                                                                                        {;}
#line 1670 "y.tab.c"
    break;

  case 42: /* Statement_rep: Statement SEMICOLON Statement_rep  */
#line 198 "gocompiler.y"
                                                                                                                        {;}
#line 1676 "y.tab.c"
    break;

  case 43: /* Statement: FOR LBRACE Statement_rep RBRACE  */
#line 202 "gocompiler.y"
                                                                                                                        {;}
#line 1682 "y.tab.c"
    break;

  case 44: /* Statement: FOR Expr LBRACE Statement_rep RBRACE  */
#line 204 "gocompiler.y"
                                                                                                                        {;}
#line 1688 "y.tab.c"
    break;

  case 45: /* Statement: RETURN  */
#line 208 "gocompiler.y"
                                                                                                                        {;}
#line 1694 "y.tab.c"
    break;

  case 46: /* Statement: RETURN Expr  */
#line 210 "gocompiler.y"
                                                                                                                        {;}
#line 1700 "y.tab.c"
    break;

  case 47: /* Statement: FuncInvocation  */
#line 214 "gocompiler.y"
                                                                                                                        {;}
#line 1706 "y.tab.c"
    break;

  case 48: /* Statement: ParseArgs  */
#line 216 "gocompiler.y"
                                                                                                                        {;}
#line 1712 "y.tab.c"
    break;

  case 49: /* Statement: PRINT LPAR Expr RPAR  */
#line 220 "gocompiler.y"
                                                                                                                        {;}
#line 1718 "y.tab.c"
    break;

  case 50: /* Statement: PRINT LPAR STRLIT RPAR  */
#line 222 "gocompiler.y"
                                                                                                                        {;}
#line 1724 "y.tab.c"
    break;

  case 51: /* Statement: error  */
#line 226 "gocompiler.y"
                                                                                                                        {;}
#line 1730 "y.tab.c"
    break;

  case 52: /* ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR  */
#line 230 "gocompiler.y"
                                                                                                                        {;}
#line 1736 "y.tab.c"
    break;

  case 53: /* ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR  */
#line 234 "gocompiler.y"
                                                                                                                        {;}
#line 1742 "y.tab.c"
    break;

  case 54: /* FuncInvocation: ID LPAR RPAR  */
#line 238 "gocompiler.y"
                                                                                                                        {;}
#line 1748 "y.tab.c"
    break;

  case 55: /* FuncInvocation: ID LPAR Expr RPAR  */
#line 240 "gocompiler.y"
                                                                                                                        {;}
#line 1754 "y.tab.c"
    break;

  case 56: /* FuncInvocation: ID LPAR Expr FuncInvocation_rep RPAR  */
#line 242 "gocompiler.y"
                                                                                                                        {;}
#line 1760 "y.tab.c"
    break;

  case 57: /* FuncInvocation_rep: COMMA Expr  */
#line 246 "gocompiler.y"
                                                                                                                        {;}
#line 1766 "y.tab.c"
    break;

  case 58: /* FuncInvocation_rep: COMMA Expr FuncInvocation_rep  */
#line 248 "gocompiler.y"
                                                                                                                        {;}
#line 1772 "y.tab.c"
    break;

  case 59: /* FuncInvocation: ID LPAR error RPAR  */
#line 252 "gocompiler.y"
                                                                                                                        {;}
#line 1778 "y.tab.c"
    break;

  case 60: /* Expr: Expr OR Expr  */
#line 256 "gocompiler.y"
                                                                                                                        {;}
#line 1784 "y.tab.c"
    break;

  case 61: /* Expr: Expr AND Expr  */
#line 258 "gocompiler.y"
                                                                                                                        {;}
#line 1790 "y.tab.c"
    break;

  case 62: /* Expr: Expr LT  */
#line 262 "gocompiler.y"
                                                                                                                        {;}
#line 1796 "y.tab.c"
    break;

  case 63: /* Expr: Expr GT  */
#line 264 "gocompiler.y"
                                                                                                                        {;}
#line 1802 "y.tab.c"
    break;

  case 64: /* Expr: Expr LE  */
#line 266 "gocompiler.y"
                                                                                                                        {;}
#line 1808 "y.tab.c"
    break;

  case 65: /* Expr: Expr GE  */
#line 268 "gocompiler.y"
                                                                                                                        {;}
#line 1814 "y.tab.c"
    break;

  case 66: /* Expr: Expr EQ  */
#line 270 "gocompiler.y"
                                                                                                                        {;}
#line 1820 "y.tab.c"
    break;

  case 67: /* Expr: Expr NE  */
#line 272 "gocompiler.y"
                                                                                                                        {;}
#line 1826 "y.tab.c"
    break;

  case 68: /* Expr: Expr PLUS Expr  */
#line 276 "gocompiler.y"
                                                                                                                        {;}
#line 1832 "y.tab.c"
    break;

  case 69: /* Expr: Expr MINUS Expr  */
#line 278 "gocompiler.y"
                                                                                                                        {;}
#line 1838 "y.tab.c"
    break;

  case 70: /* Expr: Expr STAR Expr  */
#line 280 "gocompiler.y"
                                                                                                                        {;}
#line 1844 "y.tab.c"
    break;

  case 71: /* Expr: Expr DIV Expr  */
#line 282 "gocompiler.y"
                                                                                                                        {;}
#line 1850 "y.tab.c"
    break;

  case 72: /* Expr: Expr MOD Expr  */
#line 284 "gocompiler.y"
                                                                                                                        {;}
#line 1856 "y.tab.c"
    break;

  case 73: /* Expr: NOT Expr  */
#line 288 "gocompiler.y"
                                                                                                                        {;}
#line 1862 "y.tab.c"
    break;

  case 74: /* Expr: MINUS Expr  */
#line 290 "gocompiler.y"
                                                                                                                        {;}
#line 1868 "y.tab.c"
    break;

  case 75: /* Expr: PLUS Expr  */
#line 292 "gocompiler.y"
                                                                                                                        {;}
#line 1874 "y.tab.c"
    break;

  case 76: /* Expr: INTLIT  */
#line 296 "gocompiler.y"
                                                                                                                        {;}
#line 1880 "y.tab.c"
    break;

  case 77: /* Expr: REALLIT  */
#line 298 "gocompiler.y"
                                                                                                                        {;}
#line 1886 "y.tab.c"
    break;

  case 78: /* Expr: ID  */
#line 300 "gocompiler.y"
                                                                                                                        {;}
#line 1892 "y.tab.c"
    break;

  case 79: /* Expr: FuncInvocation  */
#line 302 "gocompiler.y"
                                                                                                                        {;}
#line 1898 "y.tab.c"
    break;

  case 80: /* Expr: LPAR Expr RPAR  */
#line 304 "gocompiler.y"
                                                                                                                        {;}
#line 1904 "y.tab.c"
    break;

  case 81: /* Expr: LPAR error RPAR  */
#line 308 "gocompiler.y"
                                                                                                                        {;}
#line 1910 "y.tab.c"
    break;


#line 1914 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 310 "gocompiler.y"


