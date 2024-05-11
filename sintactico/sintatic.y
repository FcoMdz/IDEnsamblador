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
    /*program:
        lista {printf("programa\n");}
    lista:
        INT IDENTIFICADOR PYC {printf("declaración simple\n");}*/
    program: 
        PROGRAM LI list-decl list-sent LD {printf("program\n");}
    list-decl:
        | decl {printf("decl\n");}
        | list-decl decl {printf("list-decl decl\n");}
    decl: 
        tipo list-id PYC {printf("tipo list-id;\n");}
    tipo: 
        INT {printf("int\n");}
        | FLOAT {printf("float\n");}
        | BOOL {printf("bool\n");}
    list-id: 
        list-id COM IDENTIFICADOR  {printf("list-id, id\n");}
        | IDENTIFICADOR {printf("id\n");}
    list-sent: 
        | sent {printf("sent\n");}
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
        IF PI exp-bool PD THEN bloque FI {printf("if: %s %s %s %s %s\n", $1,$2,$4,$5,$7);}
        | IF PI exp-bool PD THEN bloque ELSE bloque FI {printf("if-else: %s %s %s %s %s %s\n", $1,$2,$4,$5,$7,$9);}
    sent-while: 
        WHILE PI exp-bool PD bloque {printf("while: %s %s %s\n", $1,$2,$4);}
    sent-do:
        DO bloque UNTIL PI exp-bool PD PYC {printf("do: %s %s %s %s %s\n", $1,$3,$4,$6,$7);}
    sent-read: 
        READ IDENTIFICADOR PYC {printf("read: %s %s %s\n", $1,$2,$3);}
    sent-write: 
        WRITE IDENTIFICADOR PYC {printf("write: %s %s\n", $2,$3);}
    bloque: 
        LI list-sent LD {printf("bloque: %s  %s\n", $1,$3);}
    sent-assign: 
        IDENTIFICADOR ASIG exp-bool PYC {printf("asignacion: %s %s %s\n", $1,$2,$4);}
    exp-bool:
        exp-bool OR comb  {printf("or: %s\n",$2);}
        | comb {printf("comb\n");}
        | factor {printf("factor\n");}
    comb: 
        comb AND igualdad {printf("and: %s\n", $2);}
        | igualdad {printf("igualdad\n");}
    igualdad: 
        igualdad IGU rel {printf("igualdad: %s\n", $2);}
        | igualdad DIS rel {printf("distinto: %s\n", $2);}
        | rel {printf("rel\n");}
    rel: 
        expr op-rel expr {printf("operacion\n");}
    op-rel: 
        MEN {printf("menor: %s\n", $1);}
        | MENIGL {printf("menor igual: %s\n", $1);}
        | MAY {printf("mayor: %s\n", $1);}
        | MAYIGL {printf("mayor igual: %s\n", $1);}
    expr: 
        expr RES term {printf("resta: %s\n", $2);}
        | expr MAS term {printf("suma: %s\n",$2);}
        | term
    term: 
        term MUL unario {printf("multiplicacion: %s\n", $2);}
        | term DIV unario {printf("division: %s\n",$2);}
        | unario
    unario: 
        NOT unario {printf("negacion: %s\n", $1);}
        | RES unario {printf("negativo: %s\n", $1);}
        | factor
    factor: 
        PI exp-bool PD {printf("factor: %s %s\n", $1,$3);}
        | IDENTIFICADOR {printf("id: %s\n", $1);}
        | NUMERO {printf("int: %f\n", $1);}
        | TRUE {printf("true: %s\n", $1);}
        | FALSE {printf("false: %s\n", $1);}
%%

int yyerror(char *s){
    printf("->Error sintáctico: %s\n", s);
}

int main(int argc, char **argv){
    yyparse();
    return 0;
}