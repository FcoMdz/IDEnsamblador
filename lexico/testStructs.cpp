#include <iostream>
#include <vector>

struct Lexico{
    std::string clave;
    std::string lexema;
    int fila;
    int columna;
};

int main(){
    int countLines = 0;
    int countColumn = 0;
    std::vector<Lexico> lexVec;
    for(int i=0; i<5; i++){
        lexVec.push_back(Lexico());
        lexVec[i].clave = "Hola";
        std::cout << lexVec[i].clave << " " << lexVec.size();
    }
}
