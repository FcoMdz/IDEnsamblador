/*Declaraciones*/

%{
    #include <stdio.h>
    #include <iostream>
    #include <vector>
    #include <string>
    std::string errorLine;
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
        std::string anotacion;
        std::string tipo;
        int noLinea;
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
%}

%locations

%token PROGRAM IF THEN ELSE FI DO UNTIL WHILE BREAK READ WRITE FLOAT INT BOOL NOT AND OR TRUE FALSE MAS RES MUL DIV ELE MEN MENIGL MAY MAYIGL IGU DIS ASIG PYC COM PI PD LI LD CADENA NUMEROFLOAT NUMEROINT IDENTIFICADOR OTRO SPACE SALTOLINEA

%union{
    float numerofloat;
    int numeroint;
    char* cadena;
    struct Nodo* nodo;
}

%type <cadena> CADENA
%type <cadena> SALTOLINEA
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
%type <numerofloat> NUMEROFLOAT
%type <numeroint> NUMEROINT
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
        PROGRAM LI list-decl list-sent LD{
            std::cout << "program\n";
            $$ = new struct Nodo;
            $$->nombre = "program";
            $$->hijos.push_back($3);
            $$->hijos.push_back($4);
            $$->noLinea = yylineno;
            inicial = $$;
        }
    list-decl:
        {
            $$ = NULL;
        }
        | list-decl decl {
            std::cout << "list-decl decl\n";
            $$ = new struct Nodo;
            $$->nombre = "list-decl";
            $$->hijos.push_back($1);
            $$->hijos.push_back($2);
            $$->noLinea = yylineno;
            inicial = $$;
        }
    decl: 
        tipo list-id PYC{
            std::cout << "tipo list-id;\n";
            $$ = new struct Nodo;
            $$->nombre = "decl";
            $$->hijos.push_back($1);
            $$->hijos.push_back($2);
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | tipo error{
            std::cout << "Error decl - tipo error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "declaracion - tipo error, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
    tipo: 
        INT {
            std::cout << "int\n";
                $$ = new struct Nodo;
                $$->nombre = "tipo";
                $$->valor = $1;
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | FLOAT {
            std::cout << "float\n";
                $$ = new struct Nodo;
                $$->nombre = "tipo";
                $$->valor = $1;
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | BOOL {
            std::cout << "bool\n";
                $$ = new struct Nodo;
                $$->nombre = "tipo";
                $$->valor = $1;
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | error {
                std::cout << "Error tipo\n";
                $$ = new struct Nodo;
                $$->nombre = "Error sintactico";
                $$->valor = "falta tipo, linea: " + errorLine;
                $$->noLinea = yylineno;
                inicial = $$;
                yyerrok;
        }
    list-id: 
        list-id COM IDENTIFICADOR  {
                std::cout << "list-id, id: " << $3 << "\n";
                $$ = new struct Nodo;
                $$->nombre = "list-id";
                $$->valor = $3;
                $$->hijos.push_back($1);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | IDENTIFICADOR {
            std::cout << "id: " << $1 << "\n";
            $$ = new struct Nodo;
            $$->nombre = "identificador";
            $$->valor = $1;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | COM error{
            std::cout << "Error id\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "falta id, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | error{
            std::cout << "Error id\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "falta id, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        
    list-sent: 
        {
            $$ = NULL;
        }
        | list-sent sent {
            std::cout << "list-sent sent\n";
            $$ = new struct Nodo;
            $$->nombre = "list-sent";
            $$->hijos.push_back($1);
            $$->hijos.push_back($2);
            $$->noLinea = yylineno;
            inicial = $$;
        }
    sent: 
        sent-if {
            std::cout << "sent-if\n";
                $$ = $1;
                inicial = $$;
                
            }
        | sent-while {
            std::cout << "sent-while\n";
                $$ = $1;
                inicial = $$;
            }
        | sent-do {
            std::cout << "sent-do\n";
                $$ = $1;
                inicial = $$;
            }
        | sent-read {
            std::cout << "sent-read \n";
                $$ = $1;
                inicial = $$;
            }
        | sent-write {
            std::cout << "sent-write\n";
                $$ = $1;
                inicial = $$;
            }
        | sent-assign {
            std::cout << "sent-assign\n";
                $$ = $1;
                inicial = $$;
            }
        | BREAK {
            std::cout << "break\n";
                $$ = new struct Nodo;
                $$->nombre = "break";
                inicial = $$;
            }
        /*| error{
            std::cout << "Error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "La sentencia no coincide con ninguna otra, revise la gramatica";
            inicial = $$;
        }*/
    sent-if: 
        IF PI exp-bool PD THEN bloque FI {
            std::cout << "if\n";
            $$ = new struct Nodo;
            $$->nombre = "sent-if";
            $$->hijos.push_back($3);
            $$->hijos.push_back($6);
            $$->noLinea = yylineno;
            inicial = $$;
            }      
        | IF PI exp-bool PD THEN bloque ELSE bloque FI {
            std::cout << "if-else\n";
            $$ = new struct Nodo;
            $$->nombre = "sent-if-else";
            $$->hijos.push_back($3);
            $$->hijos.push_back($6);
            $$->hijos.push_back($8);
            $$->noLinea = yylineno;
            inicial = $$;
            }
        | IF error{
            std::cout << "Error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta condicion entre parentesis, then y el bloque y finalizacion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PI exp-bool PD error{
            std::cout << "Error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta then, el bloque y finalizacion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF error THEN error{
            std::cout << "Error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta condicion, el bloque y finalizacion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PI exp-bool PD THEN error{
            std::cout << "Error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta bloque y finalizacion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF error FI{
            std::cout << "Error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta condicion y bloque, linea: " + errorLine;
            inicial = $$;
        }
        | IF PI exp-bool PD THEN bloque ELSE error{
            std::cout << "Error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if-else falta bloque y finalizacion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        } 
        | IF error ELSE error{
            std::cout << "Error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if-else falta bloque if, bloque else y finalizacion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF error ELSE bloque error{
            std::cout << "Error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if-else falta bloque if, finalizacion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        } 
        | IF PI exp-bool PD THEN bloque ELSE bloque error{
            std::cout << "Error\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if-else falta finalizacion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        } 
        | IF PI exp-bool PD error bloque ELSE bloque FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta THEN, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PI exp-bool PD THEN error ELSE bloque FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta bloque siguiente, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PI exp-bool PD THEN bloque error bloque FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta sentencia else, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PI exp-bool PD THEN bloque ELSE error FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta bloque después de else, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF error PD THEN bloque ELSE bloque FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta paréntesis de inicio y expresión boleana, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PI exp-bool PD THEN error bloque FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta paréntesis de termino y THEN, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF error THEN bloque ELSE bloque FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta paréntesis de inicio, termino y expresión, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PI exp-bool PD error bloque FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta THEN, ELSE y bloque, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PI error bloque ELSE bloque FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta expresión boleana, THEN, ELSE y bloque, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PI exp-bool PD THEN error FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta bloque, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF error ELSE bloque FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta bloque, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PI error FI {
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta Exoresión, Parentesis derecho, THEN, bloque, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }  
        | IF PD exp-bool PI error{
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta THEN, bloque, FI, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PD exp-bool PI THEN error{
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta bloque, FI, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PD exp-bool PI THEN bloque error{
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta FI, linea: " + errorLine;
            
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PD exp-bool PI THEN bloque ELSE error{
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta bloque, FI, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PD exp-bool PI THEN bloque ELSE bloque error{
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta FI, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PD exp-bool PI error bloque ELSE bloque error{
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta, THEN, FI, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PD exp-bool PI THEN bloque error bloque error{
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta, ELSE, FI, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IF PD exp-bool PI error bloque error bloque error{
            std::cout << "Error if\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "if falta, THEN, ELSE, FI, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
    sent-while: 
        WHILE PI exp-bool PD bloque {
            std::cout << "while\n";
            $$ = new struct Nodo;
            $$->nombre = "sent-while";
            $$->hijos.push_back($3);
            $$->hijos.push_back($5);
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | WHILE error{
            std::cout << "Error while\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "while falta condicion entre parentesis y cuerpo, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | WHILE error bloque{
            std::cout << "Error while\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "while falta expresion entre parentesis, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | WHILE PI exp-bool PD error{
            std::cout << "Error while\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "while falta bloque, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        
    sent-do:
        DO bloque UNTIL PI exp-bool PD PYC {
            std::cout << "do\n";
                $$ = new struct Nodo;
                $$->nombre = "sent-do";
                $$->hijos.push_back($2);
                $$->hijos.push_back($5);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | DO error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta cuerpo, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO bloque error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta until, condicion y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO UNTIL error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta bloque, condicion y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO PI exp-bool PD error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO PYC{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta bloque, until y condicion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO bloque UNTIL error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta condicion y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO bloque PI exp-bool PD error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta condicion y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO bloque PYC error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta condicion y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO UNTIL bloque error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do desorganizado, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO UNTIL PI exp-bool PD error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do desorganizado, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO UNTIL PYC{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do desorganizado, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO PI exp-bool PD bloque error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO PI exp-bool PD UNTIL error{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            inicial = $$;
        }
        | DO PI exp-bool PD PYC{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO PYC bloque{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO PYC UNTIL{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | DO PYC PI exp-bool PD{
            std::cout << "Error do\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "do falta bloque, until y punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        

    sent-read: 
        READ IDENTIFICADOR PYC {
            std::cout << "read\n";
            $$ = new struct Nodo;
            $$->nombre = "read";
            std::string variable = "";
            std::string valor = std::string($2);
            for(int i=0; i<valor.length()-1; i++){
                variable+=valor[i];
            }
            $$->valor = variable;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | READ error{
            std::cout << "Error read\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "read sentencia incompleta, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | READ IDENTIFICADOR error{
            std::cout << "Error read\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "falta punto y coma en read, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | READ error PYC{
            std::cout << "Error read\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "falta el id para leer, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        
    sent-write: 
        WRITE exp-bool PYC {
            std::cout << "write\n";
                $$ = new struct Nodo;
                $$->nombre = "write";
                $$->hijos.push_back($2);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | WRITE error{
            std::cout << "Error write\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "write sentencia incompleta, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        
    bloque: 
        LI list-sent LD {
            std::cout << "bloque\n";
                $$ = new struct Nodo;
                $$->nombre = "bloque";
                $$->hijos.push_back($2);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        
    sent-assign: 
        IDENTIFICADOR ASIG exp-bool PYC {
            std::cout << "id=exp-bool;\n";
                $$ = new struct Nodo;
                $$->nombre = "sent-assign";
                $$->noLinea = yylineno;
                Nodo *id = new struct Nodo;
                id->nombre = "identificador";
                std::string variable = std::string($1).substr(0,std::string($1).find("="));
                std::string trimed = "";
                for(int i=0; i<variable.length(); i++){
                    if(variable[i] != ' ' && variable[i] != '\t'){
                        trimed += variable[i];
                    }
                }
                id->valor = trimed;
                id->noLinea = yylineno;
                $$->hijos.push_back(id);
                $$->hijos.push_back($3);
                inicial = $$;
            }
        
        | IDENTIFICADOR error{
            std::cout << "Error assign\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "falta la sentencia de asignacion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IDENTIFICADOR ASIG error{
            std::cout << "Error assign\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "falta la expresion de asignación y un punto y coma, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | IDENTIFICADOR error PYC{
            std::cout << "Error assign\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "falta la asignacion y la expresion, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        
    exp-bool:
        exp-bool OR comb  {
            std::cout << "or\n";
                $$ = new struct Nodo;
                $$->nombre = "or";
                $$->hijos.push_back($1);
                $$->hijos.push_back($3);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | comb {
            std::cout << "comb\n";
                $$ = $1;
                inicial = $$;
            }
        
    comb: 
        comb AND igualdad {
            std::cout << "and\n";
                $$ = new struct Nodo;
                $$->nombre = "and";
                $$->hijos.push_back($1);
                $$->hijos.push_back($3);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | igualdad {
            std::cout << "igualdad\n";
                $$ = $1;
                inicial = $$;
            }
        
    igualdad: 
        igualdad IGU rel {
            std::cout << "igu\n";
                $$ = new struct Nodo;
                $$->nombre = "igualdad";
                $$->hijos.push_back($1);
                $$->hijos.push_back($3);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | igualdad DIS rel {
            std::cout << "dis\n";
                $$ = new struct Nodo;
                $$->nombre = "distinto";
                $$->hijos.push_back($1);
                $$->hijos.push_back($3);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | rel {
            std::cout << "rel\n";
                $$ = $1;
                inicial = $$;
            }
        
    rel: 
        expr op-rel expr {
            std::cout << "expr op-rel expr\n";
                $$ = new struct Nodo;
                $$->nombre = "op-rel";
                $$->hijos.push_back($1);
                $$->hijos.push_back($2);
                $$->hijos.push_back($3);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | expr {
            std::cout << "expr\n";
                $$ = $1;
                inicial = $$;
            }
    op-rel: 
        MEN {
            std::cout << "men\n";
            $$ = new struct Nodo;
            $$->nombre = "men";
            $$->valor = $1;
            $$->noLinea = yylineno;
            inicial = $$;
        }
        | MENIGL {
            std::cout << "menigl\n";
                $$ = new struct Nodo;
                $$->nombre = "menigl";
                $$->valor = $1;
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | MAY {
            std::cout << "may\n";
                $$ = new struct Nodo;
                $$->nombre = "may";
                $$->valor = $1;
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | MAYIGL {
            std::cout << "mayigl\n";
                $$ = new struct Nodo;
                $$->nombre = "mayigl";
                $$->valor = $1;
                $$->noLinea = yylineno;
                inicial = $$;
            }
        |error{
            std::cout << "Error op-rel\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "falta op-rel, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
    expr: 
        expr RES term {
            std::cout << "res\n";
                $$ = new struct Nodo;
                $$->nombre = "resta";
                $$->hijos.push_back($1);
                $$->hijos.push_back($3);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | expr MAS term {
            std::cout << "mas\n";
                $$ = new struct Nodo;
                $$->nombre = "suma";
                $$->hijos.push_back($1);
                $$->hijos.push_back($3);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | term {
            std::cout << "term\n";
                $$ = $1;
                inicial = $$;
            }
        
    term: 
        term MUL unario {
            std::cout << "mul\n";
                $$ = new struct Nodo;
                $$->nombre = "multiplicacion";
                $$->hijos.push_back($1);
                $$->hijos.push_back($3);
                $$->noLinea = yylineno;
                inicial = $$;
            
            }
        | term DIV unario {
            std::cout << "div\n";
                $$ = new struct Nodo;
                $$->nombre = "division";
                $$->hijos.push_back($1);
                $$->hijos.push_back($3);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | unario {
            std::cout << "Unario\n";
                $$ = $1;
                inicial = $$;
            }
    unario: 
        NOT unario {
            std::cout << "Not unario\n";
                $$ = new struct Nodo;
                $$->nombre = "negacion";
                $$->hijos.push_back($2);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | RES unario {
            std::cout << "RES unario\n";
                $$ = new struct Nodo;
                $$->nombre = "menos";
                $$->hijos.push_back($2);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | factor {
            std::cout << "Factor\n";
                $$ = $1;
                inicial = $$;
            }        
    factor: 
        PI exp-bool PD {
            //!Revisar
                std::cout << "(exp-bool)\n";
                $$ = new struct Nodo;
                $$->nombre = "(exp-bool)";
                $$->hijos.push_back($2);
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | IDENTIFICADOR {
                std::cout << "id: "<< $1 << "\n";
                $$ = new struct Nodo;
                $$->nombre = "identificador";
                $$->valor = $1;
                $$->noLinea = yylineno;
                inicial = $$;
            }
        | NUMEROFLOAT {
                std::cout << "Numero float: " << $1 <<  "\n";
                $$ = new struct Nodo;
                $$->nombre = "numerofloat";
                $$->valor = std::to_string($1);
                $$->noLinea = yylineno;
                $$->tipo="float";
                inicial = $$;
            }
        | NUMEROINT {
                std::cout << "Numero int: " << $1 <<  "\n";
                $$ = new struct Nodo;
                $$->nombre = "numeroint";
                $$->valor = std::to_string($1);
                $$->noLinea = yylineno;
                $$->tipo="int";
                inicial = $$;
            }
        | TRUE {
                std::cout << "True\n";
                $$ = new struct Nodo;
                $$->nombre = "booleano";
                $$->valor = $1;
                $$->noLinea = yylineno;
                $$->tipo="bool";
                inicial = $$;
            }
        | FALSE {
                std::cout << "False\n";
                $$ = new struct Nodo;
                $$->nombre = "booleano";
                $$->valor = $1;
                $$->noLinea = yylineno;
                $$->tipo="bool";
                inicial = $$;
            }
        |error{
            std::cout << "Error factor\n";
            $$ = new struct Nodo;
            $$->nombre = "Error sintactico";
            $$->valor = "falta factor, linea: " + errorLine;
            $$->noLinea = yylineno;
            inicial = $$;
        }
%%



void printNode(Nodo *init, int tabuladores){
    if(init != NULL){
        for(int i=0; i<tabuladores; i++){
            std::cout<<"  |";
        } 
        std::cout << init->nombre << ": " << init->valor << ", " << init->noLinea << "\n";
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
    yylineno = 1;
    return inicial;
}

int yyerror(std::string s){
    std::cout << "error: " << s << " in line " << yylineno << "\n";
    errorLine = std::to_string(yylineno);
    /*std::cout << "Error sin definir\n";
    Nodo *error = new struct Nodo;
    error->nombre = "Error";
    error->valor = s;
    inicial->hijos.push_back(error);*/
    //std::cout << "Error en la línea " << @$.first_line << ", columna: " << @$.first_column;
    return -1;
}

/*int main(int argc, char **argv){
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        Nodo *error = new struct Nodo;
        error->nombre = "Error";
        error->valor = "No se pudo abrir el archivo";
        inicial = error;
    }
    yyin = file;
    yyparse();
    std::cout << "\n---Arbol---\n\n";
    printNode(inicial,0);
    return 0;
}*/