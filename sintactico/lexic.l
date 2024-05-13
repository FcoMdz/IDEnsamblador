/*Código del análizador léxico adaptado para ser usado con bison*/
/*Variables*/
%{
    #include <iostream>
    #include "sintatic.tab.h"
    int yylex(void);
    void showError(char* other);
%}
%option noyywrap
/*Especificaciones regex*/
SPACE [ ]|[\t]|[\n]|[\r]
LETRA [a-z|A-Z]
DIGITO [0-9]
PROGRAM "program"
IF "if"
THEN "then"
ELSE "else"
FI "fi"
DO "do"
UNTIL "until"
WHILE "while"
BREAK "break"
READ "read"
WRITE "write"
FLOAT "float"
INT "int"
BOOL "bool"
NOT "not"
AND "and"
OR "or"
TRUE "true"
FALSE "false"
MAS [+]
RES [-]
MUL [*]
DIV [/]
ELE [\^]
MEN [<]
MENIGL [<][=]
MAY [>]
MAYIGL [>][=]
IGU [=][=]
DIS [!][=]
ASIG [=]
PYC [;]
COM [,]
PI [(]
PD [)]
LI [{]
LD [}]
IDENTIFICADOR {LETRA}({LETRA}|{DIGITO})*
CADENA ["][^"]*["]
COMENTARIO_LINEA \/\/.*
COMENTARIO_MULTI \/\*(.|\n)*\*\/
NUMERO {DIGITO}+(\.{DIGITO}+)?

/*Reglas de detección*/
/*"\n" {return 0;}*/
%%

{SPACE} {
    //printf("Espacio\n");
}
{PROGRAM} {
    //printf("lex: %s\n",yytext);
        yylval.program = yytext;
        return (PROGRAM);
    }
{IF} {
    //printf("lex: %s\n",yytext);
        yylval.i = yytext;
        return (IF);
    }
{THEN} {
    //printf("lex: %s\n",yytext);
        yylval.then = yytext;
        return (THEN);
    }
{ELSE} {
    //printf("lex: %s\n",yytext);
        yylval.els = yytext;
        return (ELSE);
    }
{FI} {
    //printf("lex: %s\n",yytext);
        yylval.fi = yytext;
        return (FI);
    }
{DO} {
    //printf("lex: %s\n",yytext);
        yylval.d = yytext;
        return (DO);
    }
{UNTIL} {
    //printf("lex: %s\n",yytext);
        yylval.until = yytext;
        return (UNTIL);
    }
{WHILE} {
    //printf("lex: %s\n",yytext);
        yylval.whil = yytext;
        return (WHILE);
    }
{BREAK} {
    //printf("lex: %s\n",yytext);
        yylval.brea = yytext;
        return (BREAK);
    }
{READ} {
    //printf("lex: %s\n",yytext);
        yylval.read = yytext;
        return (READ);
    }
{WRITE} {
    //printf("lex: %s\n",yytext);
        yylval.write = yytext;
        return (WRITE);
    }
{FLOAT} {
    //printf("lex: %s\n",yytext);
        yylval.floa = yytext;
        return (FLOAT);
    }
{INT} {
    //printf("lex: %s\n",yytext);
        yylval.in = yytext;
        return (INT);
    }
{BOOL} {
    //printf("lex: %s\n",yytext);
        yylval.boo = yytext;
        return (BOOL);
    }
{NOT} {
    //printf("lex: %s\n",yytext);
        yylval.no = yytext;
        return (NOT);
    }
{AND} {
    //printf("lex: %s\n",yytext);
        yylval.an = yytext;
        return (AND);
    }
{OR} {
    //printf("lex: %s\n",yytext);
        yylval.o = yytext;
        return (OR);
    }
{TRUE} {
    //printf("lex: %s\n",yytext);
        yylval.tru = yytext;
        return (TRUE);
    }
{FALSE} {
    //printf("lex: %s\n",yytext);
        yylval.fals = yytext;
        return (FALSE);
    }
{MAS} {
    //printf("lex: %s\n",yytext);
        yylval.mas = yytext;
        return (MAS);
    }
{RES} {
    //printf("lex: %s\n",yytext);
        yylval.res = yytext;
        return (RES);
    }
{MUL} {
    //printf("lex: %s\n",yytext);
        yylval.mul = yytext;
        return (MUL);
    }
{DIV} {
    //printf("lex: %s\n",yytext);
        yylval.div = yytext;
        return (DIV);
    }
{ELE} {
    //printf("lex: %s\n",yytext);
        yylval.ele = yytext;
        return (ELE);
    }
{MEN} {
        //printf("lex: %s\n",yytext);
        yylval.men = yytext;
        return (MEN);
    }
{MENIGL} {
        //printf("lex: %s\n",yytext);
        yylval.menigl = yytext;
        return (MENIGL);
    }
{MAY} {
    //printf("lex: %s\n",yytext);
        yylval.may = yytext;
        return (MAY);
    }
{MAYIGL} {
    //printf("lex: %s\n",yytext);
        yylval.mayigl = yytext;
        return (MAYIGL);
    }
{IGU} {
    //printf("lex: %s\n",yytext);
        yylval.igu = yytext;
        return (IGU);
    }
{DIS} {
    //printf("lex: %s\n",yytext);
        yylval.dis = yytext;
        return (DIS);
    }
{ASIG} {
    //printf("lex: %s\n",yytext);
        yylval.asig = yytext;
        return (ASIG);
    }
{PYC} {
    //printf("lex: %s\n",yytext);
        yylval.pyc = yytext;
        return (PYC);
    }
{COM} {
    //printf("lex: %s\n",yytext);
        yylval.com = yytext;
        return (COM);
    }
{PI} {
    //printf("lex: %s\n",yytext);
        yylval.pi = yytext;
        return (PI);
    }
{PD} {
    //printf("lex: %s\n",yytext);
        yylval.pd = yytext;
        return (PD);
    }
{LI} {
    //printf("lex: %s\n",yytext);
        yylval.li = yytext;
        return (LI);
    }
{LD} {
    //printf("lex: %s\n",yytext);
        yylval.ld = yytext;
        return (LD);
    }
{CADENA} {
    //printf("lex: %s\n",yytext);
        yylval.cadena = yytext;
        return (CADENA);
    }
{COMENTARIO_LINEA}|{COMENTARIO_MULTI} {
        //printf("lex: comentario\n");
    }
{NUMERO} {
    //printf("lex num: %s\n",yytext);
        yylval.numero = std::atof(yytext);
        return (NUMERO);
    }
{IDENTIFICADOR} {
    //printf("lex: %s\n",yytext);
        yylval.identificador = yytext;
        return (IDENTIFICADOR);
    }
. {
     //printf("lex: %s\n",yytext);
    showError(yytext); return(OTRO);
}
%%

/*Sección de codigo*/

void showError(char* other){
    printf("Error léxico %s\n",  other);
}