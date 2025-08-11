//Silas Hoffmann Reis Viana - 881336
#include <stdio.h>
int main (){
    printf ("Silas Hoffmann Reis Viana - 881336\n");

    double base=0, alt=0;
    
    printf ("Digite o tamanho da base: ");
    scanf ("%lf",&base);

    printf ("Digite o tamanho da altura: ");
    scanf ("%lf",&alt);
    getchar();

    printf ("\nA area de um triangulo duas vezes maior é = %.2lf",base*alt);
    
    printf ("\nAperte ENTER para encerrar o programa");
    getchar();
    return 0;
}