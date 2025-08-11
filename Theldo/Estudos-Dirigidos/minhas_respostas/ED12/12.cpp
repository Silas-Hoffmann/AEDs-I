#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void metodo01() {
    cout << "----------------- Gerar matriz aleatoria -----------------\n";

    int linhas, colunas;
    cout << "Numero de linhas da matriz: ";
    cin >> linhas;
    cout << "Numero de colunas da matriz: ";
    cin >> colunas;

    int matriz[linhas][colunas];

    srand(time(0));

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = 1 + rand() % 100;
        }
    }

    ofstream arquivo("DADOS.TXT");
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }

    arquivo << linhas << " " << colunas << endl;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            arquivo << matriz[i][j] << " ";
        }
        arquivo << endl;
    }

    arquivo.close();
    cout << "Matriz gerada e salva em DADOS.TXT\n";
}


int** readMatrixFromFile(string nome, int &linhas, int &colunas) {
    ifstream arq(nome);
    if (!arq.is_open()) {
        cout << "Erro ao abrir o arquivo" << endl;
        return nullptr;
    }

    arq >> linhas >> colunas;

    int** matriz = new int*[linhas];
    for (int i = 0; i < linhas; i++) {
        matriz[i] = new int[colunas];
        for (int j = 0; j < colunas; j++) {
            arq >> matriz[i][j];
        }
    }

    arq.close();
    return matriz;
}



void metodo02() {
    cout << "----------------- Escalar matriz -----------------" << endl;

    string nome;
    cout << "Nome do arquivo: ";
    cin >> nome;

    int linhas, colunas;
    int** matriz = readMatrixFromFile(nome, linhas, colunas);
    if (matriz == nullptr) return;

    int escalar;
    cout << "Escalar: ";
    cin >> escalar;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] *= escalar;
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < linhas; i++) delete[] matriz[i];
    delete[] matriz;
}


void metodo03() {
    cout << "----------------- Testar matriz identidade -----------------" << endl;

    string nome;
    cout << "Nome do arquivo: ";
    cin >> nome;

    int linhas, colunas;
    int** matriz = readMatrixFromFile(nome, linhas, colunas);
    if (matriz == nullptr) return;

    bool identidade = true;

    if (linhas != colunas) {
        identidade = false;
    } else {
        for (int i = 0; i < linhas && identidade; i++) {
            for (int j = 0; j < colunas; j++) {
                if ((i == j && matriz[i][j] != 1) || (i != j && matriz[i][j] != 0)) {
                    identidade = false;
                    break;
                }
            }
        }
    }

    cout << (identidade ? "Sim" : "Nao") << endl;

    for (int i = 0; i < linhas; i++) delete[] matriz[i];
    delete[] matriz;
}


void metodo04() {
    cout << "----------------- Testar igualdade de matrizes -----------------" << endl;

    string nome1, nome2;
    cout << "Nome do arquivo 1: ";
    cin >> nome1;
    cout << "Nome do arquivo 2: ";
    cin >> nome2;

    int linhas1, colunas1, linhas2, colunas2;
    int** matriz1 = readMatrixFromFile(nome1, linhas1, colunas1);
    int** matriz2 = readMatrixFromFile(nome2, linhas2, colunas2);
    if (matriz1 == nullptr || matriz2 == nullptr) return;

    bool iguais = false;
    if (linhas1 == linhas2 && colunas1 == colunas2) {
        iguais = true;
        for (int i = 0; i < linhas1 && iguais; i++) {
            for (int j = 0; j < colunas1; j++) {
                if (matriz1[i][j] != matriz2[i][j]) {
                    iguais = false;
                    break;
                }
            }
        }
    }

    cout << (iguais ? "Matrizes Iguais" : "Matrizes Diferentes") << endl;

    for (int i = 0; i < linhas1; i++) delete[] matriz1[i];
    delete[] matriz1;
    for (int i = 0; i < linhas2; i++) delete[] matriz2[i];
    delete[] matriz2;
}


void metodo05() {
    cout << "----------------- Somar duas matrizes -----------------" << endl;

    string nome1, nome2;
    cout << "Nome do arquivo 1: ";
    cin >> nome1;
    cout << "Nome do arquivo 2: ";
    cin >> nome2;

    int linhas1, colunas1, linhas2, colunas2;
    int** matriz1 = readMatrixFromFile(nome1, linhas1, colunas1);
    int** matriz2 = readMatrixFromFile(nome2, linhas2, colunas2);
    if (matriz1 == nullptr || matriz2 == nullptr) return;

    if (linhas1 != linhas2 || colunas1 != colunas2) {
        cout << "Dimensoes diferentes" << endl;
    } else {
        int** soma = new int*[linhas1];
        for (int i = 0; i < linhas1; i++) {
            soma[i] = new int[colunas1];
            for (int j = 0; j < colunas1; j++) {
                soma[i][j] = matriz1[i][j] + matriz2[i][j];
            }
        }

        for (int i = 0; i < linhas1; i++) {
            for (int j = 0; j < colunas1; j++) {
                cout << soma[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < linhas1; i++) delete[] soma[i];
        delete[] soma;
    }

    for (int i = 0; i < linhas1; i++) delete[] matriz1[i];
    delete[] matriz1;
    for (int i = 0; i < linhas2; i++) delete[] matriz2[i];
    delete[] matriz2;
}


void metodo06() {
    cout << "----------------- Somar linhas com constante -----------------" << endl;

    string nome;
    cout << "Nome do arquivo: ";
    cin >> nome;

    int linhas, colunas;
    int** matriz = readMatrixFromFile(nome, linhas, colunas);
    if (matriz == nullptr) return;

    int l1, l2, k;
    cout << "Linha para atualizar: ";
    cin >> l1;
    cout << "Linha modelo: ";
    cin >> l2;
    cout << "Constante multiplicadora: ";
    cin >> k;

    l1=l1-1;
    l2=l2-1;

    if (l1 < 0 || l1 >= linhas || l2 < 0 || l2 >= linhas) {
        cout << "Linhas invalidas" << endl;
    } else {
        for (int j = 0; j < colunas; j++) {
            matriz[l1][j] += matriz[l2][j] * k;
        }

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    for (int i = 0; i < linhas; i++) delete[] matriz[i];
    delete[] matriz;
}


void metodo07() {
    cout << "----------------- Subtrair linhas com constante -----------------" << endl;

    string nome;
    cout << "Nome do arquivo: ";
    cin >> nome;

    int linhas, colunas;
    int** matriz = readMatrixFromFile(nome, linhas, colunas);
    if (matriz == nullptr) return;

    int l1, l2, k;
    cout << "Linha para atualizar: ";
    cin >> l1;
    cout << "Linha modelo: ";
    cin >> l2;
    cout << "Constante multiplicadora: ";
    cin >> k;

    l1=l1-1;
    l2=l2-1;

    if (l1 < 0 || l1 >= linhas || l2 < 0 || l2 >= linhas) {
        cout << "Linhas invalidas" << endl;
    } else {
        for (int j = 0; j < colunas; j++) {
            matriz[l1][j] -= matriz[l2][j] * k;
        }

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    for (int i = 0; i < linhas; i++) delete[] matriz[i];
    delete[] matriz;
}


void metodo08() {
    cout << "----------------- Buscar valor e informar linha -----------------" << endl;

    string nome;
    cout << "Nome do arquivo: ";
    cin >> nome;

    int linhas, colunas;
    int** matriz = readMatrixFromFile(nome, linhas, colunas);
    if (matriz == nullptr) return;

    int valor;
    cout << "Valor a buscar: ";
    cin >> valor;

    int linhaEncontrada = -1;

    for (int i = 0; i < linhas && linhaEncontrada == -1; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                linhaEncontrada = i;
                break;
            }
        }
    }

    if (linhaEncontrada == -1)
        cout << "Nao encontrado" << endl;
    else
        cout << linhaEncontrada+1 << endl;

    for (int i = 0; i < linhas; i++) delete[] matriz[i];
    delete[] matriz;
}


void metodo09() {
    cout << "----------------- Buscar valor e informar coluna -----------------" << endl;

    string nome;
    cout << "Nome do arquivo: ";
    cin >> nome;

    int linhas, colunas;
    int** matriz = readMatrixFromFile(nome, linhas, colunas);
    if (matriz == nullptr) return;

    int valor;
    cout << "Valor a buscar: ";
    cin >> valor;

    int colunaEncontrada = -1;

    for (int j = 0; j < colunas && colunaEncontrada == -1; j++) {
        for (int i = 0; i < linhas; i++) {
            if (matriz[i][j] == valor) {
                colunaEncontrada = j;
                break;
            }
        }
    }

    if (colunaEncontrada == -1)
        cout << "Nao encontrado" << endl;
    else
        cout << colunaEncontrada+1 << endl;

    for (int i = 0; i < linhas; i++) delete[] matriz[i];
    delete[] matriz;
}


void metodo10() {
    cout << "----------------- Transpor matriz -----------------" << endl;

    string nome;
    cout << "Nome do arquivo: ";
    cin >> nome;

    int linhas, colunas;
    int** matriz = readMatrixFromFile(nome, linhas, colunas);
    if (matriz == nullptr) return;

    int** transposta = new int*[colunas];
    for (int i = 0; i < colunas; i++) {
        transposta[i] = new int[linhas];
        for (int j = 0; j < linhas; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }

    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            cout << transposta[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < linhas; i++) delete[] matriz[i];
    delete[] matriz;
    for (int i = 0; i < colunas; i++) delete[] transposta[i];
    delete[] transposta;
}


int main() {
    int opcao = -1;

    while (opcao != 0) {
        cout << "\n----------------- Procedimento -----------------\n" << endl;
        for (int i = 1; i <= 10; i++) {
            cout << i << " - Metodo " << (i < 10 ? "0" : "") << i << endl;
        }
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
        case 1:
            metodo01();
            break;
        case 2:
            metodo02();
            break;
        case 3:
            metodo03();
            break;
        case 4:
            metodo04();
            break;
        case 5:
            metodo05();
            break;
        case 6:
            metodo06();
            break;
        case 7:
            metodo07();
            break;
        case 8:
            metodo08();
            break;
        case 9:
            metodo09();
            break;
        case 10:
            metodo10();
            break;
        case 0:
            cout << "Programa encerrado" << endl;
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
        }
    }
    return 0;
}
