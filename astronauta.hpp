#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Astronauta {
public:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;
    vector<int> voosParticipados;

    Astronauta(string _cpf, int _idade, string _nome) {
        cpf = _cpf;
        idade = _idade;
        nome = _nome;
        vivo = true;       
        disponivel = true; 
    }
};

#endif