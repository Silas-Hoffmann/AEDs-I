//Silas Hoffmann Reis Viana - 881336
#include <stdio.h>
#include <math.h>
int main (){
    printf ("Silas Hoffmann Reis Viana - 881336\n\n");

    double lado=0, res=0;

    printf ("Digite o lado do cubo: ");
    scanf ("%lf",&lado);
    getchar();

    lado=lado*4;
    res=lado*lado*lado;
    printf ("o volume do cubo com lado %.2lf = %.2lf",lado,res);
        
    printf ("\n\nAperte ENTER para encerrar o programa");
    getchar();
    return 0;
}
