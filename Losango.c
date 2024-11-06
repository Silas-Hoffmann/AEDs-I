#include <stdio.h>

void enunciado (){
    printf ("Escrever um programa que recebe um inteiro positivo não nulo imprime um triângulo losango formado apenas por símbolos de asterisco (“*”) e de espaço (“ ”)");
    printf ("\n---------------------------------\n");
    printf ("\nResposta: \n");
}

int funcao (int num){
    for (int j=1;j<=num;j++){
        for (int i=1;i<=num+j-1;i++){
            if (i<=num-j){
                printf (" ");
            }else {
                printf ("*");
            }
        }
        printf ("\n");
    }
    for (int j=num-1;j>=1;j--){
        for (int i=1;i<=num+j-1;i++){
            if (i<=num-j){
                printf (" ");
            }else {
                printf ("*");
            }
        }
        printf ("\n");
    }
}

int main (){
    enunciado ();
    int num;
    printf ("tamanho do losango: ");
    scanf ("%d",&num);
    funcao (num);
}