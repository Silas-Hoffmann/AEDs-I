#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// -----------------------------------------------
// ------------------ Questao 1 ------------------
// -----------------------------------------------
void gerarNumerosAleatorios(int arr[], int n, int inferior, int superior) {
    for (int i = 0; i < n; i++) {
        int valor = inferior + rand() % (superior - inferior + 1);
        arr[i] = valor;
    }
}

void gravarNoArquivo(const char* nomeArquivo, int arr[], int n) {
    ofstream arquivo(nomeArquivo);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo\n";
        return;
    }
    arquivo << n << "\n";
    for (int i = 0; i < n; i++) {
        arquivo << arr[i] << "\n";
    }
    arquivo.close();
    cout << "Arquivo criado\n";
}

void questao1() {
    cout << "\n--------- Q1 ---------\n";
    srand(time(NULL));

    int N;
    int inferior, superior;

    cout << "Quantidade de números gerados: ";
    cin >> N;

    cout << "limite menor do intervalo: ";
    cin >> inferior;

    cout << "limite maior do intervalo: ";
    cin >> superior;

    if (N <= 0) {
        cout << "Quantidade maior que 0\n";
        return;
    }
    if (inferior > superior) {
        cout << "Erro: Menor > Maior\n";
        return;
    }

    int* arr = new int[N];
    gerarNumerosAleatorios(arr, N, inferior, superior);
    gravarNoArquivo("DADOS.txt", arr, N);

    cout << "Números gerados:\n";
    int i = 0;
    for (; i < N/2; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    for (; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr;
}

// -----------------------------------------------
// ------------------ Questao 2 ------------------
// -----------------------------------------------
void lerArrayDeArquivo(const char* nomeArquivo, int*& arr, int& n) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo\n";
        arr = nullptr;
        n = 0;
        return;
    }

    arquivo >> n;
    if (n <= 0) {
        cout << "Quantidade inválida no arquivo\n";
        arr = nullptr;
        n = 0;
        return;
    }

    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arquivo >> arr[i];
    }

    arquivo.close();
}

int maiorImpar(int arr[], int n) {
    int maior = 0;
    bool encontrouImpar = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            if (!encontrouImpar) {
                maior = arr[i];
                encontrouImpar = true;
            } else if (arr[i] > maior) {
                maior = arr[i];
            }
        }
    }

    if (!encontrouImpar) {
        return 0;
    }
    return maior;
}

void questao2() {
    cout << "\n--------- Q2 ---------\n";
    char nomeArquivo[100];
    cout << "Nome do arquivo: ";
    cin >> nomeArquivo;

    int* arr;
    int n;
    lerArrayDeArquivo(nomeArquivo, arr, n);

    if (arr == nullptr || n <= 0) {
        cout << "Erro ao ler arranjo\n";
        return;
    }

    int maior = maiorImpar(arr, n);

    if (maior == 0) {
        cout << "Nenhum número ímpar encontrado\n";
    } else {
        cout << "Maior número ímpar encontrado: " << maior << "\n";
    }
    
    delete[] arr;
}

// -----------------------------------------------
// ------------------ Questao 3 ------------------
// -----------------------------------------------
int maiorImparMultiplo3(int arr[], int n) {
    int maior = 0;
    bool encontrou = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0 && arr[i] % 3 == 0) {
            if (!encontrou) {
                maior = arr[i];
                encontrou = true;
            } else if (arr[i] > maior) {
                maior = arr[i];
            }
        }
    }

    if (!encontrou) {
        return 0;
    }
    return maior;
}

void questao3() {
    cout << "\n--------- Q3 ---------\n";
    char nomeArquivo[100];
    cout << "Nome do arquivo: ";
    cin >> nomeArquivo;

    int* arr;
    int n;
    lerArrayDeArquivo(nomeArquivo, arr, n);

    if (arr == nullptr || n <= 0) {
        cout << "Erro ao ler arranjo\n";
        return;
    }

    int maior = maiorImparMultiplo3(arr, n);

    if (maior == 0) {
        cout << "Nenhum ímpar múltiplo de 3 encontrado\n";
    } else {
        cout << "Maior ímpar múltiplo de 3 encontrado: " << maior << "\n";
    }

    delete[] arr;
}

// -----------------------------------------------
// ------------------ Questao 4 ------------------
// -----------------------------------------------
int somaIntervalo(int arr[], int n, int inicio, int fim) {
    if (inicio < 0) inicio = 0;
    if (fim >= n) fim = n - 1;
    if (inicio > fim) return 0;

    int soma = 0;
    for (int i = inicio; i <= fim; i++) {
        soma += arr[i];
    }
    return soma;
}

void questao4() {
    cout << "\n--------- Q4 ---------\n";
    char nomeArquivo[100];
    cout << "Nome do arquivo: ";
    cin >> nomeArquivo;

    int* arr;
    int n;
    lerArrayDeArquivo(nomeArquivo, arr, n);

    if (arr == nullptr || n <= 0) {
        cout << "Erro ao ler arranjo\n";
        return;
    }

    int inicio, fim;
    cout << "Posição inicial do intervalo (0 a " << (n-1) << "): ";
    cin >> inicio;
    cout << "Posição final do intervalo (0 a " << (n-1) << "): ";
    cin >> fim;

    int soma = somaIntervalo(arr, n, inicio, fim);

    cout << "Soma entre " << inicio << " e " << fim << ": " << soma << "\n";

    delete[] arr;
}

// -----------------------------------------------
// ------------------ Questao 5 ------------------
// -----------------------------------------------
double mediaIntervalo(int arr[], int n, int inicio, int fim) {
    if (inicio < 0) inicio = 0;
    if (fim >= n) fim = n - 1;
    if (inicio > fim) return 0.0;
    int soma = 0;
    int count = 0;
    for (int i = inicio; i <= fim; i++) {
        soma += arr[i];
        count++;
    }
    return (count > 0) ? (double)soma / count : 0.0;
}

void questao5() {
    cout << "\n--------- Q5 ---------\n";
    char nomeArquivo[100];
    cout << "Nome do arquivo: ";
    cin >> nomeArquivo;

    int* arr;
    int n;
    lerArrayDeArquivo(nomeArquivo, arr, n);

    if (arr == nullptr || n <= 0) {
        cout << "Erro ao ler arranjo\n";
        return;
    }

    int inicio, fim;
    cout << "Posição inicial do intervalo (0 a " << (n-1) << "): ";
    cin >> inicio;
    cout << "Posição final do intervalo (0 a " << (n-1) << "): ";
    cin >> fim;

    double media = mediaIntervalo(arr, n, inicio, fim);

    cout << "Média entre " << inicio << " e " << fim << ": " << media << "\n";

    delete[] arr;
}

// -----------------------------------------------
// ------------------ Questao 6 ------------------
// -----------------------------------------------
bool todosMaioresQue100(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 100) {
            return false;
        }
    }
    return true;
}

void questao6() {
    cout << "\n--------- Q6 ---------\n";
    char nomeArquivo[100];
    cout << "Nome do arquivo: ";
    cin >> nomeArquivo;

    int* arr;
    int n;
    lerArrayDeArquivo(nomeArquivo, arr, n);

    if (arr == nullptr || n <= 0) {
        cout << "Erro ao ler arranjo\n";
        return;
    }

    bool resultado = todosMaioresQue100(arr, n);

    if (resultado) {
        cout << "Todos são positivos e maiores que 100\n";
    } else {
        cout << "Existem valores menores ou iguais a 100\n";
    }

    delete[] arr;
}

// -----------------------------------------------
// ------------------ Questao 7 ------------------
// -----------------------------------------------
bool estaOrdenadoDecrescente(int arr[], int n) {
    bool ordenado = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            ordenado = false;
        }
    }
    return ordenado;
}

void questao7() {
    cout << "\n--------- Q7 ---------\n";
    char nomeArquivo[100];
    cout << "Nome do arquivo: ";
    cin >> nomeArquivo;

    int* arr;
    int n;
    lerArrayDeArquivo(nomeArquivo, arr, n);

    if (arr == nullptr || n <= 0) {
        cout << "Erro ao ler arranjo\n";
        return;
    }

    bool resultado = estaOrdenadoDecrescente(arr, n);

    if (resultado) {
        cout << "O arranjo está decrescente\n";
    } else {
        cout << "O arranjo não está decrescente\n";
    }

    delete[] arr;
}

// -----------------------------------------------
// ------------------ Questao 8 ------------------
// -----------------------------------------------
bool valorNoIntervalo(int arr[], int n, int procurado, int inicio, int fim) {
    if (inicio < 0) inicio = 0;
    if (fim >= n) fim = n - 1;
    bool existe = false;
    for (int i = inicio; i <= fim; i++) {
        if (arr[i] == procurado) {
            existe = true;
        }
    }
    return existe;
}

void questao8() {
    cout << "\n--------- Q8 ---------\n";
    char nomeArquivo[100];
    cout << "Nome do arquivo: ";
    cin >> nomeArquivo;

    int* arr;
    int n;
    lerArrayDeArquivo(nomeArquivo, arr, n);

    if (arr == nullptr || n <= 0) {
        cout << "Erro ao ler arranjo\n";
        return;
    }

    int procurado, inicio, fim;
    cout << "Digite o valor a ser procurado: ";
    cin >> procurado;
    cout << "Posição inicial do intervalo (0 a " << (n - 1) << "): ";
    cin >> inicio;
    cout << "Posição final do intervalo (0 a " << (n - 1) << "): ";
    cin >> fim;

    bool resultado = valorNoIntervalo(arr, n, procurado, inicio, fim);

    if (resultado) {
        cout << "O valor " << procurado << " está [" << inicio << ", " << fim << "]\n";
    } else {
        cout << "O valor " << procurado << " está [" << inicio << ", " << fim << "]\n";
    }

    delete[] arr;
}

// -----------------------------------------------
// ------------------ Questao 9 ------------------
// -----------------------------------------------
void escalarIntervalo(int arr[], int n, int constante, int inicio, int fim) {
    if (inicio < 0) inicio = 0;
    if (fim >= n) fim = n - 1;
    for (int i = inicio; i <= fim; i++) {
        arr[i] = arr[i] * constante;
    }
}

void questao9() {
    cout << "\n--------- Q9 ---------\n";
    char nomeArquivo[100];
    cout << "Nome do arquivo: ";
    cin >> nomeArquivo;

    int* arr;
    int n;
    lerArrayDeArquivo(nomeArquivo, arr, n);

    if (arr == nullptr || n <= 0) {
        cout << "Erro ao ler arranjo\n";
        return;
    }

    int constante, inicio, fim;
    cout << "Digite a constante multiplicadora: ";
    cin >> constante;
    cout << "Posição inicial do intervalo (0 a " << (n - 1) << "): ";
    cin >> inicio;
    cout << "Posição final do intervalo (0 a " << (n - 1) << "): ";
    cin >> fim;

    escalarIntervalo(arr, n, constante, inicio, fim);

    cout << "Arranjo escalado:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr;
}

// -----------------------------------------------
// ------------------ Questao 10 -----------------
// -----------------------------------------------
void ordenarDecrescente(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void questao10() {
    cout << "\n--------- Q10 --------\n";
    char nomeArquivo[100];
    cout << "Nome do arquivo: ";
    cin >> nomeArquivo;

    int* arr;
    int n;
    lerArrayDeArquivo(nomeArquivo, arr, n);

    if (arr == nullptr || n <= 0) {
        cout << "Erro ao ler arranjo\n";
        return;
    }

    ordenarDecrescente(arr, n);

    cout << "Arranjo ordenado decrescente:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr;
}

// -----------------------------------------------
// ------------------ Questao E1 -----------------
// -----------------------------------------------
bool diferenteEmAlgumaPosicao(int arr1[], int n1, int arr2[], int n2) {
    if (n1 != n2) {
        return true;
    }
    for (int i = 0; i < n1; i++) {
        if (arr1[i] != arr2[i]) {
            return true;
        }
    }
    return false;
}

void extra1() {
    cout << "\n--------- E1 ---------\n";
    char arquivo1[100], arquivo2[100];
    cout << "Nome do primeiro arquivo: ";
    cin >> arquivo1;
    cout << "Nome do segundo arquivo: ";
    cin >> arquivo2;

    int *arr1, *arr2;
    int n1, n2;

    lerArrayDeArquivo(arquivo1, arr1, n1);
    lerArrayDeArquivo(arquivo2, arr2, n2);

    if (arr1 == nullptr || arr2 == nullptr || n1 <= 0 || n2 <= 0) {
        cout << "Erro ao ler um dos arranjos\n";
        return;
    }

    bool diferente = diferenteEmAlgumaPosicao(arr1, n1, arr2, n2);

    if (diferente) {
        cout << "Os arranjos são diferentes em pelo menos uma posição\n";
    } else {
        cout << "Os arranjos são iguais\n";
    }

    delete[] arr1;
    delete[] arr2;
}

// -----------------------------------------------
// ------------------ Questao E2 -----------------
// -----------------------------------------------
void calcularDiferencas(int arr1[], int arr2[], int n, int diferencas[]) {
    for (int i = 0; i < n; i++) {
        diferencas[i] = arr1[i] - arr2[i];
    }
}

void extra2() {
    cout << "\n--------- E2 ---------\n";
    char arquivo1[100], arquivo2[100];
    cout << "Nome do primeiro arquivo: ";
    cin >> arquivo1;
    cout << "Nome do segundo arquivo: ";
    cin >> arquivo2;

    int *arr1, *arr2;
    int n1, n2;

    lerArrayDeArquivo(arquivo1, arr1, n1);
    lerArrayDeArquivo(arquivo2, arr2, n2);

    if (arr1 == nullptr || arr2 == nullptr || n1 <= 0 || n2 <= 0) {
        cout << "Erro ao ler um dos arranjos\n";
        return;
    }

    if (n1 != n2) {
        cout << "Os arranjos têm tamanhos diferentes\n";
        delete[] arr1;
        delete[] arr2;
        return;
    }

    int* diferencas = new int[n1];
    calcularDiferencas(arr1, arr2, n1, diferencas);

    cout << "Diferenças posição a posição:\n";
    for (int i = 0; i < n1; i++) {
        cout << diferencas[i] << " ";
    }
    cout << "\n";

    delete[] arr1;
    delete[] arr2;
    delete[] diferencas;
}

// -----------------------------------------------
// ---------------- Execucao Geral ---------------
// -----------------------------------------------
int main() {
    int opcao = -1;

    while (opcao != 0) {
        cout << "\n--------- Menu ---------";
        cout << "\nEscolha a opcao desejada:\n";
        cout << "0 - Cancelar\n";
        cout << "1 - 1111\n";
        cout << "2 - 1112\n";
        cout << "3 - 1113\n";
        cout << "4 - 1114\n";
        cout << "5 - 1115\n";
        cout << "6 - 1116\n";
        cout << "7 - 1117\n";
        cout << "8 - 1118\n";
        cout << "9 - 1119\n";
        cout << "10 - 1120\n";
        cout << "11 - E1\n";
        cout << "12 - E2\n";
        cout << "Opção: ";
        cin >> opcao;

        switch(opcao) {
            case 0:
                break;
            case 1: 
                questao1(); 
                break;
            case 2: 
                questao2(); 
                break;
            case 3: 
                questao3(); 
                break;
            case 4: 
                questao4(); 
                break;
            case 5: 
                questao5(); 
                break;
            case 6: 
                questao6(); 
                break;
            case 7: 
                questao7(); 
                break;
            case 8: 
                questao8(); 
                break;
            case 9: 
                questao9();
                break;
            case 10: 
                questao10(); 
                break;
            case 11: 
                extra1(); 
                break;
            case 12: 
                extra2(); 
                break;
            default: 
                cout << "Opção inválida\n"; 
                break;
        }
    }
    return 0;
}