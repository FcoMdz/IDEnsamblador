#!/bin/bash

clear
echo "Iniciando compilación"
bison -d -o sintatic.tab.cpp sintatic.y #-Wcounterexamples
flex -o lex.yy.cpp lexic.l
g++ -DYYERROR_VERBOSE lex.yy.cpp -o sintatic.exe -lfl
echo "Compilación terminada, comprueba errores"