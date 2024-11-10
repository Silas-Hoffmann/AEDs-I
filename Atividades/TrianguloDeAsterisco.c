#include <stdio.h>
void enunciado (){
printf ("Escrever um programa que recebe um inteiro positivo não nulo imprime um triângulo retângulo formado apenas por símbolos de asterisco (“*”) \ne de espaço (“ ”) como no exemplo a seguir (para i = 5):");
printf ("\n*\n**\n***\n****\n*****\n");
printf ("\n---------------------------------\n");
printf ("\nResposta: \n");
}
int funcao (int num){
    int n=1;
    for (int i=1;i<=num;i++){
        for (int j=1;j<=n;j++){
            printf ("*");
        }
        printf ("\n");
        if (n<=num){
            n++;
        }
    }
}

int main (){
    enunciado ();
    int num;
    printf ("Tamanho do triângulo: ");
    scanf ("%d",&num);
    funcao (num);
}