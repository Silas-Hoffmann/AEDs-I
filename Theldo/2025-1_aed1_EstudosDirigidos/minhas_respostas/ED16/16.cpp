#include <iostream>
using namespace std;

/*------------------------------------------
--------Funcoes Auxiliares (07 a E2)--------
------------------------------------------*/
typedef int* ref_intArray;

int intArray_cmp(ref_intArray p, int tamP, ref_intArray q, int tamQ);
ref_intArray intArray_cat(ref_intArray p, int tamP, ref_intArray q, int tamQ);
ref_intArray intArray_seek(ref_intArray a, int tam, int x);
ref_intArray intArray_sub(ref_intArray a, int tam, int start, int size);
ref_intArray intArray_merge(ref_intArray p, int tamP, ref_intArray q, int tamQ);
ref_intArray intArray_mergeDown(ref_intArray p, int tamP, ref_intArray q, int tamQ);

int intArray_cmp(ref_intArray p, int tamP, ref_intArray q, int tamQ) {
    int minTam = (tamP < tamQ) ? tamP : tamQ;
    for (int i = 0; i < minTam; i++) {
        if (p[i] != q[i]) return p[i] - q[i];
    }
    return tamP - tamQ;
}

ref_intArray intArray_cat(ref_intArray p, int tamP, ref_intArray q, int tamQ) {
    int* r = new int[tamP + tamQ];
    for (int i = 0; i < tamP; i++) r[i] = p[i];
    for (int i = 0; i < tamQ; i++) r[tamP + i] = q[i];
    return r;
}

ref_intArray intArray_seek(ref_intArray a, int tam, int x) {
    for (int i = 0; i < tam; i++) {
        if (a[i] == x) return a + i;
    }
    return NULL;
}

ref_intArray intArray_sub(ref_intArray a, int tam, int start, int size) {
    if (start < 0 || start + size > tam || size <= 0) return NULL;
    int* sub = new int[size];
    for (int i = 0; i < size; i++) sub[i] = a[start + i];
    return sub;
}

ref_intArray intArray_merge(ref_intArray p, int tamP, ref_intArray q, int tamQ) {
    int* r = new int[tamP + tamQ];
    int i = 0, j = 0, k = 0;
    while (i < tamP || j < tamQ) {
        if (i < tamP) r[k++] = p[i++];
        if (j < tamQ) r[k++] = q[j++];
    }
    return r;
}

ref_intArray intArray_mergeDown(ref_intArray p, int tamP, ref_intArray q, int tamQ) {
    int* r = new int[tamP + tamQ];
    int i = 0, j = 0, k = 0;

    while (i < tamP && j < tamQ) {
        if (p[i] > q[j]) r[k++] = p[i++];
        else r[k++] = q[j++];
    }
    while (i < tamP) r[k++] = p[i++];
    while (j < tamQ) r[k++] = q[j++];

    return r;
}

/*------------------------------------------
--------Funcoes Auxiliares (01 a 06)--------
------------------------------------------*/
int* array_push_back(int* a1, int value, int tam) { // acrescentar valor ao final de um arranjo
    int* a2 = new int[tam + 1];
    for (int i = 0; i < tam; i++) {
        a2[i] = a1[i];
    }
    a2[tam] = value;
    return a2;
}

int* array_pop_back ( int *a1, int tam ){ // remover valor do final de um arranjo, por m
    int* a2 = new int[tam - 1];
    for (int i = 0; i < tam - 1; i++) {
        a2[i] = a1[i];
    }
    return a2;
}

int* array_push_front (int *a1, int value, int tam ){ // acrescentar valor ao início de um arranjo
    int* a2 = new int[tam + 1];
    for (int i = 1; i <= tam; i++) {
        a2[i] = a1[i-1];
    }
    a2[0] = value;
    return a2;
}

int* array_pop_front ( int *a1, int tam ){ // remover valor do início de um arranjo, po
    int* a2 = new int[tam - 1];
    for (int i = 0; i < tam - 1; i++) {
        a2[i] = a1[i+1];
    }
    return a2;
}

int* array_push_mid ( int *a1, int value, int tam ){ // acrescentar valor no meio (aproximadamente) de um arranjo
    int meio = tam / 2;
    int* a2 = new int[tam + 1];
    for (int i = 0; i < meio; i++) {
        a2[i] = a1[i];
    }
    a2[meio] = value;
    for (int i = meio; i < tam; i++) {
        a2[i + 1] = a1[i];
    }
    return a2;
}

int* array_pop_mid ( int *a1, int tam ){ // remover valor do meio (aproximadamente) de um arranj
    if (tam < 2) {
        return a1;
    }
    int meio = tam / 2;
    int* a2 = new int[tam-1];
    for (int i = 0; i < meio; i++) {
        a2[i] = a1[i];
    }
    for (int i = meio; i < tam; i++) {
        a2[i] = a1[i+1];
    }
    return a2;
}

/*------------------------------------------
-------------Funcoes Principais-------------
------------------------------------------*/
void q1601 (){
    int tam;
    cout << "tamanho do array: ";
    cin >> tam;
    
    int a1[tam];
    int value;
    
    cout << "digite o array: ";
    for (int i=0;i<tam;i++){
        cin >> a1[i];
    }
    
    cout << "digite o valor final: ";
    cin >> value;
    cin.ignore();
    
    int* a2 = array_push_back (a1, value, tam);
    cout << "Novo array: ";
    for (int i=0;i<tam+1;i++){
        cout << a2[i] << " ";
    }
    cout << endl;
    delete[] a2;
}

void q1602 (){
    int tam;
    cout << "tamanho do array: ";
    cin >> tam;
    
    int a1[tam];
    int value;
    
    cout << "digite o array: ";
    for (int i=0;i<tam;i++){
        cin >> a1[i];
    }
    int* a2 = array_pop_back (a1, tam);
    cout << "Novo array: ";
    for (int i=0;i<tam-1;i++){
        cout << a2[i] << " ";
    }
    cout << endl;
    delete[] a2;
}

void q1603 (){
    int tam;
    cout << "tamanho do array: ";
    cin >> tam;
    
    int a1[tam];
    int value;
    
    cout << "digite o array: ";
    for (int i=0;i<tam;i++){
        cin >> a1[i];
    }
    
    cout << "digite o valor inicial: ";
    cin >> value;
    cin.ignore();
    
    int* a2 = array_push_front (a1, value, tam);
    cout << "Novo array: ";
    for (int i=0;i<tam+1;i++){
        cout << a2[i] << " ";
    }
    cout << endl;
    delete[] a2;
}

void q1604 (){
    int tam;
    cout << "tamanho do array: ";
    cin >> tam;
    
    int a1[tam];
    int value;
    
    cout << "digite o array: ";
    for (int i=0;i<tam;i++){
        cin >> a1[i];
    }
    int* a2 = array_pop_front (a1, tam);
    cout << "Novo array: ";
    for (int i=0;i<tam-1;i++){
        cout << a2[i] << " ";
    }
    cout << endl;
    delete[] a2;
}

void q1605 (){
    int tam;
    cout << "tamanho do array: ";
    cin >> tam;
    
    int a1[tam];
    int value;
    
    cout << "digite o array: ";
    for (int i=0;i<tam;i++){
        cin >> a1[i];
    }
    
    cout << "digite o valor do meio: ";
    cin >> value;
    cin.ignore();
    
    int* a2 = array_push_mid (a1, value, tam);
    cout << "Novo array: ";
    for (int i=0;i<tam+1;i++){
        cout << a2[i] << " ";
    }
    cout << endl;
    delete[] a2;
}

void q1606 (){
    int tam;
    cout << "tamanho do array: ";
    cin >> tam;
    
    int a1[tam];
    int value;
    
    cout << "digite o array: ";
    for (int i=0;i<tam;i++){
        cin >> a1[i];
    }
    int* a2 = array_pop_mid (a1, tam);
    cout << "Novo array: ";
    for (int i=0;i<tam-1;i++){
        cout << a2[i] << " ";
    }
    cout << endl;
    delete[] a2;
}

void q1607() {
    int tam1, tam2;
    cout << "tamanho do primeiro array: ";
    cin >> tam1;
    int a1[tam1];
    cout << "digite o primeiro array: ";
    for (int i = 0; i < tam1; i++) cin >> a1[i];

    cout << "tamanho do segundo array: ";
    cin >> tam2;
    int a2[tam2];
    cout << "digite o segundo array: ";
    for (int i = 0; i < tam2; i++) cin >> a2[i];

    int cmp = intArray_cmp(a1, tam1, a2, tam2);
    cout << "Resultado da comparacao: " << cmp << endl;
}

void q1608() {
    int tam1, tam2;
    cout << "tamanho do primeiro array: ";
    cin >> tam1;
    int a1[tam1];
    cout << "digite o primeiro array: ";
    for (int i = 0; i < tam1; i++) cin >> a1[i];

    cout << "tamanho do segundo array: ";
    cin >> tam2;
    int a2[tam2];
    cout << "digite o segundo array: ";
    for (int i = 0; i < tam2; i++) cin >> a2[i];

    int* a3 = intArray_cat(a1, tam1, a2, tam2);
    cout << "Array concatenado: ";
    for (int i = 0; i < tam1 + tam2; i++) cout << a3[i] << " ";
    cout << endl;
    delete[] a3;
}

void q1609() {
    int tam, valor;
    cout << "tamanho do array: ";
    cin >> tam;
    int a[tam];
    cout << "digite o array: ";
    for (int i = 0; i < tam; i++) cin >> a[i];

    cout << "valor a ser procurado: ";
    cin >> valor;

    int* p = intArray_seek(a, tam, valor);
    if (p != NULL)
        cout << "Valor encontrado na posicao: " << (p - a) << endl;
    else
        cout << "Valor nao encontrado" << endl;
}

void q1610() {
    int tam, ini, qtd;
    cout << "tamanho do array: ";
    cin >> tam;
    int a[tam];
    cout << "digite o array: ";
    for (int i = 0; i < tam; i++) cin >> a[i];

    cout << "posicao inicial: ";
    cin >> ini;
    cout << "quantidade: ";
    cin >> qtd;

    int* sub = intArray_sub(a, tam, ini, qtd);
    if (sub != NULL) {
        cout << "Subarray: ";
        for (int i = 0; i < qtd; i++) cout << sub[i] << " ";
        cout << endl;
        delete[] sub;
    } else {
        cout << "Intervalo invalido" << endl;
    }
}

void q16E1() {
    int tam1, tam2;
    cout << "tamanho do primeiro array: ";
    cin >> tam1;
    int a1[tam1];
    cout << "digite o primeiro array: ";
    for (int i = 0; i < tam1; i++) cin >> a1[i];

    cout << "tamanho do segundo array: ";
    cin >> tam2;
    int a2[tam2];
    cout << "digite o segundo array: ";
    for (int i = 0; i < tam2; i++) cin >> a2[i];

    int* a3 = intArray_merge(a1, tam1, a2, tam2);
    cout << "Array intercalado: ";
    for (int i = 0; i < tam1 + tam2; i++) cout << a3[i] << " ";
    cout << endl;
    delete[] a3;
}

void q16E2() {
    int tam1, tam2;
    cout << "tamanho do primeiro array: ";
    cin >> tam1;
    int a1[tam1];
    cout << "digite o primeiro array: ";
    for (int i = 0; i < tam1; i++) cin >> a1[i];

    cout << "tamanho do segundo array: ";
    cin >> tam2;
    int a2[tam2];
    cout << "digite o segundo array: ";
    for (int i = 0; i < tam2; i++) cin >> a2[i];

    int* a3 = intArray_mergeDown(a1, tam1, a2, tam2);
    cout << "Array mesclado em ordem decrescente: ";
    for (int i = 0; i < tam1 + tam2; i++) cout << a3[i] << " ";
    cout << endl;
    delete[] a3;
}

int main (){
    int opc=-1;
    while (opc!=0){
        cout << "Escolha a opcao:\n";
        for (int i = 1; i < 10; i++) {
            cout << i << " - q160" << i << endl;
        }
        cout <<"10 - q1610"<< endl;
        cout <<"11 - q16E1"<< endl;
        cout <<"12 - q16E2"<< endl;
        cin >> opc;
        cin.get();
        
        switch (opc){
            case 0:
                break;
            case 1:
                q1601 ();
                break;
            case 2:
                q1602 ();
                break;
            case 3:
                q1603 ();
                break;
            case 4:
                q1604 ();
                break;
            case 5:
                q1605 ();
                break;
            case 6:
                q1606 ();
                break;
            case 7:
                q1607 ();
                break;
            case 8:
                q1608 ();
                break;
            case 9:
                q1609 ();
                break;
            case 10:
                q1610 ();
                break;
            case 11:
                q16E1 ();
                break;
            case 12:
                q16E2 ();
                break;
            default:
                cout << "ERRO";
                break;
        }
    }
    return 0;
}