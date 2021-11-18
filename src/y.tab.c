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

int yylex (void);
void yyerror(char* s);

int yydebug = 1;


#line 84 "y.tab.c"

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
# define YYDEBUG 1
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
typedef int YYSTYPE;
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
  YYSYMBOL_VarDeclaration_1 = 49,          /* VarDeclaration_1  */
  YYSYMBOL_VarSpec = 50,                   /* VarSpec  */
  YYSYMBOL_VarSpec_1 = 51,                 /* VarSpec_1  */
  YYSYMBOL_Type = 52,                      /* Type  */
  YYSYMBOL_FuncDeclaration = 53,           /* FuncDeclaration  */
  YYSYMBOL_FuncDeclaration_1 = 54,         /* FuncDeclaration_1  */
  YYSYMBOL_FuncDeclaration_2 = 55,         /* FuncDeclaration_2  */
  YYSYMBOL_Parameters = 56,                /* Parameters  */
  YYSYMBOL_Parameters_1 = 57,              /* Parameters_1  */
  YYSYMBOL_FuncBody = 58,                  /* FuncBody  */
  YYSYMBOL_VarsAndStatements = 59,         /* VarsAndStatements  */
  YYSYMBOL_Statement = 60,                 /* Statement  */
  YYSYMBOL_Statement_1 = 61,               /* Statement_1  */
  YYSYMBOL_Statement_rep = 62,             /* Statement_rep  */
  YYSYMBOL_ParseArgs = 63,                 /* ParseArgs  */
  YYSYMBOL_FuncInvocation = 64,            /* FuncInvocation  */
  YYSYMBOL_FuncInvocation_rep = 65,        /* FuncInvocation_rep  */
  YYSYMBOL_Expr = 66                       /* Expr  */
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
#define YYLAST   461

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

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
       0,    68,    68,    72,    74,    76,    80,    84,    86,    90,
      94,    96,   100,   102,   104,   106,   110,   114,   116,   120,
     122,   126,   128,   132,   134,   138,   140,   144,   146,   148,
     150,   152,   154,   158,   162,   164,   168,   170,   174,   176,
     178,   180,   182,   184,   188,   192,   194,   196,   198,   202,
     204,   208,   210,   214,   216,   220,   224,   228,   232,   234,
     236,   240,   242,   246,   250,   252,   256,   258,   260,   262,
     264,   266,   270,   272,   274,   276,   278,   282,   284,   286,
     290,   292,   294,   296,   298,   302
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
  "Declarations", "VarDeclaration", "VarDeclaration_1", "VarSpec",
  "VarSpec_1", "Type", "FuncDeclaration", "FuncDeclaration_1",
  "FuncDeclaration_2", "Parameters", "Parameters_1", "FuncBody",
  "VarsAndStatements", "Statement", "Statement_1", "Statement_rep",
  "ParseArgs", "FuncInvocation", "FuncInvocation_rep", "Expr", YY_NULLPTR
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

#define YYPACT_NINF (-86)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-37)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    -2,    10,    13,   -86,    -5,    54,    28,   -86,    38,
      67,    85,    34,   -86,   -86,    75,    -5,    -5,    79,   -86,
     -86,   -86,   -86,   -86,   -86,    84,    80,   -86,   -86,    85,
      83,    99,   106,   -86,    96,   -86,   -86,    94,   255,    77,
     -86,   -86,   106,   109,   -86,   -86,    26,   276,   -86,   326,
      95,    95,    64,   119,   125,   120,   128,   -86,   -86,   -86,
     -86,    99,    44,   112,    95,   -86,   -86,   138,   144,   166,
      33,    95,    95,    95,   -86,   -86,   -86,   189,   421,   347,
     215,    86,   297,   -86,   318,    94,   167,   -86,   116,   158,
     421,   355,   -86,   168,   131,   -86,   -86,   -86,   376,    95,
      95,   -86,   -86,   -86,   -86,   -86,   -86,    95,    95,    95,
      95,    95,   -86,   185,   228,   384,   249,   149,   -86,   -86,
     -86,   -86,   -86,    95,   250,   238,   -86,   -86,   -86,   245,
     251,   176,   201,   102,   102,   -86,   -86,   -86,   -86,   -86,
     -86,   252,   -86,   -86,   163,   -86,   257,   253,   260,   -86,
     -86,     4,   405,   256,   259,   247,   -86,   265,   413,   -86,
      95,   -86,   -86,   269,   408,   -86,   277,   -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     0,     0,     2,     0,
       0,     0,     0,     6,     7,     0,     5,     5,     0,    12,
      13,    14,    15,     9,    10,     0,     0,     3,     4,     0,
       0,     0,     0,    16,     0,    11,     8,    21,     0,     0,
      17,    19,     0,     0,    22,    55,     0,     0,    25,     0,
       0,    49,     0,     0,     0,     0,     0,    52,    51,    20,
      18,     0,     0,     0,     0,    30,    34,     0,     0,    82,
       0,     0,     0,     0,    80,    81,    83,     0,    50,     0,
       0,     0,     0,    26,     0,    23,     0,    58,     0,     0,
      33,     0,    35,     0,     0,    79,    78,    77,     0,     0,
       0,    66,    67,    70,    71,    68,    69,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,    31,    32,
      24,    63,    59,     0,     0,     0,    37,    85,    84,    38,
       0,    64,    65,    72,    73,    74,    75,    76,    44,    46,
      47,     0,    54,    53,    61,    60,     0,     0,    39,    48,
      62,     0,     0,     0,     0,     0,    40,     0,     0,    57,
       0,    41,    42,     0,     0,    43,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -86,     7,    -1,   -86,   272,   258,   -11,   -86,   -86,
     244,   -86,   203,   261,   -25,   -35,   198,   -85,   -86,   -38,
     148,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,    54,    13,    14,    23,    24,    10,    33,
      40,    34,    44,    41,    55,   113,    68,   114,    57,    76,
     124,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,     6,     3,    56,     9,   154,    78,    80,     1,    58,
       4,    58,    56,   130,    67,     9,     9,    88,     5,    90,
      37,    39,    65,    27,    28,    94,    95,    96,    97,   155,
     141,    39,    15,    62,    93,    63,   117,    69,    11,     7,
      70,    58,    64,    16,    58,    86,    58,    56,    69,    56,
      85,    70,    87,    58,   131,   132,    67,   118,    11,   119,
      58,    12,   133,   134,   135,   136,   137,   157,    69,    71,
      72,    70,    17,   163,    73,    74,    75,    58,   144,    79,
      71,    72,    26,    29,    31,    73,    74,    75,    32,    30,
      69,    36,    38,    70,    18,    19,    20,    21,    22,    69,
      71,    72,    70,    43,    42,    73,    74,    75,   116,    19,
      20,    21,    22,    61,    58,   164,    19,    20,    21,    22,
      58,    38,    71,    72,   122,   123,    81,    73,    74,    75,
      82,    71,    72,    84,    83,    89,    73,    74,    75,   128,
     109,   110,   111,    91,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   143,    92,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   123,    62,   125,   121,   127,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     138,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     115,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   139,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    45,   142,   145,    46,
      47,     6,   146,   147,   151,   148,   149,   159,   152,    48,
      49,   158,    50,   160,    51,    52,    53,    45,   153,   161,
      46,    47,     6,   165,    25,   167,    60,    35,   120,   126,
     -27,    49,   150,    50,     0,    51,    52,    53,    45,     0,
      59,    46,    47,     6,     0,     0,     0,     0,     0,     0,
       0,   -28,    49,     0,    50,     0,    51,    52,    53,    45,
       0,     0,    46,    47,     6,     0,     0,    45,     0,     0,
      46,     0,   -29,    49,     0,    50,     0,    51,    52,    53,
      66,    49,     0,    50,     0,    51,    52,    53,    45,     0,
       0,    46,     0,     0,     0,     0,    45,     0,     0,    46,
       0,   112,    49,     0,    50,     0,    51,    52,    53,   -36,
      49,     0,    50,     0,    51,    52,    53,    45,     0,     0,
      46,     0,     0,     0,     0,    45,     0,     0,    46,     0,
     129,    49,     0,    50,     0,    51,    52,    53,   140,    49,
       0,    50,     0,    51,    52,    53,    45,     0,     0,    46,
       0,     0,     0,     0,    45,     0,     0,    46,     0,   156,
      49,     0,    50,     0,    51,    52,    53,   162,    49,     0,
      50,     0,    51,    52,    53,   166,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111
};

static const yytype_int16 yycheck[] =
{
      38,     6,     4,    38,     5,     1,    51,    52,     3,    47,
       0,    49,    47,    98,    49,    16,    17,    62,     5,    64,
      31,    32,    47,    16,    17,    70,    71,    72,    73,    25,
     115,    42,     4,     7,     1,     9,    81,     4,     4,    44,
       7,    79,    16,     5,    82,     1,    84,    82,     4,    84,
      61,     7,     8,    91,    99,   100,    91,    82,     4,    84,
      98,     7,   107,   108,   109,   110,   111,   152,     4,    36,
      37,     7,     5,   158,    41,    42,    43,   115,   123,    15,
      36,    37,     7,     4,     4,    41,    42,    43,     8,     5,
       4,     8,    15,     7,     9,    10,    11,    12,    13,     4,
      36,    37,     7,     9,     8,    41,    42,    43,    22,    10,
      11,    12,    13,     4,   152,   160,    10,    11,    12,    13,
     158,    15,    36,    37,     8,     9,     7,    41,    42,    43,
       5,    36,    37,     5,    14,    23,    41,    42,    43,     8,
      38,    39,    40,     5,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     8,    14,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     9,     7,    16,     8,     8,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       5,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    15,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      15,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    14,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     1,     8,     8,     4,
       5,     6,    24,    18,     7,    14,    14,     8,    15,    14,
      15,    15,    17,    26,    19,    20,    21,     1,    18,    14,
       4,     5,     6,    14,    12,     8,    42,    29,    85,    91,
      14,    15,   144,    17,    -1,    19,    20,    21,     1,    -1,
      39,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    -1,    17,    -1,    19,    20,    21,     1,
      -1,    -1,     4,     5,     6,    -1,    -1,     1,    -1,    -1,
       4,    -1,    14,    15,    -1,    17,    -1,    19,    20,    21,
      14,    15,    -1,    17,    -1,    19,    20,    21,     1,    -1,
      -1,     4,    -1,    -1,    -1,    -1,     1,    -1,    -1,     4,
      -1,    14,    15,    -1,    17,    -1,    19,    20,    21,    14,
      15,    -1,    17,    -1,    19,    20,    21,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,     1,    -1,    -1,     4,    -1,
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
       0,     3,    46,     4,     0,     5,     6,    44,    47,    48,
      53,     4,     7,    49,    50,     4,     5,     5,     9,    10,
      11,    12,    13,    51,    52,    50,     7,    47,    47,     4,
       5,     4,     8,    54,    56,    51,     8,    52,    15,    52,
      55,    58,     8,     9,    57,     1,     4,     5,    14,    15,
      17,    19,    20,    21,    48,    59,    60,    63,    64,    58,
      55,     4,     7,     9,    16,    59,    14,    60,    61,     4,
       7,    36,    37,    41,    42,    43,    64,    66,    66,    15,
      66,     7,     5,    14,     5,    52,     1,     8,    66,    23,
      66,     5,    14,     1,    66,    66,    66,    66,    15,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    14,    60,    62,    15,    22,    66,    59,    59,
      57,     8,     8,     9,    65,    16,    61,     8,     8,    14,
      62,    66,    66,    66,    66,    66,    66,    66,     5,    14,
      14,    62,     8,     8,    66,     8,    24,    18,    14,    14,
      65,     7,    15,    18,     1,    25,    14,    62,    15,     8,
      26,    14,    14,    62,    66,    14,    27,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    48,    49,    49,    50,
      51,    51,    52,    52,    52,    52,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    61,    61,    60,    60,
      60,    60,    60,    60,    62,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    63,    63,    64,    64,
      64,    65,    65,    64,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     2,     1,     4,     2,
       1,     3,     1,     1,     1,     1,     4,     2,     3,     1,
       2,     2,     3,     3,     4,     2,     3,     1,     2,     2,
       2,     3,     3,     3,     2,     3,     2,     3,     4,     5,
       7,     8,     8,     9,     2,     3,     4,     4,     5,     1,
       2,     1,     1,     4,     4,     1,    11,     8,     3,     4,
       5,     2,     3,     4,     3,     3,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     2,     2,     2,
       1,     1,     1,     1,     3,     3
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
#line 68 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; yyval=yyvsp[-2]; yyval=yyvsp[-1]; printf("1\n");}
#line 1441 "y.tab.c"
    break;

  case 3: /* Declarations: VarDeclaration SEMICOLON Declarations  */
#line 72 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1447 "y.tab.c"
    break;

  case 4: /* Declarations: FuncDeclaration SEMICOLON Declarations  */
#line 74 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1453 "y.tab.c"
    break;

  case 5: /* Declarations: %empty  */
#line 76 "gocompiler.y"
                                                                                                                        {printf("1\n");}
#line 1459 "y.tab.c"
    break;

  case 6: /* VarDeclaration: VAR VarDeclaration_1  */
#line 80 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1465 "y.tab.c"
    break;

  case 7: /* VarDeclaration_1: VarSpec  */
#line 84 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1471 "y.tab.c"
    break;

  case 8: /* VarDeclaration_1: LPAR VarSpec SEMICOLON RPAR  */
#line 86 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; printf("1\n");}
#line 1477 "y.tab.c"
    break;

  case 9: /* VarSpec: ID VarSpec_1  */
#line 90 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1483 "y.tab.c"
    break;

  case 10: /* VarSpec_1: Type  */
#line 94 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1489 "y.tab.c"
    break;

  case 11: /* VarSpec_1: COMMA ID VarSpec_1  */
#line 96 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1495 "y.tab.c"
    break;

  case 12: /* Type: INT  */
#line 100 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1501 "y.tab.c"
    break;

  case 13: /* Type: FLOAT32  */
#line 102 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1507 "y.tab.c"
    break;

  case 14: /* Type: BOOL  */
#line 104 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1513 "y.tab.c"
    break;

  case 15: /* Type: STRING  */
#line 106 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1519 "y.tab.c"
    break;

  case 16: /* FuncDeclaration: FUNC ID LPAR FuncDeclaration_1  */
#line 110 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; printf("1\n");}
#line 1525 "y.tab.c"
    break;

  case 17: /* FuncDeclaration_1: RPAR FuncDeclaration_2  */
#line 114 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1531 "y.tab.c"
    break;

  case 18: /* FuncDeclaration_1: Parameters RPAR FuncDeclaration_2  */
#line 116 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1537 "y.tab.c"
    break;

  case 19: /* FuncDeclaration_2: FuncBody  */
#line 120 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1543 "y.tab.c"
    break;

  case 20: /* FuncDeclaration_2: Type FuncBody  */
#line 122 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1549 "y.tab.c"
    break;

  case 21: /* Parameters: ID Type  */
#line 126 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1555 "y.tab.c"
    break;

  case 22: /* Parameters: ID Type Parameters_1  */
#line 128 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1561 "y.tab.c"
    break;

  case 23: /* Parameters_1: COMMA ID Type  */
#line 132 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1567 "y.tab.c"
    break;

  case 24: /* Parameters_1: COMMA ID Type Parameters_1  */
#line 134 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; printf("1\n");}
#line 1573 "y.tab.c"
    break;

  case 25: /* FuncBody: LBRACE RBRACE  */
#line 138 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1579 "y.tab.c"
    break;

  case 26: /* FuncBody: LBRACE VarsAndStatements RBRACE  */
#line 140 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1585 "y.tab.c"
    break;

  case 27: /* VarsAndStatements: SEMICOLON  */
#line 144 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1591 "y.tab.c"
    break;

  case 28: /* VarsAndStatements: VarDeclaration SEMICOLON  */
#line 146 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1597 "y.tab.c"
    break;

  case 29: /* VarsAndStatements: Statement SEMICOLON  */
#line 148 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1603 "y.tab.c"
    break;

  case 30: /* VarsAndStatements: SEMICOLON VarsAndStatements  */
#line 150 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1609 "y.tab.c"
    break;

  case 31: /* VarsAndStatements: VarDeclaration SEMICOLON VarsAndStatements  */
#line 152 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1615 "y.tab.c"
    break;

  case 32: /* VarsAndStatements: Statement SEMICOLON VarsAndStatements  */
#line 154 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1621 "y.tab.c"
    break;

  case 33: /* Statement: ID ASSIGN Expr  */
#line 158 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1627 "y.tab.c"
    break;

  case 34: /* Statement: LBRACE RBRACE  */
#line 162 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1633 "y.tab.c"
    break;

  case 35: /* Statement: LBRACE Statement_1 RBRACE  */
#line 164 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1639 "y.tab.c"
    break;

  case 36: /* Statement_1: Statement SEMICOLON  */
#line 168 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1645 "y.tab.c"
    break;

  case 37: /* Statement_1: Statement SEMICOLON Statement_1  */
#line 170 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1651 "y.tab.c"
    break;

  case 38: /* Statement: IF Expr LBRACE RBRACE  */
#line 174 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; printf("1\n");}
#line 1657 "y.tab.c"
    break;

  case 39: /* Statement: IF Expr LBRACE Statement_rep RBRACE  */
#line 176 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-4]; printf("1\n");}
#line 1663 "y.tab.c"
    break;

  case 40: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE RBRACE  */
#line 178 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-6]; printf("1\n");}
#line 1669 "y.tab.c"
    break;

  case 41: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE Statement_rep RBRACE  */
#line 180 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-7]; printf("1\n");}
#line 1675 "y.tab.c"
    break;

  case 42: /* Statement: IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE RBRACE  */
#line 182 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-7]; printf("1\n");}
#line 1681 "y.tab.c"
    break;

  case 43: /* Statement: IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE Statement_rep RBRACE  */
#line 184 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-8]; printf("1\n");}
#line 1687 "y.tab.c"
    break;

  case 44: /* Statement_rep: Statement SEMICOLON  */
#line 188 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1693 "y.tab.c"
    break;

  case 45: /* Statement: FOR LBRACE RBRACE  */
#line 192 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1699 "y.tab.c"
    break;

  case 46: /* Statement: FOR LBRACE Statement_rep RBRACE  */
#line 194 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; printf("1\n");}
#line 1705 "y.tab.c"
    break;

  case 47: /* Statement: FOR Expr LBRACE RBRACE  */
#line 196 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; printf("1\n");}
#line 1711 "y.tab.c"
    break;

  case 48: /* Statement: FOR Expr LBRACE Statement_rep RBRACE  */
#line 198 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-4]; printf("1\n");}
#line 1717 "y.tab.c"
    break;

  case 49: /* Statement: RETURN  */
#line 202 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1723 "y.tab.c"
    break;

  case 50: /* Statement: RETURN Expr  */
#line 204 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1729 "y.tab.c"
    break;

  case 51: /* Statement: FuncInvocation  */
#line 208 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1735 "y.tab.c"
    break;

  case 52: /* Statement: ParseArgs  */
#line 210 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1741 "y.tab.c"
    break;

  case 53: /* Statement: PRINT LPAR Expr RPAR  */
#line 214 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; printf("1\n");}
#line 1747 "y.tab.c"
    break;

  case 54: /* Statement: PRINT LPAR STRLIT RPAR  */
#line 216 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; printf("1\n");}
#line 1753 "y.tab.c"
    break;

  case 55: /* Statement: error  */
#line 220 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1759 "y.tab.c"
    break;

  case 56: /* ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR  */
#line 224 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-10]; printf("1\n");}
#line 1765 "y.tab.c"
    break;

  case 57: /* ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR  */
#line 228 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-7]; printf("1\n");}
#line 1771 "y.tab.c"
    break;

  case 58: /* FuncInvocation: ID LPAR RPAR  */
#line 232 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1777 "y.tab.c"
    break;

  case 59: /* FuncInvocation: ID LPAR Expr RPAR  */
#line 234 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; printf("1\n");}
#line 1783 "y.tab.c"
    break;

  case 60: /* FuncInvocation: ID LPAR Expr FuncInvocation_rep RPAR  */
#line 236 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-4]; printf("1\n");}
#line 1789 "y.tab.c"
    break;

  case 61: /* FuncInvocation_rep: COMMA Expr  */
#line 240 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1795 "y.tab.c"
    break;

  case 62: /* FuncInvocation_rep: COMMA Expr FuncInvocation_rep  */
#line 242 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1801 "y.tab.c"
    break;

  case 63: /* FuncInvocation: ID LPAR error RPAR  */
#line 246 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-3]; printf("1\n");}
#line 1807 "y.tab.c"
    break;

  case 64: /* Expr: Expr OR Expr  */
#line 250 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1813 "y.tab.c"
    break;

  case 65: /* Expr: Expr AND Expr  */
#line 252 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1819 "y.tab.c"
    break;

  case 66: /* Expr: Expr LT  */
#line 256 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1825 "y.tab.c"
    break;

  case 67: /* Expr: Expr GT  */
#line 258 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1831 "y.tab.c"
    break;

  case 68: /* Expr: Expr LE  */
#line 260 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1837 "y.tab.c"
    break;

  case 69: /* Expr: Expr GE  */
#line 262 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1843 "y.tab.c"
    break;

  case 70: /* Expr: Expr EQ  */
#line 264 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1849 "y.tab.c"
    break;

  case 71: /* Expr: Expr NE  */
#line 266 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1855 "y.tab.c"
    break;

  case 72: /* Expr: Expr PLUS Expr  */
#line 270 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1861 "y.tab.c"
    break;

  case 73: /* Expr: Expr MINUS Expr  */
#line 272 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1867 "y.tab.c"
    break;

  case 74: /* Expr: Expr STAR Expr  */
#line 274 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1873 "y.tab.c"
    break;

  case 75: /* Expr: Expr DIV Expr  */
#line 276 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1879 "y.tab.c"
    break;

  case 76: /* Expr: Expr MOD Expr  */
#line 278 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1885 "y.tab.c"
    break;

  case 77: /* Expr: NOT Expr  */
#line 282 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1891 "y.tab.c"
    break;

  case 78: /* Expr: MINUS Expr  */
#line 284 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1897 "y.tab.c"
    break;

  case 79: /* Expr: PLUS Expr  */
#line 286 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-1]; printf("1\n");}
#line 1903 "y.tab.c"
    break;

  case 80: /* Expr: INTLIT  */
#line 290 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1909 "y.tab.c"
    break;

  case 81: /* Expr: REALLIT  */
#line 292 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1915 "y.tab.c"
    break;

  case 82: /* Expr: ID  */
#line 294 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1921 "y.tab.c"
    break;

  case 83: /* Expr: FuncInvocation  */
#line 296 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[0]; printf("1\n");}
#line 1927 "y.tab.c"
    break;

  case 84: /* Expr: LPAR Expr RPAR  */
#line 298 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1933 "y.tab.c"
    break;

  case 85: /* Expr: LPAR error RPAR  */
#line 302 "gocompiler.y"
                                                                                                                        {yyval=yyvsp[-2]; printf("1\n");}
#line 1939 "y.tab.c"
    break;


#line 1943 "y.tab.c"

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

#line 304 "gocompiler.y"


