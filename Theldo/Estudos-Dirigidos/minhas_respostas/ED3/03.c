#include <stdio.h>

// cada um dos metodos possui pelo menos 1 funcao para auxiliar e fracionar o processo
// Ocorre a reutilizacao de funcoes

void retirarN (char *texto){ // retira o \n do final das strings, evitando a utilização da biblioteca string.h
    while (*texto!='\n'){
        //printf ("%c",*texto);
        texto++;
    }
    *texto='\0';
}

void retirarN2 (char *texto, int *final){ // Funcao que retira o /n e tira a necessidade de usar a biblioteca string.h
    while (*texto!='\n'){
        *final=*final+1;
        texto++;
    }
    *texto='\0';
}

void contadorLetras1(char *texto, int *contador){
    while (*texto!='\0'){
        *contador=*contador+1;
        //printf ("%c %d\n", *texto, *contador);
        texto++;
    }
}

void contadorLetras2(char *texto){
    printf ("Letras maiusculas maiores que K: "); // impressao incompleta e padrao
    while (*texto!='\0'){ // enquanto nao acabar a palavra
        if (*texto<91){ // se a letra for maiuscula
            if (*texto>'K'){ // compara a letra
                printf ("%c ",*texto); // imprime a letra
            }
        }
        texto++; // pula para o proximo endereco e continua a leitura da palavra
    } // fim do while
    printf ("\n");
}

void contadorLetras3(char *texto){
    printf ("Letras minusculas menores que K: "); // impressao incompleta e padrao
    while (*texto!='\0'){ // enquanto nao acabar a palavra
        if (*texto>96){ // se a letra for minuscula
            if (*texto<'k'){ // compara a letra
                printf ("%c ",*texto); // imprime a letra
            }
        }
        texto++; // pula para o proximo endereco e continua a leitura da palavra
    } // fim do while
    printf ("\n");
}

void contadorLetras4(char *texto){
    printf ("Letras minusculas maiores que K: "); // impressao incompleta e padrao
    while (*texto!='\0'){ // enquanto nao acabar a palavra
        if (*texto>96){ // se a letra for minuscula
            if (*texto>'k'){ // compara a letra
                printf ("%c ",*texto); // imprime a letra
            }
        }
        texto--; // pula para o endereco anterior e continua a leitura da palavra
    } // fim do while
    printf ("\n");
}

void contadorLetras5(char *texto){
    printf ("letras no texto: ");
    while (*texto!='\0'){
        if ((*texto>64&&*texto<90) || (*texto>96&&*texto<123)){ // se for uma letra
            printf("%c ",*texto);
        }
        texto++;
    }
    printf ("\n");
}

void contadorLetras6(char *texto){
    int i=1;
    printf ("letras nas posicoes pares: ");
    while (*texto!='\0'){
        if (i%2==0){
            printf("%c ",*texto);
        }
        i=i+1;
        texto++;
    }
    printf ("\n");
}

void contadorLetras7(char *texto){
    while (*texto!='\0'){
        if ((*texto>64 && *texto<91) || (*texto>96 && *texto<123)){
            if (*texto%2==0){
                printf ("%c ",*texto);
            }
        }
        texto++;
    }
    printf ("\n");
}

void comparaNumeros1(int m, int n, int x, int *arr){
    for (int i=0;i<x;i++){
        if (*(arr+i)>m && *(arr+i)<n){
            printf ("%d está entre %d e %d", *(arr+i), m, n);
            if (*(arr+i)%3==0){
                printf(" e e multiplo de 3");
            }
            printf ("\n");
        }
    }
}

void comparaNumeros2(int m, int n, int x, int *arr){
    for (int i=0;i<x;i++){
        if (*(arr+i)>m && *(arr+i)<n){
            if ( (*(arr+i)%4==0) && (*(arr+i)%3!=0) ){
                printf("%d está entre %d e %d e multiplo de 4 e nao e multiplo de 3", *(arr+i), m, n);
            }
            printf ("\n");
        }
    }
}

void comparaNumeros3(double m, double n, int x, double *arr) {
    for (int i = 0; i < x; i++) {
        if (*(arr + i) >= m && *(arr + i) <= n) {
            if (*(arr + i) < 5) {
                int inteiro = (int) *(arr + i);
                if (inteiro % 2 == 0) {
                    printf("%.2lf está entre %.2lf e %.2lf, tem parte inteira par e menor que 5\n", *(arr + i), m, n);
                }
            }
        }
    }
}

void comparaNumeros4(double m, double n, int x, double *arr) {
    int count = 0;
    for (int i = 0; i < x; i++) {
        double fracao = arr[i] - (int)arr[i];
        if (fracao > m && fracao < n) {
            printf("%.2lf tem parte fracionária %.2lf, que está no intervalo ]%.2lf:%.2lf[\n", 
                   arr[i], fracao, m, n);
            count++;
        }
    }
    printf("Total de números com parte fracionária no intervalo: %d\n", count);
}

void metoth0310(){
    char texto[20];
    int contador=0;
    printf ("Digite o texto: ");
    fgets(texto,20,stdin);
    retirarN(&texto[0]);
    contadorLetras1(&texto[0],&contador);
    printf ("A palavra %s possui %d letras\n", texto, contador);
}

void metoth0311(){
    char texto[50];
    printf ("Digite o texto: ");
    fgets(texto,50,stdin); // le a palavra
    retirarN(&texto[0]); // retira o /n
    contadorLetras2(&texto[0]); // confere as letras
}

void metoth0312(){
    char texto[50];
    printf ("Digite o texto: ");
    fgets(texto,50,stdin); // le a palavra
    retirarN(&texto[0]); // retira o /n
    contadorLetras3(&texto[0]); // confere as letras
}

void metoth0313(){
    char texto[50];
    int final=0;
    printf ("Digite o texto: ");
    fgets(texto,50,stdin); // le a palavra
    retirarN2(&texto[0],&final); // retira o /n e ver o final da palavra
    contadorLetras4(&texto[final-1]); // confere as letras
}

void metoth0314(){
    char texto[50];
    printf ("Digite o texto: ");
    fgets(texto,50,stdin); // le a palavra
    retirarN(&texto[0]); // retira o /n e ver o final da palavra
    contadorLetras5(&texto[0]); // confere as letras
}

void metoth0315(){
    char texto[50];
    printf ("Digite o texto: ");
    fgets(texto,50,stdin); // le a palavra
    retirarN(&texto[0]); // retira o /n e ver o final da palavra
    contadorLetras6(&texto[0]); // confere as letras
}

void metoth0316(){
    char texto[50];
    printf ("Digite o texto: ");
    fgets(texto,50,stdin); // le a palavra
    retirarN(&texto[0]); // retira o /n e ver o final da palavra
    contadorLetras7(&texto[0]); // confere as letras
}

void metoth0317(){
    int m=0, n=(int)0;
    printf ("Digite o intervalo: ");
    scanf ("%d",&m);
    scanf ("%d",&n);

    int x=0;
    printf ("Digie a quantidade de numeros: ");
    scanf ("%d",&x);

    int arr[x];

    printf ("Digite os numeros: ");
    for (int i=0 ; i<x ; i++){
        scanf ("%d",&arr[i]);
    }
    comparaNumeros1(m,n,x,&arr[0]);
}

void metoth0318(){
    int m=0, n=(int)0;
    printf ("Digite o intervalo: ");
    scanf ("%d",&m);
    scanf ("%d",&n);
    int x=0;
    printf ("Digie a quantidade de numeros: ");
    scanf ("%d",&x);
    int arr[x];
    printf ("Digite os numeros: ");
    for (int i=0 ; i<x ; i++){
        scanf ("%d",&arr[i]);
    }
    comparaNumeros2(m,n,x,&arr[0]);
}

void metoth0319(){
    double m = 0, n = 0;
    printf("Digite o intervalo: ");
    scanf("%lf", &m);
    scanf("%lf", &n);
    int x = 0;
    printf("Digite a quantidade de números: ");
    scanf("%d", &x);
    double arr[x];
    printf("Digite os números: ");
    for (int i = 0; i < x; i++) {
        scanf("%lf", &arr[i]);
    }
    comparaNumeros3(m, n, x, arr);
}

void metoth0320(){
    double m = 0, n = 0;
    printf("Digite o intervalo: ");
    scanf("%lf", &m);
    scanf("%lf", &n);
    int x = 0;
    printf("Digite a quantidade de números: ");
    scanf("%d", &x);
    double arr[x];
    printf("Digite os números: ");
    for (int i = 0; i < x; i++) {
        scanf("%lf", &arr[i]);
    }
    comparaNumeros4(m, n, x, arr);
}

int main (){
    int opc=-1;
    
    printf ("Escolha o metodo:\n");
    for (int i=0;i<11;i++){
        printf ("0%d\n",310+i);
    }

    scanf ("%d",&opc);
    getchar();

    switch (opc) {
        case 310:
            metoth0310();
            break;
        case 311:
            metoth0311();
            break;
        case 312:
            metoth0312();
            break;
        case 313:
            metoth0313();
            break;
        case 314:
            metoth0314();
            break;
        case 315:
            metoth0315();
            break;
        case 316:
            metoth0316();
            break;
        case 317:
            metoth0317();
            break;
        case 318:
            metoth0318();
            break;
        case 319:
            metoth0319();
            break;
        case 320:
            metoth0320();
            break;
    }
}