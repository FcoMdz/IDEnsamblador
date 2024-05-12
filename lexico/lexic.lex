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
        std::string estilo;
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
SPACE [ ]|[\t]|[\r]
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
%%

"\n" {countLines++; countColumn=1;}
{SPACE} {
    countColumn++;
}
{PROGRAM} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "PROGRAM";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{IF} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "IF";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{THEN} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "THEN";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{ELSE} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "ELSE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{FI} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "FI";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{DO} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "DO";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{UNTIL} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "UNTIL";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{WHILE} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "WHILE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{BREAK} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "BREAK";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{READ} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "READ";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{WRITE} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "WRITE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{FLOAT} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "FLOAT";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{INT} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "INT";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{BOOL} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "BOOL";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{NOT} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "NOT";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{AND} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "AND";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{OR} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "OR";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{TRUE} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "TRUE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{FALSE} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "FALSE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{MAS} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MAS";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{RES} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "RES";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{MUL} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MUL";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{DIV} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "DIV";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{ELE} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "ELE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{MEN} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MEN";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{MENIGL} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MENIGL";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{MAY} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MAY";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{MAYIGL} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MAYIGL";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{IGU} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "IGU";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{DIS} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "DIS";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{ASIG} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "ASIG";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{PYC} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Otro";
        lexVec[lexVec.size()-1].clave = "PYC";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{COM} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Otro";
        lexVec[lexVec.size()-1].clave = "COM";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{PI} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "PI";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{PD} {
       lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "PD";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{LI} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "LI";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{LD} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "LD";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{CADENA} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Cadena";
        lexVec[lexVec.size()-1].clave = "CADENA";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{COMENTARIO_LINEA}|{COMENTARIO_MULTI} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Comentario";
        lexVec[lexVec.size()-1].clave = "COMENTARIO";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
}
{NUMERO} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Numero";
        lexVec[lexVec.size()-1].clave = "NUMERO";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
    }
{IDENTIFICADOR} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Identificador";
        lexVec[lexVec.size()-1].clave = "IDENTIFICADOR";
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