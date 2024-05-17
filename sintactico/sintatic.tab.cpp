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
#line 2 "sintatic.y"

    #include <stdio.h>
    #include <iostream>
    #include <vector>
    #include <string>

    extern FILE *yyin;
    extern int yylineno; // Línea actual de análisis
    extern int yynerrs; // Número de errores sintácticos
    //extern int yyerrstatus = 0;
    int yyerror(std::string s);

    typedef struct Nodo{
        std::string nombre;
        std::string valor;
        std::vector<Nodo*> hijos;
    } Nodo;
    Nodo *inicial = new struct Nodo;
    int yylex();
    void printNode(Nodo *init, int tabuladores);
    Nodo* getSintactic(const char* filename);
    void freeNode(Nodo *init);


#line 96 "sintatic.tab.cpp"

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

#include "sintatic.tab.hpp"
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
  YYSYMBOL_45_n_ = 45,                     /* '\n'  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

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
      45,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,   102,   102,   122,   124,   127,   135,   146,   148,   154,
     160,   167,   181,   188,   191,   198,   200,   206,   212,   218,
     224,   230,   236,   242,   244,   271,   304,   324,   352,   370,
     385,   399,   401,   420,   431,   437,   439,   450,   456,   458,
     469,   480,   486,   488,   496,   502,   504,   510,   516,   522,
     528,   530,   541,   552,   558,   560,   572,   583,   589,   591,
     601,   611,   617,   619,   634,   640,   646,   652
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
  "IDENTIFICADOR", "OTRO", "SPACE", "'\\n'", "$accept", "program",
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

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -35,   -30,    20,   -80,   -80,   -80,    15,   -11,   -80,
     -80,   -80,   -80,   -27,    38,   -80,   -80,   -22,    16,    32,
       0,    35,   -80,    36,    75,   -80,    55,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,    47,   -80,    75,    48,    52,
      81,    75,    63,    61,    84,   -80,   -80,    84,    75,   -80,
     -80,    13,    82,     9,   -80,   169,    34,   -80,   -80,    75,
     -80,   -16,   -80,    64,    71,    76,   -13,   -80,   186,    69,
     -80,   -80,    -2,    98,   -80,   107,   121,   121,    78,   130,
     130,   -80,   -80,   -80,   -80,   144,    84,    84,    18,   124,
     -80,   -80,    75,     0,   -80,   -80,    87,    82,    88,     9,
      90,   -80,   -80,   -80,    91,    34,    34,    92,    44,   -80,
     -80,   -80,     0,    -1,   -80,   190,   207,   211,   -80,    45,
      67,   112,     0,   -80,   -80,   145,   -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     3,     4,     1,     0,     0,     9,
       8,    10,     5,     0,     0,     7,    12,     0,     0,     0,
       0,     0,    22,     0,     0,     2,     0,    14,    16,    17,
      18,    19,    20,    21,     6,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,    66,    67,     0,     0,    65,
      64,     0,    34,    37,    41,     0,    53,    57,    61,     0,
      11,     0,    31,     0,     0,     0,     0,    28,    54,     0,
      59,    60,     0,     0,    29,     0,     0,     0,     0,     0,
       0,    46,    47,    48,    49,     0,     0,     0,     0,     0,
      15,    30,     0,     0,    62,    63,     0,    33,     0,    36,
       0,    39,    40,    50,     0,    52,    51,     0,    43,    55,
      56,    32,     0,     0,    26,    54,    54,    54,    58,    54,
       0,     0,     0,    24,    27,     0,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -80,   -80,   115,   -80,   -80,   -80,
     -80,   -80,   -80,   -79,   -80,   -37,    83,    80,    10,   -80,
      73,    23,   -42,   -80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     7,    12,    13,    17,    14,    27,    28,    29,
      30,    31,    32,    40,    33,    51,    52,    53,    54,    85,
      55,    56,    57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      61,    38,    70,    73,    66,    71,    73,     1,     5,     2,
       4,    72,    34,    35,   114,    16,     8,    73,    73,   -13,
       6,    89,    88,   -13,    93,   -13,   -13,   -13,   -13,     9,
      10,    11,    73,   120,    15,    95,   121,    73,    39,    18,
      76,    77,    19,   125,   109,   110,    20,    74,    21,    22,
      23,    24,   111,    63,   -13,   113,   -13,   -13,    86,    87,
     -13,    36,   -13,   -13,   -13,   -13,    79,    80,    37,   -58,
     -58,    41,    18,   122,   123,    19,    43,    25,    42,    20,
      26,    21,    22,    23,    24,    69,   101,   102,    59,    60,
      65,   -13,    44,    62,   -13,    45,    46,    67,    47,    96,
      75,    44,   105,   106,    45,    46,    68,    47,    98,    90,
      91,    48,    92,    26,    94,    44,    49,    50,    45,    46,
      48,    47,   100,   103,    44,    49,    50,    45,    46,   112,
      47,   104,   115,   116,    48,   117,   118,   119,    44,    49,
      50,    45,    46,    48,    47,   107,   124,    44,    49,    50,
      45,    46,   126,    47,    64,    99,    97,    48,   108,     0,
       0,    44,    49,    50,    45,    46,    48,    47,     0,     0,
      78,    49,    50,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,    49,    50,   -44,   -44,     0,
       0,    79,    80,     0,     0,     0,    81,    82,    83,    84,
     -44,   -44,     0,   -44,   -38,   -35,   -44,     0,   -38,   -38,
     -58,   -58,     0,     0,   -58,   -58,     0,   -42,   -42,     0,
     -35,   -42,   -42,   -35,   -38,   -42,   -42,   -38,     0,   -45,
     -45,   -58,   -58,     0,     0,   -58,   -58,     0,   -42,   -42,
       0,   -42,   -45,   -45,   -42,   -45,     0,     0,   -45
};

static const yytype_int8 yycheck[] =
{
      37,     1,    44,    19,    41,    47,    19,     1,    38,     3,
      45,    48,    34,    35,    93,    42,     1,    19,    19,     4,
       0,    37,    59,     8,    37,    10,    11,    12,    13,    14,
      15,    16,    19,   112,    45,    37,    37,    19,    38,     1,
      31,    32,     4,   122,    86,    87,     8,    34,    10,    11,
      12,    13,    34,     1,    39,    92,     4,    42,    24,    25,
       8,    45,    10,    11,    12,    13,    22,    23,    36,    24,
      25,    36,     1,     6,     7,     4,     1,    39,    42,     8,
      42,    10,    11,    12,    13,     1,    76,    77,    33,    42,
       9,    39,    17,    45,    42,    20,    21,    34,    23,     1,
      18,    17,    79,    80,    20,    21,    45,    23,     1,    45,
      39,    36,    36,    42,    45,    17,    41,    42,    20,    21,
      36,    23,     1,    45,    17,    41,    42,    20,    21,     5,
      23,     1,    45,    45,    36,    45,    45,    45,    17,    41,
      42,    20,    21,    36,    23,     1,    34,    17,    41,    42,
      20,    21,     7,    23,    39,    75,    73,    36,    85,    -1,
      -1,    17,    41,    42,    20,    21,    36,    23,    -1,    -1,
       1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    41,    42,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    34,    18,    19,    37,    -1,    18,    19,
      24,    25,    -1,    -1,    24,    25,    -1,    31,    32,    -1,
      34,    31,    32,    37,    34,    18,    19,    37,    -1,    18,
      19,    24,    25,    -1,    -1,    24,    25,    -1,    31,    32,
      -1,    34,    31,    32,    37,    34,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    47,    45,    38,     0,    48,     1,    14,
      15,    16,    49,    50,    52,    45,    42,    51,     1,     4,
       8,    10,    11,    12,    13,    39,    42,    53,    54,    55,
      56,    57,    58,    60,    34,    35,    45,    36,     1,    38,
      59,    36,    42,     1,    17,    20,    21,    23,    36,    41,
      42,    61,    62,    63,    64,    66,    67,    68,    69,    33,
      42,    61,    45,     1,    52,     9,    61,    34,    45,     1,
      68,    68,    61,    19,    34,    18,    31,    32,     1,    22,
      23,    27,    28,    29,    30,    65,    24,    25,    61,    37,
      45,    39,    36,    37,    45,    37,     1,    62,     1,    63,
       1,    64,    64,    45,     1,    67,    67,     1,    66,    68,
      68,    34,     5,    61,    59,    45,    45,    45,    45,    45,
      59,    37,     6,     7,    34,    59,     7
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      50,    51,    51,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    56,    57,    58,
      59,    59,    60,    61,    61,    61,    62,    62,    62,    63,
      63,    63,    63,    64,    64,    64,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    67,    67,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     0,     2,     3,     2,     1,     1,
       1,     3,     1,     0,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     7,     9,     5,     7,     3,     3,
       3,     2,     4,     3,     1,     2,     3,     1,     2,     3,
       3,     1,     2,     3,     1,     2,     1,     1,     1,     1,
       2,     3,     3,     1,     2,     3,     3,     1,     2,     2,
       2,     1,     2,     3,     1,     1,     1,     1
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
  case 2: /* program: PROGRAM LI list-decl list-sent LD  */
#line 102 "sintatic.y"
                                          {
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "program";
            Nodo *prog = new struct Nodo;
            prog->nombre = "program";
            prog->valor = "program";
            Nodo *li = new struct Nodo;
            li->nombre = "li";
            li->valor = "{";
            Nodo *ld = new struct Nodo;
            ld->nombre = "ld";
            ld->valor = "}";
            (yyval.nodo)->hijos.push_back(prog);
            (yyval.nodo)->hijos.push_back(li);
            (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->hijos.push_back(ld);
            inicial = (yyval.nodo);
            
        }
#line 1275 "sintatic.tab.cpp"
    break;

  case 4: /* list-decl: %empty  */
#line 124 "sintatic.y"
        {
            (yyval.nodo) = NULL;
        }
#line 1283 "sintatic.tab.cpp"
    break;

  case 5: /* list-decl: list-decl decl  */
#line 127 "sintatic.y"
                         {
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "list-decl";
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
            inicial = (yyval.nodo);
        }
#line 1295 "sintatic.tab.cpp"
    break;

  case 6: /* decl: tipo list-id PYC  */
#line 135 "sintatic.y"
                         {
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "decl";
            Nodo *pyc = new struct Nodo;
            pyc->nombre = "pyc";
            pyc->valor = ";";
            (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->hijos.push_back(pyc);
            inicial = (yyval.nodo);
        }
#line 1311 "sintatic.tab.cpp"
    break;

  case 8: /* tipo: INT  */
#line 148 "sintatic.y"
            {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "tipo";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1322 "sintatic.tab.cpp"
    break;

  case 9: /* tipo: FLOAT  */
#line 154 "sintatic.y"
                {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "tipo";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1333 "sintatic.tab.cpp"
    break;

  case 10: /* tipo: BOOL  */
#line 160 "sintatic.y"
               {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "tipo";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1344 "sintatic.tab.cpp"
    break;

  case 11: /* list-id: list-id COM IDENTIFICADOR  */
#line 167 "sintatic.y"
                                   {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "list-id";
                Nodo *coma = new struct Nodo;
                coma->nombre = "coma";
                coma->valor = ",";
                Nodo *id = new struct Nodo;
                id->nombre = "id";
                id->valor = (yyvsp[0].cadena);
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back(coma);
                (yyval.nodo)->hijos.push_back(id);
                inicial = (yyval.nodo);
            }
#line 1363 "sintatic.tab.cpp"
    break;

  case 12: /* list-id: IDENTIFICADOR  */
#line 181 "sintatic.y"
                        {
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "id";
            (yyval.nodo)->valor = (yyvsp[0].cadena);
            inicial = (yyval.nodo);
        }
#line 1374 "sintatic.tab.cpp"
    break;

  case 13: /* list-sent: %empty  */
#line 188 "sintatic.y"
        {
            (yyval.nodo) = NULL;
        }
#line 1382 "sintatic.tab.cpp"
    break;

  case 14: /* list-sent: list-sent sent  */
#line 191 "sintatic.y"
                         {
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "list-sent";
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
            inicial = (yyval.nodo);
        }
#line 1394 "sintatic.tab.cpp"
    break;

  case 16: /* sent: sent-if  */
#line 200 "sintatic.y"
                {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1405 "sintatic.tab.cpp"
    break;

  case 17: /* sent: sent-while  */
#line 206 "sintatic.y"
                     {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1416 "sintatic.tab.cpp"
    break;

  case 18: /* sent: sent-do  */
#line 212 "sintatic.y"
                  {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1427 "sintatic.tab.cpp"
    break;

  case 19: /* sent: sent-read  */
#line 218 "sintatic.y"
                    {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1438 "sintatic.tab.cpp"
    break;

  case 20: /* sent: sent-write  */
#line 224 "sintatic.y"
                     {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1449 "sintatic.tab.cpp"
    break;

  case 21: /* sent: sent-assign  */
#line 230 "sintatic.y"
                      {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1460 "sintatic.tab.cpp"
    break;

  case 22: /* sent: BREAK  */
#line 236 "sintatic.y"
                {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1471 "sintatic.tab.cpp"
    break;

  case 24: /* sent-if: IF PI exp-bool PD THEN bloque FI  */
#line 244 "sintatic.y"
                                         {
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "sent-if";
            Nodo *i = new struct Nodo;
            i->nombre = "if";
            i->valor = "if";
            Nodo *pi = new struct Nodo;
            pi->nombre = "pi";
            pi->valor = "(";
            Nodo *pd = new struct Nodo;
            pd->nombre = "pd";
            pd->valor = ")";
            Nodo *the = new struct Nodo;
            the->nombre = "then";
            the->valor = "then";
            Nodo *fi = new struct Nodo;
            fi->nombre = "fi";
            fi->valor = "fi";
            (yyval.nodo)->hijos.push_back(i);
            (yyval.nodo)->hijos.push_back(pi);
            (yyval.nodo)->hijos.push_back((yyvsp[-4].nodo));
            (yyval.nodo)->hijos.push_back(pd);
            (yyval.nodo)->hijos.push_back(the);
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->hijos.push_back(fi);
            inicial = (yyval.nodo);
            }
#line 1503 "sintatic.tab.cpp"
    break;

  case 25: /* sent-if: IF PI exp-bool PD THEN bloque ELSE bloque FI  */
#line 271 "sintatic.y"
                                                       {
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "sent-if";
            Nodo *i = new struct Nodo;
            i->nombre = "if";
            i->valor = "if";
            Nodo *pi = new struct Nodo;
            pi->nombre = "pi";
            pi->valor = "(";
            Nodo *pd = new struct Nodo;
            pd->nombre = "pd";
            pd->valor = ")";
            Nodo *the = new struct Nodo;
            the->nombre = "then";
            the->valor = "then";
            Nodo *els = new struct Nodo;
            els->nombre = "else";
            els->valor = "else";
            Nodo *fi = new struct Nodo;
            fi->nombre = "fi";
            fi->valor = "fi";
            (yyval.nodo)->hijos.push_back(i);
            (yyval.nodo)->hijos.push_back(pi);
            (yyval.nodo)->hijos.push_back((yyvsp[-6].nodo));
            (yyval.nodo)->hijos.push_back(pd);
            (yyval.nodo)->hijos.push_back(the);
            (yyval.nodo)->hijos.push_back((yyvsp[-3].nodo));
            (yyval.nodo)->hijos.push_back(els);
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->hijos.push_back(fi);
            inicial = (yyval.nodo);
            }
#line 1540 "sintatic.tab.cpp"
    break;

  case 26: /* sent-while: WHILE PI exp-bool PD bloque  */
#line 304 "sintatic.y"
                                    {
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "sent-while";
            Nodo *whil = new struct Nodo;
            whil->nombre = "while";
            whil->valor = "while";
            Nodo *pi = new struct Nodo;
            pi->nombre = "pi";
            pi->valor = "(";
            Nodo *pd = new struct Nodo;
            pd->nombre = "pd";
            pd->valor = ")";
            (yyval.nodo)->hijos.push_back(whil);
            (yyval.nodo)->hijos.push_back(pi);
            (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
            (yyval.nodo)->hijos.push_back(pd);
            (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
            inicial = (yyval.nodo);
        }
#line 1564 "sintatic.tab.cpp"
    break;

  case 27: /* sent-do: DO bloque UNTIL PI exp-bool PD PYC  */
#line 324 "sintatic.y"
                                           {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent-do";
                Nodo *d = new struct Nodo;
                d->nombre = "do";
                d->valor = "do";
                Nodo *unti = new struct Nodo;
                unti->nombre = "until";
                unti->valor = "until";
                Nodo *pi = new struct Nodo;
                pi->nombre = "pi";
                pi->valor = "(";
                Nodo *pd = new struct Nodo;
                pd->nombre = "pd";
                pd->valor = ")";
                Nodo *pyc = new struct Nodo;
                pyc->nombre = "pyc";
                pyc->valor = ";";
                (yyval.nodo)->hijos.push_back(d);
                (yyval.nodo)->hijos.push_back((yyvsp[-5].nodo));
                (yyval.nodo)->hijos.push_back(unti);
                (yyval.nodo)->hijos.push_back(pi);
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back(pd);
                (yyval.nodo)->hijos.push_back(pyc);
                inicial = (yyval.nodo);
            }
#line 1596 "sintatic.tab.cpp"
    break;

  case 28: /* sent-read: READ IDENTIFICADOR PYC  */
#line 352 "sintatic.y"
                               {
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "bloque";
            Nodo *read = new struct Nodo;
            read->nombre = "read";
            read->valor = "read";
            Nodo *id = new struct Nodo;
            id->nombre = "id";
            id->valor = (yyvsp[-1].cadena);
            Nodo *pyc = new struct Nodo;
            pyc->nombre = "pyc";
            pyc->valor = ";";
            (yyval.nodo)->hijos.push_back(read);
            (yyval.nodo)->hijos.push_back(id);
            (yyval.nodo)->hijos.push_back(pyc);
            inicial = (yyval.nodo);
        }
#line 1618 "sintatic.tab.cpp"
    break;

  case 29: /* sent-write: WRITE exp-bool PYC  */
#line 370 "sintatic.y"
                           {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "bloque";
                Nodo *write = new struct Nodo;
                write->nombre = "write";
                write->valor = "write";
                Nodo *pyc = new struct Nodo;
                pyc->nombre = "pyc";
                pyc->valor = ";";
                (yyval.nodo)->hijos.push_back(write);
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                (yyval.nodo)->hijos.push_back(pyc);
                inicial = (yyval.nodo);
            }
#line 1637 "sintatic.tab.cpp"
    break;

  case 30: /* bloque: LI list-sent LD  */
#line 385 "sintatic.y"
                        {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "bloque";
                Nodo *li = new struct Nodo;
                li->nombre = "li";
                li->valor = "{";
                Nodo *ld = new struct Nodo;
                ld->nombre = "ld";
                ld->valor = "}";
                (yyval.nodo)->hijos.push_back(li);
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                (yyval.nodo)->hijos.push_back(ld);
                inicial = (yyval.nodo);
            }
#line 1656 "sintatic.tab.cpp"
    break;

  case 32: /* sent-assign: IDENTIFICADOR ASIG exp-bool PYC  */
#line 401 "sintatic.y"
                                        {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent-assign";
                Nodo *id = new struct Nodo;
                id->nombre = "id";
                id->valor = (yyvsp[-3].cadena);
                Nodo *asig = new struct Nodo;
                asig->nombre = "asig";
                asig->valor = "=";
                Nodo *pyc = new struct Nodo;
                pyc->nombre = "pyc";
                pyc->valor = ";";
                (yyval.nodo)->hijos.push_back(id);
                (yyval.nodo)->hijos.push_back(asig);
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                (yyval.nodo)->hijos.push_back(pyc);
                inicial = (yyval.nodo);
            }
#line 1679 "sintatic.tab.cpp"
    break;

  case 33: /* exp-bool: exp-bool OR comb  */
#line 420 "sintatic.y"
                          {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "exp-bool";
                Nodo *o = new struct Nodo;
                o->nombre = "or";
                o->valor = "or";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back(o);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1695 "sintatic.tab.cpp"
    break;

  case 34: /* exp-bool: comb  */
#line 431 "sintatic.y"
               {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "exp-bool";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1706 "sintatic.tab.cpp"
    break;

  case 36: /* comb: comb AND igualdad  */
#line 439 "sintatic.y"
                          {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "comb";
                Nodo *an = new struct Nodo;
                an->nombre = "and";
                an->valor = "and";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back(an);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1722 "sintatic.tab.cpp"
    break;

  case 37: /* comb: igualdad  */
#line 450 "sintatic.y"
                   {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "comb";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1733 "sintatic.tab.cpp"
    break;

  case 39: /* igualdad: igualdad IGU rel  */
#line 458 "sintatic.y"
                         {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "igualdad";
                Nodo *igu = new struct Nodo;
                igu->nombre = "igu";
                igu->valor = "==";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back(igu);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1749 "sintatic.tab.cpp"
    break;

  case 40: /* igualdad: igualdad DIS rel  */
#line 469 "sintatic.y"
                           {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "igualdad";
                Nodo *dis = new struct Nodo;
                dis->nombre = "dis";
                dis->valor = "!=";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back(dis);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1765 "sintatic.tab.cpp"
    break;

  case 41: /* igualdad: rel  */
#line 480 "sintatic.y"
              {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "igualdad";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1776 "sintatic.tab.cpp"
    break;

  case 43: /* rel: expr op-rel expr  */
#line 488 "sintatic.y"
                         {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "rel";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1789 "sintatic.tab.cpp"
    break;

  case 44: /* rel: expr  */
#line 496 "sintatic.y"
               {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "rel";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1800 "sintatic.tab.cpp"
    break;

  case 46: /* op-rel: MEN  */
#line 504 "sintatic.y"
            {
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "men";
            (yyval.nodo)->valor = (yyvsp[0].cadena);
            inicial = (yyval.nodo);
        }
#line 1811 "sintatic.tab.cpp"
    break;

  case 47: /* op-rel: MENIGL  */
#line 510 "sintatic.y"
                 {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "menigl";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1822 "sintatic.tab.cpp"
    break;

  case 48: /* op-rel: MAY  */
#line 516 "sintatic.y"
              {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "may";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1833 "sintatic.tab.cpp"
    break;

  case 49: /* op-rel: MAYIGL  */
#line 522 "sintatic.y"
                 {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "mayigl";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1844 "sintatic.tab.cpp"
    break;

  case 51: /* expr: expr RES term  */
#line 530 "sintatic.y"
                      {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "expr";
                Nodo *res = new struct Nodo;
                res->nombre = "res";
                res->valor = "-";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back(res);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1860 "sintatic.tab.cpp"
    break;

  case 52: /* expr: expr MAS term  */
#line 541 "sintatic.y"
                        {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "expr";
                Nodo *mas = new struct Nodo;
                mas->nombre = "mas";
                mas->valor = "+";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back(mas);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1876 "sintatic.tab.cpp"
    break;

  case 53: /* expr: term  */
#line 552 "sintatic.y"
               {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "expr";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1887 "sintatic.tab.cpp"
    break;

  case 55: /* term: term MUL unario  */
#line 560 "sintatic.y"
                        {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "term";
                Nodo *mul = new struct Nodo;
                mul->nombre = "mul";
                mul->valor = "*";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back(mul);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            
            }
#line 1904 "sintatic.tab.cpp"
    break;

  case 56: /* term: term DIV unario  */
#line 572 "sintatic.y"
                          {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "term";
                Nodo *div = new struct Nodo;
                div->nombre = "div";
                div->valor = "/";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back(div);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1920 "sintatic.tab.cpp"
    break;

  case 57: /* term: unario  */
#line 583 "sintatic.y"
                 {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "term";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1931 "sintatic.tab.cpp"
    break;

  case 59: /* unario: NOT unario  */
#line 591 "sintatic.y"
                   {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "unario";
                Nodo *no = new struct Nodo;
                no->nombre = "not";
                no->valor = "not";
                (yyval.nodo)->hijos.push_back(no);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1946 "sintatic.tab.cpp"
    break;

  case 60: /* unario: RES unario  */
#line 601 "sintatic.y"
                     {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "unario";
                Nodo *res = new struct Nodo;
                res->nombre = "res";
                res->valor = "-";
                (yyval.nodo)->hijos.push_back(res);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1961 "sintatic.tab.cpp"
    break;

  case 61: /* unario: factor  */
#line 611 "sintatic.y"
                 {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "unario";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1972 "sintatic.tab.cpp"
    break;

  case 63: /* factor: PI exp-bool PD  */
#line 619 "sintatic.y"
                       {
            //!Revisar
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "factor";
                Nodo *pi = new struct Nodo;
                pi->nombre = "pi";
                pi->valor = "(";
                Nodo *pd = new struct Nodo;
                pd->nombre = "pd";
                pd->valor = ")";
                (yyval.nodo)->hijos.push_back(pi);
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                (yyval.nodo)->hijos.push_back(pd);
                inicial = (yyval.nodo);
            }
#line 1992 "sintatic.tab.cpp"
    break;

  case 64: /* factor: IDENTIFICADOR  */
#line 634 "sintatic.y"
                        {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "factor";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 2003 "sintatic.tab.cpp"
    break;

  case 65: /* factor: NUMERO  */
#line 640 "sintatic.y"
                 {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "factor";
                (yyval.nodo)->valor = std::to_string((yyvsp[0].numero));
                inicial = (yyval.nodo);
            }
#line 2014 "sintatic.tab.cpp"
    break;

  case 66: /* factor: TRUE  */
#line 646 "sintatic.y"
               {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "factor";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 2025 "sintatic.tab.cpp"
    break;

  case 67: /* factor: FALSE  */
#line 652 "sintatic.y"
                {
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "factor";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 2036 "sintatic.tab.cpp"
    break;


#line 2040 "sintatic.tab.cpp"

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

#line 658 "sintatic.y"




void printNode(Nodo *init, int tabuladores){
    if(init != NULL){
        for(int i=0; i<tabuladores; i++){
            std::cout<<"  |";
        } 
        std::cout << init->nombre << ": " << init->valor << "\n";
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
    return inicial;
}

int yyerror(std::string s){
    Nodo *error = new struct Nodo;
    error->nombre = "Error";
    error->valor = s;
    inicial->hijos.push_back(error);
    return 0;
}

int main(int argc, char **argv){
    yyparse();
    std::cout << "\n---Arbol---\n\n";
    printNode(inicial,0);
    return 0;
}
