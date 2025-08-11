//Silas Hoffmann Reis Viana - 881336
#include <stdio.h>
#include <math.h>
int main (){
    printf ("Silas Hoffmann Reis Viana - 881336\n\n");

    double comp=0, larg=0, alt=0, res=0;

    printf ("Digite o comprimento do paralelepipedo: ");
    scanf ("%lf",&comp);
    printf ("Digite a largura do paralelepipedo: ");
    scanf ("%lf",&larg);
    printf ("Digite a altura do paralelepipedo: ");
    scanf ("%lf",&alt);
    getchar();

    comp=comp*5;
    larg=larg*5;
    alt=alt*5;
    res=comp*larg*alt;

    printf ("O paralelepipedo de comp = %.2lf | larg = %.2lf | alt = %.2lf | tem volume = %.2lf",comp,larg,alt,res);
        
    printf ("\n\nAperte ENTER para encerrar o programa");
    getchar();
    return 0;
}
