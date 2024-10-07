/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "sintatic.y"

    #include <stdio.h>
    #include <iostream>
    #include <vector>
    #include <string>
    std::string errorLine;
    extern int yylineno;
    // Definiciones para el rastreo de ubicaciones
    /*#define YYLTYPE_IS_DECLARED 1
    typedef struct YYLTYPE {
        int first_line;
        int first_column;
        int last_line;
        int last_column;
    } YYLTYPE;*/

    extern FILE *yyin;
    //extern int yyerrstatus = 0;
    int yyerror(/*YYLTYPE *yylloc, */std::string s);

    typedef struct Nodo{
        std::string nombre;
        std::string valor;
        std::vector<Nodo*> hijos;
        std::string anotacion;
        int noLinea;
    } Nodo;
    Nodo *inicial = new struct Nodo;
    int yylex(void);
    void printNode(Nodo *init, int tabuladores);
    Nodo* getSintactic(const char* filename);
    void freeNode(Nodo *init);

    extern int yylineno;
    extern int column;
    extern char *lineptr;
    #define YYERROR_VERBOSE 1

#line 110 "sintatic.tab.c"

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

#include "sintatic.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_THEN = 5,                       /* THEN  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_FI = 7,                         /* FI  */
  YYSYMBOL_DO = 8,                         /* DO  */
  YYSYMBOL_UNTIL = 9,                      /* UNTIL  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_BREAK = 11,                     /* BREAK  */
  YYSYMBOL_READ = 12,                      /* READ  */
  YYSYMBOL_WRITE = 13,                     /* WRITE  */
  YYSYMBOL_FLOAT = 14,                     /* FLOAT  */
  YYSYMBOL_INT = 15,                       /* INT  */
  YYSYMBOL_BOOL = 16,                      /* BOOL  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_TRUE = 20,                      /* TRUE  */
  YYSYMBOL_FALSE = 21,                     /* FALSE  */
  YYSYMBOL_MAS = 22,                       /* MAS  */
  YYSYMBOL_RES = 23,                       /* RES  */
  YYSYMBOL_MUL = 24,                       /* MUL  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_ELE = 26,                       /* ELE  */
  YYSYMBOL_MEN = 27,                       /* MEN  */
  YYSYMBOL_MENIGL = 28,                    /* MENIGL  */
  YYSYMBOL_MAY = 29,                       /* MAY  */
  YYSYMBOL_MAYIGL = 30,                    /* MAYIGL  */
  YYSYMBOL_IGU = 31,                       /* IGU  */
  YYSYMBOL_DIS = 32,                       /* DIS  */
  YYSYMBOL_ASIG = 33,                      /* ASIG  */
  YYSYMBOL_PYC = 34,                       /* PYC  */
  YYSYMBOL_COM = 35,                       /* COM  */
  YYSYMBOL_PI = 36,                        /* PI  */
  YYSYMBOL_PD = 37,                        /* PD  */
  YYSYMBOL_LI = 38,                        /* LI  */
  YYSYMBOL_LD = 39,                        /* LD  */
  YYSYMBOL_CADENA = 40,                    /* CADENA  */
  YYSYMBOL_NUMERO = 41,                    /* NUMERO  */
  YYSYMBOL_IDENTIFICADOR = 42,             /* IDENTIFICADOR  */
  YYSYMBOL_OTRO = 43,                      /* OTRO  */
  YYSYMBOL_SPACE = 44,                     /* SPACE  */
  YYSYMBOL_SALTOLINEA = 45,                /* SALTOLINEA  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_48_list_decl = 48,              /* list-decl  */
  YYSYMBOL_decl = 49,                      /* decl  */
  YYSYMBOL_tipo = 50,                      /* tipo  */
  YYSYMBOL_51_list_id = 51,                /* list-id  */
  YYSYMBOL_52_list_sent = 52,              /* list-sent  */
  YYSYMBOL_sent = 53,                      /* sent  */
  YYSYMBOL_54_sent_if = 54,                /* sent-if  */
  YYSYMBOL_55_sent_while = 55,             /* sent-while  */
  YYSYMBOL_56_sent_do = 56,                /* sent-do  */
  YYSYMBOL_57_sent_read = 57,              /* sent-read  */
  YYSYMBOL_58_sent_write = 58,             /* sent-write  */
  YYSYMBOL_bloque = 59,                    /* bloque  */
  YYSYMBOL_60_sent_assign = 60,            /* sent-assign  */
  YYSYMBOL_61_exp_bool = 61,               /* exp-bool  */
  YYSYMBOL_comb = 62,                      /* comb  */
  YYSYMBOL_igualdad = 63,                  /* igualdad  */
  YYSYMBOL_rel = 64,                       /* rel  */
  YYSYMBOL_65_op_rel = 65,                 /* op-rel  */
  YYSYMBOL_expr = 66,                      /* expr  */
  YYSYMBOL_term = 67,                      /* term  */
  YYSYMBOL_unario = 68,                    /* unario  */
  YYSYMBOL_factor = 69                     /* factor  */
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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   278

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   120,   120,   130,   133,   143,   152,   161,   169,   177,
     185,   195,   204,   212,   220,   230,   233,   243,   249,   254,
     259,   264,   269,   274,   288,   297,   307,   315,   323,   331,
     339,   346,   354,   362,   370,   378,   386,   394,   402,   410,
     418,   426,   434,   442,   450,   458,   466,   474,   482,   490,
     499,   507,   515,   523,   531,   540,   549,   557,   565,   575,
     584,   592,   600,   608,   616,   624,   632,   640,   648,   656,
     664,   672,   680,   687,   695,   703,   711,   722,   730,   738,
     746,   756,   764,   774,   784,   798,   806,   814,   824,   833,
     840,   849,   856,   865,   874,   881,   891,   897,   905,   913,
     921,   929,   938,   947,   956,   963,   973,   982,   988,   996,
    1004,  1010,  1019,  1027,  1035,  1043,  1051
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
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "IF",
  "THEN", "ELSE", "FI", "DO", "UNTIL", "WHILE", "BREAK", "READ", "WRITE",
  "FLOAT", "INT", "BOOL", "NOT", "AND", "OR", "TRUE", "FALSE", "MAS",
  "RES", "MUL", "DIV", "ELE", "MEN", "MENIGL", "MAY", "MAYIGL", "IGU",
  "DIS", "ASIG", "PYC", "COM", "PI", "PD", "LI", "LD", "CADENA", "NUMERO",
  "IDENTIFICADOR", "OTRO", "SPACE", "SALTOLINEA", "$accept", "program",
  "list-decl", "decl", "tipo", "list-id", "list-sent", "sent", "sent-if",
  "sent-while", "sent-do", "sent-read", "sent-write", "bloque",
  "sent-assign", "exp-bool", "comb", "igualdad", "rel", "op-rel", "expr",
  "term", "unario", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      75,   -21,    94,   -44,   -44,    26,   -44,   -44,   -44,   -44,
     -44,    14,   119,   139,    96,   -44,   174,    63,    24,    71,
     -44,     3,    34,   -44,    11,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,    74,   197,    60,    97,   -44,    70,
     161,    97,   -44,   154,   110,    97,   101,   102,   156,    97,
     -44,   -44,    97,    97,   -44,   -44,   -11,   153,   209,   -44,
     199,   220,   -44,   -44,   120,   136,   -44,     9,    12,   -44,
     211,   127,    55,   -44,    50,   -44,   -44,    97,   185,   -44,
      97,   -44,   103,   171,   -44,    90,   241,    97,   -44,   105,
     -44,   -44,   -44,   -44,   -44,   143,    97,   -44,    97,    97,
      97,   -44,    97,    97,   -44,   -44,   -44,   -44,    97,    97,
      97,   -44,   181,    54,   -44,   219,   -44,    13,   110,   -44,
     248,   210,   238,   168,   -44,   177,    81,   -44,   -44,    97,
     -44,   182,    21,   -44,   153,   209,   -44,   -44,   220,   220,
     224,   -44,   -44,   -44,   110,   -44,   -44,   249,   110,   110,
      25,   110,    47,   255,   -44,   -44,   256,   -44,   257,   187,
     258,   -44,   -44,   253,   110,   254,   242,   138,   231,    15,
     -44,   206,   -44,   -44,   -44,   228,   -44,   -44,   259,   -44,
     110,   -44,   110,   -44,   260,   110,    51,   -44,   110,   110,
     110,    83,   -44,   -44,   261,   262,   -44,   263,   264,    17,
     271,   272,   273,   -44,   274,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,    10,     8,     7,     9,
       4,     0,     0,     6,     0,    12,     0,     0,     0,     0,
      23,     0,     0,     2,     0,    16,    17,    18,    19,    20,
      21,    22,    13,     5,     0,    26,     0,     0,    60,     0,
      64,     0,    15,     0,    56,     0,    78,     0,   116,     0,
     114,   115,     0,     0,   113,   112,     0,    89,    91,    94,
       0,   104,   107,   110,    85,     0,    11,     0,     0,    30,
       0,   116,     0,   116,     0,    62,    70,     0,     0,    75,
       0,    74,     0,     0,    61,     0,     0,     0,    57,     0,
      80,    79,    77,   108,   109,     0,     0,    81,     0,     0,
       0,   101,     0,     0,    97,    98,    99,   100,     0,     0,
       0,    87,   116,     0,    28,     0,    32,     0,     0,    46,
       0,     0,     0,     0,    68,     0,     0,    83,    65,     0,
      67,     0,     0,   111,    88,    90,    92,    93,   103,   102,
      95,   105,   106,    84,     0,    33,    45,     0,     0,    27,
       0,    47,     0,     0,    76,    63,     0,    73,     0,     0,
       0,    58,    55,     0,     0,     0,     0,    29,     0,     0,
      48,     0,    69,    72,    71,     0,    66,    41,     0,    43,
       0,    42,     0,    44,     0,     0,     0,    24,     0,     0,
      49,     0,    59,    39,     0,     0,    40,     0,    31,     0,
       0,     0,     0,    50,     0,    35,    36,    37,    38,    34,
      25,    54,    52,    53,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   -44,   -44,   -44,   -44,   221,   -44,   -44,   -44,
     -44,   -44,   -44,   -39,   -44,   -34,   169,   166,   151,   -44,
     170,   150,   -43,   -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     5,    10,    11,    16,    12,    25,    26,    27,
      28,    29,    30,    43,    31,    56,    57,    58,    59,   108,
      60,    61,    62,    63
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    81,    72,    74,    46,    88,    93,    82,    96,    94,
     114,    89,    64,   116,   145,    13,   188,     3,   209,    95,
     146,   189,   161,    97,   210,    38,   167,     6,   115,   117,
     -15,   113,   120,    39,   -15,    48,   -15,   -15,   -15,   -15,
       7,     8,     9,   123,    65,    47,   125,    42,   170,    14,
      42,    49,   198,   131,    50,    51,    15,    52,    40,    42,
      41,    71,    42,    42,    35,   -15,   141,   142,   -15,    96,
      53,    75,    44,    96,    96,    54,    55,    49,     1,   147,
      50,    51,   155,    52,   203,    42,   122,   158,   143,    42,
     156,   128,   121,   162,     4,   159,    53,    32,    73,    36,
      37,    54,    55,    91,    76,   163,    77,    45,    42,   165,
     166,   168,   169,   171,    49,   157,    66,    50,    51,    42,
      52,    42,    96,    17,    96,   178,   129,    18,   184,    19,
      20,    21,    22,    53,   119,    90,    92,   112,    54,    55,
     126,   194,   132,   195,   182,   183,   197,   199,    42,   200,
     201,   202,   204,    49,   111,    84,    50,    51,    23,    52,
     -82,    24,    96,    85,   -82,    42,   -82,   -82,   -82,   -82,
      79,    98,    53,   -14,   -14,    17,    42,    54,    55,    18,
     133,    19,    20,    21,    22,   -86,   124,    96,    86,   -86,
      87,   -86,   -86,   -86,   -86,   -82,    96,    80,   -82,    42,
     101,    96,    67,    68,    69,   153,    96,   190,    33,    34,
     127,   149,   191,    24,   154,   150,   118,   -96,   -96,   160,
     -86,   102,   103,   -86,   175,   144,   104,   105,   106,   107,
     -96,   -96,   185,   -96,    70,   -96,   -96,   186,   187,   151,
      99,   100,   130,   152,   109,   110,   102,   103,   180,   181,
     136,   137,   138,   139,   148,   164,   172,   173,   174,   176,
     177,   179,   192,    83,   135,   134,   193,   196,   205,   206,
     207,   208,   211,   212,   213,   214,     0,     0,   140
};

static const yytype_int16 yycheck[] =
{
      39,    40,    36,    37,     1,    44,    49,    41,    19,    52,
       1,    45,     1,     1,     1,     1,     1,    38,     1,    53,
       7,     6,     1,    34,     7,     1,     1,     1,    67,    68,
       4,    65,    71,     9,     8,     1,    10,    11,    12,    13,
      14,    15,    16,    77,    33,    42,    80,    38,     1,    35,
      38,    17,     1,    87,    20,    21,    42,    23,    34,    38,
      36,     1,    38,    38,     1,    39,   109,   110,    42,    19,
      36,     1,     1,    19,    19,    41,    42,    17,     3,   118,
      20,    21,     1,    23,     1,    38,    36,   126,    34,    38,
       9,     1,    37,   132,     0,   129,    36,     1,     1,    36,
      37,    41,    42,     1,    34,   144,    36,    36,    38,   148,
     149,   150,   151,   152,    17,    34,    42,    20,    21,    38,
      23,    38,    19,     4,    19,   164,    36,     8,   167,    10,
      11,    12,    13,    36,     7,    34,    34,     1,    41,    42,
      37,   180,    37,   182,     6,     7,   185,   186,    38,   188,
     189,   190,   191,    17,    34,     1,    20,    21,    39,    23,
       4,    42,    19,     9,     8,    38,    10,    11,    12,    13,
       9,    18,    36,    34,    35,     4,    38,    41,    42,     8,
      37,    10,    11,    12,    13,     4,     1,    19,    34,     8,
      36,    10,    11,    12,    13,    39,    19,    36,    42,    38,
       1,    19,     5,     6,     7,    37,    19,     1,    34,    35,
      39,     1,     6,    42,    37,     5,     5,    18,    19,    37,
      39,    22,    23,    42,    37,     6,    27,    28,    29,    30,
      31,    32,     1,    34,    37,    36,    37,     6,     7,     1,
      31,    32,     1,     5,    24,    25,    22,    23,     6,     7,
      99,   100,   102,   103,     6,     6,     1,     1,     1,     1,
       7,     7,    34,    42,    98,    96,     7,     7,     7,     7,
       7,     7,     1,     1,     1,     1,    -1,    -1,   108
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,    38,     0,    48,     1,    14,    15,    16,
      49,    50,    52,     1,    35,    42,    51,     4,     8,    10,
      11,    12,    13,    39,    42,    53,    54,    55,    56,    57,
      58,    60,     1,    34,    35,     1,    36,    37,     1,     9,
      34,    36,    38,    59,     1,    36,     1,    42,     1,    17,
      20,    21,    23,    36,    41,    42,    61,    62,    63,    64,
      66,    67,    68,    69,     1,    33,    42,     5,     6,     7,
      37,     1,    61,     1,    61,     1,    34,    36,    59,     9,
      36,    59,    61,    52,     1,     9,    34,    36,    59,    61,
      34,     1,    34,    68,    68,    61,    19,    34,    18,    31,
      32,     1,    22,    23,    27,    28,    29,    30,    65,    24,
      25,    34,     1,    61,     1,    59,     1,    59,     5,     7,
      59,    37,    36,    61,     1,    61,    37,    39,     1,    36,
       1,    61,    37,    37,    62,    63,    64,    64,    67,    67,
      66,    68,    68,    34,     6,     1,     7,    59,     6,     1,
       5,     1,     5,    37,    37,     1,     9,    34,    59,    61,
      37,     1,    59,    59,     6,    59,    59,     1,    59,    59,
       1,    59,     1,     1,     1,    37,     1,     7,    59,     7,
       6,     7,     6,     7,    59,     1,     6,     7,     1,     6,
       1,     6,    34,     7,    59,    59,     7,    59,     1,    59,
      59,    59,    59,     1,    59,     7,     7,     7,     7,     1,
       7,     1,     1,     1,     1
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    50,
      50,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    59,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     2,     3,     2,     1,     1,     1,
       1,     3,     1,     2,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     7,     9,     2,     5,     4,     6,
       3,     8,     4,     5,     9,     9,     9,     9,     9,     8,
       8,     7,     7,     7,     7,     5,     4,     5,     6,     7,
       8,     9,     9,     9,     9,     5,     2,     3,     5,     7,
       2,     3,     3,     5,     2,     4,     6,     4,     4,     6,
       3,     6,     6,     5,     3,     3,     5,     3,     2,     3,
       3,     3,     2,     3,     4,     2,     3,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     1,     2,     2,
       1,     3,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
    YYNOMEM;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: PROGRAM LI list-decl list-sent LD  */
#line 120 "sintatic.y"
                                         {
            std::cout << "program\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "program";
            (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1443 "sintatic.tab.c"
    break;

  case 3: /* list-decl: %empty  */
#line 130 "sintatic.y"
        {
            (yyval.nodo) = NULL;
        }
#line 1451 "sintatic.tab.c"
    break;

  case 4: /* list-decl: list-decl decl  */
#line 133 "sintatic.y"
                         {
            std::cout << "list-decl decl\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "list-decl";
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1465 "sintatic.tab.c"
    break;

  case 5: /* decl: tipo list-id PYC  */
#line 143 "sintatic.y"
                        {
            std::cout << "tipo list-id;\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "decl";
            (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1479 "sintatic.tab.c"
    break;

  case 6: /* decl: tipo error  */
#line 152 "sintatic.y"
                    {
            std::cout << "Error decl - tipo error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "declaracion - tipo error, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1492 "sintatic.tab.c"
    break;

  case 7: /* tipo: INT  */
#line 161 "sintatic.y"
            {
            std::cout << "int\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "tipo";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 1505 "sintatic.tab.c"
    break;

  case 8: /* tipo: FLOAT  */
#line 169 "sintatic.y"
                {
            std::cout << "float\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "tipo";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 1518 "sintatic.tab.c"
    break;

  case 9: /* tipo: BOOL  */
#line 177 "sintatic.y"
               {
            std::cout << "bool\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "tipo";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 1531 "sintatic.tab.c"
    break;

  case 10: /* tipo: error  */
#line 185 "sintatic.y"
                {
                std::cout << "Error tipo\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "Error sintactico";
                (yyval.nodo)->valor = "falta tipo, linea: " + errorLine;
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
                yyerrok;
        }
#line 1545 "sintatic.tab.c"
    break;

  case 11: /* list-id: list-id COM IDENTIFICADOR  */
#line 195 "sintatic.y"
                                   {
                std::cout << "list-id, id: " << (yyvsp[0].cadena) << "\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "list-id";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 1559 "sintatic.tab.c"
    break;

  case 12: /* list-id: IDENTIFICADOR  */
#line 204 "sintatic.y"
                        {
            std::cout << "id: " << (yyvsp[0].cadena) << "\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "identificador";
            (yyval.nodo)->valor = (yyvsp[0].cadena);
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1572 "sintatic.tab.c"
    break;

  case 13: /* list-id: COM error  */
#line 212 "sintatic.y"
                   {
            std::cout << "Error id\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta id, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1585 "sintatic.tab.c"
    break;

  case 14: /* list-id: error  */
#line 220 "sintatic.y"
               {
            std::cout << "Error id\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta id, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1598 "sintatic.tab.c"
    break;

  case 15: /* list-sent: %empty  */
#line 230 "sintatic.y"
        {
            (yyval.nodo) = NULL;
        }
#line 1606 "sintatic.tab.c"
    break;

  case 16: /* list-sent: list-sent sent  */
#line 233 "sintatic.y"
                         {
            std::cout << "list-sent sent\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "list-sent";
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1620 "sintatic.tab.c"
    break;

  case 17: /* sent: sent-if  */
#line 243 "sintatic.y"
                {
            std::cout << "sent-if\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
                
            }
#line 1631 "sintatic.tab.c"
    break;

  case 18: /* sent: sent-while  */
#line 249 "sintatic.y"
                     {
            std::cout << "sent-while\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 1641 "sintatic.tab.c"
    break;

  case 19: /* sent: sent-do  */
#line 254 "sintatic.y"
                  {
            std::cout << "sent-do\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 1651 "sintatic.tab.c"
    break;

  case 20: /* sent: sent-read  */
#line 259 "sintatic.y"
                    {
            std::cout << "sent-read \n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 1661 "sintatic.tab.c"
    break;

  case 21: /* sent: sent-write  */
#line 264 "sintatic.y"
                     {
            std::cout << "sent-write\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 1671 "sintatic.tab.c"
    break;

  case 22: /* sent: sent-assign  */
#line 269 "sintatic.y"
                      {
            std::cout << "sent-assign\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 1681 "sintatic.tab.c"
    break;

  case 23: /* sent: BREAK  */
#line 274 "sintatic.y"
                {
            std::cout << "break\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "break";
                inicial = (yyval.nodo);
            }
#line 1692 "sintatic.tab.c"
    break;

  case 24: /* sent-if: IF PI exp-bool PD THEN bloque FI  */
#line 288 "sintatic.y"
                                         {
            std::cout << "if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "sent-if";
            (yyval.nodo)->hijos.push_back((yyvsp[-4].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
            }
#line 1706 "sintatic.tab.c"
    break;

  case 25: /* sent-if: IF PI exp-bool PD THEN bloque ELSE bloque FI  */
#line 297 "sintatic.y"
                                                       {
            std::cout << "if-else\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "sent-if-else";
            (yyval.nodo)->hijos.push_back((yyvsp[-6].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[-3].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
            }
#line 1721 "sintatic.tab.c"
    break;

  case 26: /* sent-if: IF error  */
#line 307 "sintatic.y"
                  {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta condicion entre parentesis, then y el bloque y finalizacion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1734 "sintatic.tab.c"
    break;

  case 27: /* sent-if: IF PI exp-bool PD error  */
#line 315 "sintatic.y"
                                 {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta then, el bloque y finalizacion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1747 "sintatic.tab.c"
    break;

  case 28: /* sent-if: IF error THEN error  */
#line 323 "sintatic.y"
                             {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta condicion, el bloque y finalizacion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1760 "sintatic.tab.c"
    break;

  case 29: /* sent-if: IF PI exp-bool PD THEN error  */
#line 331 "sintatic.y"
                                      {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta bloque y finalizacion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1773 "sintatic.tab.c"
    break;

  case 30: /* sent-if: IF error FI  */
#line 339 "sintatic.y"
                     {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta condicion y bloque, linea: " + errorLine;
            inicial = (yyval.nodo);
        }
#line 1785 "sintatic.tab.c"
    break;

  case 31: /* sent-if: IF PI exp-bool PD THEN bloque ELSE error  */
#line 346 "sintatic.y"
                                                  {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if-else falta bloque y finalizacion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1798 "sintatic.tab.c"
    break;

  case 32: /* sent-if: IF error ELSE error  */
#line 354 "sintatic.y"
                             {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if-else falta bloque if, bloque else y finalizacion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1811 "sintatic.tab.c"
    break;

  case 33: /* sent-if: IF error ELSE bloque error  */
#line 362 "sintatic.y"
                                    {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if-else falta bloque if, finalizacion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1824 "sintatic.tab.c"
    break;

  case 34: /* sent-if: IF PI exp-bool PD THEN bloque ELSE bloque error  */
#line 370 "sintatic.y"
                                                         {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if-else falta finalizacion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1837 "sintatic.tab.c"
    break;

  case 35: /* sent-if: IF PI exp-bool PD error bloque ELSE bloque FI  */
#line 378 "sintatic.y"
                                                        {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta THEN, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1850 "sintatic.tab.c"
    break;

  case 36: /* sent-if: IF PI exp-bool PD THEN error ELSE bloque FI  */
#line 386 "sintatic.y"
                                                      {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta bloque siguiente, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1863 "sintatic.tab.c"
    break;

  case 37: /* sent-if: IF PI exp-bool PD THEN bloque error bloque FI  */
#line 394 "sintatic.y"
                                                        {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta sentencia else, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1876 "sintatic.tab.c"
    break;

  case 38: /* sent-if: IF PI exp-bool PD THEN bloque ELSE error FI  */
#line 402 "sintatic.y"
                                                      {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta bloque después de else, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1889 "sintatic.tab.c"
    break;

  case 39: /* sent-if: IF error PD THEN bloque ELSE bloque FI  */
#line 410 "sintatic.y"
                                                 {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta paréntesis de inicio y expresión boleana, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1902 "sintatic.tab.c"
    break;

  case 40: /* sent-if: IF PI exp-bool PD THEN error bloque FI  */
#line 418 "sintatic.y"
                                                 {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta paréntesis de termino y THEN, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1915 "sintatic.tab.c"
    break;

  case 41: /* sent-if: IF error THEN bloque ELSE bloque FI  */
#line 426 "sintatic.y"
                                              {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta paréntesis de inicio, termino y expresión, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1928 "sintatic.tab.c"
    break;

  case 42: /* sent-if: IF PI exp-bool PD error bloque FI  */
#line 434 "sintatic.y"
                                            {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta THEN, ELSE y bloque, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1941 "sintatic.tab.c"
    break;

  case 43: /* sent-if: IF PI error bloque ELSE bloque FI  */
#line 442 "sintatic.y"
                                            {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta expresión boleana, THEN, ELSE y bloque, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1954 "sintatic.tab.c"
    break;

  case 44: /* sent-if: IF PI exp-bool PD THEN error FI  */
#line 450 "sintatic.y"
                                          {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta bloque, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1967 "sintatic.tab.c"
    break;

  case 45: /* sent-if: IF error ELSE bloque FI  */
#line 458 "sintatic.y"
                                  {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta bloque, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1980 "sintatic.tab.c"
    break;

  case 46: /* sent-if: IF PI error FI  */
#line 466 "sintatic.y"
                         {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta Exoresión, Parentesis derecho, THEN, bloque, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 1993 "sintatic.tab.c"
    break;

  case 47: /* sent-if: IF PD exp-bool PI error  */
#line 474 "sintatic.y"
                                 {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta THEN, bloque, FI, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2006 "sintatic.tab.c"
    break;

  case 48: /* sent-if: IF PD exp-bool PI THEN error  */
#line 482 "sintatic.y"
                                      {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta bloque, FI, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2019 "sintatic.tab.c"
    break;

  case 49: /* sent-if: IF PD exp-bool PI THEN bloque error  */
#line 490 "sintatic.y"
                                             {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta FI, linea: " + errorLine;
            
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2033 "sintatic.tab.c"
    break;

  case 50: /* sent-if: IF PD exp-bool PI THEN bloque ELSE error  */
#line 499 "sintatic.y"
                                                  {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta bloque, FI, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2046 "sintatic.tab.c"
    break;

  case 51: /* sent-if: IF PD exp-bool PI THEN bloque ELSE bloque error  */
#line 507 "sintatic.y"
                                                         {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta FI, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2059 "sintatic.tab.c"
    break;

  case 52: /* sent-if: IF PD exp-bool PI error bloque ELSE bloque error  */
#line 515 "sintatic.y"
                                                          {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta, THEN, FI, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2072 "sintatic.tab.c"
    break;

  case 53: /* sent-if: IF PD exp-bool PI THEN bloque error bloque error  */
#line 523 "sintatic.y"
                                                          {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta, ELSE, FI, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2085 "sintatic.tab.c"
    break;

  case 54: /* sent-if: IF PD exp-bool PI error bloque error bloque error  */
#line 531 "sintatic.y"
                                                           {
            std::cout << "Error if\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta, THEN, ELSE, FI, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2098 "sintatic.tab.c"
    break;

  case 55: /* sent-while: WHILE PI exp-bool PD bloque  */
#line 540 "sintatic.y"
                                    {
            std::cout << "while\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "sent-while";
            (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2112 "sintatic.tab.c"
    break;

  case 56: /* sent-while: WHILE error  */
#line 549 "sintatic.y"
                     {
            std::cout << "Error while\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "while falta condicion entre parentesis y cuerpo, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2125 "sintatic.tab.c"
    break;

  case 57: /* sent-while: WHILE error bloque  */
#line 557 "sintatic.y"
                            {
            std::cout << "Error while\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "while falta expresion entre parentesis, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2138 "sintatic.tab.c"
    break;

  case 58: /* sent-while: WHILE PI exp-bool PD error  */
#line 565 "sintatic.y"
                                    {
            std::cout << "Error while\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "while falta bloque, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2151 "sintatic.tab.c"
    break;

  case 59: /* sent-do: DO bloque UNTIL PI exp-bool PD PYC  */
#line 575 "sintatic.y"
                                           {
            std::cout << "do\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent-do";
                (yyval.nodo)->hijos.push_back((yyvsp[-5].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2165 "sintatic.tab.c"
    break;

  case 60: /* sent-do: DO error  */
#line 584 "sintatic.y"
                  {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta cuerpo, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2178 "sintatic.tab.c"
    break;

  case 61: /* sent-do: DO bloque error  */
#line 592 "sintatic.y"
                         {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta until, condicion y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2191 "sintatic.tab.c"
    break;

  case 62: /* sent-do: DO UNTIL error  */
#line 600 "sintatic.y"
                        {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, condicion y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2204 "sintatic.tab.c"
    break;

  case 63: /* sent-do: DO PI exp-bool PD error  */
#line 608 "sintatic.y"
                                 {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2217 "sintatic.tab.c"
    break;

  case 64: /* sent-do: DO PYC  */
#line 616 "sintatic.y"
                {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y condicion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2230 "sintatic.tab.c"
    break;

  case 65: /* sent-do: DO bloque UNTIL error  */
#line 624 "sintatic.y"
                               {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta condicion y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2243 "sintatic.tab.c"
    break;

  case 66: /* sent-do: DO bloque PI exp-bool PD error  */
#line 632 "sintatic.y"
                                        {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta condicion y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2256 "sintatic.tab.c"
    break;

  case 67: /* sent-do: DO bloque PYC error  */
#line 640 "sintatic.y"
                             {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta condicion y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2269 "sintatic.tab.c"
    break;

  case 68: /* sent-do: DO UNTIL bloque error  */
#line 648 "sintatic.y"
                               {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do desorganizado, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2282 "sintatic.tab.c"
    break;

  case 69: /* sent-do: DO UNTIL PI exp-bool PD error  */
#line 656 "sintatic.y"
                                       {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do desorganizado, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2295 "sintatic.tab.c"
    break;

  case 70: /* sent-do: DO UNTIL PYC  */
#line 664 "sintatic.y"
                      {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do desorganizado, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2308 "sintatic.tab.c"
    break;

  case 71: /* sent-do: DO PI exp-bool PD bloque error  */
#line 672 "sintatic.y"
                                        {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2321 "sintatic.tab.c"
    break;

  case 72: /* sent-do: DO PI exp-bool PD UNTIL error  */
#line 680 "sintatic.y"
                                       {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            inicial = (yyval.nodo);
        }
#line 2333 "sintatic.tab.c"
    break;

  case 73: /* sent-do: DO PI exp-bool PD PYC  */
#line 687 "sintatic.y"
                               {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2346 "sintatic.tab.c"
    break;

  case 74: /* sent-do: DO PYC bloque  */
#line 695 "sintatic.y"
                       {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2359 "sintatic.tab.c"
    break;

  case 75: /* sent-do: DO PYC UNTIL  */
#line 703 "sintatic.y"
                      {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2372 "sintatic.tab.c"
    break;

  case 76: /* sent-do: DO PYC PI exp-bool PD  */
#line 711 "sintatic.y"
                               {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2385 "sintatic.tab.c"
    break;

  case 77: /* sent-read: READ IDENTIFICADOR PYC  */
#line 722 "sintatic.y"
                               {
            std::cout << "read\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "read";
            (yyval.nodo)->valor = (yyvsp[-1].cadena);
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2398 "sintatic.tab.c"
    break;

  case 78: /* sent-read: READ error  */
#line 730 "sintatic.y"
                    {
            std::cout << "Error read\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "read sentencia incompleta, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2411 "sintatic.tab.c"
    break;

  case 79: /* sent-read: READ IDENTIFICADOR error  */
#line 738 "sintatic.y"
                                  {
            std::cout << "Error read\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta punto y coma en read, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2424 "sintatic.tab.c"
    break;

  case 80: /* sent-read: READ error PYC  */
#line 746 "sintatic.y"
                        {
            std::cout << "Error read\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta el id para leer, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2437 "sintatic.tab.c"
    break;

  case 81: /* sent-write: WRITE exp-bool PYC  */
#line 756 "sintatic.y"
                           {
            std::cout << "write\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "write";
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2450 "sintatic.tab.c"
    break;

  case 82: /* sent-write: WRITE error  */
#line 764 "sintatic.y"
                     {
            std::cout << "Error write\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "write sentencia incompleta, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2463 "sintatic.tab.c"
    break;

  case 83: /* bloque: LI list-sent LD  */
#line 774 "sintatic.y"
                        {
            std::cout << "bloque\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "bloque";
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2476 "sintatic.tab.c"
    break;

  case 84: /* sent-assign: IDENTIFICADOR ASIG exp-bool PYC  */
#line 784 "sintatic.y"
                                        {
            std::cout << "id=exp-bool;\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent-assign";
                (yyval.nodo)->noLinea = yylineno;
                Nodo *id = new struct Nodo;
                id->nombre = "identificador";
                id->valor = (yyvsp[-3].cadena)[0];
                id->noLinea = yylineno;
                (yyval.nodo)->hijos.push_back(id);
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                inicial = (yyval.nodo);
            }
#line 2494 "sintatic.tab.c"
    break;

  case 85: /* sent-assign: IDENTIFICADOR error  */
#line 798 "sintatic.y"
                             {
            std::cout << "Error assign\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta la sentencia de asignacion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2507 "sintatic.tab.c"
    break;

  case 86: /* sent-assign: IDENTIFICADOR ASIG error  */
#line 806 "sintatic.y"
                                  {
            std::cout << "Error assign\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta la expresion de asignación y un punto y coma, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2520 "sintatic.tab.c"
    break;

  case 87: /* sent-assign: IDENTIFICADOR error PYC  */
#line 814 "sintatic.y"
                                 {
            std::cout << "Error assign\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta la asignacion y la expresion, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2533 "sintatic.tab.c"
    break;

  case 88: /* exp-bool: exp-bool OR comb  */
#line 824 "sintatic.y"
                          {
            std::cout << "or\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "or";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2547 "sintatic.tab.c"
    break;

  case 89: /* exp-bool: comb  */
#line 833 "sintatic.y"
               {
            std::cout << "comb\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 2557 "sintatic.tab.c"
    break;

  case 90: /* comb: comb AND igualdad  */
#line 840 "sintatic.y"
                          {
            std::cout << "and\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "and";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2571 "sintatic.tab.c"
    break;

  case 91: /* comb: igualdad  */
#line 849 "sintatic.y"
                   {
            std::cout << "igualdad\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 2581 "sintatic.tab.c"
    break;

  case 92: /* igualdad: igualdad IGU rel  */
#line 856 "sintatic.y"
                         {
            std::cout << "igu\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "igualdad";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2595 "sintatic.tab.c"
    break;

  case 93: /* igualdad: igualdad DIS rel  */
#line 865 "sintatic.y"
                           {
            std::cout << "dis\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "distinto";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2609 "sintatic.tab.c"
    break;

  case 94: /* igualdad: rel  */
#line 874 "sintatic.y"
              {
            std::cout << "rel\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 2619 "sintatic.tab.c"
    break;

  case 95: /* rel: expr op-rel expr  */
#line 881 "sintatic.y"
                         {
            std::cout << "expr op-rel expr\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "op-rel";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2634 "sintatic.tab.c"
    break;

  case 96: /* rel: expr  */
#line 891 "sintatic.y"
               {
            std::cout << "expr\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 2644 "sintatic.tab.c"
    break;

  case 97: /* op-rel: MEN  */
#line 897 "sintatic.y"
            {
            std::cout << "men\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "men";
            (yyval.nodo)->valor = (yyvsp[0].cadena);
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2657 "sintatic.tab.c"
    break;

  case 98: /* op-rel: MENIGL  */
#line 905 "sintatic.y"
                 {
            std::cout << "menigl\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "menigl";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2670 "sintatic.tab.c"
    break;

  case 99: /* op-rel: MAY  */
#line 913 "sintatic.y"
              {
            std::cout << "may\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "may";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2683 "sintatic.tab.c"
    break;

  case 100: /* op-rel: MAYIGL  */
#line 921 "sintatic.y"
                 {
            std::cout << "mayigl\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "mayigl";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2696 "sintatic.tab.c"
    break;

  case 101: /* op-rel: error  */
#line 929 "sintatic.y"
              {
            std::cout << "Error op-rel\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta op-rel, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2709 "sintatic.tab.c"
    break;

  case 102: /* expr: expr RES term  */
#line 938 "sintatic.y"
                      {
            std::cout << "res\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "resta";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2723 "sintatic.tab.c"
    break;

  case 103: /* expr: expr MAS term  */
#line 947 "sintatic.y"
                        {
            std::cout << "mas\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "suma";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2737 "sintatic.tab.c"
    break;

  case 104: /* expr: term  */
#line 956 "sintatic.y"
               {
            std::cout << "term\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 2747 "sintatic.tab.c"
    break;

  case 105: /* term: term MUL unario  */
#line 963 "sintatic.y"
                        {
            std::cout << "mul\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "multiplicacion";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            
            }
#line 2762 "sintatic.tab.c"
    break;

  case 106: /* term: term DIV unario  */
#line 973 "sintatic.y"
                          {
            std::cout << "div\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "division";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2776 "sintatic.tab.c"
    break;

  case 107: /* term: unario  */
#line 982 "sintatic.y"
                 {
            std::cout << "Unario\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 2786 "sintatic.tab.c"
    break;

  case 108: /* unario: NOT unario  */
#line 988 "sintatic.y"
                   {
            std::cout << "Not unario\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "negacion";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2799 "sintatic.tab.c"
    break;

  case 109: /* unario: RES unario  */
#line 996 "sintatic.y"
                     {
            std::cout << "RES unario\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "menos";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2812 "sintatic.tab.c"
    break;

  case 110: /* unario: factor  */
#line 1004 "sintatic.y"
                 {
            std::cout << "Factor\n";
                (yyval.nodo) = (yyvsp[0].nodo);
                inicial = (yyval.nodo);
            }
#line 2822 "sintatic.tab.c"
    break;

  case 111: /* factor: PI exp-bool PD  */
#line 1010 "sintatic.y"
                       {
            //!Revisar
                std::cout << "(exp-bool)\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "(exp-bool)";
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2836 "sintatic.tab.c"
    break;

  case 112: /* factor: IDENTIFICADOR  */
#line 1019 "sintatic.y"
                        {
                std::cout << "id: "<< (yyvsp[0].cadena) << "\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "identificador";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2849 "sintatic.tab.c"
    break;

  case 113: /* factor: NUMERO  */
#line 1027 "sintatic.y"
                 {
                std::cout << "Numero: " << (yyvsp[0].numero) <<  "\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "numero";
                (yyval.nodo)->valor = std::to_string((yyvsp[0].numero));
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2862 "sintatic.tab.c"
    break;

  case 114: /* factor: TRUE  */
#line 1035 "sintatic.y"
               {
                std::cout << "True\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "true";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2875 "sintatic.tab.c"
    break;

  case 115: /* factor: FALSE  */
#line 1043 "sintatic.y"
                {
                std::cout << "False\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "false";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                (yyval.nodo)->noLinea = yylineno;
                inicial = (yyval.nodo);
            }
#line 2888 "sintatic.tab.c"
    break;

  case 116: /* factor: error  */
#line 1051 "sintatic.y"
              {
            std::cout << "Error factor\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta factor, linea: " + errorLine;
            (yyval.nodo)->noLinea = yylineno;
            inicial = (yyval.nodo);
        }
#line 2901 "sintatic.tab.c"
    break;


#line 2905 "sintatic.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  ++yynerrs;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1059 "sintatic.y"




void printNode(Nodo *init, int tabuladores){
    if(init != NULL){
        for(int i=0; i<tabuladores; i++){
            std::cout<<"  |";
        } 
        std::cout << init->nombre << ": " << init->valor << ", " << init->noLinea << "\n";
        for(int i=0; i<init->hijos.size(); i++){
            printNode(init->hijos.at(i),tabuladores+1);
        }
    }
}

void freeNode(Nodo *init){
    if(init != NULL){
        for(int i=0; i<init->hijos.size(); i++){
            freeNode(init->hijos.at(i));
        }
        free(init);
    }
}

Nodo* getSintactic(const char* filename){
    freeNode(inicial);
    inicial = new struct Nodo;
    FILE *file = fopen(filename, "r");
    if (!file) {
        Nodo *error = new struct Nodo;
        error->nombre = "Error";
        error->valor = "No se pudo abrir el archivo";
        inicial = error;
    }
    yyin = file;
    yyparse();
    fclose(file);
    yylineno = 1;
    return inicial;
}

int yyerror(std::string s){
    std::cout << "error: " << s << " in line " << yylineno << "\n";
    errorLine = std::to_string(yylineno);
    /*std::cout << "Error sin definir\n";
    Nodo *error = new struct Nodo;
    error->nombre = "Error";
    error->valor = s;
    inicial->hijos.push_back(error);*/
    //std::cout << "Error en la línea " << @$.first_line << ", columna: " << @$.first_column;
    return -1;
}

/*int main(int argc, char **argv){
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        Nodo *error = new struct Nodo;
        error->nombre = "Error";
        error->valor = "No se pudo abrir el archivo";
        inicial = error;
    }
    yyin = file;
    yyparse();
    std::cout << "\n---Arbol---\n\n";
    printNode(inicial,0);
    return 0;
}*/
