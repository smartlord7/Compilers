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
union YYSTYPE
{
#line 58 "gocompiler.y"

	char * strlit, * id, * reallit, * intlit;

#line 229 "y.tab.c"

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
  YYSYMBOL_Statement_rep = 59,             /* Statement_rep  */
  YYSYMBOL_ParseArgs = 60,                 /* ParseArgs  */
  YYSYMBOL_FuncInvocation = 61,            /* FuncInvocation  */
  YYSYMBOL_FuncInvocation_rep = 62,        /* FuncInvocation_rep  */
  YYSYMBOL_Expr = 63                       /* Expr  */
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
#define YYLAST   419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

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
       0,    72,    72,    74,    78,    80,    82,    84,    88,    90,
      94,    98,   100,   104,   106,   108,   110,   114,   116,   118,
     120,   124,   126,   130,   132,   136,   138,   142,   144,   146,
     148,   150,   152,   156,   160,   162,   166,   168,   172,   174,
     176,   178,   180,   182,   186,   190,   192,   194,   196,   200,
     202,   206,   208,   212,   214,   218,   222,   226,   230,   232,
     234,   238,   240,   244,   248,   250,   254,   256,   258,   260,
     262,   264,   268,   270,   272,   274,   276,   280,   282,   284,
     288,   290,   292,   294,   296,   300
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

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-37)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,    28,    34,    33,   -99,    -3,     4,    48,   -99,    49,
      59,   117,    69,   -99,    46,    -3,    -3,    75,   -99,   -99,
     -99,   -99,   -99,   -99,    82,    29,   -99,   -99,   117,    80,
     100,    94,    81,   -99,   -99,    85,   255,    86,   -99,    94,
      91,   -99,   -99,    77,   -99,   -99,   284,    95,    95,    55,
      83,   103,   276,   111,   -99,   -99,   -99,    86,   -99,   100,
      35,    99,    95,   -99,   128,   120,   133,     8,    95,    95,
      95,   -99,   -99,   -99,   189,   379,   305,   215,    78,   -99,
     -99,   -99,   130,   136,   -99,   -99,    85,   134,   -99,   116,
     127,   379,   313,   -99,   150,   131,   -99,   -99,   -99,   334,
      95,    95,   -99,   -99,   -99,   -99,   -99,   -99,    95,    95,
      95,    95,    95,   -99,   168,   160,   342,   167,   149,   -99,
     -99,   -99,   -99,   -99,    95,   182,   152,   -99,   -99,   -99,
     224,   243,   176,   201,   -17,   -17,   -99,   -99,   -99,   -99,
     -99,   -99,   244,   -99,   -99,   163,   -99,   256,   247,   246,
     -99,   -99,     6,   363,   250,   258,   241,   -99,   254,   371,
     -99,    95,   -99,   -99,   257,   366,   -99,   265,   -99
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
       0,    22,    55,     0,    27,    25,     0,     0,    49,     0,
       0,     0,     0,     0,    52,    51,    19,     0,    18,     0,
       0,     0,     0,    34,     0,     0,    82,     0,     0,     0,
       0,    80,    81,    83,     0,    50,     0,     0,     0,    28,
      30,    26,     0,     0,    29,    20,    23,     0,    58,     0,
       0,    33,     0,    35,     0,     0,    79,    78,    77,     0,
       0,     0,    66,    67,    70,    71,    68,    69,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,    31,
      32,    24,    63,    59,     0,     0,     0,    37,    85,    84,
      38,     0,    64,    65,    72,    73,    74,    75,    76,    44,
      46,    47,     0,    54,    53,    61,    60,     0,     0,    39,
      48,    62,     0,     0,     0,     0,     0,    40,     0,     0,
      57,     0,    41,    42,     0,     0,    43,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,    31,   -23,   266,   251,    44,   -99,   -99,   197,
      -9,   -99,   -32,   192,   -98,   -99,   -36,   141,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     8,     9,    13,    22,    23,    10,    32,    41,
      38,    52,   114,    65,   115,    54,    73,   125,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,   131,     1,     6,    53,    75,    77,   155,    11,    94,
      55,    12,    66,    51,    64,    67,    55,    89,   142,    91,
      83,   110,   111,   112,    95,    96,    97,    98,    56,    82,
      58,   156,     3,    30,     4,   118,    87,    31,     5,    66,
      55,     7,    67,    88,    68,    69,    26,    27,    85,    70,
      71,    72,    14,    25,    15,   158,    55,   132,   133,    66,
      64,   164,    67,    55,    16,   134,   135,   136,   137,   138,
      76,    68,    69,    11,    35,    37,    70,    71,    72,    28,
      55,   145,    66,    57,    60,    67,    61,    29,    34,    39,
      78,    68,    69,    62,    40,    59,    70,    71,    72,    66,
     117,    36,    67,    86,    18,    19,    20,    21,    79,    36,
      18,    19,    20,    21,    68,    69,    84,    55,   165,    70,
      71,    72,    90,    55,   123,   124,    17,    18,    19,    20,
      21,    68,    69,    92,    93,   119,    70,    71,    72,   129,
      60,   120,   122,   126,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   144,   128,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   124,   139,   140,   143,   147,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     146,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    99,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     116,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   148,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    42,   149,   150,    43,
      44,     6,   153,   152,   154,   159,   160,   161,   162,    45,
      46,   166,    47,   168,    48,    49,    50,    42,    24,    33,
      43,    80,     6,   121,   127,    42,   151,     0,    43,     0,
      81,    46,     0,    47,     0,    48,    49,    50,    63,    46,
       0,    47,     0,    48,    49,    50,    42,     0,     0,    43,
       0,     0,     0,     0,    42,     0,     0,    43,     0,   113,
      46,     0,    47,     0,    48,    49,    50,   -36,    46,     0,
      47,     0,    48,    49,    50,    42,     0,     0,    43,     0,
       0,     0,     0,    42,     0,     0,    43,     0,   130,    46,
       0,    47,     0,    48,    49,    50,   141,    46,     0,    47,
       0,    48,    49,    50,    42,     0,     0,    43,     0,     0,
       0,     0,    42,     0,     0,    43,     0,   157,    46,     0,
      47,     0,    48,    49,    50,   163,    46,     0,    47,     0,
      48,    49,    50,   167,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
      36,    99,     3,     6,    36,    48,    49,     1,     4,     1,
      46,     7,     4,    36,    46,     7,    52,    60,   116,    62,
      52,    38,    39,    40,    67,    68,    69,    70,    37,    52,
      39,    25,     4,     4,     0,    78,     1,     8,     5,     4,
      76,    44,     7,     8,    36,    37,    15,    16,    57,    41,
      42,    43,     4,     7,     5,   153,    92,   100,   101,     4,
      92,   159,     7,    99,     5,   108,   109,   110,   111,   112,
      15,    36,    37,     4,    30,    31,    41,    42,    43,     4,
     116,   124,     4,    39,     7,     7,     9,     5,     8,     8,
       7,    36,    37,    16,     9,     4,    41,    42,    43,     4,
      22,    15,     7,    59,    10,    11,    12,    13,     5,    15,
      10,    11,    12,    13,    36,    37,     5,   153,   161,    41,
      42,    43,    23,   159,     8,     9,     9,    10,    11,    12,
      13,    36,    37,     5,    14,     5,    41,    42,    43,     8,
       7,     5,     8,    16,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     8,     8,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     9,     5,    14,     8,    24,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       8,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    15,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      15,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    18,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     1,    14,    14,     4,
       5,     6,    15,     7,    18,    15,     8,    26,    14,    14,
      15,    14,    17,     8,    19,    20,    21,     1,    12,    28,
       4,     5,     6,    86,    92,     1,   145,    -1,     4,    -1,
      14,    15,    -1,    17,    -1,    19,    20,    21,    14,    15,
      -1,    17,    -1,    19,    20,    21,     1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,     1,    -1,    -1,     4,    -1,    14,
      15,    -1,    17,    -1,    19,    20,    21,    14,    15,    -1,
      17,    -1,    19,    20,    21,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,     1,    -1,    -1,     4,    -1,    14,    15,
      -1,    17,    -1,    19,    20,    21,    14,    15,    -1,    17,
      -1,    19,    20,    21,     1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,     1,    -1,    -1,     4,    -1,    14,    15,    -1,
      17,    -1,    19,    20,    21,    14,    15,    -1,    17,    -1,
      19,    20,    21,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40
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
      21,    48,    56,    57,    60,    61,    55,    51,    55,     4,
       7,     9,    16,    14,    57,    58,     4,     7,    36,    37,
      41,    42,    43,    61,    63,    63,    15,    63,     7,     5,
       5,    14,    48,    57,     5,    55,    51,     1,     8,    63,
      23,    63,     5,    14,     1,    63,    63,    63,    63,    15,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    14,    57,    59,    15,    22,    63,     5,
       5,    54,     8,     8,     9,    62,    16,    58,     8,     8,
      14,    59,    63,    63,    63,    63,    63,    63,    63,     5,
      14,    14,    59,     8,     8,    63,     8,    24,    18,    14,
      14,    62,     7,    15,    18,     1,    25,    14,    59,    15,
       8,    26,    14,    14,    59,    63,    14,    27,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    47,    47,    48,    48,
      49,    50,    50,    51,    51,    51,    51,    52,    52,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    58,    58,    57,    57,
      57,    57,    57,    57,    59,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    60,    60,    61,    61,
      61,    62,    62,    61,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     3,     2,     5,
       2,     1,     3,     1,     1,     1,     1,     5,     6,     6,
       7,     2,     3,     3,     4,     2,     3,     1,     2,     2,
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
#line 72 "gocompiler.y"
                                                                                                                        {printf("1\n");}
#line 1434 "y.tab.c"
    break;

  case 3: /* Program: PACKAGE ID SEMICOLON  */
#line 74 "gocompiler.y"
                                                                                                                        {;}
#line 1440 "y.tab.c"
    break;

  case 4: /* Declarations: VarDeclaration SEMICOLON  */
#line 78 "gocompiler.y"
                                                                                                                        {printf("3\n");}
#line 1446 "y.tab.c"
    break;

  case 5: /* Declarations: VarDeclaration SEMICOLON Declarations  */
#line 80 "gocompiler.y"
                                                                                                                        {printf("4\n");}
#line 1452 "y.tab.c"
    break;

  case 6: /* Declarations: FuncDeclaration SEMICOLON  */
#line 82 "gocompiler.y"
                                                                                                                        {printf("5\n");}
#line 1458 "y.tab.c"
    break;

  case 7: /* Declarations: FuncDeclaration SEMICOLON Declarations  */
#line 84 "gocompiler.y"
                                                                                                                        {printf("6\n");}
#line 1464 "y.tab.c"
    break;

  case 8: /* VarDeclaration: VAR VarSpec  */
#line 88 "gocompiler.y"
                                                                                                                        {printf("7\n");}
#line 1470 "y.tab.c"
    break;

  case 9: /* VarDeclaration: VAR LPAR VarSpec SEMICOLON RPAR  */
#line 90 "gocompiler.y"
                                                                                                                        {printf("8\n");}
#line 1476 "y.tab.c"
    break;

  case 10: /* VarSpec: ID VarSpec_1  */
#line 94 "gocompiler.y"
                                                                                                                        {printf("9\n");}
#line 1482 "y.tab.c"
    break;

  case 11: /* VarSpec_1: Type  */
#line 98 "gocompiler.y"
                                                                                                                        {printf("10\n");}
#line 1488 "y.tab.c"
    break;

  case 12: /* VarSpec_1: COMMA ID VarSpec_1  */
#line 100 "gocompiler.y"
                                                                                                                        {printf("11\n");}
#line 1494 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 104 "gocompiler.y"
                                                                                                                        {printf("12\n");}
#line 1500 "y.tab.c"
    break;

  case 14: /* Type: FLOAT32  */
#line 106 "gocompiler.y"
                                                                                                                        {printf("13\n");}
#line 1506 "y.tab.c"
    break;

  case 15: /* Type: BOOL  */
#line 108 "gocompiler.y"
                                                                                                                        {printf("14\n");}
#line 1512 "y.tab.c"
    break;

  case 16: /* Type: STRING  */
#line 110 "gocompiler.y"
                                                                                                                        {printf("15\n");}
#line 1518 "y.tab.c"
    break;

  case 17: /* FuncDeclaration: FUNC ID LPAR RPAR FuncBody  */
#line 114 "gocompiler.y"
                                                                                                                        {printf("16\n");}
#line 1524 "y.tab.c"
    break;

  case 18: /* FuncDeclaration: FUNC ID LPAR Parameters RPAR FuncBody  */
#line 116 "gocompiler.y"
                                                                                                                        {printf("17\n");}
#line 1530 "y.tab.c"
    break;

  case 19: /* FuncDeclaration: FUNC ID LPAR RPAR Type FuncBody  */
#line 118 "gocompiler.y"
                                                                                                                        {printf("18\n");}
#line 1536 "y.tab.c"
    break;

  case 20: /* FuncDeclaration: FUNC ID LPAR Parameters RPAR Type FuncBody  */
#line 120 "gocompiler.y"
                                                                                                                        {printf("19\n");}
#line 1542 "y.tab.c"
    break;

  case 21: /* Parameters: ID Type  */
#line 124 "gocompiler.y"
                                                                                                                        {printf("20\n");}
#line 1548 "y.tab.c"
    break;

  case 22: /* Parameters: ID Type Parameters_1  */
#line 126 "gocompiler.y"
                                                                                                                        {printf("21\n");}
#line 1554 "y.tab.c"
    break;

  case 23: /* Parameters_1: COMMA ID Type  */
#line 130 "gocompiler.y"
                                                                                                                        {printf("22\n");}
#line 1560 "y.tab.c"
    break;

  case 24: /* Parameters_1: COMMA ID Type Parameters_1  */
#line 132 "gocompiler.y"
                                                                                                                        {printf("23\n");}
#line 1566 "y.tab.c"
    break;

  case 25: /* FuncBody: LBRACE RBRACE  */
#line 136 "gocompiler.y"
                                                                                                                        {printf("24\n");}
#line 1572 "y.tab.c"
    break;

  case 26: /* FuncBody: LBRACE VarsAndStatements RBRACE  */
#line 138 "gocompiler.y"
                                                                                                                        {printf("25\n");}
#line 1578 "y.tab.c"
    break;

  case 27: /* VarsAndStatements: SEMICOLON  */
#line 142 "gocompiler.y"
                                                                                                                        {printf("26\n");}
#line 1584 "y.tab.c"
    break;

  case 28: /* VarsAndStatements: VarDeclaration SEMICOLON  */
#line 144 "gocompiler.y"
                                                                                                                        {printf("27\n");}
#line 1590 "y.tab.c"
    break;

  case 29: /* VarsAndStatements: Statement SEMICOLON  */
#line 146 "gocompiler.y"
                                                                                                                        {printf("28\n");}
#line 1596 "y.tab.c"
    break;

  case 30: /* VarsAndStatements: VarsAndStatements SEMICOLON  */
#line 148 "gocompiler.y"
                                                                                                                        {printf("29\n");}
#line 1602 "y.tab.c"
    break;

  case 31: /* VarsAndStatements: VarsAndStatements VarDeclaration SEMICOLON  */
#line 150 "gocompiler.y"
                                                                                                                        {printf("30\n");}
#line 1608 "y.tab.c"
    break;

  case 32: /* VarsAndStatements: VarsAndStatements Statement SEMICOLON  */
#line 152 "gocompiler.y"
                                                                                                                        {printf("31\n");}
#line 1614 "y.tab.c"
    break;

  case 33: /* Statement: ID ASSIGN Expr  */
#line 156 "gocompiler.y"
                                                                                                                        {printf("32\n");}
#line 1620 "y.tab.c"
    break;

  case 34: /* Statement: LBRACE RBRACE  */
#line 160 "gocompiler.y"
                                                                                                                        {printf("33\n");}
#line 1626 "y.tab.c"
    break;

  case 35: /* Statement: LBRACE Statement_1 RBRACE  */
#line 162 "gocompiler.y"
                                                                                                                        {printf("34\n");}
#line 1632 "y.tab.c"
    break;

  case 36: /* Statement_1: Statement SEMICOLON  */
#line 166 "gocompiler.y"
                                                                                                                        {printf("35\n");}
#line 1638 "y.tab.c"
    break;

  case 37: /* Statement_1: Statement SEMICOLON Statement_1  */
#line 168 "gocompiler.y"
                                                                                                                        {printf("36\n");}
#line 1644 "y.tab.c"
    break;

  case 38: /* Statement: IF Expr LBRACE RBRACE  */
#line 172 "gocompiler.y"
                                                                                                                        {printf("37\n");}
#line 1650 "y.tab.c"
    break;

  case 39: /* Statement: IF Expr LBRACE Statement_rep RBRACE  */
#line 174 "gocompiler.y"
                                                                                                                        {printf("38\n");}
#line 1656 "y.tab.c"
    break;

  case 40: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE RBRACE  */
#line 176 "gocompiler.y"
                                                                                                                        {printf("39\n");}
#line 1662 "y.tab.c"
    break;

  case 41: /* Statement: IF Expr LBRACE RBRACE ELSE LBRACE Statement_rep RBRACE  */
#line 178 "gocompiler.y"
                                                                                                                        {printf("40\n");}
#line 1668 "y.tab.c"
    break;

  case 42: /* Statement: IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE RBRACE  */
#line 180 "gocompiler.y"
                                                                                                                        {printf("41\n");}
#line 1674 "y.tab.c"
    break;

  case 43: /* Statement: IF Expr LBRACE Statement_rep RBRACE ELSE LBRACE Statement_rep RBRACE  */
#line 182 "gocompiler.y"
                                                                                                                        {printf("42\n");}
#line 1680 "y.tab.c"
    break;

  case 44: /* Statement_rep: Statement SEMICOLON  */
#line 186 "gocompiler.y"
                                                                                                                        {printf("43\n");}
#line 1686 "y.tab.c"
    break;

  case 45: /* Statement: FOR LBRACE RBRACE  */
#line 190 "gocompiler.y"
                                                                                                                        {printf("44\n");}
#line 1692 "y.tab.c"
    break;

  case 46: /* Statement: FOR LBRACE Statement_rep RBRACE  */
#line 192 "gocompiler.y"
                                                                                                                        {printf("45\n");}
#line 1698 "y.tab.c"
    break;

  case 47: /* Statement: FOR Expr LBRACE RBRACE  */
#line 194 "gocompiler.y"
                                                                                                                        {printf("46\n");}
#line 1704 "y.tab.c"
    break;

  case 48: /* Statement: FOR Expr LBRACE Statement_rep RBRACE  */
#line 196 "gocompiler.y"
                                                                                                                        {printf("47\n");}
#line 1710 "y.tab.c"
    break;

  case 49: /* Statement: RETURN  */
#line 200 "gocompiler.y"
                                                                                                                        {printf("48\n");}
#line 1716 "y.tab.c"
    break;

  case 50: /* Statement: RETURN Expr  */
#line 202 "gocompiler.y"
                                                                                                                        {printf("49\n");}
#line 1722 "y.tab.c"
    break;

  case 51: /* Statement: FuncInvocation  */
#line 206 "gocompiler.y"
                                                                                                                        {printf("50\n");}
#line 1728 "y.tab.c"
    break;

  case 52: /* Statement: ParseArgs  */
#line 208 "gocompiler.y"
                                                                                                                        {printf("51\n");}
#line 1734 "y.tab.c"
    break;

  case 53: /* Statement: PRINT LPAR Expr RPAR  */
#line 212 "gocompiler.y"
                                                                                                                        {printf("52\n");}
#line 1740 "y.tab.c"
    break;

  case 54: /* Statement: PRINT LPAR STRLIT RPAR  */
#line 214 "gocompiler.y"
                                                                                                                        {printf("53\n");}
#line 1746 "y.tab.c"
    break;

  case 55: /* Statement: error  */
#line 218 "gocompiler.y"
                                                                                                                        {printf("54\n");}
#line 1752 "y.tab.c"
    break;

  case 56: /* ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR  */
#line 222 "gocompiler.y"
                                                                                                                        {printf("55\n");}
#line 1758 "y.tab.c"
    break;

  case 57: /* ParseArgs: ID COMMA BLANKID ASSIGN PARSEINT LPAR error RPAR  */
#line 226 "gocompiler.y"
                                                                                                                        {printf("56\n");}
#line 1764 "y.tab.c"
    break;

  case 58: /* FuncInvocation: ID LPAR RPAR  */
#line 230 "gocompiler.y"
                                                                                                                        {printf("57\n");}
#line 1770 "y.tab.c"
    break;

  case 59: /* FuncInvocation: ID LPAR Expr RPAR  */
#line 232 "gocompiler.y"
                                                                                                                        {printf("58\n");}
#line 1776 "y.tab.c"
    break;

  case 60: /* FuncInvocation: ID LPAR Expr FuncInvocation_rep RPAR  */
#line 234 "gocompiler.y"
                                                                                                                        {printf("59\n");}
#line 1782 "y.tab.c"
    break;

  case 61: /* FuncInvocation_rep: COMMA Expr  */
#line 238 "gocompiler.y"
                                                                                                                        {printf("60\n");}
#line 1788 "y.tab.c"
    break;

  case 62: /* FuncInvocation_rep: COMMA Expr FuncInvocation_rep  */
#line 240 "gocompiler.y"
                                                                                                                        {printf("61\n");}
#line 1794 "y.tab.c"
    break;

  case 63: /* FuncInvocation: ID LPAR error RPAR  */
#line 244 "gocompiler.y"
                                                                                                                        {printf("62\n");}
#line 1800 "y.tab.c"
    break;

  case 64: /* Expr: Expr OR Expr  */
#line 248 "gocompiler.y"
                                                                                                                        {printf("63\n");}
#line 1806 "y.tab.c"
    break;

  case 65: /* Expr: Expr AND Expr  */
#line 250 "gocompiler.y"
                                                                                                                        {printf("64\n");}
#line 1812 "y.tab.c"
    break;

  case 66: /* Expr: Expr LT  */
#line 254 "gocompiler.y"
                                                                                                                        {printf("65\n");}
#line 1818 "y.tab.c"
    break;

  case 67: /* Expr: Expr GT  */
#line 256 "gocompiler.y"
                                                                                                                        {printf("66\n");}
#line 1824 "y.tab.c"
    break;

  case 68: /* Expr: Expr LE  */
#line 258 "gocompiler.y"
                                                                                                                        {printf("67\n");}
#line 1830 "y.tab.c"
    break;

  case 69: /* Expr: Expr GE  */
#line 260 "gocompiler.y"
                                                                                                                        {printf("68\n");}
#line 1836 "y.tab.c"
    break;

  case 70: /* Expr: Expr EQ  */
#line 262 "gocompiler.y"
                                                                                                                        {printf("69\n");}
#line 1842 "y.tab.c"
    break;

  case 71: /* Expr: Expr NE  */
#line 264 "gocompiler.y"
                                                                                                                        {printf("70\n");}
#line 1848 "y.tab.c"
    break;

  case 72: /* Expr: Expr PLUS Expr  */
#line 268 "gocompiler.y"
                                                                                                                        {printf("71\n");}
#line 1854 "y.tab.c"
    break;

  case 73: /* Expr: Expr MINUS Expr  */
#line 270 "gocompiler.y"
                                                                                                                        {printf("72\n");}
#line 1860 "y.tab.c"
    break;

  case 74: /* Expr: Expr STAR Expr  */
#line 272 "gocompiler.y"
                                                                                                                        {printf("73\n");}
#line 1866 "y.tab.c"
    break;

  case 75: /* Expr: Expr DIV Expr  */
#line 274 "gocompiler.y"
                                                                                                                        {printf("74\n");}
#line 1872 "y.tab.c"
    break;

  case 76: /* Expr: Expr MOD Expr  */
#line 276 "gocompiler.y"
                                                                                                                        {printf("75\n");}
#line 1878 "y.tab.c"
    break;

  case 77: /* Expr: NOT Expr  */
#line 280 "gocompiler.y"
                                                                                                                        {printf("76\n");}
#line 1884 "y.tab.c"
    break;

  case 78: /* Expr: MINUS Expr  */
#line 282 "gocompiler.y"
                                                                                                                        {printf("77\n");}
#line 1890 "y.tab.c"
    break;

  case 79: /* Expr: PLUS Expr  */
#line 284 "gocompiler.y"
                                                                                                                        {printf("78\n");}
#line 1896 "y.tab.c"
    break;

  case 80: /* Expr: INTLIT  */
#line 288 "gocompiler.y"
                                                                                                                        {printf("79\n");}
#line 1902 "y.tab.c"
    break;

  case 81: /* Expr: REALLIT  */
#line 290 "gocompiler.y"
                                                                                                                        {printf("80\n");}
#line 1908 "y.tab.c"
    break;

  case 82: /* Expr: ID  */
#line 292 "gocompiler.y"
                                                                                                                        {printf("81\n");}
#line 1914 "y.tab.c"
    break;

  case 83: /* Expr: FuncInvocation  */
#line 294 "gocompiler.y"
                                                                                                                        {printf("82\n");}
#line 1920 "y.tab.c"
    break;

  case 84: /* Expr: LPAR Expr RPAR  */
#line 296 "gocompiler.y"
                                                                                                                        {printf("83\n");}
#line 1926 "y.tab.c"
    break;

  case 85: /* Expr: LPAR error RPAR  */
#line 300 "gocompiler.y"
                                                                                                                        {printf("84\n");}
#line 1932 "y.tab.c"
    break;


#line 1936 "y.tab.c"

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

#line 302 "gocompiler.y"


