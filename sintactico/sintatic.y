/*Declaraciones*/
%{
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
    void printNode(Nodo *init, int tabuladores);

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
            recorrer = recorrer->hijos.at(0);
        }
        if(recorrer->nombre.compare(termino) == 0){
            //Le quita el siguiente list-decl como hijo
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

    void checkDiv(Nodo *init, Nodo *siguiente, std::string termino){
        if (init == NULL || siguiente == NULL) {
            return;
        }
        Nodo *recorrer = init;
        while(recorrer->hijos.size() != 0 && recorrer->nombre.compare(termino) != 0){
            recorrer = recorrer->hijos.at(0);
        }
        if(recorrer->nombre.compare(termino) == 0){
            //Le quita el siguiente list-decl como hijo 
            if(recorrer->hijos.at(0)->hijos.size() > 0){
                Nodo *expresion = recorrer->hijos.at(0)->hijos.at(0);
                recorrer->hijos.at(0)->hijos.erase(recorrer->hijos.at(0)->hijos.begin()); 
                //Hace que el padre del tipo sea la delcaración
                expresion->padre = siguiente;
                //Inserta los hijos en orden
                siguiente->hijos.push_back(expresion);
            }
        }
        return;
    }

     void checkWhile(Nodo *init, Nodo *siguiente, std::string termino){
        if (init == NULL || siguiente == NULL) {
            return;
        }
        Nodo *recorrer = init;
        while(recorrer->hijos.size() != 0 && recorrer->nombre.compare(termino) != 0){
            recorrer = recorrer->hijos.at(0);
        }
        if(recorrer->nombre.compare(termino) == 0){
            //Le quita el siguiente list-decl como hijo
            Nodo *expresion = recorrer;
            recorrer->padre->hijos.erase(recorrer->padre->hijos.begin()); 
            //Hace que el padre del tipo sea la delcaración
            expresion->padre = siguiente;
            //Inserta los hijos en orden
            siguiente->hijos.push_back(expresion);
        }
        return;
    }


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
        PROGRAM LI list-decl list-sent LD {
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
            printf("program\n");
        }
    list-decl:
        | list-decl decl {
            Nodo *siguiente = new struct Nodo;
            siguiente->nombre = "list-decl";
            siguiente->valor = "";
            siguiente->padre = NULL;
            //Busca el nodo del tipo
            check(inicial, siguiente, "list-decl");
            siguiente->hijos.push_back(inicial);
            inicial = siguiente;
        }
    decl: 
        tipo list-id PYC {
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
    tipo: 
        INT {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "int";
                    inicial->valor = $1;
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "int";
                    siguiente->valor = $1;
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
            }
        | FLOAT {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "float";
                    inicial->valor = $1;
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "float";
                    siguiente->valor = $1;
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
            }
        | BOOL {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "bool";
                    inicial->valor = $1;
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "bool";
                    siguiente->valor = $1;
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
            }
    list-id: 
        list-id COM IDENTIFICADOR  {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "list-id, id";
                siguiente->valor = $3;
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
            }
        | IDENTIFICADOR {
            if(inicial == NULL){
                inicial = new struct Nodo;
                inicial->nombre = "id";
                inicial->valor = $1;
                inicial->padre = NULL;
            }else{
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "id";
                siguiente->valor = $1;
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
            }
        }
    list-sent: 
        | list-sent sent {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "list-sent sent";
                siguiente->valor = "";
                siguiente->padre = NULL;
                check(inicial, siguiente, "list-sent sent");
                
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("list-sent sent\n");
            
            }
    sent: 
        sent-if {printf("sent-if\n");}
        | sent-while {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "sent";
                siguiente->valor = "sent-while";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("sent-while\n");
            }
        | sent-do {printf("sent-do\n");}
        | sent-read {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "sent";
                siguiente->valor = "sent-read";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("sent-read\n");
            }
        | sent-write {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "sent";
                siguiente->valor = "sent-write";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("sent-write\n");
            }
        | sent-assign {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "sent";
                siguiente->valor = "sent-assign";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("sent-assign\n");
            }
        | BREAK {printf("break\n");}
    sent-if: 
        IF PI exp-bool PD THEN bloque FI {printf("if\n");}
        | IF PI exp-bool PD THEN bloque ELSE bloque FI {printf("if-else\n");}
    sent-while: 
        WHILE PI exp-bool PD bloque {
            Nodo *siguiente = new struct Nodo;
            siguiente->nombre = "while";
            siguiente->valor = "";
            siguiente->padre = NULL;
            inicial->padre = siguiente;
            printf("\n--Pre operacion--\n");
            printNode(inicial, 0);
            checkDiv(inicial, siguiente, "factor");
            checkWhile(inicial, siguiente, "comb");
            Nodo *exp_bool = new struct Nodo;
            exp_bool->nombre = "exp-bool";
            exp_bool->valor= "";
            exp_bool->padre=siguiente;
            if(siguiente->hijos.size()>1){
               if(siguiente->hijos.at(0)->nombre == "comb" && siguiente->hijos.at(1)->nombre != "comb"){
                    std::cout << "Hijo en 0 es comb\n";
                    exp_bool->hijos.push_back(siguiente->hijos.at(0));
                    siguiente->hijos.erase(siguiente->hijos.begin());
                }else if(siguiente->hijos.at(0)->nombre != "comb" && siguiente->hijos.at(1)->nombre == "comb"){
                    exp_bool->hijos.push_back(siguiente->hijos.at(1));
                    siguiente->hijos.erase(siguiente->hijos.begin()+1);
                }else if(siguiente->hijos.at(0)->nombre == "comb" && siguiente->hijos.at(1)->nombre == "comb"){
                    exp_bool->hijos.push_back(siguiente->hijos.at(1));
                    siguiente->hijos.erase(siguiente->hijos.begin()+1);
                }
            }else{
                if(siguiente->hijos.at(0)->nombre == "comb"){
                    exp_bool->hijos.push_back(siguiente->hijos.at(0));
                    siguiente->hijos.erase(siguiente->hijos.begin());
                }
            }
            siguiente->hijos.push_back(exp_bool);
            //Crea su estructura
            Nodo *pi = new struct Nodo;
            pi->nombre = "pi";
            pi->valor= "(";
            pi->padre=inicial;
            siguiente->hijos.push_back(pi);
            //Crea el id como hijo
            Nodo *pd = new struct Nodo;
            pd->nombre = "pd";
            pd->valor = ")";
            pd->padre = inicial;
            siguiente->hijos.push_back(pd);
            siguiente->hijos.push_back(inicial);
            inicial = siguiente;
            printf("\n--Tras operacion--\n");
            printNode(inicial, 0);
            printf("while\n");
        }
    sent-do:
        DO bloque UNTIL PI exp-bool PD PYC {printf("do\n");}
    sent-read: 
        READ IDENTIFICADOR PYC {
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
                id->valor = $2;
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
                id->valor = $2;
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
            printf("read\n");
        }
    sent-write: 
        WRITE exp-bool PYC {
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
        
    bloque: 
        LI list-sent LD {
                if(inicial == NULL){
                    inicial = new struct Nodo;  
                    inicial->nombre = "bloque";
                    inicial->valor = "";
                    inicial->padre = NULL;
                    Nodo *li = new struct Nodo;
                    li->nombre = "li";
                    li->valor= "{";
                    li->padre=inicial;
                    inicial->hijos.push_back(li);
                    //Assign
                    Nodo *ld = new struct Nodo;
                    ld->nombre = "ld";
                    ld->valor= "}";
                    ld->padre=inicial;
                    inicial->hijos.push_back(ld);
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "bloque";
                    siguiente->valor = "";
                    siguiente->padre = NULL;
                    inicial->padre = siguiente;
                    //Buscar el nodo!!
                    siguiente->hijos.push_back(inicial);
                    //Crea su estructura
                    Nodo *li = new struct Nodo;
                    li->nombre = "li";
                    li->valor= "{";
                    li->padre=siguiente;
                    siguiente->hijos.push_back(li);
                    //Assign
                    Nodo *ld = new struct Nodo;
                    ld->nombre = "ld";
                    ld->valor= "}";
                    ld->padre=siguiente;
                    siguiente->hijos.push_back(ld);
                    inicial = siguiente;
                    
                }
                printf("bloque\n");
            }
    sent-assign: 
        IDENTIFICADOR ASIG exp-bool PYC {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "sent-assign";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                Nodo *exp_bool = new struct Nodo;
                exp_bool->nombre = "exp-bool";
                exp_bool->valor= "";
                exp_bool->padre=siguiente;
                exp_bool->hijos.push_back(inicial);
                siguiente->hijos.push_back(exp_bool);
                //Crea su estructura
                Nodo *wirte = new struct Nodo;
                wirte->nombre = "id";
                wirte->valor= $1;
                wirte->padre=siguiente;
                siguiente->hijos.push_back(wirte);
                //Assign
                Nodo *asign = new struct Nodo;
                asign->nombre = "asign";
                asign->valor= "=";
                asign->padre=siguiente;
                siguiente->hijos.push_back(asign);
                //Crea el punto y coma como hijo
                Nodo *pyc = new struct Nodo;
                pyc->nombre = "pyc";
                pyc->valor = ";";
                pyc->padre = siguiente;
                siguiente->hijos.push_back(pyc);
                inicial = siguiente;
                printf("asignacion\n");
            }
    exp-bool:
        exp-bool OR comb  {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "exp-bool OR comb";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                checkDiv(inicial, siguiente, "factor");
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
        | comb {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "comb";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("comb\n");
            }
    comb: 
        comb AND igualdad {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "comb AND igualdad";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                checkDiv(inicial, siguiente, "factor");
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
        | igualdad {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "igualdad";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("igualdad\n");
            }
    igualdad: 
        igualdad IGU rel {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "igualdad IGU rel";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                 //Buscar el nodo!!
                checkDiv(inicial, siguiente, "factor");
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
        | igualdad DIS rel {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "igualdad DIS rel";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                checkDiv(inicial, siguiente, "factor");
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
        | rel {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "rel";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("rel\n");
            }
    rel: 
        expr op-rel expr {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "expr op-rel expr";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                checkDiv(inicial, siguiente, "factor");
                if(siguiente->hijos.size() > 0){
                    std::cout << "operacion sig factor: " << siguiente->hijos.at(0)->nombre << "\n";
                    Nodo *oprel = siguiente->hijos.at(0);
                    siguiente->hijos.at(0) = siguiente->hijos.at(0)->hijos.at(0)->hijos.at(0);
                    oprel->hijos.at(0)->hijos.erase(oprel->hijos.at(0)->hijos.begin());
                    siguiente->hijos.push_back(oprel);
                }
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("operacion\n");
            }
        | expr {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "expr";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("expresion\n");
            }
    op-rel: 
        MEN {
            Nodo *siguiente = new struct Nodo;
            siguiente->nombre = "MEN";
            siguiente->valor = $1;
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
            printf("op-rel\n");
        }
        | MENIGL {
                
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "MENIGL";
                siguiente->valor = $1;
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
                printf("op-rel\n");
            }
        | MAY {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "MAY";
                siguiente->valor = $1;
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
                printf("op-rel\n");
            }
        | MAYIGL {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "MAYIGL";
                siguiente->valor = $1;
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
                printf("op-rel\n");
            }
    expr: 
        expr RES term {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "expr RES term";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                //check(inicial, siguiente, "expr");
                checkDiv(inicial, siguiente, "factor");
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
        | expr MAS term {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "expr MAS term";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                //check(inicial, siguiente, "expr");
                checkDiv(inicial, siguiente, "factor");
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
        | term {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "term";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("term\n");
            }
    term: 
        term MUL unario {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "term MUL unario";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                checkDiv(inicial, siguiente, "factor");
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
        | term DIV unario {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "term DIV unario";
                siguiente->valor = "";
                siguiente->padre = NULL;
                inicial->padre = siguiente;
                //Buscar el nodo!!
                checkDiv(inicial, siguiente, "factor");
                Nodo *div = new struct Nodo;
                div->nombre = "DIV";
                div->valor= "/";
                div->padre=siguiente;
                siguiente->hijos.push_back(div);
                siguiente->hijos.push_back(inicial);
                inicial = siguiente;
                printf("division\n");
            }
        | unario {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "unario";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("unario\n");
            }
    unario: 
        NOT unario {
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
                printf("not unario\n");
            }
        | RES unario {
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
                printf("res unario\n");
            }
        | factor {
                Nodo *siguiente = new struct Nodo;
                siguiente->nombre = "factor";
                siguiente->valor = "";
                siguiente->padre = NULL;
                siguiente->hijos.push_back(inicial);
                inicial->padre = siguiente;
                inicial = siguiente;
                printf("factor\n");
            }
    factor: 
        PI exp-bool PD {
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
        | IDENTIFICADOR {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "id";
                    inicial->valor = $1;
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "id";
                    siguiente->valor = $1;
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
                printf("id: %s\n",$1);
            }
        | NUMERO {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "numero";
                    inicial->valor = $1;
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "numero";
                    siguiente->valor = std::to_string($1);
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
                std::cout << "numero: " << std::to_string($1) << "\n";
            }
        | TRUE {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "true";
                    inicial->valor = $1;
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "true";
                    siguiente->valor = $1;
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
                printf("true\n");
            }
        | FALSE {
                if(inicial == NULL){
                    inicial = new struct Nodo;
                    inicial->nombre = "false";
                    inicial->valor = $1;
                    inicial->padre = NULL;
                }else{
                    Nodo *siguiente = new struct Nodo;
                    siguiente->nombre = "false";
                    siguiente->valor = $1;
                    siguiente->padre = NULL;
                    siguiente->hijos.push_back(inicial);
                    inicial->padre = siguiente;
                    inicial = siguiente;
                }
                printf("false\n");
            }
%%

int yyerror(char *s){
    printf("->Error sintáctico: %s\n", s);
}


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

int main(int argc, char **argv){
    yyparse();
    std::cout << "\n\n---Arbol---\n\n";
    printNode(inicial,0);
    return 0;
}