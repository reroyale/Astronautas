#include <iostream>
#include <vector>
#include <string>
#include "astronauta.hpp"
#include "voo.hpp"

using namespace std;

vector<Astronauta> astronautas;
vector<Voo> voos;

int main() {
    string comando;

    while (cin >> comando && comando != "FIM") {
        
        if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome; int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);

            bool existe = false;
            for (int i = 0; i < astronautas.size(); i++) {
                if (astronautas[i].cpf == cpf) existe = true;
            }

            if (!existe) {
                astronautas.push_back(Astronauta(cpf, idade, nome));
            } else {
                cout << "Erro: Astronauta com CPF " << cpf << " ja existe." << endl;
            }
        }

        else if (comando == "CADASTRAR_VOO") {
            int codigo; cin >> codigo;
            bool existe = false;
            for (int i = 0; i < voos.size(); i++) {
                if (voos[i].codigo == codigo) existe = true;
            }

            if (!existe) {
                voos.push_back(Voo(codigo));
            } else {
                cout << "Erro: Voo " << codigo << " ja cadastrado." << endl;
            }
        }

        else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf; int cod; cin >> cpf >> cod;
            int idxA = -1, idxV = -1;

            for (int i = 0; i < astronautas.size(); i++) if (astronautas[i].cpf == cpf) idxA = i;
            for (int i = 0; i < voos.size(); i++) if (voos[i].codigo == cod) idxV = i;

            if (idxA != -1 && idxV != -1) {
                if (voos[idxV].estado == 0 && astronautas[idxA].vivo) {
                    voos[idxV].passageirosCpf.push_back(cpf);
                } else {
                    cout << "Erro: Voo nao esta planejado ou astronauta nao esta vivo." << endl;
                }
            } else {
                cout << "Erro: CPF ou Codigo de voo nao encontrados." << endl;
            }
        }

        else if (comando == "LANCAR_VOO") {
            int cod; cin >> cod;
            for (int i = 0; i < voos.size(); i++) {
                if (voos[i].codigo == cod) {
                    if (voos[i].estado == 0 && voos[i].passageirosCpf.size() > 0) {
                        bool prontos = true;
                        for (int j = 0; j < voos[i].passageirosCpf.size(); j++) {
                            for (int k = 0; k < astronautas.size(); k++) {
                                if (astronautas[k].cpf == voos[i].passageirosCpf[j]) {
                                    if (!astronautas[k].vivo || !astronautas[k].disponivel) prontos = false;
                                }
                            }
                        }

                        if (prontos) {
                            voos[i].estado = 1; // Em curso
                            for (int j = 0; j < voos[i].passageirosCpf.size(); j++) {
                                for (int k = 0; k < astronautas.size(); k++) {
                                    if (astronautas[k].cpf == voos[i].passageirosCpf[j]) {
                                        astronautas[k].disponivel = false;
                                        astronautas[k].voosParticipados.push_back(cod);
                                    }
                                }
                            }
                        } else {
                            cout << "Erro: Ha astronautas mortos ou ja em missao neste voo." << endl;
                        }
                    } else {
                        cout << "Erro: Voo precisa estar planejado e ter passageiros para ser lancado." << endl;
                    }
                }
            }
        }

        else if (comando == "EXPLODIR_VOO") {
            int cod; cin >> cod;
            for (int i = 0; i < voos.size(); i++) {
                if (voos[i].codigo == cod) {
                    if (voos[i].estado == 1) {
                        voos[i].estado = 3;
                        for (int j = 0; j < voos[i].passageirosCpf.size(); j++) {
                            for (int k = 0; k < astronautas.size(); k++) {
                                if (astronautas[k].cpf == voos[i].passageirosCpf[j]) {
                                    astronautas[k].vivo = false;
                                    astronautas[k].disponivel = false;
                                }
                            }
                        }
                    } else cout << "Erro: Apenas voos EM CURSO podem explodir." << endl;
                }
            }
        }

        else if (comando == "FINALIZAR_VOO") {
            int cod; cin >> cod;
            for (int i = 0; i < voos.size(); i++) {
                if (voos[i].codigo == cod) {
                    if (voos[i].estado == 1) {
                        voos[i].estado = 2;
                        for (int j = 0; j < voos[i].passageirosCpf.size(); j++) {
                            for (int k = 0; k < astronautas.size(); k++) {
                                if (astronautas[k].cpf == voos[i].passageirosCpf[j]) {
                                    astronautas[k].disponivel = true;
                                }
                            }
                        }
                    } else cout << "Erro: Apenas voos EM CURSO podem ser finalizados." << endl;
                }
            }
        }

        else if (comando == "LISTAR_VOOS") {
            // Lista agrupada por estado (0: Planejado, 1: Curso, 2: Sucesso, 3: Explosao)
            for (int e = 0; e <= 3; e++) {
                for (int i = 0; i < voos.size(); i++) {
                    if (voos[i].estado == e) {
                        cout << "Voo: " << voos[i].codigo << " | Estado: " << e << endl;
                        for (int j = 0; j < voos[i].passageirosCpf.size(); j++) {
                            for (int k = 0; k < astronautas.size(); k++) {
                                if (astronautas[k].cpf == voos[i].passageirosCpf[j]) {
                                    cout << "   - " << astronautas[k].nome << " (" << astronautas[k].cpf << ")" << endl;
                                }
                            }
                        }
                    }
                }
            }
        }

        else if (comando == "LISTAR_MORTOS") {
            cout << "ASTRONAUTAS MORTOS:" << endl;
            for (int i = 0; i < astronautas.size(); i++) {
                if (!astronautas[i].vivo) {
                    cout << "Nome: " << astronautas[i].nome << " | CPF: " << astronautas[i].cpf << " | Voos: ";
                    for (int j = 0; j < astronautas[i].voosParticipados.size(); j++) {
                        cout << astronautas[i].voosParticipados[j] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}