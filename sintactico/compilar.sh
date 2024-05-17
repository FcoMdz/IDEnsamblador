#!/bin/bash

clear
echo "Iniciando compilación"
bison -d -o sintatic.tab.cpp sintatic.y 
flex -o lex.yy.cpp lexic.l
g++ sintatic.tab.cpp lex.yy.cpp -o sintatic.exe -lfl
echo "Compilación terminada, comprueba errores"