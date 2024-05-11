#!/bin/bash

clear
echo "Iniciando compilación"
bison -dv sintatic.y
flex -l lexic.l
g++ sintatic.tab.c lex.yy.c -o sintactic.exe
echo "Compilación terminada, comprueba errores"