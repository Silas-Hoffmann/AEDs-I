#include <stdio.h>
void enunciado (){
    printf ("Implemente um função que receba um inteiro N e retorne o resultado da seguinte expressão:");
    printf ("\nS = 1+1/1!+1/2!+1/3!+...+1/N!");
    printf ("\n---------------------------------\n");
    printf ("\nResposta: \n");
}
double funcao(int n){
    double s=1.0, fat=1.0;
    for (int i=1;i<=n;i++){
        fat = fat*i;
        s += 1/fat;
    }
    return s;
}


int main(){
    enunciado ();
    int n;
    scanf ("%d",&n);
    printf ("%.2lf",funcao(n));
}