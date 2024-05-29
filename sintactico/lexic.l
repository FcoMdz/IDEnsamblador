/*Código del análizador léxico adaptado para ser usado con bison*/
/*Variables*/
%{
    #include <iostream>
    #include "sintatic.tab.cpp"
    #include <vector>
    int yylex(void);
    void showError(char* other);
    void yyrestart(FILE *);

    bool ret = true;
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
    std::vector<Lexico> lexVec;

    int yyinput(char *buf, int max_size) {
        ret = false;
        int num_to_copy = std::min(max_size - 1, (int)strlen(input_text + text_index));
        strncpy(buf, input_text + text_index, num_to_copy);
        text_index += num_to_copy;
        return num_to_copy;
    }

    std::vector<Lexico> analyzeFile(const char *filename) {
        ret = false;
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

    void activateRet(){
        ret = true;
    }

    std::vector<Lexico> analyzeText(const char *text) {
        ret = false;
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

%option noyywrap noinput nounput yylineno
/*Especificaciones regex*/
SPACE [ ]|[\t]|[\r]
SALTOLINEA [\n]+
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
{SALTOLINEA} {
    countLines++; 
    countColumn=1;
}
{SPACE} {
    countColumn++;
    //printf("Espacio\n");
}
{PROGRAM} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "PROGRAM";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (PROGRAM);
    }
{IF} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "IF";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (IF);
    }
{THEN} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "THEN";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (THEN);
    }
{ELSE} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "ELSE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (ELSE);
    }
{FI} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "FI";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (FI);
    }
{DO} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "DO";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (DO);
    }
{UNTIL} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "UNTIL";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (UNTIL);
    }
{WHILE} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "WHILE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (WHILE);
    }
{BREAK} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "BREAK";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (BREAK);
    }
{READ} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "READ";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (READ);
    }
{WRITE} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "WRITE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (WRITE);
    }
{FLOAT} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "FLOAT";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (FLOAT);
    }
{INT} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "INT";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (INT);
    }
{BOOL} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "BOOL";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (BOOL);
    }
{NOT} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "NOT";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (NOT);
    }
{AND} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "AND";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (AND);
    }
{OR} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "OR";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (OR);
    }
{TRUE} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "TRUE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (TRUE);
    }
{FALSE} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Reservada";
        lexVec[lexVec.size()-1].clave = "FALSE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (FALSE);
    }
{MAS} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MAS";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (MAS);
    }
{RES} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "RES";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (RES);
    }
{MUL} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MUL";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (MUL);
    }
{DIV} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "DIV";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (DIV);
    }
{ELE} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "ELE";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (ELE);
    }
{MEN} {
        //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MEN";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (MEN);
    }
{MENIGL} {
        //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MENIGL";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (MENIGL);
    }
{MAY} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MAY";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (MAY);
    }
{MAYIGL} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "MAYIGL";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (MAYIGL);
    }
{IGU} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "IGU";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (IGU);
    }
{DIS} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "DIS";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (DIS);
    }
{ASIG} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "ASIG";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (ASIG);
    }
{PYC} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Otro";
        lexVec[lexVec.size()-1].clave = "PYC";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (PYC);
    }
{COM} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Otro";
        lexVec[lexVec.size()-1].clave = "COM";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (COM);
    }
{PI} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "PI";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (PI);
    }
{PD} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "PD";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (PD);
    }
{LI} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "LI";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (LI);
    }
{LD} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Simbolo";
        lexVec[lexVec.size()-1].clave = "LD";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (LD);
    }
{CADENA} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Cadena";
        lexVec[lexVec.size()-1].clave = "CADENA";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (CADENA);
    }
{COMENTARIO_LINEA}|{COMENTARIO_MULTI} {
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Comentario";
        lexVec[lexVec.size()-1].clave = "COMENTARIO";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        //printf("lex: comentario\n");
    }
{NUMERO} {
    //printf("lex num: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Numero";
        lexVec[lexVec.size()-1].clave = "NUMERO";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.numero = std::atof(yytext);
        if(ret)  return (NUMERO);
    }
{IDENTIFICADOR} {
    //printf("lex: %s\n",yytext);
        lexVec.push_back(Lexico());
        lexVec[lexVec.size()-1].estilo = "Identificador";
        lexVec[lexVec.size()-1].clave = "IDENTIFICADOR";
        lexVec[lexVec.size()-1].lexema = yytext;
        lexVec[lexVec.size()-1].columna = countColumn;
        lexVec[lexVec.size()-1].fila = countLines;
        countColumn += strlen(yytext);
        yylval.cadena = yytext;
        if(ret) return (IDENTIFICADOR);
    }
. {
    lexVec.push_back(Lexico());
    lexVec[lexVec.size()-1].estilo = "Error";
    lexVec[lexVec.size()-1].clave = "ERROR";
    lexVec[lexVec.size()-1].lexema = yytext;
    lexVec[lexVec.size()-1].columna = countColumn;
    lexVec[lexVec.size()-1].fila = countLines;
     //printf("lex: %s\n",yytext);
    return 0;
}
%%

/*Sección de codigo*/

void showError(char* other){
    printf("Error léxico %s\n",  other);
}

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