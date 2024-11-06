#include <stdio.h>
void enunciado (){
    printf ("Escreva um função recursiva que receba um número inteiro e imprima esse número invertido.\n");
    printf ("Exemplo: ao receber 123 a função deve imprimir 321");
    printf ("\n---------------------------------\n");
    printf ("\nResposta: \n");
}
int inverter (int num, int invert){
    if (num==0){
        return invert;
    }
    return inverter (num/10, invert*10+num%10);
}

int main (){
    enunciado();
    int n;
    scanf ("%d",&n);
    printf ("%d",inverter (n, 0));
}