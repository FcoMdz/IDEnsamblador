/*Variables*/
%{
    #include <iostream>
    #include <vector>
    int countLines = 1;
    int countColumn = 1;
    const char *input_text;
    int text_index = 0;


    struct Lexico{
        std::string clave;
        std::string lexema;
        int fila;
        int columna;
    };
    int yylex(void);
    void yyrestart(FILE *);
    std::vector<Lexico> lexVec;

   int yyinput(char *buf, int max_size) {
        int num_to_copy = std::min(max_size - 1, (int)strlen(input_text + text_index));
        strncpy(buf, input_text + text_index, num_to_copy);
        text_index += num_to_copy;
        return num_to_copy;
    }

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

    std::vector<Lexico> analyzeText(const char *text) {
        countColumn = 1;
        countLines = 1;
        lexVec.clear();  // Limpia cualquier resultado anterior
        input_text = text;
        text_index = 0;
        yy_scan_string(input_text);
        yylex();
        return lexVec;
    }

    void showError(){

    }
%}

/*Especificaciones regex*/
LETRA [a-z|A-Z]
DIGITO [0-9]
RESERVADAS "program"|"if"|"else"|"fi"|"do"|"until"|"while"|"read"|"write"|"float"|"int"|"bool"|"not"|"and"|"or"|"true"|"false"|"char"
SIMBOLO \+|\-|\*|\/|\^|<|<=|>|>=|==|!=|=|;|,|\(|\)|\{|\}
IDENTIFICADOR {LETRA}({LETRA}|{DIGITO})*
CADENA ["][^"]*["]
COMENTARIO_LINEA \/\/.*
COMENTARIO_MULTI \/\*(.|\n)*\*\/
SPACE [ ]
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
{COMENTARIO_LINEA}|{COMENTARIO_MULTI} {
    lexVec.push_back(Lexico());
    lexVec[lexVec.size()-1].clave = "Comentario";
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
{SPACE} {
    lexVec.push_back(Lexico());
    lexVec[lexVec.size()-1].clave = "Espacio";
    lexVec[lexVec.size()-1].lexema = yytext;
    lexVec[lexVec.size()-1].columna = countColumn;
    lexVec[lexVec.size()-1].fila = countLines;
    countColumn += strlen(yytext);
}
[^\s] {
    /*if(yytext != " "){
        lexVec[lexVec.size()-1].clave = "Error";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
    }*/
    countColumn++;
}
"-stop" {return 0;}
%%

/*Sección de codigo*/

int yywrap(){
    return 1;
} //Parsea el codigo anterior



int main(int argc, char **argv){
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
}