#include <stdio.h>
void enunciado (){
    printf ("Faça uma sub-rotina que receba como parâmetro um inteiro no intervalo de 1 a 9 e mostre a seguinte tabela de multiplicação (no exemplo, n = 9):");
    printf ("\n1\n2 4\n3 6 9\n4 8 12 16\n5 10 15 20 25\n6 12 18 24 30 36\n7 14 21 28 35 42 49\n8 16 24 32 40 48 56 64\n9 18 27 36 45 54 63 72 81\n");
    printf ("\n---------------------------------\n");
    printf ("\nResposta: \n");
}
void piramide (int n){
    for (int i=1;i<=n;i++){
        printf ("%d ",i*n);
    }
}

int main(){
    enunciado();
    int n;
    printf ("\nValor de n: ");
    scanf ("%d",&n);
    for (int i=1;i<=n;i++){
        piramide (i);
        printf ("\n");
    }
}