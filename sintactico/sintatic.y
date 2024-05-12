/*Declaraciones*/
%{
    #include <stdio.h>
    int yylex();
    int yyerror(char *s);
%}

%token PROGRAM IF THEN ELSE FI DO UNTIL WHILE BREAK READ WRITE FLOAT INT BOOL NOT AND OR TRUE FALSE MAS RES MUL DIV ELE MEN MENIGL MAY MAYIGL IGU DIS ASIG PYC COM PI PD LI LD CADENA NUMERO IDENTIFICADOR OTRO SPACE

%union{
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
}

%type <cadena> CADENA
%type <program> PROGRAM
%type <i> IF
%type <then> THEN
%type <els> ELSE
%type <fi> FI
%type <d> DO
%type <until> UNTIL
%type <whil> WHILE
%type <brea> BREAK
%type <read> READ
%type <write> WRITE
%type <floa> FLOAT
%type <in> INT
%type <boo> BOOL
%type <no> NOT
%type <an> AND
%type <o> OR
%type <tru> TRUE
%type <fals> FALSE
%type <mas> MAS
%type <res> RES
%type <mul> MUL
%type <div> DIV
%type <ele> ELE
%type <men> MEN
%type <menigl> MENIGL
%type <may> MAY
%type <mayigl> MAYIGL
%type <igu> IGU
%type <dis> DIS
%type <asig> ASIG
%type <pyc> PYC
%type <com> COM
%type <pi> PI
%type <pd> PD
%type <li> LI
%type <ld> LD
%type <identificador> IDENTIFICADOR
%type <numero> NUMERO
%type <space> SPACE



%%
    program: 
        PROGRAM LI list-decl list-sent LD {printf("program\n");}
    list-decl:
        | list-decl decl {printf("list-decl decl\n");}
    decl: 
        tipo list-id PYC {printf("tipo list-id;\n");}
    tipo: 
        INT {printf("int\n");}
        | FLOAT {printf("float\n");}
        | BOOL {printf("bool\n");}
    list-id: 
        list-id COM IDENTIFICADOR  {printf("list-id, id: %s\n",$3);}
        | IDENTIFICADOR {printf("id: %s\n", $1);}
    list-sent: 
        | list-sent sent {printf("list-sent sent\n");}
    sent: 
        sent-if {printf("sent-if\n");}
        | sent-while {printf("sent-while\n");}
        | sent-do {printf("sent-do\n");}
        | sent-read {printf("sent-read\n");}
        | sent-write {printf("sent-write\n");}
        | bloque {printf("bloque\n");}
        | sent-assign {printf("sent-assign\n");}
        | BREAK {printf("break\n");}
    sent-if: 
        IF PI exp-bool PD THEN bloque FI {printf("if\n");}
        | IF PI exp-bool PD THEN bloque ELSE bloque FI {printf("if-else\n");}
    sent-while: 
        WHILE PI exp-bool PD bloque {printf("while\n");}
    sent-do:
        DO bloque UNTIL PI exp-bool PD PYC {printf("do\n");}
    sent-read: 
        READ IDENTIFICADOR PYC {printf("read\n");}
    sent-write: 
        WRITE IDENTIFICADOR PYC {printf("write\n");}
    bloque: 
        LI list-sent LD {printf("bloque\n");}
    sent-assign: 
        IDENTIFICADOR ASIG exp-bool PYC {printf("asignacion\n");}
    exp-bool:
        exp-bool OR comb  {printf("or\n");}
        | comb {printf("comb\n");}
    comb: 
        comb AND igualdad {printf("and\n");}
        | igualdad {printf("igualdad\n");}
    igualdad: 
        igualdad IGU rel {printf("igual igual\n");}
        | igualdad DIS rel {printf("distinto\n");}
        | rel {printf("rel\n");}
    rel: 
        expr op-rel expr {printf("operacion\n");}
        | expr {printf("expresion\n");}
    op-rel: 
        MEN {printf("menor\n");}
        | MENIGL {printf("menor igual\n");}
        | MAY {printf("mayor\n");}
        | MAYIGL {printf("mayor igual\n");}
    expr: 
        expr RES term {printf("resta\n");}
        | expr MAS term {printf("suma\n");}
        | term {printf("term\n");}
    term: 
        term MUL unario {printf("multiplicacion\n");}
        | term DIV unario {printf("division\n");}
        | unario {printf("unario\n");}
    unario: 
        NOT unario {printf("negacion\n");}
        | RES unario {printf("negativo\n");}
        | factor {printf("factor\n");}
    factor: 
        PI exp-bool PD {printf("factor\n");}
        | IDENTIFICADOR {printf("id: %s\n",$1);}
        | NUMERO {printf("numero: %f\n",$1);}
        | TRUE {printf("true\n");}
        | FALSE {printf("false\n");}
%%

int yyerror(char *s){
    printf("->Error sintáctico: %s\n", s);
}

int main(int argc, char **argv){
    yyparse();
    return 0;
}