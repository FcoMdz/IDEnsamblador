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
    int yylex();
    int yyerror(char *s);
    struct Nodo{
        std::string nombre;
        std::string valor;
        Nodo *padre;
        std::vector<Nodo*> hijos;
    };
    Nodo *inicial = NULL;
    void printNode(Nodo *init);

    void checkListId(Nodo *init, Nodo *siguiente){
        if (init == NULL || siguiente == NULL) {
            return;
        }
        //Busca el nodo del tipo
        Nodo *recorrer = init;
        while(recorrer->nombre.compare("bool") != 0 && recorrer->nombre.compare("int") != 0 && recorrer->nombre.compare("float") != 0){
            recorrer = recorrer->hijos.at(0);
        }
        //Le quita el tipo como hijo a la variable declarada
        recorrer->padre->hijos.erase(recorrer->padre->hijos.begin()); 
        //Hace que el padre del tipo sea la delcaración
        recorrer->padre = siguiente;
        
        //Inserta los hijos en orden
        siguiente->hijos.push_back(recorrer);
    }

    void checkSec(Nodo *init, Nodo *siguiente, std::string termino, int prof = 0, int limit = 1){
        if (init == NULL || siguiente == NULL) {
            return;
        }
        if(init->nombre.compare(termino) == 0) return;
        Nodo *recorrer = init;
        while(recorrer->hijos.size() != 0 && recorrer->nombre.compare(termino) != 0){
            if(termino.compare("term")==0) std::cout << "check: " << recorrer->nombre << "\n";
            recorrer = recorrer->hijos.at(0);
        }
        if(recorrer->nombre.compare(termino) == 0){
            //Le quita el siguiente list-decl como hijo 
            if(termino.compare("term")==0) std::cout << "check inner: " << recorrer->valor << "\n";
            if(prof == limit){
                recorrer->padre->hijos.erase(recorrer->padre->hijos.begin()); 
                //Hace que el padre del tipo sea la delcaración
                recorrer->padre = siguiente;
                //Inserta los hijos en orden
                siguiente->hijos.push_back(recorrer);
                return;
            }
            if(recorrer->hijos.size() != 0) checkSec(recorrer->hijos.at(0), siguiente, termino, ++prof, limit);
        }
        if(termino.compare("term")==0) std::cout << "check outer: " << recorrer->valor << "\n";
        return;
    }

    void check(Nodo *init, Nodo *siguiente, std::string termino){
        if (init == NULL || siguiente == NULL) {
            return;
        }
        if(init->nombre.compare(termino) == 0) return;
        Nodo *recorrer = init;
        while(recorrer->hijos.size() != 0 && recorrer->nombre.compare(termino) != 0){
            recorrer = recorrer->hijos.at(0);
        }
        if(recorrer->nombre.compare(termino) == 0){
            //Le quita el siguiente list-decl como hijo 
            recorrer->padre->hijos.erase(recorrer->padre->hijos.begin()); 
            //Hace que el padre del tipo sea la delcaración
            recorrer->padre = siguiente;
            if(recorrer->hijos.size() != 0) check(recorrer->hijos.at(0), siguiente, termino);
            //Inserta los hijos en orden
            siguiente->hijos.push_back(recorrer);
        }
        return;
    }


#line 155 "sintatic.tab.c"

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
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_47_list_decl = 47,              /* list-decl  */
  YYSYMBOL_decl = 48,                      /* decl  */
  YYSYMBOL_tipo = 49,                      /* tipo  */
  YYSYMBOL_50_list_id = 50,                /* list-id  */
  YYSYMBOL_51_list_sent = 51,              /* list-sent  */
  YYSYMBOL_sent = 52,                      /* sent  */
  YYSYMBOL_53_sent_if = 53,                /* sent-if  */
  YYSYMBOL_54_sent_while = 54,             /* sent-while  */
  YYSYMBOL_55_sent_do = 55,                /* sent-do  */
  YYSYMBOL_56_sent_read = 56,              /* sent-read  */
  YYSYMBOL_57_sent_write = 57,             /* sent-write  */
  YYSYMBOL_bloque = 58,                    /* bloque  */
  YYSYMBOL_59_sent_assign = 59,            /* sent-assign  */
  YYSYMBOL_60_exp_bool = 60,               /* exp-bool  */
  YYSYMBOL_comb = 61,                      /* comb  */
  YYSYMBOL_igualdad = 62,                  /* igualdad  */
  YYSYMBOL_rel = 63,                       /* rel  */
  YYSYMBOL_64_op_rel = 64,                 /* op-rel  */
  YYSYMBOL_expr = 65,                      /* expr  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_unario = 67,                    /* unario  */
  YYSYMBOL_factor = 68                     /* factor  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   94

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

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
       0,   178,   178,   194,   195,   206,   222,   238,   254,   271,
     280,   296,   297,   310,   311,   312,   313,   323,   334,   335,
     336,   338,   339,   341,   343,   345,   399,   430,   432,   434,
     452,   463,   481,   492,   510,   528,   539,   558,   570,   587,
     605,   622,   640,   659,   678,   689,   709,   728,   739,   761,
     783,   794,   825,   842,   859,   876
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
  "IDENTIFICADOR", "OTRO", "SPACE", "$accept", "program", "list-decl",
  "decl", "tipo", "list-id", "list-sent", "sent", "sent-if", "sent-while",
  "sent-do", "sent-read", "sent-write", "bloque", "sent-assign",
  "exp-bool", "comb", "igualdad", "rel", "op-rel", "expr", "term",
  "unario", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      16,   -36,    36,   -37,   -37,    -9,   -37,   -37,   -37,   -37,
       4,     0,   -37,    -6,    19,    38,    42,   -37,    39,    20,
     -37,   -37,    46,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,    43,    20,    71,    20,    49,    20,   -37,   -37,
      20,    20,   -37,   -37,    14,    66,    -1,   -37,    41,    33,
     -37,   -37,    12,    20,   -37,    -5,    50,    -2,   -37,   -37,
     -37,     7,    20,   -37,    20,    20,    20,    20,    20,   -37,
     -37,   -37,   -37,    20,    20,    20,   -37,    15,    82,    20,
      38,   -37,    66,    -1,   -37,   -37,    33,    33,    37,   -37,
     -37,   -37,    38,     8,   -37,    60,    54,    38,   -37,   -37,
      83,   -37
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     1,    11,     7,     6,     8,     4,
       0,     0,    10,     0,     0,     0,     0,    20,     0,     0,
      11,     2,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     5,     0,     0,     0,     0,     0,     0,    54,    55,
       0,     0,    53,    52,     0,    30,    32,    35,    37,    44,
      47,    50,     0,     0,     9,     0,     0,     0,    25,    48,
      49,     0,     0,    26,     0,     0,     0,     0,     0,    38,
      39,    40,    41,     0,     0,     0,    27,     0,     0,     0,
       0,    51,    29,    31,    33,    34,    43,    42,    36,    45,
      46,    28,     0,     0,    23,     0,     0,     0,    21,    24,
       0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   -37,   -37,   -37,   -37,    69,   -37,   -37,   -37,
     -37,   -37,   -37,   -15,   -37,   -32,    29,    28,     9,   -37,
      21,     5,   -22,   -37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     5,     9,    10,    13,    11,    23,    24,    25,
      26,    27,    28,    29,    30,    44,    45,    46,    47,    73,
      48,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      34,    55,     3,    57,    14,     6,     7,     8,    15,    61,
      16,    17,    18,    19,    62,    59,    14,    62,    60,     1,
      15,    77,    16,    17,    18,    19,    62,    62,    31,    32,
      65,    66,    78,    62,    62,    80,     4,    37,    20,    21,
      38,    39,    22,    40,    81,    96,    12,    93,    63,    91,
      20,    76,    89,    90,    22,    33,    41,    74,    75,    67,
      68,    42,    43,    67,    68,    94,    97,    98,    69,    70,
      71,    72,    86,    87,    84,    85,    20,    95,    35,    53,
      56,    36,   100,    58,    64,    54,    79,    92,    99,    52,
     101,    82,    83,     0,    88
};

static const yytype_int8 yycheck[] =
{
      15,    33,    38,    35,     4,    14,    15,    16,     8,    41,
      10,    11,    12,    13,    19,    37,     4,    19,    40,     3,
       8,    53,    10,    11,    12,    13,    19,    19,    34,    35,
      31,    32,    37,    19,    19,    37,     0,    17,    38,    39,
      20,    21,    42,    23,    37,    37,    42,    79,    34,    34,
      38,    39,    74,    75,    42,    36,    36,    24,    25,    22,
      23,    41,    42,    22,    23,    80,     6,     7,    27,    28,
      29,    30,    67,    68,    65,    66,    38,    92,    36,    33,
       9,    42,    97,    34,    18,    42,    36,     5,    34,    20,
       7,    62,    64,    -1,    73
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    46,    38,     0,    47,    14,    15,    16,    48,
      49,    51,    42,    50,     4,     8,    10,    11,    12,    13,
      38,    39,    42,    52,    53,    54,    55,    56,    57,    58,
      59,    34,    35,    36,    58,    36,    42,    17,    20,    21,
      23,    36,    41,    42,    60,    61,    62,    63,    65,    66,
      67,    68,    51,    33,    42,    60,     9,    60,    34,    67,
      67,    60,    19,    34,    18,    31,    32,    22,    23,    27,
      28,    29,    30,    64,    24,    25,    39,    60,    37,    36,
      37,    37,    61,    62,    63,    63,    66,    66,    65,    67,
      67,    34,     5,    60,    58,    58,    37,     6,     7,    34,
      58,     7
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    49,    49,    49,    50,
      50,    51,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    53,    53,    54,    55,    56,    57,    58,    59,    60,
      60,    61,    61,    62,    62,    62,    63,    63,    64,    64,
      64,    64,    65,    65,    65,    66,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     2,     3,     1,     1,     1,     3,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     9,     5,     7,     3,     3,     3,     4,     3,
       1,     3,     1,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     1,     2,     2,
       1,     3,     1,     1,     1,     1
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
#line 178 "sintatic.y"
                                          {
            if(inicial == NULL){
                inicial = new struct Nodo;
                inicial->nombre = "program";
                inicial->valor = "";
                inicial->padre = NULL;
            }else{
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "program";
                siguiente->valor = "";
                siguiente->padre = NULL;
                check(inicial, siguiente, "list-decl");
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
            }
        }
#line 1290 "sintatic.tab.c"
    break;

  case 4: /* list-decl: list-decl decl  */
#line 195 "sintatic.y"
                         {
            Nodo *siguiente = new struct Nodo;
            siguiente->nombre = "list-decl";
            siguiente->valor = "";
            siguiente->padre = NULL;
            //Busca el nodo del tipo
            check(inicial, siguiente, "list-decl");
            siguiente->hijos.push_back(inicial);
            inicial = siguiente;
        }
#line 1305 "sintatic.tab.c"
    break;

  case 5: /* decl: tipo list-id PYC  */
#line 206 "sintatic.y"
                         {
            Nodo *siguiente = new struct Nodo;
            siguiente->nombre = "decl";
            siguiente->valor = "";
            siguiente->padre = NULL;
            checkListId(inicial, siguiente);
            siguiente->hijos.push_back(inicial);
            //Agrega el pyc como hijo
            Nodo *pyc = new struct Nodo;
            pyc->nombre = "pyc";
            pyc->valor = ";";
            pyc->padre = siguiente;
            siguiente->hijos.push_back(pyc);
            inicial = siguiente;
        }
#line 1325 "sintatic.tab.c"
    break;

  case 6: /* tipo: INT  */
#line 222 "sintatic.y"
            {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "int";
                    inicial->valor = (yyvsp[0].in);
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "int";
                    siguiente->valor = (yyvsp[0].in);
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
            }
#line 1346 "sintatic.tab.c"
    break;

  case 7: /* tipo: FLOAT  */
#line 238 "sintatic.y"
                {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "float";
                    inicial->valor = (yyvsp[0].floa);
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "float";
                    siguiente->valor = (yyvsp[0].floa);
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
            }
#line 1367 "sintatic.tab.c"
    break;

  case 8: /* tipo: BOOL  */
#line 254 "sintatic.y"
               {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "bool";
                    inicial->valor = (yyvsp[0].boo);
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "bool";
                    siguiente->valor = (yyvsp[0].boo);
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
            }
#line 1388 "sintatic.tab.c"
    break;

  case 9: /* list-id: list-id COM IDENTIFICADOR  */
#line 271 "sintatic.y"
                                   {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "list-id, id";
                siguiente->valor = (yyvsp[0].identificador);
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
            }
#line 1402 "sintatic.tab.c"
    break;

  case 10: /* list-id: IDENTIFICADOR  */
#line 280 "sintatic.y"
                        {
            if(inicial == NULL){
                inicial = new struct Nodo;
                inicial->nombre = "id";
                inicial->valor = (yyvsp[0].identificador);
                inicial->padre = NULL;
            }else{
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "id";
                siguiente->valor = (yyvsp[0].identificador);
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
            }
        }
#line 1423 "sintatic.tab.c"
    break;

  case 12: /* list-sent: list-sent sent  */
#line 297 "sintatic.y"
                         {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "list-sent";
                siguiente->valor = "";
                siguiente->padre = NULL;
                check(inicial, siguiente, "list-sent");
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("list-sent sent\n");
            
            }
#line 1440 "sintatic.tab.c"
    break;

  case 13: /* sent: sent-if  */
#line 310 "sintatic.y"
                {printf("sent-if\n");}
#line 1446 "sintatic.tab.c"
    break;

  case 14: /* sent: sent-while  */
#line 311 "sintatic.y"
                     {printf("sent-while\n");}
#line 1452 "sintatic.tab.c"
    break;

  case 15: /* sent: sent-do  */
#line 312 "sintatic.y"
                  {printf("sent-do\n");}
#line 1458 "sintatic.tab.c"
    break;

  case 16: /* sent: sent-read  */
#line 313 "sintatic.y"
                    {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "sent";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("sent-read\n");
            }
#line 1473 "sintatic.tab.c"
    break;

  case 17: /* sent: sent-write  */
#line 323 "sintatic.y"
                     {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "sent";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("sent-read\n");
                printf("sent-write\n");
            }
#line 1489 "sintatic.tab.c"
    break;

  case 18: /* sent: bloque  */
#line 334 "sintatic.y"
                 {printf("bloque\n");}
#line 1495 "sintatic.tab.c"
    break;

  case 19: /* sent: sent-assign  */
#line 335 "sintatic.y"
                      {printf("sent-assign\n");}
#line 1501 "sintatic.tab.c"
    break;

  case 20: /* sent: BREAK  */
#line 336 "sintatic.y"
                {printf("break\n");}
#line 1507 "sintatic.tab.c"
    break;

  case 21: /* sent-if: IF PI exp-bool PD THEN bloque FI  */
#line 338 "sintatic.y"
                                         {printf("if\n");}
#line 1513 "sintatic.tab.c"
    break;

  case 22: /* sent-if: IF PI exp-bool PD THEN bloque ELSE bloque FI  */
#line 339 "sintatic.y"
                                                       {printf("if-else\n");}
#line 1519 "sintatic.tab.c"
    break;

  case 23: /* sent-while: WHILE PI exp-bool PD bloque  */
#line 341 "sintatic.y"
                                    {printf("while\n");}
#line 1525 "sintatic.tab.c"
    break;

  case 24: /* sent-do: DO bloque UNTIL PI exp-bool PD PYC  */
#line 343 "sintatic.y"
                                           {printf("do\n");}
#line 1531 "sintatic.tab.c"
    break;

  case 25: /* sent-read: READ IDENTIFICADOR PYC  */
#line 345 "sintatic.y"
                               {
            if(inicial == NULL){
                //Crea el nodo padre
                inicial = new struct Nodo;
                inicial->nombre = "sent-read";
                inicial->valor = "";
                inicial->padre = NULL;
                //Crea read como hijo
                Nodo *read = new struct Nodo;
                read->nombre = "read";
                read->valor= "read";
                read->padre=inicial;
                inicial->hijos.push_back(read);
                //Crea el id como hijo
                Nodo *id = new struct Nodo;
                id->nombre = "id";
                id->valor = (yyvsp[-1].identificador);
                id->padre = inicial;
                inicial->hijos.push_back(id);
                //Crea el punto y coma como hijo
                Nodo *pyc = new struct Nodo;
                pyc->nombre = "pyc";
                pyc->valor = ";";
                pyc->padre = inicial;
                inicial->hijos.push_back(pyc);
            }else{
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "sent-read";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                //Crea su estructura
                Nodo *read = new struct Nodo;
                read->nombre = "read";
                read->valor= "read";
                read->padre=inicial;
                siguiente->hijos.push_back(read);
                //Crea el id como hijo
                Nodo *id = new struct Nodo;
                id->nombre = "id";
                id->valor = (yyvsp[-1].identificador);
                id->padre = inicial;
                siguiente->hijos.push_back(id);
                //Crea el punto y coma como hijo
                Nodo *pyc = new struct Nodo;
                pyc->nombre = "pyc";
                pyc->valor = ";";
                pyc->padre = inicial;
                siguiente->hijos.push_back(pyc);
                inicial = siguiente;
            }
        }
#line 1589 "sintatic.tab.c"
    break;

  case 26: /* sent-write: WRITE exp-bool PYC  */
#line 399 "sintatic.y"
                           {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "sent-write";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                Nodo *exp_bool = new struct Nodo;
                exp_bool->nombre = "exp-bool";
                exp_bool->valor= "";
                exp_bool->padre=siguiente;
                exp_bool->hijos.push_back(inicial/*->hijos.at(0)*/);
                //inicial->hijos.erase(inicial->hijos.begin());
                siguiente->hijos.push_back(exp_bool);
                //Crea su estructura
                Nodo *wirte = new struct Nodo;
                wirte->nombre = "write";
                wirte->valor= "write";
                wirte->padre=siguiente;
                siguiente->hijos.push_back(wirte);
                //Crea el punto y coma como hijo
                Nodo *pyc = new struct Nodo;
                pyc->nombre = "pyc";
                pyc->valor = ";";
                pyc->padre = siguiente;
                siguiente->hijos.push_back(pyc);
                inicial = siguiente;
                printf("write\n");
            }
#line 1623 "sintatic.tab.c"
    break;

  case 27: /* bloque: LI list-sent LD  */
#line 430 "sintatic.y"
                        {printf("bloque\n");}
#line 1629 "sintatic.tab.c"
    break;

  case 28: /* sent-assign: IDENTIFICADOR ASIG exp-bool PYC  */
#line 432 "sintatic.y"
                                        {printf("asignacion\n");}
#line 1635 "sintatic.tab.c"
    break;

  case 29: /* exp-bool: exp-bool OR comb  */
#line 434 "sintatic.y"
                          {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "exp-bool OR comb";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                check(inicial, siguiente, "comb");
                //Crea OR como hijo
                Nodo *oi = new struct Nodo;
                oi->nombre = "OR";
                oi->valor= "or";
                oi->padre=siguiente;
                siguiente->hijos.push_back(oi);
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("or\n");
            }
#line 1658 "sintatic.tab.c"
    break;

  case 30: /* exp-bool: comb  */
#line 452 "sintatic.y"
               {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "comb";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("comb\n");
            }
#line 1673 "sintatic.tab.c"
    break;

  case 31: /* comb: comb AND igualdad  */
#line 463 "sintatic.y"
                          {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "comb AND igualdad";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                check(inicial, siguiente, "igualdad");
                //Crea MAS como hijo
                Nodo *an = new struct Nodo;
                an->nombre = "AND";
                an->valor= "and";
                an->padre=siguiente;
                siguiente->hijos.push_back(an);
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("and\n");
            }
#line 1696 "sintatic.tab.c"
    break;

  case 32: /* comb: igualdad  */
#line 481 "sintatic.y"
                   {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "igualdad";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("igualdad\n");
            }
#line 1711 "sintatic.tab.c"
    break;

  case 33: /* igualdad: igualdad IGU rel  */
#line 492 "sintatic.y"
                         {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "igualdad IGU rel";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                check(inicial, siguiente, "rel");
                //Crea MAS como hijo
                Nodo *igu = new struct Nodo;
                igu->nombre = "IGU";
                igu->valor= "==";
                igu->padre=siguiente;
                siguiente->hijos.push_back(igu);
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("igual igual\n");
            }
#line 1734 "sintatic.tab.c"
    break;

  case 34: /* igualdad: igualdad DIS rel  */
#line 510 "sintatic.y"
                           {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "igualdad DIS rel";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                check(inicial, siguiente, "rel");
                //Crea MAS como hijo
                Nodo *dis = new struct Nodo;
                dis->nombre = "DIS";
                dis->valor= "!=";
                dis->padre=siguiente;
                siguiente->hijos.push_back(dis);
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("distinto\n");
            }
#line 1757 "sintatic.tab.c"
    break;

  case 35: /* igualdad: rel  */
#line 528 "sintatic.y"
              {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "rel";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("rel\n");
            }
#line 1772 "sintatic.tab.c"
    break;

  case 36: /* rel: expr op-rel expr  */
#line 539 "sintatic.y"
                         {
                
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "expr op-rel expr";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                check(inicial, siguiente, "op-rel");
                if(siguiente->hijos.size() > 0){
                    check(siguiente->hijos.at(0), siguiente, "term");
                    Nodo *oprel = siguiente->hijos.at(0);
                    siguiente->hijos.at(0) = siguiente->hijos.at(1);
                    siguiente->hijos.at(1) = oprel;
                }
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("operacion\n");
            }
#line 1796 "sintatic.tab.c"
    break;

  case 37: /* rel: expr  */
#line 558 "sintatic.y"
               {
                std::cout<<"hola\n";
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "expr";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("expresion\n");
            }
#line 1812 "sintatic.tab.c"
    break;

  case 38: /* op-rel: MEN  */
#line 570 "sintatic.y"
            {
            Nodo *siguiente = new struct Nodo;
            siguiente->nombre = "MEN";
            siguiente->valor = (yyvsp[0].men);
            siguiente->padre = NULL;
            siguiente->hijos.push_back(inicial);
            inicial->padre = siguiente;
            inicial = siguiente;
            Nodo *op_rel = new struct Nodo;
            op_rel->nombre = "op-rel";
            op_rel->valor = "";
            op_rel->padre = NULL;
            op_rel->hijos.push_back(inicial);
            inicial->padre = op_rel;
            inicial = op_rel;
            printf("menor\n");
        }
#line 1834 "sintatic.tab.c"
    break;

  case 39: /* op-rel: MENIGL  */
#line 587 "sintatic.y"
                 {
                
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "MENIGL";
                siguiente->valor = (yyvsp[0].menigl);
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                Nodo *op_rel = new struct Nodo;
                op_rel->nombre = "op-rel";
                op_rel->valor = "";
                op_rel->padre = NULL;
                op_rel->hijos.push_back(inicial);
                inicial->padre = op_rel;
                inicial = op_rel;
                printf("menor igual\n");
            }
#line 1857 "sintatic.tab.c"
    break;

  case 40: /* op-rel: MAY  */
#line 605 "sintatic.y"
              {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "MAY";
                siguiente->valor = (yyvsp[0].may);
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                Nodo *op_rel = new struct Nodo;
                op_rel->nombre = "op-rel";
                op_rel->valor = "";
                op_rel->padre = NULL;
                op_rel->hijos.push_back(inicial);
                inicial->padre = op_rel;
                inicial = op_rel;
                printf("mayor\n");
            }
#line 1879 "sintatic.tab.c"
    break;

  case 41: /* op-rel: MAYIGL  */
#line 622 "sintatic.y"
                 {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "MAYIGL";
                siguiente->valor = (yyvsp[0].mayigl);
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                Nodo *op_rel = new struct Nodo;
                op_rel->nombre = "op-rel";
                op_rel->valor = "";
                op_rel->padre = NULL;
                op_rel->hijos.push_back(inicial);
                inicial->padre = op_rel;
                inicial = op_rel;
                printf("mayor igual\n");
            }
#line 1901 "sintatic.tab.c"
    break;

  case 42: /* expr: expr RES term  */
#line 640 "sintatic.y"
                      {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "expr RES term";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                check(inicial, siguiente, "expr");
                check(inicial, siguiente, "term");
                //Crea MAS como hijo
                Nodo *res = new struct Nodo;
                res->nombre = "RES";
                res->valor= "-";
                res->padre=siguiente;
                siguiente->hijos.push_back(res);
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("resta\n");
            }
#line 1925 "sintatic.tab.c"
    break;

  case 43: /* expr: expr MAS term  */
#line 659 "sintatic.y"
                        {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "expr MAS term";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                check(inicial, siguiente, "expr");
                check(inicial, siguiente, "term");
                //Crea MAS como hijo
                Nodo *mas = new struct Nodo;
                mas->nombre = "MAS";
                mas->valor= "+";
                mas->padre=siguiente;
                siguiente->hijos.push_back(mas);
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("suma\n");
            }
#line 1949 "sintatic.tab.c"
    break;

  case 44: /* expr: term  */
#line 678 "sintatic.y"
               {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "term";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("term\n");
            }
#line 1964 "sintatic.tab.c"
    break;

  case 45: /* term: term MUL unario  */
#line 689 "sintatic.y"
                        {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "term MUL unario";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                check(inicial, siguiente, "term");
                check(inicial, siguiente, "unario");
                //Crea MUL como hijo
                Nodo *mul = new struct Nodo;
                mul->nombre = "MUL";
                mul->valor= "*";
                mul->padre=siguiente;
                siguiente->hijos.push_back(mul);
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("multiplicacion\n");
            
            }
#line 1989 "sintatic.tab.c"
    break;

  case 46: /* term: term DIV unario  */
#line 709 "sintatic.y"
                          {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "term DIV unario";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                check(inicial, siguiente, "term");
                check(inicial, siguiente, "unario");
                //Crea div como hijo
                Nodo *div = new struct Nodo;
                div->nombre = "DIV";
                div->valor= "/";
                div->padre=siguiente;
                siguiente->hijos.push_back(div);
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("division\n");
            }
#line 2013 "sintatic.tab.c"
    break;

  case 47: /* term: unario  */
#line 728 "sintatic.y"
                 {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "unario";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("unario\n");
            }
#line 2028 "sintatic.tab.c"
    break;

  case 48: /* unario: NOT unario  */
#line 739 "sintatic.y"
                   {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "not unario";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                Nodo *unario = new struct Nodo;
                unario->nombre = "unario";
                unario->valor= "";
                unario->padre=siguiente;
                unario->hijos.push_back(inicial);
                siguiente->hijos.push_back(unario);
                //Crea not como hijo
                Nodo *no = new struct Nodo;
                no->nombre = "NOT";
                no->valor= "not";
                no->padre=siguiente;
                siguiente->hijos.push_back(no);
                inicial = siguiente;
                printf("negacion\n");
            }
#line 2055 "sintatic.tab.c"
    break;

  case 49: /* unario: RES unario  */
#line 761 "sintatic.y"
                     {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "-unario";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                Nodo *unario = new struct Nodo;
                unario->nombre = "unario";
                unario->valor= "";
                unario->padre=siguiente;
                unario->hijos.push_back(inicial);
                siguiente->hijos.push_back(unario);
                //Crea res como hijo
                Nodo *res = new struct Nodo;
                res->nombre = "RES";
                res->valor= "-";
                res->padre=siguiente;
                siguiente->hijos.push_back(res);
                inicial = siguiente;
                printf("negativo\n");
            }
#line 2082 "sintatic.tab.c"
    break;

  case 50: /* unario: factor  */
#line 783 "sintatic.y"
                 {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "factor";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("factor\n");
            }
#line 2097 "sintatic.tab.c"
    break;

  case 51: /* factor: PI exp-bool PD  */
#line 794 "sintatic.y"
                       {
            //!Revisar
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "(exp-bool)";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                checkSec(inicial, siguiente, "term", 0, 1);
                Nodo *exp_bool = new struct Nodo;
                exp_bool->nombre = "exp-bool";
                exp_bool->valor= "";
                exp_bool->padre=siguiente;
                exp_bool->hijos.push_back(inicial/*->hijos.at(0)*/);
                //inicial->hijos.erase(inicial->hijos.begin());
                siguiente->hijos.push_back(exp_bool);
                //Crea pi como hijo
                Nodo *pi = new struct Nodo;
                pi->nombre = "PI";
                pi->valor= "(";
                pi->padre=siguiente;
                siguiente->hijos.push_back(pi);
                //Crea pd punto y coma como hijo
                Nodo *pd = new struct Nodo;
                pd->nombre = "PD";
                pd->valor = ")";
                pd->padre = siguiente;
                siguiente->hijos.push_back(pd);
                inicial = siguiente;
                printf("(exp-bool)\n");
            }
#line 2133 "sintatic.tab.c"
    break;

  case 52: /* factor: IDENTIFICADOR  */
#line 825 "sintatic.y"
                        {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "id";
                    inicial->valor = (yyvsp[0].identificador);
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "id";
                    siguiente->valor = (yyvsp[0].identificador);
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
                printf("id: %s\n",(yyvsp[0].identificador));
            }
#line 2155 "sintatic.tab.c"
    break;

  case 53: /* factor: NUMERO  */
#line 842 "sintatic.y"
                 {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "numero";
                    inicial->valor = (yyvsp[0].numero);
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "numero";
                    siguiente->valor = std::to_string((yyvsp[0].numero));
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
                std::cout << "numero: " << std::to_string((yyvsp[0].numero)) << "\n";
            }
#line 2177 "sintatic.tab.c"
    break;

  case 54: /* factor: TRUE  */
#line 859 "sintatic.y"
               {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "true";
                    inicial->valor = (yyvsp[0].tru);
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "true";
                    siguiente->valor = (yyvsp[0].tru);
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
                printf("true\n");
            }
#line 2199 "sintatic.tab.c"
    break;

  case 55: /* factor: FALSE  */
#line 876 "sintatic.y"
                {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "false";
                    inicial->valor = (yyvsp[0].fals);
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "false";
                    siguiente->valor = (yyvsp[0].fals);
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
                printf("false\n");
            }
#line 2221 "sintatic.tab.c"
    break;


#line 2225 "sintatic.tab.c"

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

#line 893 "sintatic.y"


int yyerror(char *s){
    printf("->Error sintáctico: %s\n", s);
}


void printNode(Nodo *init, int tabuladores){
    if(init != NULL){
        for(int i=0; i<tabuladores; i++){
            std::cout<<"   ";
        } 
        std::cout << init->nombre << ": " << init->valor << "\n";
        for(int i=0; i<init->hijos.size(); i++){
            printNode(init->hijos.at(i),tabuladores+1);
        }
    }
}

int main(int argc, char **argv){
    yyparse();
    printNode(inicial,0);
    return 0;
}
