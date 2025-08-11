//Silas Hoffmann Reis Viana
//26/02/25
#include <stdio.h>

void parImpar(int* num){
    if ((*num%2)==0){
        printf ("Esse numero e par");
    } else if ((*num%2)==1){
        printf ("Esse numero e impar");
    }
}

void posNeg(int* num){
    if (*num>0){
        printf (" e positivo\n");
    } else if (*num<0){
        printf (" e negativo\n");
    } else if (*num==0){
        printf("\n");
    }
}

int main (){

    printf ("Silas Hoffmann Reis Viana - 26/02/25\n");//identificacao
    
    int num=0;
    printf ("digite o numero inteiro: ");
    scanf("%d",&num);
    parImpar(&num);
    posNeg(&num);

    return 0;
}