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

#line 108 "sintatic.tab.cpp"

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
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

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
       0,   118,   118,   139,   142,   151,   163,   171,   178,   185,
     192,   201,   216,   223,   230,   239,   242,   251,   258,   265,
     272,   279,   286,   293,   308,   336,   369,   376,   383,   390,
     397,   404,   411,   418,   425,   435,   455,   462,   469,   478,
     506,   513,   520,   527,   534,   541,   548,   555,   562,   569,
     576,   583,   590,   597,   604,   611,   618,   628,   646,   653,
     660,   669,   684,   693,   710,   730,   737,   744,   753,   765,
     774,   786,   795,   807,   819,   828,   837,   845,   852,   859,
     866,   873,   881,   893,   905,   914,   927,   939,   947,   958,
     969,   977,   993,  1000,  1007,  1014,  1021
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

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,   -24,    78,   -45,   -45,    11,   -45,   -45,   -45,   -45,
     -45,     2,    92,   128,    32,   -45,   131,    12,   138,    19,
     -45,    10,    15,   -45,    57,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,    17,   164,    46,   -45,     7,    83,
      46,   -45,   139,    73,    46,    50,    30,   102,    46,   -45,
     -45,    46,    46,   -45,   -45,   123,   100,   127,   -45,   159,
     155,   -45,   -45,    96,    53,   -45,   148,     8,   -45,   -45,
      61,   -45,   -45,    46,   154,   -45,    46,   -45,    64,   112,
     -45,    71,   184,    46,   -45,    72,   -45,   -45,   -45,   -45,
     -45,    89,    46,   -45,    46,    46,    46,   -45,    46,    46,
     -45,   -45,   -45,   -45,    46,    46,    46,   -45,   125,   134,
     -45,   -45,   191,   151,   108,   -45,   109,    59,   -45,   -45,
      46,   -45,   113,    27,   -45,   100,   127,   -45,   -45,   155,
     155,   161,   -45,   -45,   -45,   -45,   -45,    33,   196,   -45,
     -45,   199,   -45,   200,   124,   203,   -45,   -45,   -45,   188,
     -45,   -45,   -45,   171,   -45,    39,   -45,   -45,   -45,    74,
     -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,    10,     8,     7,     9,
       4,     0,     0,     6,     0,    12,     0,     0,     0,     0,
      23,     0,     0,     2,     0,    16,    17,    18,    19,    20,
      21,    22,    13,     5,     0,    26,     0,    40,     0,    44,
       0,    15,     0,    36,     0,    58,     0,    96,     0,    94,
      95,     0,     0,    93,    92,     0,    69,    71,    74,     0,
      84,    87,    90,    65,     0,    11,     0,     0,    30,    96,
       0,    42,    50,     0,     0,    55,     0,    54,     0,     0,
      41,     0,     0,     0,    37,     0,    60,    59,    57,    88,
      89,     0,     0,    61,     0,     0,     0,    81,     0,     0,
      77,    78,    79,    80,     0,     0,     0,    67,    96,     0,
      28,    32,     0,     0,     0,    48,     0,     0,    63,    45,
       0,    47,     0,     0,    91,    68,    70,    72,    73,    83,
      82,    75,    85,    86,    64,    33,    27,     0,     0,    56,
      43,     0,    53,     0,     0,     0,    38,    35,    29,     0,
      49,    52,    51,     0,    46,     0,    24,    39,    31,     0,
      34,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,   -45,   -45,   -45,   -45,   165,   -45,   -45,   -45,
     -45,   -45,   -45,   -38,   -45,   -34,   115,   114,   103,   -45,
     105,   104,   -44,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     5,    10,    11,    16,    12,    25,    26,    27,
      28,    29,    30,    42,    31,    55,    56,    57,    58,   104,
      59,    60,    61,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,    77,    70,    13,    89,    84,    78,    90,    71,   111,
      85,    45,     6,    35,     3,   -15,    47,     1,    91,   -15,
      43,   -15,   -15,   -15,   -15,     7,     8,     9,   146,   112,
     109,    87,    48,    32,   148,    49,    50,    14,    51,   114,
     158,    72,   116,    73,    15,    41,    41,    69,    36,   122,
     -15,    52,    46,   -15,   108,    44,    53,    54,    63,    65,
     140,   132,   133,    48,    88,    41,    49,    50,   141,    51,
      48,    41,   119,    49,    50,   160,    51,    41,     4,   143,
      92,   161,    52,    92,    86,   147,   144,    53,    54,    52,
      64,    92,    75,   142,    53,    54,    17,    41,   113,   149,
      18,   117,    19,    20,    21,    22,   -62,   120,    92,   123,
     -62,    41,   -62,   -62,   -62,   -62,    17,   159,    94,    76,
      18,    41,    19,    20,    21,    22,   124,    92,    92,   -66,
     107,    23,    92,   -66,    24,   -66,   -66,   -66,   -66,    37,
      80,   -62,    92,    92,   -62,   138,   139,    38,    81,   110,
     145,   118,   136,    92,    24,   115,   137,    93,    95,    96,
      97,   153,   -14,   -14,   -66,    33,    34,   -66,   134,    66,
      67,    68,    39,    82,    40,    83,    41,   -76,   -76,   105,
     106,    98,    99,    98,    99,   121,   100,   101,   102,   103,
     -76,   -76,   135,   -76,   155,   156,   -76,   150,   127,   128,
     151,   152,   129,   130,   154,   157,    79,   125,   126,   131
};

static const yytype_uint8 yycheck[] =
{
      38,    39,    36,     1,    48,    43,    40,    51,     1,     1,
      44,     1,     1,     1,    38,     4,     1,     3,    52,     8,
       1,    10,    11,    12,    13,    14,    15,    16,     1,    67,
      64,     1,    17,     1,     1,    20,    21,    35,    23,    73,
       1,    34,    76,    36,    42,    38,    38,     1,    36,    83,
      39,    36,    42,    42,     1,    36,    41,    42,     1,    42,
       1,   105,   106,    17,    34,    38,    20,    21,     9,    23,
      17,    38,     1,    20,    21,     1,    23,    38,     0,   117,
      19,     7,    36,    19,    34,   123,   120,    41,    42,    36,
      33,    19,     9,    34,    41,    42,     4,    38,    37,   137,
       8,    37,    10,    11,    12,    13,     4,    36,    19,    37,
       8,    38,    10,    11,    12,    13,     4,   155,    18,    36,
       8,    38,    10,    11,    12,    13,    37,    19,    19,     4,
      34,    39,    19,     8,    42,    10,    11,    12,    13,     1,
       1,    39,    19,    19,    42,    37,    37,     9,     9,     1,
      37,    39,     1,    19,    42,     1,     5,    34,    31,    32,
       1,    37,    34,    35,    39,    34,    35,    42,    34,     5,
       6,     7,    34,    34,    36,    36,    38,    18,    19,    24,
      25,    22,    23,    22,    23,     1,    27,    28,    29,    30,
      31,    32,     1,    34,     6,     7,    37,     1,    95,    96,
       1,     1,    98,    99,     1,    34,    41,    92,    94,   104
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,    38,     0,    48,     1,    14,    15,    16,
      49,    50,    52,     1,    35,    42,    51,     4,     8,    10,
      11,    12,    13,    39,    42,    53,    54,    55,    56,    57,
      58,    60,     1,    34,    35,     1,    36,     1,     9,    34,
      36,    38,    59,     1,    36,     1,    42,     1,    17,    20,
      21,    23,    36,    41,    42,    61,    62,    63,    64,    66,
      67,    68,    69,     1,    33,    42,     5,     6,     7,     1,
      61,     1,    34,    36,    59,     9,    36,    59,    61,    52,
       1,     9,    34,    36,    59,    61,    34,     1,    34,    68,
      68,    61,    19,    34,    18,    31,    32,     1,    22,    23,
      27,    28,    29,    30,    65,    24,    25,    34,     1,    61,
       1,     1,    59,    37,    61,     1,    61,    37,    39,     1,
      36,     1,    61,    37,    37,    62,    63,    64,    64,    67,
      67,    66,    68,    68,    34,     1,     1,     5,    37,    37,
       1,     9,    34,    59,    61,    37,     1,    59,     1,    59,
       1,     1,     1,    37,     1,     6,     7,    34,     1,    59,
       1,     7
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    50,
      50,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    54,    54,
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
       3,     8,     4,     5,     9,     5,     2,     3,     5,     7,
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
#line 118 "sintatic.y"
                                         {
            std::cout << "program\n";
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
#line 1417 "sintatic.tab.cpp"
    break;

  case 3: /* list-decl: %empty  */
#line 139 "sintatic.y"
        {
            (yyval.nodo) = NULL;
        }
#line 1425 "sintatic.tab.cpp"
    break;

  case 4: /* list-decl: list-decl decl  */
#line 142 "sintatic.y"
                         {
            std::cout << "list-decl decl\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "list-decl";
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
            inicial = (yyval.nodo);
        }
#line 1438 "sintatic.tab.cpp"
    break;

  case 5: /* decl: tipo list-id PYC  */
#line 151 "sintatic.y"
                        {
            std::cout << "tipo list-id;\n";
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
#line 1455 "sintatic.tab.cpp"
    break;

  case 6: /* decl: tipo error  */
#line 163 "sintatic.y"
                    {
            std::cout << "Error decl - tipo error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "declaracion - tipo error";
            inicial = (yyval.nodo);
        }
#line 1467 "sintatic.tab.cpp"
    break;

  case 7: /* tipo: INT  */
#line 171 "sintatic.y"
            {
            std::cout << "int\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "tipo";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1479 "sintatic.tab.cpp"
    break;

  case 8: /* tipo: FLOAT  */
#line 178 "sintatic.y"
                {
            std::cout << "float\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "tipo";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1491 "sintatic.tab.cpp"
    break;

  case 9: /* tipo: BOOL  */
#line 185 "sintatic.y"
               {
            std::cout << "bool\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "tipo";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1503 "sintatic.tab.cpp"
    break;

  case 10: /* tipo: error  */
#line 192 "sintatic.y"
                {
                std::cout << "Error tipo\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "Error sintactico";
                (yyval.nodo)->valor = "falta tipo";
                inicial = (yyval.nodo);
                yyerrok;
        }
#line 1516 "sintatic.tab.cpp"
    break;

  case 11: /* list-id: list-id COM IDENTIFICADOR  */
#line 201 "sintatic.y"
                                   {
                std::cout << "list-id, id: " << (yyvsp[0].cadena) << "\n";
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
#line 1536 "sintatic.tab.cpp"
    break;

  case 12: /* list-id: IDENTIFICADOR  */
#line 216 "sintatic.y"
                        {
            std::cout << "id: " << (yyvsp[0].cadena) << "\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "id";
            (yyval.nodo)->valor = (yyvsp[0].cadena);
            inicial = (yyval.nodo);
        }
#line 1548 "sintatic.tab.cpp"
    break;

  case 13: /* list-id: COM error  */
#line 223 "sintatic.y"
                   {
            std::cout << "Error id\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta id";
            inicial = (yyval.nodo);
        }
#line 1560 "sintatic.tab.cpp"
    break;

  case 14: /* list-id: error  */
#line 230 "sintatic.y"
               {
            std::cout << "Error id\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta id";
            inicial = (yyval.nodo);
        }
#line 1572 "sintatic.tab.cpp"
    break;

  case 15: /* list-sent: %empty  */
#line 239 "sintatic.y"
        {
            (yyval.nodo) = NULL;
        }
#line 1580 "sintatic.tab.cpp"
    break;

  case 16: /* list-sent: list-sent sent  */
#line 242 "sintatic.y"
                         {
            std::cout << "list-sent sent\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "list-sent";
            (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
            (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
            inicial = (yyval.nodo);
        }
#line 1593 "sintatic.tab.cpp"
    break;

  case 17: /* sent: sent-if  */
#line 251 "sintatic.y"
                {
            std::cout << "sent-if\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1605 "sintatic.tab.cpp"
    break;

  case 18: /* sent: sent-while  */
#line 258 "sintatic.y"
                     {
            std::cout << "sent-while\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1617 "sintatic.tab.cpp"
    break;

  case 19: /* sent: sent-do  */
#line 265 "sintatic.y"
                  {
            std::cout << "sent-do\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1629 "sintatic.tab.cpp"
    break;

  case 20: /* sent: sent-read  */
#line 272 "sintatic.y"
                    {
            std::cout << "sent-read \n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1641 "sintatic.tab.cpp"
    break;

  case 21: /* sent: sent-write  */
#line 279 "sintatic.y"
                     {
            std::cout << "sent-write\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1653 "sintatic.tab.cpp"
    break;

  case 22: /* sent: sent-assign  */
#line 286 "sintatic.y"
                      {
            std::cout << "sent-assign\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 1665 "sintatic.tab.cpp"
    break;

  case 23: /* sent: BREAK  */
#line 293 "sintatic.y"
                {
            std::cout << "break\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "sent";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 1677 "sintatic.tab.cpp"
    break;

  case 24: /* sent-if: IF PI exp-bool PD THEN bloque FI  */
#line 308 "sintatic.y"
                                         {
            std::cout << "if\n";
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
#line 1710 "sintatic.tab.cpp"
    break;

  case 25: /* sent-if: IF PI exp-bool PD THEN bloque ELSE bloque FI  */
#line 336 "sintatic.y"
                                                       {
            std::cout << "if-else\n";
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
#line 1748 "sintatic.tab.cpp"
    break;

  case 26: /* sent-if: IF error  */
#line 369 "sintatic.y"
                  {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta condicion entre parentesis, then y el bloque y finalizacion";
            inicial = (yyval.nodo);
        }
#line 1760 "sintatic.tab.cpp"
    break;

  case 27: /* sent-if: IF PI exp-bool PD error  */
#line 376 "sintatic.y"
                         {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta then, el bloque y finalizacion";
            inicial = (yyval.nodo);
        }
#line 1772 "sintatic.tab.cpp"
    break;

  case 28: /* sent-if: IF error THEN error  */
#line 383 "sintatic.y"
                             {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta condicion, el bloque y finalizacion";
            inicial = (yyval.nodo);
        }
#line 1784 "sintatic.tab.cpp"
    break;

  case 29: /* sent-if: IF PI exp-bool PD THEN error  */
#line 390 "sintatic.y"
                                      {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta bloque y finalizacion";
            inicial = (yyval.nodo);
        }
#line 1796 "sintatic.tab.cpp"
    break;

  case 30: /* sent-if: IF error FI  */
#line 397 "sintatic.y"
                     {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if falta condicion y bloque ";
            inicial = (yyval.nodo);
        }
#line 1808 "sintatic.tab.cpp"
    break;

  case 31: /* sent-if: IF PI exp-bool PD THEN bloque ELSE error  */
#line 404 "sintatic.y"
                                                  {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if-else falta bloque y finalizacion";
            inicial = (yyval.nodo);
        }
#line 1820 "sintatic.tab.cpp"
    break;

  case 32: /* sent-if: IF error ELSE error  */
#line 411 "sintatic.y"
                             {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if-else falta bloque if, bloque else y finalizacion";
            inicial = (yyval.nodo);
        }
#line 1832 "sintatic.tab.cpp"
    break;

  case 33: /* sent-if: IF error ELSE bloque error  */
#line 418 "sintatic.y"
                                    {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if-else falta bloque if, finalizacion";
            inicial = (yyval.nodo);
        }
#line 1844 "sintatic.tab.cpp"
    break;

  case 34: /* sent-if: IF PI exp-bool PD THEN bloque ELSE bloque error  */
#line 425 "sintatic.y"
                                                         {
            std::cout << "Error\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "if-else falta finalizacion";
            inicial = (yyval.nodo);
        }
#line 1856 "sintatic.tab.cpp"
    break;

  case 35: /* sent-while: WHILE PI exp-bool PD bloque  */
#line 435 "sintatic.y"
                                    {
            std::cout << "while\n";
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
#line 1881 "sintatic.tab.cpp"
    break;

  case 36: /* sent-while: WHILE error  */
#line 455 "sintatic.y"
                     {
            std::cout << "Error while\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "while falta condicion entre parentesis y cuerpo";
            inicial = (yyval.nodo);
        }
#line 1893 "sintatic.tab.cpp"
    break;

  case 37: /* sent-while: WHILE error bloque  */
#line 462 "sintatic.y"
                            {
            std::cout << "Error while\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "while falta expresion entre parentesis";
            inicial = (yyval.nodo);
        }
#line 1905 "sintatic.tab.cpp"
    break;

  case 38: /* sent-while: WHILE PI exp-bool PD error  */
#line 469 "sintatic.y"
                                    {
            std::cout << "Error while\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "while falta bloque";
            inicial = (yyval.nodo);
        }
#line 1917 "sintatic.tab.cpp"
    break;

  case 39: /* sent-do: DO bloque UNTIL PI exp-bool PD PYC  */
#line 478 "sintatic.y"
                                           {
            std::cout << "do\n";
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
#line 1950 "sintatic.tab.cpp"
    break;

  case 40: /* sent-do: DO error  */
#line 506 "sintatic.y"
                  {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta cuerpo";
            inicial = (yyval.nodo);
        }
#line 1962 "sintatic.tab.cpp"
    break;

  case 41: /* sent-do: DO bloque error  */
#line 513 "sintatic.y"
                         {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta until, condicion y punto y coma";
            inicial = (yyval.nodo);
        }
#line 1974 "sintatic.tab.cpp"
    break;

  case 42: /* sent-do: DO UNTIL error  */
#line 520 "sintatic.y"
                        {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, condicion y punto y coma";
            inicial = (yyval.nodo);
        }
#line 1986 "sintatic.tab.cpp"
    break;

  case 43: /* sent-do: DO PI exp-bool PD error  */
#line 527 "sintatic.y"
                                 {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma";
            inicial = (yyval.nodo);
        }
#line 1998 "sintatic.tab.cpp"
    break;

  case 44: /* sent-do: DO PYC  */
#line 534 "sintatic.y"
                {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y condicion";
            inicial = (yyval.nodo);
        }
#line 2010 "sintatic.tab.cpp"
    break;

  case 45: /* sent-do: DO bloque UNTIL error  */
#line 541 "sintatic.y"
                               {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta condicion y punto y coma";
            inicial = (yyval.nodo);
        }
#line 2022 "sintatic.tab.cpp"
    break;

  case 46: /* sent-do: DO bloque PI exp-bool PD error  */
#line 548 "sintatic.y"
                                        {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta condicion y punto y coma";
            inicial = (yyval.nodo);
        }
#line 2034 "sintatic.tab.cpp"
    break;

  case 47: /* sent-do: DO bloque PYC error  */
#line 555 "sintatic.y"
                             {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta condicion y punto y coma";
            inicial = (yyval.nodo);
        }
#line 2046 "sintatic.tab.cpp"
    break;

  case 48: /* sent-do: DO UNTIL bloque error  */
#line 562 "sintatic.y"
                               {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do desorganizado";
            inicial = (yyval.nodo);
        }
#line 2058 "sintatic.tab.cpp"
    break;

  case 49: /* sent-do: DO UNTIL PI exp-bool PD error  */
#line 569 "sintatic.y"
                                       {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do desorganizado";
            inicial = (yyval.nodo);
        }
#line 2070 "sintatic.tab.cpp"
    break;

  case 50: /* sent-do: DO UNTIL PYC  */
#line 576 "sintatic.y"
                      {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do desorganizado";
            inicial = (yyval.nodo);
        }
#line 2082 "sintatic.tab.cpp"
    break;

  case 51: /* sent-do: DO PI exp-bool PD bloque error  */
#line 583 "sintatic.y"
                                        {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma";
            inicial = (yyval.nodo);
        }
#line 2094 "sintatic.tab.cpp"
    break;

  case 52: /* sent-do: DO PI exp-bool PD UNTIL error  */
#line 590 "sintatic.y"
                                       {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma";
            inicial = (yyval.nodo);
        }
#line 2106 "sintatic.tab.cpp"
    break;

  case 53: /* sent-do: DO PI exp-bool PD PYC  */
#line 597 "sintatic.y"
                               {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma";
            inicial = (yyval.nodo);
        }
#line 2118 "sintatic.tab.cpp"
    break;

  case 54: /* sent-do: DO PYC bloque  */
#line 604 "sintatic.y"
                       {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma";
            inicial = (yyval.nodo);
        }
#line 2130 "sintatic.tab.cpp"
    break;

  case 55: /* sent-do: DO PYC UNTIL  */
#line 611 "sintatic.y"
                      {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma";
            inicial = (yyval.nodo);
        }
#line 2142 "sintatic.tab.cpp"
    break;

  case 56: /* sent-do: DO PYC PI exp-bool PD  */
#line 618 "sintatic.y"
                               {
            std::cout << "Error do\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "do falta bloque, until y punto y coma";
            inicial = (yyval.nodo);
        }
#line 2154 "sintatic.tab.cpp"
    break;

  case 57: /* sent-read: READ IDENTIFICADOR PYC  */
#line 628 "sintatic.y"
                               {
            std::cout << "read\n";
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
#line 2177 "sintatic.tab.cpp"
    break;

  case 58: /* sent-read: READ error  */
#line 646 "sintatic.y"
                    {
            std::cout << "Error read\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "read sentencia incompleta";
            inicial = (yyval.nodo);
        }
#line 2189 "sintatic.tab.cpp"
    break;

  case 59: /* sent-read: READ IDENTIFICADOR error  */
#line 653 "sintatic.y"
                                  {
            std::cout << "Error read\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta punto y coma en read";
            inicial = (yyval.nodo);
        }
#line 2201 "sintatic.tab.cpp"
    break;

  case 60: /* sent-read: READ error PYC  */
#line 660 "sintatic.y"
                        {
            std::cout << "Error read\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta el id para leer";
            inicial = (yyval.nodo);
        }
#line 2213 "sintatic.tab.cpp"
    break;

  case 61: /* sent-write: WRITE exp-bool PYC  */
#line 669 "sintatic.y"
                           {
            std::cout << "write\n";
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
#line 2233 "sintatic.tab.cpp"
    break;

  case 62: /* sent-write: WRITE error  */
#line 684 "sintatic.y"
                     {
            std::cout << "Error write\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "write sentencia incompleta";
            inicial = (yyval.nodo);
        }
#line 2245 "sintatic.tab.cpp"
    break;

  case 63: /* bloque: LI list-sent LD  */
#line 693 "sintatic.y"
                        {
            std::cout << "bloque\n";
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
#line 2265 "sintatic.tab.cpp"
    break;

  case 64: /* sent-assign: IDENTIFICADOR ASIG exp-bool PYC  */
#line 710 "sintatic.y"
                                        {
            std::cout << "id=exp-bool;\n";
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
#line 2289 "sintatic.tab.cpp"
    break;

  case 65: /* sent-assign: IDENTIFICADOR error  */
#line 730 "sintatic.y"
                             {
            std::cout << "Error assign\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta la sentencia de asignacion";
            inicial = (yyval.nodo);
        }
#line 2301 "sintatic.tab.cpp"
    break;

  case 66: /* sent-assign: IDENTIFICADOR ASIG error  */
#line 737 "sintatic.y"
                                  {
            std::cout << "Error assign\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta la expresion de asignación y un punto y coma";
            inicial = (yyval.nodo);
        }
#line 2313 "sintatic.tab.cpp"
    break;

  case 67: /* sent-assign: IDENTIFICADOR error PYC  */
#line 744 "sintatic.y"
                                 {
            std::cout << "Error assign\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta la asignacion y la expresion";
            inicial = (yyval.nodo);
        }
#line 2325 "sintatic.tab.cpp"
    break;

  case 68: /* exp-bool: exp-bool OR comb  */
#line 753 "sintatic.y"
                          {
            std::cout << "or\n";
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
#line 2342 "sintatic.tab.cpp"
    break;

  case 69: /* exp-bool: comb  */
#line 765 "sintatic.y"
               {
            std::cout << "comb\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "exp-bool";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 2354 "sintatic.tab.cpp"
    break;

  case 70: /* comb: comb AND igualdad  */
#line 774 "sintatic.y"
                          {
            std::cout << "and\n";
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
#line 2371 "sintatic.tab.cpp"
    break;

  case 71: /* comb: igualdad  */
#line 786 "sintatic.y"
                   {
            std::cout << "igualdad\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "comb";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 2383 "sintatic.tab.cpp"
    break;

  case 72: /* igualdad: igualdad IGU rel  */
#line 795 "sintatic.y"
                         {
            std::cout << "igu\n";
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
#line 2400 "sintatic.tab.cpp"
    break;

  case 73: /* igualdad: igualdad DIS rel  */
#line 807 "sintatic.y"
                           {
            std::cout << "dis\n";
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
#line 2417 "sintatic.tab.cpp"
    break;

  case 74: /* igualdad: rel  */
#line 819 "sintatic.y"
              {
            std::cout << "rel\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "igualdad";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 2429 "sintatic.tab.cpp"
    break;

  case 75: /* rel: expr op-rel expr  */
#line 828 "sintatic.y"
                         {
            std::cout << "expr op-rel expr\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "rel";
                (yyval.nodo)->hijos.push_back((yyvsp[-2].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[-1].nodo));
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 2443 "sintatic.tab.cpp"
    break;

  case 76: /* rel: expr  */
#line 837 "sintatic.y"
               {
            std::cout << "expr\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "rel";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 2455 "sintatic.tab.cpp"
    break;

  case 77: /* op-rel: MEN  */
#line 845 "sintatic.y"
            {
            std::cout << "men\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "men";
            (yyval.nodo)->valor = (yyvsp[0].cadena);
            inicial = (yyval.nodo);
        }
#line 2467 "sintatic.tab.cpp"
    break;

  case 78: /* op-rel: MENIGL  */
#line 852 "sintatic.y"
                 {
            std::cout << "menigl\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "menigl";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 2479 "sintatic.tab.cpp"
    break;

  case 79: /* op-rel: MAY  */
#line 859 "sintatic.y"
              {
            std::cout << "may\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "may";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 2491 "sintatic.tab.cpp"
    break;

  case 80: /* op-rel: MAYIGL  */
#line 866 "sintatic.y"
                 {
            std::cout << "mayigl\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "mayigl";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 2503 "sintatic.tab.cpp"
    break;

  case 81: /* op-rel: error  */
#line 873 "sintatic.y"
              {
            std::cout << "Error op-rel\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta op-rel";
            inicial = (yyval.nodo);
        }
#line 2515 "sintatic.tab.cpp"
    break;

  case 82: /* expr: expr RES term  */
#line 881 "sintatic.y"
                      {
            std::cout << "res\n";
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
#line 2532 "sintatic.tab.cpp"
    break;

  case 83: /* expr: expr MAS term  */
#line 893 "sintatic.y"
                        {
            std::cout << "mas\n";
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
#line 2549 "sintatic.tab.cpp"
    break;

  case 84: /* expr: term  */
#line 905 "sintatic.y"
               {
            std::cout << "term\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "expr";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 2561 "sintatic.tab.cpp"
    break;

  case 85: /* term: term MUL unario  */
#line 914 "sintatic.y"
                        {
            std::cout << "mul\n";
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
#line 2579 "sintatic.tab.cpp"
    break;

  case 86: /* term: term DIV unario  */
#line 927 "sintatic.y"
                          {
            std::cout << "div\n";
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
#line 2596 "sintatic.tab.cpp"
    break;

  case 87: /* term: unario  */
#line 939 "sintatic.y"
                 {
            std::cout << "Unario\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "term";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 2608 "sintatic.tab.cpp"
    break;

  case 88: /* unario: NOT unario  */
#line 947 "sintatic.y"
                   {
            std::cout << "Not unario\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "unario";
                Nodo *no = new struct Nodo;
                no->nombre = "not";
                no->valor = "not";
                (yyval.nodo)->hijos.push_back(no);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 2624 "sintatic.tab.cpp"
    break;

  case 89: /* unario: RES unario  */
#line 958 "sintatic.y"
                     {
            std::cout << "RES unario\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "unario";
                Nodo *res = new struct Nodo;
                res->nombre = "res";
                res->valor = "-";
                (yyval.nodo)->hijos.push_back(res);
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 2640 "sintatic.tab.cpp"
    break;

  case 90: /* unario: factor  */
#line 969 "sintatic.y"
                 {
            std::cout << "Factor\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "unario";
                (yyval.nodo)->hijos.push_back((yyvsp[0].nodo));
                inicial = (yyval.nodo);
            }
#line 2652 "sintatic.tab.cpp"
    break;

  case 91: /* factor: PI exp-bool PD  */
#line 977 "sintatic.y"
                       {
            //!Revisar
                std::cout << "(exp-bool)\n";
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
#line 2673 "sintatic.tab.cpp"
    break;

  case 92: /* factor: IDENTIFICADOR  */
#line 993 "sintatic.y"
                        {
                std::cout << "id: "<< (yyvsp[0].cadena) << "\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "factor";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 2685 "sintatic.tab.cpp"
    break;

  case 93: /* factor: NUMERO  */
#line 1000 "sintatic.y"
                 {
                std::cout << "Numero: " << (yyvsp[0].numero) <<  "\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "factor";
                (yyval.nodo)->valor = std::to_string((yyvsp[0].numero));
                inicial = (yyval.nodo);
            }
#line 2697 "sintatic.tab.cpp"
    break;

  case 94: /* factor: TRUE  */
#line 1007 "sintatic.y"
               {
                std::cout << "True\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "factor";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 2709 "sintatic.tab.cpp"
    break;

  case 95: /* factor: FALSE  */
#line 1014 "sintatic.y"
                {
                std::cout << "False\n";
                (yyval.nodo) = new struct Nodo;
                (yyval.nodo)->nombre = "factor";
                (yyval.nodo)->valor = (yyvsp[0].cadena);
                inicial = (yyval.nodo);
            }
#line 2721 "sintatic.tab.cpp"
    break;

  case 96: /* factor: error  */
#line 1021 "sintatic.y"
              {
            std::cout << "Error factor\n";
            (yyval.nodo) = new struct Nodo;
            (yyval.nodo)->nombre = "Error sintactico";
            (yyval.nodo)->valor = "falta factor";
            inicial = (yyval.nodo);
        }
#line 2733 "sintatic.tab.cpp"
    break;


#line 2737 "sintatic.tab.cpp"

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

#line 1028 "sintatic.y"




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
    std::cout << "error: " << s << " in line " << yylineno << "\n";
    /*std::cout << "Error sin definir\n";
    Nodo *error = new struct Nodo;
    error->nombre = "Error";
    error->valor = s;
    inicial->hijos.push_back(error);*/
    //std::cout << "Error en la línea " << @$.first_line << ", columna: " << @$.first_column;
    return -1;
}

int main(int argc, char **argv){
    yyparse();
    std::cout << "\n---Arbol---\n\n";
    printNode(inicial,0);
    return 0;
}
