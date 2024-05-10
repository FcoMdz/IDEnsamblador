/*Variables*/
%{
    #include <iostream>
    #include <vector>
    int countLines = 1;
    int countColumn = 1;
    struct Lexico{
        std::string clave;
        std::string lexema;
        int fila;
        int columna;
    };
    int yylex(void);
    void yyrestart(FILE *);
    std::vector<Lexico> lexVec;
    std::vector<Lexico> analyzeFile(const char *filename) {
        FILE *file = fopen(filename, "r");
        if (!file) {
            std::cerr << "No se pudo abrir el archivo: " << filename << std::endl;
            return std::vector<Lexico>();  // Devuelve vector vacío si el archivo no se puede abrir
        }
        countColumn = 1;
        countLines = 1;
        lexVec.clear();  // Limpia cualquier resultado anterior
        yyrestart(file); 
        yylex();
        fclose(file);
        return lexVec;
    }
%}

/*Especificaciones regex*/
LETRA [a-z|A-Z]
DIGITO [0-9]
RESERVADAS "program"|"if"|"else"|"fi"|"do"|"until"|"while"|"read"|"write"|"float"|"int"|"bool"|"not"|"and"|"or"|"true"|"false"
SIMBOLO \+|\-|\*|\/|\^|<|<=|>|>=|==|!=|=|;|,|\(|\)|\{|\}
IDENTIFICADOR {LETRA}({LETRA}|{DIGITO})*
CADENA ["]*["]
NUMERO {DIGITO}{DIGITO}*(.{DIGITO}{DIGITO}*)?

/*Reglas de detección*/
%%

"\n" {countLines++; countColumn=1;}
{RESERVADAS} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].clave = "Reservada";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{SIMBOLO} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].clave = "Simbolo";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{CADENA} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].clave = "Cadena";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{NUMERO} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].clave = "Numero";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{IDENTIFICADOR} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].clave = "Identificador";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
. {
    countColumn++;
}
"-stop" {return 0;}
%%

/*Sección de codigo*/

int yywrap(){
    return 1;
} //Parsea el codigo anterior

/*int main(int argc, char **argv){
    if(argc < 2){
        printf("Ingrese el texto a evaluar:\n");
        yyin=stdin;
    }else{
        yyin=fopen(argv[1],"r");
    }
    yylex(); //Función principal de lex
    for(int i=0; i<lexVec.size(); i++){
        std::cout << lexVec[i].clave << "\t" << lexVec[i].lexema << "\t" << lexVec[i].fila << "\t" << lexVec[i].columna << "\n";
    }
    return 0;
}*/