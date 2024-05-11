/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTATIC_TAB_H_INCLUDED
# define YY_YY_SINTATIC_TAB_H_INCLUDED
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
    PROGRAM = 258,                 /* PROGRAM  */
    IF = 259,                      /* IF  */
    THEN = 260,                    /* THEN  */
    ELSE = 261,                    /* ELSE  */
    FI = 262,                      /* FI  */
    DO = 263,                      /* DO  */
    UNTIL = 264,                   /* UNTIL  */
    WHILE = 265,                   /* WHILE  */
    BREAK = 266,                   /* BREAK  */
    READ = 267,                    /* READ  */
    WRITE = 268,                   /* WRITE  */
    FLOAT = 269,                   /* FLOAT  */
    INT = 270,                     /* INT  */
    BOOL = 271,                    /* BOOL  */
    NOT = 272,                     /* NOT  */
    AND = 273,                     /* AND  */
    OR = 274,                      /* OR  */
    TRUE = 275,                    /* TRUE  */
    FALSE = 276,                   /* FALSE  */
    MAS = 277,                     /* MAS  */
    RES = 278,                     /* RES  */
    MUL = 279,                     /* MUL  */
    DIV = 280,                     /* DIV  */
    ELE = 281,                     /* ELE  */
    MEN = 282,                     /* MEN  */
    MENIGL = 283,                  /* MENIGL  */
    MAY = 284,                     /* MAY  */
    MAYIGL = 285,                  /* MAYIGL  */
    IGU = 286,                     /* IGU  */
    DIS = 287,                     /* DIS  */
    ASIG = 288,                    /* ASIG  */
    PYC = 289,                     /* PYC  */
    COM = 290,                     /* COM  */
    PI = 291,                      /* PI  */
    PD = 292,                      /* PD  */
    LI = 293,                      /* LI  */
    LD = 294,                      /* LD  */
    CADENA = 295,                  /* CADENA  */
    NUMERO = 296,                  /* NUMERO  */
    IDENTIFICADOR = 297,           /* IDENTIFICADOR  */
    OTRO = 298,                    /* OTRO  */
    SPACE = 299                    /* SPACE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "sintatic.y"

    float numero;
    char* cadena;
    char* program;
    char* i;
    char* then;
    char* els;
    char* fi;
    char* d;
    char* until;
    char* whil;
    char* brea;
    char* read;
    char* write;
    char* floa;
    char* in;
    char* boo;
    char* no;
    char* an;
    char* o;
    char* tru;
    char* fals;
    char* mas;
    char* res;
    char* mul;
    char* div;
    char* ele;
    char* men;
    char* menigl;
    char* may;
    char* mayigl;
    char* igu;
    char* dis;
    char* asig;
    char* pyc;
    char* com;
    char* pi;
    char* pd;
    char* li;
    char* space;
    char* ld;
    char* identificador;

#line 152 "sintatic.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATIC_TAB_H_INCLUDED  */
