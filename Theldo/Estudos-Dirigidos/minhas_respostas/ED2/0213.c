//Silas Hoffmann Reis Viana
//26/02/25
#include <stdio.h>

void pertence(int* num){
    if (*num>20 && *num<55){
        printf ("%d pertence ao intervalo aberto entre (20:55)", *num);
    } else if (*num<=20 || *num>=55){
        printf ("%d nao pertence ao intervalo aberto entre (20:55)", *num);
    }
    printf ("\n");
}

int main (){

    printf ("Silas Hoffmann Reis Viana - 26/02/25\n"); // identificacao
    
    int num=0;
    printf ("digite o numero inteiro: ");
    scanf("%d",&num);
    pertence(&num);
    
    return 0;
}