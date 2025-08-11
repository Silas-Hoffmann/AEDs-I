#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Contato {
private:
    string nome;
    string telefones[2];
    int quantidade;

    bool isValidPhone(string fone) {
        int countHifen = 0;
        for (char c : fone) {
            if (c == '-') countHifen++;
            else if (!isdigit(c)) return false;
        }
        return countHifen <= 1;
    }

public:
    Contato(string n = "", string f1 = "", string f2 = "") {
        nome = n;
        telefones[0] = f1;
        telefones[1] = f2;
        quantidade = (f1 != "") + (f2 != "");
    }

    void readName(string msg) {
        cout << msg;
        getline(cin, nome);
        if (nome == "") cout << "Nome invalido" << endl;
        else cout << "Nome adicionado" << endl;
    }

    void readPhone(string msg) {
        cout << msg;
        getline(cin, telefones[0]);
        if (telefones[0] == "") cout << "Telefone invalido" << endl;
        else {
            quantidade = 1;
            cout << "Telefone 1 adicionado" << endl;
        }
    }

    void testPhoneValid() {
        cout << "Telefone valido? " << (isValidPhone(telefones[0]) ? "Sim" : "Nao") << endl;
    }

    void readFromFile(string nomeArq) {
        ifstream arq(nomeArq);
        if (arq) {
            string n, f1, f2;
            if (getline(arq, n) && !n.empty() &&
                getline(arq, f1) &&
                getline(arq, f2)) {
    
                nome = n;
                telefones[0] = f1;
                telefones[1] = f2;
                quantidade = (f1 != "") + (f2 != "");
    
                cout << "Dados lidos do arquivo:" << endl;
                print();
                cout << "Leitura concluida" << endl;
    
            } else {
                cout << "Arquivo vazio ou formato invalido" << endl;
            }
            arq.close();
        } else {
            cout << "Erro ao abrir o arquivo" << endl;
        }
    }


    void writeToFile(string nomeArq) {
        ofstream arq(nomeArq);
        if (arq) {
            arq << nome << endl;
            arq << telefones[0] << endl;
            arq << telefones[1] << endl;
            arq.close();
            cout << "Dados gravados no arquivo" << endl;
        } else cout << "Erro ao abrir o arquivo" << endl;
    }

    int phones() {
        return quantidade;
    }

    void setPhone2a() {
        if (quantidade == 1) {
            cout << "Digite o segundo telefone: ";
            getline(cin, telefones[1]);
            quantidade++;
            cout << "Segundo telefone criado" << endl;
        } else {
            cout << "Ja possui dois telefones" << endl;
        }
    }

    void setPhone2b(string fone) {
        if (quantidade == 2) {
            telefones[1] = fone;
            cout << "Segundo telefone alterado" << endl;
        } else {
            cout << "Nao ha segundo telefone" << endl;
        }
    }

    void setPhone2c(string fone) {
        if (quantidade == 2) {
            telefones[1] = fone;
            quantidade--;
            cout << "Segundo telefone removido" << endl;
        } else {
            cout << "Nao ha segundo telefone" << endl;
        }
    }

    void readPhone2() {
        string fone;
        cout << "Digite o telefone 2: ";
        getline(cin, fone);
    
        if (isValidPhone(fone)) {
            if (quantidade == 0) {
                telefones[0] = fone;
                quantidade = 1;
            } else if (quantidade == 1) {
                telefones[1] = fone;
                quantidade = 2;
            } else {
                telefones[1] = fone;
            }
            cout << "Telefone 2 lido e atribuido" << endl;
        } else {
            cout << "Telefone invalido" << endl;
        }
    }


    void print() {
        cout << "Nome: " << nome << endl;
        cout << "Telefone 1: " << telefones[0] << endl;
        if (quantidade == 2) cout << "Telefone 2: " << telefones[1] << endl;
    }

    string getName() {
        return nome;
    }

    string getPhone1() {
        return telefones[0];
    }
};

int main() {
    Contato contato;
    int opcao;
    string entrada;

    do {
        cout << "\nEscolha uma opcao (1311 a 1320, 0 para sair): ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
        case 1311:
            contato.readName("Nome: ");
            break;
        case 1312:
            contato.readPhone("Fone: ");
            break;
        case 1313:
            contato.testPhoneValid();
            break;
        case 1314:
            cout << "Nome do arquivo: ";
            getline(cin, entrada);
            contato.readFromFile(entrada);
            break;
        case 1315:
            contato.writeToFile("Pessoa1.txt");
            break;
        case 1316: {
            string nomeAtual = contato.getName();
            string fone1Atual = contato.getPhone1();
        
            contato = Contato(nomeAtual, fone1Atual, "98888-2222");
            contato.print();
            cout << "Telefone 2 criado" << endl;
            break;
        }
        case 1317:
            cout << "Quantidade de telefones: " << contato.phones() << endl;
            break;
        case 1318:
            contato.readPhone2();
            break;
        case 1319:
            contato.setPhone2b("00000-0000");
            break;
        case 1320:
            contato.setPhone2c("");
            break;
        case 0:
            cout << "Programa Encerrado" << endl;
            break;
        default:
            cout << "Opcao invalida" << endl;
        }

    } while (opcao != 0);

    return 0;
}