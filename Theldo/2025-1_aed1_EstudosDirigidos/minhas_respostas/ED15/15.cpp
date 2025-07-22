#include <iostream>
#include <cstring>
using namespace std;

/*----------------
Funcoes Auxiliares
----------------*/
char* str_push_back ( char *s1, char c ){
    int tam = strlen(s1);
    char* s2 = new char[tam + 2];
    for (int i = 0; i < tam; i++) {
        s2[i] = s1[i];
    }
    s2[tam] = c;
    s2[tam + 1] = '\0';
    return s2;
}

char* str_push_front ( char *s1, char c ){
    int tam = strlen(s1);
    char* s2 = new char[tam + 2];
    s2[0] = c;
    for (int i = 1; i <= tam; i++) {
        s2[i] = s1[i-1];
    }
    s2[tam + 1] = '\0';
    return s2;
}

char* str_push_mid(char* s1, char c) {
    int tam = strlen(s1);
    if (tam < 2) {
        return s1;
    }
    int meio = tam / 2;
    char* s2 = new char[tam + 2];
    for (int i = 0; i < meio; i++) {
        s2[i] = s1[i];
    }
    s2[meio] = c;
    for (int i = meio; i < tam; i++) {
        s2[i + 1] = s1[i];
    }
    s2[tam + 1] = '\0';
    return s2;
}

char* str_pop_back(char* s1) {
    int tam = strlen(s1);
    if (tam == 0) {
        return s1;
    }
    char* s2 = new char[tam];
    for (int i = 0; i < tam - 1; i++) {
        s2[i] = s1[i];
    }
    s2[tam - 1] = '\0';
    return s2;
}

char* str_pop_front(char* s1) {
    int tam = strlen(s1);
    if (tam == 0) {
        return s1;
    }
    char* s2 = new char[tam];
    for (int i = 0; i < tam - 1; i++) {
        s2[i] = s1[i+1];
    }
    s2[tam - 1] = '\0';
    return s2;
}

char* str_pop_mid(char* s1) {
    int tam = strlen(s1);
    if (tam < 2) {
        return s1;
    }
    int meio = tam / 2;
    char* s2 = new char[tam-1];
    for (int i = 0; i < meio; i++) {
        s2[i] = s1[i];
    }
    for (int i = meio; i < tam; i++) {
        s2[i] = s1[i+1];
    }
    s2[tam] = '\0';
    return s2;
}

char* str_insert(char* s1, char c, int index) {
    int tam = strlen(s1);
    if (index < 0 || index > tam) {
        return s1;
    }
    char* s2 = new char[tam + 2];
    for (int i = 0; i < index; i++) {
        s2[i] = s1[i];
    }
    s2[index] = c;
    for (int i = index; i < tam; i++) {
        s2[i + 1] = s1[i];
    }
    s2[tam + 1] = '\0';
    return s2;
}

char* str_remove(char* s1, int index) {
    int tam = strlen(s1);
    if (index < 0 || index >= tam) {
        return s1;
    }
    char* s2 = new char[tam];
    for (int i = 0; i < index; i++) {
        s2[i] = s1[i];
    }
    for (int i = index + 1; i < tam; i++) {
        s2[i - 1] = s1[i];
    }
    s2[tam - 1] = '\0';
    return s2;
}

char* str_chr(char* s, char c) {
    while (*s != '\0') {
        if (*s == c) {
            return s;
        }
        s++;
    }
    return nullptr;
}

char* str_tok(char* s, char delimiter) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == delimiter) {
            char* token = new char[i + 1];
            for (int j = 0; j < i; j++) {
                token[j] = s[j];
            }
            token[i] = '\0';
            return token;
        }
        i++;
    }
    return nullptr;
}

char* str_prefix(char* prefix, char* s) {
    int tam_prefix = strlen(prefix);
    for (int i = 0; i < tam_prefix; i++) {
        if (s[i] != prefix[i]) {
            return nullptr;
        }
    }
    return s;
}

char* str_suffix(char* s, char* suffix) {
    int tam_s = strlen(s);
    int tam_suffix = strlen(suffix);
    if (tam_suffix > tam_s) {
        return nullptr;
    }
    for (int i = 0; i < tam_suffix; i++) {
        if (s[tam_s - tam_suffix + i] != suffix[i]) {
            return nullptr;
        }
    }
    return s + (tam_s - tam_suffix);
}

/*--------------------------------
Funcoes Principais de cada questao
--------------------------------*/
void q1501 (){
    char s1[100];
    char c;
    
    cout << "digite a string: ";
    cin.getline (s1,100);
    cout << "digite o caractere final: ";
    cin >> c;
    
    char* s2 = str_push_back (s1, c);
    cout << "Nova String: " << s2 << endl;
    delete[] s2;
}

void q1502 () {
    char s1[100];
    
    cout << "digite a string: ";
    cin.getline(s1, 100);
    
    char* resultado = str_pop_back(s1);
    cout << "Resultado: " << resultado << endl;
    delete[] resultado;
}

void q1503 () {
    char s1[100];
    char c;
    
    cout << "digite a string: ";
    cin.getline (s1,100);
    cout << "digite o caractere inicial: ";
    cin >> c;
    
    char* s2 = str_push_front (s1, c);
    cout << "Nova String: " << s2 << endl;
    delete[] s2;
}

void q1504 () {
    char s1[100];
    
    cout << "digite a string: ";
    cin.getline(s1, 100);
    
    char* resultado = str_pop_front(s1);
    cout << "Resultado: " << resultado << endl;
    delete[] resultado;
}

void q1505 () {
    char s1[100];
    char c;

    cout << "digite a string: ";
    cin.getline(s1, 100);
    cout << "digite o caractere do meio: ";
    cin >> c;

    char* s2 = str_push_mid(s1, c);
    cout << "Nova String: " << s2 << endl;
    if (strlen(s1) >= 2) {
        delete[] s2;
    }
}

void q1506 () {
    char s1[100];
    
    cout << "digite a string: ";
    cin.getline(s1, 100);
    
    char* resultado = str_pop_mid(s1);
    cout << "Resultado: " << resultado << endl;
    delete[] resultado;
}

void q1507() {
    char s1[100];
    char c;
    int index;

    cout << "digite a string: ";
    cin.getline(s1, 100);
    cout << "digite o caractere: ";
    cin >> c;
    cout << "digite a posicao: ";
    cin >> index;

    char* resultado = str_insert(s1, c, index);
    if (index >= 0 && index <= strlen(s1)) {
        cout << "Nova String: " << resultado << endl;
        delete[] resultado;
    } else {
        cout << "Indice invalido" << endl;
    }
}

void q1508() {
    char s1[100];
    int index;

    cout << "digite a string: ";
    cin.getline(s1, 100);
    cout << "digite a posicao: ";
    cin >> index;

    char* resultado = str_remove(s1, index);
    if (index >= 0 && index < strlen(s1)) {
        cout << "Nova String: " << resultado << endl;
        delete[] resultado;
    } else {
        cout << "Indice invalido" << endl;
    }
}

void q1509() {
    char s[100];
    char c;

    cout << "digite a string: ";
    cin.getline(s, 100);
    cout << "digite o caractere a ser procurado: ";
    cin >> c;

    char* resultado = str_chr(s, c);
    if (resultado != nullptr) {
        cout << "Caractere encontrado a partir de: " << resultado << endl;
    } else {
        cout << "Caractere nao encontrado" << endl;
    }
}

void q1510() {
    char s[100];
    char d;

    cout << "digite a string: ";
    cin.getline(s, 100);
    cout << "digite o delimitador: ";
    cin >> d;

    char* resultado = str_tok(s, d);
    if (resultado != nullptr) {
        cout << "Token encontrado: " << resultado << endl;
        delete[] resultado;
    } else {
        cout << "Delimitador nao encontrado" << endl;
    }
}

void q15E1() {
    char s[100];
    char prefix[100];

    cout << "digite a string: ";
    cin.getline(s, 100);
    cout << "digite o prefixo: ";
    cin.getline(prefix, 100);

    char* resultado = str_prefix(prefix, s);
    if (resultado != nullptr) {
        cout << "Prefixo encontrado: " << resultado << endl;
    } else {
        cout << "Prefixo nao encontrado" << endl;
    }
}

void q15E2() {
    char s[100];
    char suffix[100];

    cout << "digite a string: ";
    cin.getline(s, 100);
    cout << "digite o sufixo: ";
    cin.getline(suffix, 100);

    char* resultado = str_suffix(s, suffix);
    if (resultado != nullptr) {
        cout << "Sufixo encontrado: " << resultado << endl;
    } else {
        cout << "Sufixo nao encontrado" << endl;
    }
}

int main (){
    int opc=-1;
    while (opc!=0){
        cout << "Escolha a opcao:\n";
        for (int i = 1; i < 10; i++) {
            cout << i << " - q150" << i << endl;
        }
        cout <<"10 - q1510"<< endl;
        cout <<"11 - q15E1"<< endl;
        cout <<"12 - q15E2"<< endl;
        cin >> opc;
        cin.get();
        
        switch (opc){
            case 1:
                q1501 ();
                break;
            case 2:
                q1502 ();
                break;
            case 3:
                q1503 ();
                break;
            case 4:
                q1504 ();
                break;
            case 5:
                q1505 ();
                break;
            case 6:
                q1506 ();
                break;
            case 7:
                q1507 ();
                break;
            case 8:
                q1508 ();
                break;
            case 9:
                q1509 ();
                break;
            case 10:
                q1510 ();
                break;
            case 11:
                q15E1 ();
                break;
            case 12:
                q15E2 ();
                break;
            default:
                cout << "ERRO";
                break;
        }
    }
    return 0;
}