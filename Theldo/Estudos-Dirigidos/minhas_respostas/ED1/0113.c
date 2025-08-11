//Silas Hoffmann Reis Viana - 881336
#include <stdio.h>
int main (){
    printf ("Silas Hoffmann Reis Viana - 881336\n");

    double larg=0, comp=0;
    printf ("\nDigite a largura: ");
    scanf ("%lf",&larg);
    printf ("Digite o comprimento: ");
    scanf ("%lf",&comp);
    getchar();

    printf ("\nA area de um retangulo duas vezes maior é = %.2lf",(comp*larg)*2);

    printf ("\nAperte ENTER para encerrar o programa");
    getchar();
    return 0;
}