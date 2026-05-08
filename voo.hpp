#ifndef VOO_HPP
#define VOO_HPP

#include <string>
#include <vector>

using namespace std;

class Voo {
public:
    int codigo;
    vector<string> passageirosCpf;
    int estado; // 0: Planejado, 1: Em curso, 2: Sucesso, 3: Explosão

    Voo(int c) {
        codigo = c;
        estado = 0; 
    }
};

#endif