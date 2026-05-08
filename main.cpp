#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "astronauta.hpp"
#include "voo.hpp"

using namespace std;

vector<Astronauta> astronautas;
vector<Voo> voos;

void exibirHelp() {
    cout << "\n================ COMANDOS DISPONIVEIS ================" << endl;
    cout << "ca [cpf] [idade] [nome]  - Cadastrar novo astronauta" << endl;
    cout << "cv [codigo]              - Cadastrar novo voo" << endl;
    cout << "add [cpf] [codigo]       - Adicionar astronauta ao voo" << endl;
    cout << "lan [codigo]             - Lancar voo ao espaco" << endl;
    cout << "fim [codigo]             - Finalizar voo com sucesso" << endl;
    cout << "boom [codigo]            - Finalizar voo com explosao" << endl;
    cout << "lv                       - Listar todos os voos" << endl;
    cout << "lm                       - Listar astronautas mortos" << endl;
    cout << "!help                    - Mostrar este menu" << endl;
    cout << "sair                     - Encerrar o sistema" << endl;
    cout << "======================================================" << endl;
}

int main() {
    string comando;
    
    cout << "******************************************************" << endl;
    cout << "* SISTEMA DE CONTROLE AEROESPACIAL          *" << endl;
    cout << "******************************************************" << endl;
    cout << "Digite !help para ver os comandos ou 'sair' para finalizar." << endl;

    while (true) {
        cout << "\n> ";
        cin >> comando;

        if (comando == "sair" || comando == "FIM") break;

        if (comando == "!help") {
            exibirHelp();
        } 
        
        else if (comando == "ca") { // CADASTRAR_ASTRONAUTA
            string cpf, nome; int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);

            bool existe = false;
            for (int i = 0; i < (int)astronautas.size(); i++) {
                if (astronautas[i].cpf == cpf) existe = true;
            }

            if (!existe) {
                astronautas.push_back(Astronauta(cpf, idade, nome));
                cout << "[SUCESSO] Astronauta " << nome << " registrado." << endl;
            } else {
                cout << "[ERRO] Este CPF ja consta no sistema." << endl;
            }
        }

        else if (comando == "cv") { // CADASTRAR_VOO
            int codigo; cin >> codigo;
            bool existe = false;
            for (int i = 0; i < (int)voos.size(); i++) {
                if (voos[i].codigo == codigo) existe = true;
            }

            if (!existe) {
                voos.push_back(Voo(codigo));
                cout << "[SUCESSO] Voo " << codigo << " planejado." << endl;
            } else {
                cout << "[ERRO] Voo com este codigo ja existe." << endl;
            }
        }

        else if (comando == "add") { // ADICIONAR_ASTRONAUTA
            string cpf; int cod; cin >> cpf >> cod;
            int idxA = -1, idxV = -1;
            for (int i = 0; i < (int)astronautas.size(); i++) if (astronautas[i].cpf == cpf) idxA = i;
            for (int i = 0; i < (int)voos.size(); i++) if (voos[i].codigo == cod) idxV = i;

            if (idxA != -1 && idxV != -1) {
                if (voos[idxV].estado == 0 && astronautas[idxA].vivo) {
                    voos[idxV].passageirosCpf.push_back(cpf);
                    cout << "[SUCESSO] " << astronautas[idxA].nome << " adicionado ao voo " << cod << "." << endl;
                } else cout << "[ERRO] Voo indisponivel ou astronauta falecido." << endl;
            } else cout << "[ERRO] Dados nao encontrados." << endl;
        }

        else if (comando == "lan") { // LANCAR_VOO
            int cod; cin >> cod;
            for (int i = 0; i < (int)voos.size(); i++) {
                if (voos[i].codigo == cod) {
                    if (voos[i].estado == 0 && !voos[i].passageirosCpf.empty()) {
                        voos[i].estado = 1;
                        cout << "[LANÇAMENTO] O voo " << cod << " partiu com sucesso!" << endl;
                        for (int j = 0; j < (int)voos[i].passageirosCpf.size(); j++) {
                            for (int k = 0; k < (int)astronautas.size(); k++) {
                                if (astronautas[k].cpf == voos[i].passageirosCpf[j]) {
                                    astronautas[k].disponivel = false;
                                    astronautas[k].voosParticipados.push_back(cod);
                                }
                            }
                        }
                    } else cout << "[ERRO] Voo sem tripulacao ou ja lancado." << endl;
                }
            }
        }

        else if (comando == "fim") { // FINALIZAR_VOO
            int cod; cin >> cod;
            for (int i = 0; i < (int)voos.size(); i++) {
                if (voos[i].codigo == cod && voos[i].estado == 1) {
                    voos[i].estado = 2;
                    cout << "[MISSAO CONCLUIDA] Tripulacao do voo " << cod << " retornou em seguranca." << endl;
                    for (int j = 0; j < (int)voos[i].passageirosCpf.size(); j++) {
                        for (int k = 0; k < (int)astronautas.size(); k++) {
                            if (astronautas[k].cpf == voos[i].passageirosCpf[j]) astronautas[k].disponivel = true;
                        }
                    }
                }
            }
        }

        else if (comando == "lv") { // LISTAR_VOOS
            cout << "\n--- LISTAGEM DE VOOS ---" << endl;
            for (int i = 0; i < (int)voos.size(); i++) {
                cout << "Codigo: " << voos[i].codigo << " | Status: " << voos[i].getStatus() << endl;
            }
        }

        else {
            cout << "[COMANDO INVALIDO] Digite !help para ver a lista de comandos." << endl;
        }
    }

    cout << "\nEncerrando sistema... Ate logo, Comandante!" << endl;
    return 0;
}
