/*Declaraciones*/
%{
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

%}

%token PROGRAM IF THEN ELSE FI DO UNTIL WHILE BREAK READ WRITE FLOAT INT BOOL NOT AND OR TRUE FALSE MAS RES MUL DIV ELE MEN MENIGL MAY MAYIGL IGU DIS ASIG PYC COM PI PD LI LD CADENA NUMERO IDENTIFICADOR OTRO SPACE

%union{
    float numero;
    char* cadena;
    struct Nodo* nodo;
}

%type <cadena> CADENA
%type <cadena> PROGRAM
%type <cadena> IF
%type <cadena> THEN
%type <cadena> ELSE
%type <cadena> FI
%type <cadena> DO
%type <cadena> UNTIL
%type <cadena> WHILE
%type <cadena> BREAK
%type <cadena> READ
%type <cadena> WRITE
%type <cadena> FLOAT
%type <cadena> INT
%type <cadena> BOOL
%type <cadena> NOT
%type <cadena> AND
%type <cadena> OR
%type <cadena> TRUE
%type <cadena> FALSE
%type <cadena> MAS
%type <cadena> RES
%type <cadena> MUL
%type <cadena> DIV
%type <cadena> ELE
%type <cadena> MEN
%type <cadena> MENIGL
%type <cadena> MAY
%type <cadena> MAYIGL
%type <cadena> IGU
%type <cadena> DIS
%type <cadena> ASIG
%type <cadena> PYC
%type <cadena> COM
%type <cadena> PI
%type <cadena> PD
%type <cadena> LI
%type <cadena> LD
%type <cadena> IDENTIFICADOR
%type <numero> NUMERO
%type <cadena> SPACE
%type <nodo> program
%type <nodo> list-decl
%type <nodo> decl
%type <nodo> tipo
%type <nodo> list-id
%type <nodo> list-sent
%type <nodo> sent
%type <nodo> sent-if
%type <nodo> sent-while
%type <nodo> sent-do
%type <nodo> sent-read
%type <nodo> sent-write
%type <nodo> bloque
%type <nodo> sent-assign
%type <nodo> exp-bool
%type <nodo> comb
%type <nodo> igualdad
%type <nodo> rel
%type <nodo> op-rel
%type <nodo> expr
%type <nodo> term
%type <nodo> unario
%type <nodo> factor

%%
    program: 
        PROGRAM LI list-decl list-sent LD {
            $$ = new struct Nodo;
            $$->nombre = "program";
            Nodo *prog = new struct Nodo;
            prog->nombre = "program";
            prog->valor = "program";
            Nodo *li = new struct Nodo;
            li->nombre = "li";
            li->valor = "{";
            Nodo *ld = new struct Nodo;
            ld->nombre = "ld";
            ld->valor = "}";
            $$->hijos.push_back(prog);
            $$->hijos.push_back(li);
            $$->hijos.push_back($3);
            $$->hijos.push_back($4);
            $$->hijos.push_back(ld);
            inicial = $$;
            
        }
        |error '\n'
    list-decl:
        {
            $$ = NULL;
        }
        | list-decl decl {
            $$ = new struct Nodo;
            $$->nombre = "list-decl";
            $$->hijos.push_back($1);
            $$->hijos.push_back($2);
            inicial = $$;
        }
    decl: 
        tipo list-id PYC {
            $$ = new struct Nodo;
            $$->nombre = "decl";
            Nodo *pyc = new struct Nodo;
            pyc->nombre = "pyc";
            pyc->valor = ";";
            $$->hijos.push_back($1);
            $$->hijos.push_back($2);
            $$->hijos.push_back(pyc);
            inicial = $$;
        }
        |error '\n'
    tipo: 
        INT {
                $$ = new struct Nodo;
                $$->nombre = "tipo";
                $$->valor = $1;
                inicial = $$;
            }
        | FLOAT {
                $$ = new struct Nodo;
                $$->nombre = "tipo";
                $$->valor = $1;
                inicial = $$;
            }
        | BOOL {
                $$ = new struct Nodo;
                $$->nombre = "tipo";
                $$->valor = $1;
                inicial = $$;
            }
    list-id: 
        list-id COM IDENTIFICADOR  {
                $$ = new struct Nodo;
                $$->nombre = "list-id";
                Nodo *coma = new struct Nodo;
                coma->nombre = "coma";
                coma->valor = ",";
                Nodo *id = new struct Nodo;
                id->nombre = "id";
                id->valor = $3;
                $$->hijos.push_back($1);
                $$->hijos.push_back(coma);
                $$->hijos.push_back(id);
                inicial = $$;
            }
        | IDENTIFICADOR {
            $$ = new struct Nodo;
            $$->nombre = "id";
            $$->valor = $1;
            inicial = $$;
        }
    list-sent: 
        {
            $$ = NULL;
        }
        | list-sent sent {
            $$ = new struct Nodo;
            $$->nombre = "list-sent";
            $$->hijos.push_back($1);
            $$->hijos.push_back($2);
            inicial = $$;
        }
        |error '\n'
    sent: 
        sent-if {
                $$ = new struct Nodo;
                $$->nombre = "sent";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        | sent-while {
                $$ = new struct Nodo;
                $$->nombre = "sent";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        | sent-do {
                $$ = new struct Nodo;
                $$->nombre = "sent";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        | sent-read {
                $$ = new struct Nodo;
                $$->nombre = "sent";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        | sent-write {
                $$ = new struct Nodo;
                $$->nombre = "sent";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        | sent-assign {
                $$ = new struct Nodo;
                $$->nombre = "sent";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        | BREAK {
                $$ = new struct Nodo;
                $$->nombre = "sent";
                $$->valor = $1;
                inicial = $$;
            }
        |error '\n'
    sent-if: 
        IF PI exp-bool PD THEN bloque FI {
            $$ = new struct Nodo;
            $$->nombre = "sent-if";
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
            $$->hijos.push_back(i);
            $$->hijos.push_back(pi);
            $$->hijos.push_back($3);
            $$->hijos.push_back(pd);
            $$->hijos.push_back(the);
            $$->hijos.push_back($6);
            $$->hijos.push_back(fi);
            inicial = $$;
            }
        | IF PI exp-bool PD THEN bloque ELSE bloque FI {
            $$ = new struct Nodo;
            $$->nombre = "sent-if";
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
            $$->hijos.push_back(i);
            $$->hijos.push_back(pi);
            $$->hijos.push_back($3);
            $$->hijos.push_back(pd);
            $$->hijos.push_back(the);
            $$->hijos.push_back($6);
            $$->hijos.push_back(els);
            $$->hijos.push_back($8);
            $$->hijos.push_back(fi);
            inicial = $$;
            }
    sent-while: 
        WHILE PI exp-bool PD bloque {
            $$ = new struct Nodo;
            $$->nombre = "sent-while";
            Nodo *whil = new struct Nodo;
            whil->nombre = "while";
            whil->valor = "while";
            Nodo *pi = new struct Nodo;
            pi->nombre = "pi";
            pi->valor = "(";
            Nodo *pd = new struct Nodo;
            pd->nombre = "pd";
            pd->valor = ")";
            $$->hijos.push_back(whil);
            $$->hijos.push_back(pi);
            $$->hijos.push_back($3);
            $$->hijos.push_back(pd);
            $$->hijos.push_back($5);
            inicial = $$;
        }
    sent-do:
        DO bloque UNTIL PI exp-bool PD PYC {
                $$ = new struct Nodo;
                $$->nombre = "sent-do";
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
                $$->hijos.push_back(d);
                $$->hijos.push_back($2);
                $$->hijos.push_back(unti);
                $$->hijos.push_back(pi);
                $$->hijos.push_back($5);
                $$->hijos.push_back(pd);
                $$->hijos.push_back(pyc);
                inicial = $$;
            }
    sent-read: 
        READ IDENTIFICADOR PYC {
            $$ = new struct Nodo;
            $$->nombre = "bloque";
            Nodo *read = new struct Nodo;
            read->nombre = "read";
            read->valor = "read";
            Nodo *id = new struct Nodo;
            id->nombre = "id";
            id->valor = $2;
            Nodo *pyc = new struct Nodo;
            pyc->nombre = "pyc";
            pyc->valor = ";";
            $$->hijos.push_back(read);
            $$->hijos.push_back(id);
            $$->hijos.push_back(pyc);
            inicial = $$;
        }
    sent-write: 
        WRITE exp-bool PYC {
                $$ = new struct Nodo;
                $$->nombre = "bloque";
                Nodo *write = new struct Nodo;
                write->nombre = "write";
                write->valor = "write";
                Nodo *pyc = new struct Nodo;
                pyc->nombre = "pyc";
                pyc->valor = ";";
                $$->hijos.push_back(write);
                $$->hijos.push_back($2);
                $$->hijos.push_back(pyc);
                inicial = $$;
            }        
    bloque: 
        LI list-sent LD {
                $$ = new struct Nodo;
                $$->nombre = "bloque";
                Nodo *li = new struct Nodo;
                li->nombre = "li";
                li->valor = "{";
                Nodo *ld = new struct Nodo;
                ld->nombre = "ld";
                ld->valor = "}";
                $$->hijos.push_back(li);
                $$->hijos.push_back($2);
                $$->hijos.push_back(ld);
                inicial = $$;
            }
        |error '\n'
    sent-assign: 
        IDENTIFICADOR ASIG exp-bool PYC {
                $$ = new struct Nodo;
                $$->nombre = "sent-assign";
                Nodo *id = new struct Nodo;
                id->nombre = "id";
                id->valor = $1;
                Nodo *asig = new struct Nodo;
                asig->nombre = "asig";
                asig->valor = "=";
                Nodo *pyc = new struct Nodo;
                pyc->nombre = "pyc";
                pyc->valor = ";";
                $$->hijos.push_back(id);
                $$->hijos.push_back(asig);
                $$->hijos.push_back($3);
                $$->hijos.push_back(pyc);
                inicial = $$;
            }
    exp-bool:
        exp-bool OR comb  {
                $$ = new struct Nodo;
                $$->nombre = "exp-bool";
                Nodo *o = new struct Nodo;
                o->nombre = "or";
                o->valor = "or";
                $$->hijos.push_back($1);
                $$->hijos.push_back(o);
                $$->hijos.push_back($3);
                inicial = $$;
            }
        | comb {
                $$ = new struct Nodo;
                $$->nombre = "exp-bool";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        |error '\n'
    comb: 
        comb AND igualdad {
                $$ = new struct Nodo;
                $$->nombre = "comb";
                Nodo *an = new struct Nodo;
                an->nombre = "and";
                an->valor = "and";
                $$->hijos.push_back($1);
                $$->hijos.push_back(an);
                $$->hijos.push_back($3);
                inicial = $$;
            }
        | igualdad {
                $$ = new struct Nodo;
                $$->nombre = "comb";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        |error '\n'
    igualdad: 
        igualdad IGU rel {
                $$ = new struct Nodo;
                $$->nombre = "igualdad";
                Nodo *igu = new struct Nodo;
                igu->nombre = "igu";
                igu->valor = "==";
                $$->hijos.push_back($1);
                $$->hijos.push_back(igu);
                $$->hijos.push_back($3);
                inicial = $$;
            }
        | igualdad DIS rel {
                $$ = new struct Nodo;
                $$->nombre = "igualdad";
                Nodo *dis = new struct Nodo;
                dis->nombre = "dis";
                dis->valor = "!=";
                $$->hijos.push_back($1);
                $$->hijos.push_back(dis);
                $$->hijos.push_back($3);
                inicial = $$;
            }
        | rel {
                $$ = new struct Nodo;
                $$->nombre = "igualdad";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        |error '\n'
    rel: 
        expr op-rel expr {
                $$ = new struct Nodo;
                $$->nombre = "rel";
                $$->hijos.push_back($1);
                $$->hijos.push_back($2);
                $$->hijos.push_back($3);
                inicial = $$;
            }
        | expr {
                $$ = new struct Nodo;
                $$->nombre = "rel";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        |error '\n'
    op-rel: 
        MEN {
            $$ = new struct Nodo;
            $$->nombre = "men";
            $$->valor = $1;
            inicial = $$;
        }
        | MENIGL {
                $$ = new struct Nodo;
                $$->nombre = "menigl";
                $$->valor = $1;
                inicial = $$;
            }
        | MAY {
                $$ = new struct Nodo;
                $$->nombre = "may";
                $$->valor = $1;
                inicial = $$;
            }
        | MAYIGL {
                $$ = new struct Nodo;
                $$->nombre = "mayigl";
                $$->valor = $1;
                inicial = $$;
            }
        |error '\n'
    expr: 
        expr RES term {
                $$ = new struct Nodo;
                $$->nombre = "expr";
                Nodo *res = new struct Nodo;
                res->nombre = "res";
                res->valor = "-";
                $$->hijos.push_back($1);
                $$->hijos.push_back(res);
                $$->hijos.push_back($3);
                inicial = $$;
            }
        | expr MAS term {
                $$ = new struct Nodo;
                $$->nombre = "expr";
                Nodo *mas = new struct Nodo;
                mas->nombre = "mas";
                mas->valor = "+";
                $$->hijos.push_back($1);
                $$->hijos.push_back(mas);
                $$->hijos.push_back($3);
                inicial = $$;
            }
        | term {
                $$ = new struct Nodo;
                $$->nombre = "expr";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        |error '\n'
    term: 
        term MUL unario {
                $$ = new struct Nodo;
                $$->nombre = "term";
                Nodo *mul = new struct Nodo;
                mul->nombre = "mul";
                mul->valor = "*";
                $$->hijos.push_back($1);
                $$->hijos.push_back(mul);
                $$->hijos.push_back($3);
                inicial = $$;
            
            }
        | term DIV unario {
                $$ = new struct Nodo;
                $$->nombre = "term";
                Nodo *div = new struct Nodo;
                div->nombre = "div";
                div->valor = "/";
                $$->hijos.push_back($1);
                $$->hijos.push_back(div);
                $$->hijos.push_back($3);
                inicial = $$;
            }
        | unario {
                $$ = new struct Nodo;
                $$->nombre = "term";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        |error '\n'
    unario: 
        NOT unario {
                $$ = new struct Nodo;
                $$->nombre = "unario";
                Nodo *no = new struct Nodo;
                no->nombre = "not";
                no->valor = "not";
                $$->hijos.push_back(no);
                $$->hijos.push_back($2);
                inicial = $$;
            }
        | RES unario {
                $$ = new struct Nodo;
                $$->nombre = "unario";
                Nodo *res = new struct Nodo;
                res->nombre = "res";
                res->valor = "-";
                $$->hijos.push_back(res);
                $$->hijos.push_back($2);
                inicial = $$;
            }
        | factor {
                $$ = new struct Nodo;
                $$->nombre = "unario";
                $$->hijos.push_back($1);
                inicial = $$;
            }
        |error '\n'
    factor: 
        PI exp-bool PD {
            //!Revisar
                $$ = new struct Nodo;
                $$->nombre = "factor";
                Nodo *pi = new struct Nodo;
                pi->nombre = "pi";
                pi->valor = "(";
                Nodo *pd = new struct Nodo;
                pd->nombre = "pd";
                pd->valor = ")";
                $$->hijos.push_back(pi);
                $$->hijos.push_back($2);
                $$->hijos.push_back(pd);
                inicial = $$;
            }
        | IDENTIFICADOR {
                $$ = new struct Nodo;
                $$->nombre = "factor";
                $$->valor = $1;
                inicial = $$;
            }
        | NUMERO {
                $$ = new struct Nodo;
                $$->nombre = "factor";
                $$->valor = std::to_string($1);
                inicial = $$;
            }
        | TRUE {
                $$ = new struct Nodo;
                $$->nombre = "factor";
                $$->valor = $1;
                inicial = $$;
            }
        | FALSE {
                $$ = new struct Nodo;
                $$->nombre = "factor";
                $$->valor = $1;
                inicial = $$;
            }
%%



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