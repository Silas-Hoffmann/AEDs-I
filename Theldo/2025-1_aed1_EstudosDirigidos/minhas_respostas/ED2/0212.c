//Silas Hoffmann Reis Viana
//26/02/25
#include <stdio.h>

void parImpar(int* num){
    if ((*num%2)==0){
        printf ("Esse numero e par");
    } else if ((*num%2)==1||(*num%2)==-1){
        printf ("Esse numero e impar");
    }
}

void maiorMenor(int* num){
    if (*num>25){
        printf (" e maior de 25");
    } else if (*num<-25){
        printf (" e menor de -25");
    }
    printf("\n");
}

int main (){

    printf ("Silas Hoffmann Reis Viana - 26/02/25\n");//identificacao
    
    int num=0;
    printf ("digite o numero inteiro: ");
    scanf("%d",&num);
    parImpar(&num);
    maiorMenor(&num);

    return 0;
}