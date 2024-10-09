#!/bin/bash

clear
echo "Iniciando compilación"
bison -d -o sintatic.tab.c sintatic.y -Wcounterexamples
flex -o lex.yy.c lexic.l
g++ -DYYERROR_VERBOSE lex.yy.c -o sintatic.exe -lfl
echo "Compilación terminada, comprueba errores"