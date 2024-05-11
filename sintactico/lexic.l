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
MAS \+
RES \-
MUL \*
DIV \/
ELE \^
MEN \<
MENIGL \<=
MAY >
MAYIGL >=
IGU ==
DIS !=
ASIG =
PYC ;
COM ,
PI \(
PD \)
LI \{
LD \}
IDENTIFICADOR {LETRA}({LETRA}|{DIGITO})*
CADENA ["][^"]*["]
COMENTARIO_LINEA \/\/.*
COMENTARIO_MULTI \/\*(.|\n)*\*\/
NUMERO {DIGITO}{DIGITO}*(.{DIGITO}{DIGITO}*)?

/*Reglas de detección*/
/*"\n" {return 0;}*/
%%

{SPACE} {
    //printf("Espacio\n");
}
{PROGRAM} {
        yylval.program = yytext;
        return (PROGRAM);
    }
{IF} {
        yylval.i = yytext;
        return (IF);
    }
{THEN} {
        yylval.then = yytext;
        return (THEN);
    }
{ELSE} {
        yylval.els = yytext;
        return (ELSE);
    }
{FI} {
        yylval.fi = yytext;
        return (FI);
    }
{DO} {
        yylval.d = yytext;
        return (DO);
    }
{UNTIL} {
        yylval.until = yytext;
        return (UNTIL);
    }
{WHILE} {
        yylval.whil = yytext;
        return (WHILE);
    }
{BREAK} {
        yylval.brea = yytext;
        return (BREAK);
    }
{READ} {
        yylval.read = yytext;
        return (READ);
    }
{WRITE} {
        yylval.write = yytext;
        return (WRITE);
    }
{FLOAT} {
        yylval.floa = yytext;
        return (FLOAT);
    }
{INT} {
        yylval.in = yytext;
        return (INT);
    }
{BOOL} {
        yylval.boo = yytext;
        return (BOOL);
    }
{NOT} {
        yylval.no = yytext;
        return (NOT);
    }
{AND} {
        yylval.an = yytext;
        return (AND);
    }
{OR} {
        yylval.o = yytext;
        return (OR);
    }
{TRUE} {
        yylval.tru = yytext;
        return (TRUE);
    }
{FALSE} {
        yylval.fals = yytext;
        return (FALSE);
    }
{MAS} {
        yylval.mas = yytext;
        return (MAS);
    }
{RES} {
        yylval.res = yytext;
        return (RES);
    }
{MUL} {
        yylval.mul = yytext;
        return (MUL);
    }
{DIV} {
        yylval.div = yytext;
        return (DIV);
    }
{ELE} {
        yylval.ele = yytext;
        return (ELE);
    }
{MEN} {
        yylval.men = yytext;
        return (MEN);
    }
{MENIGL} {
        yylval.menigl = yytext;
        return (MENIGL);
    }
{MAY} {
        yylval.may = yytext;
        return (MAY);
    }
{MAYIGL} {
        yylval.mayigl = yytext;
        return (MAYIGL);
    }
{IGU} {
        yylval.igu = yytext;
        return (IGU);
    }
{DIS} {
        yylval.dis = yytext;
        return (DIS);
    }
{ASIG} {
        yylval.asig = yytext;
        return (ASIG);
    }
{PYC} {
        yylval.pyc = yytext;
        return (PYC);
    }
{COM} {
        yylval.com = yytext;
        return (COM);
    }
{PI} {
        yylval.pi = yytext;
        return (PI);
    }
{PD} {
        yylval.pd = yytext;
        return (PD);
    }
{LI} {
        yylval.li = yytext;
        return (LI);
    }
{LD} {
        yylval.ld = yytext;
        return (LD);
    }
{CADENA} {
        yylval.cadena = yytext;
        return (CADENA);
    }
{COMENTARIO_LINEA}|{COMENTARIO_MULTI} {
        printf("Comentario\n");
    }
{NUMERO} {
        yylval.numero = std::atof(yytext);
        return (NUMERO);
    }
{IDENTIFICADOR} {
        yylval.identificador = yytext;
        return (IDENTIFICADOR);
    }
. {
    showError(yytext); return(OTRO);
}
%%

/*Sección de codigo*/

void showError(char* other){
    printf("Error léxico %s\n", other);
}