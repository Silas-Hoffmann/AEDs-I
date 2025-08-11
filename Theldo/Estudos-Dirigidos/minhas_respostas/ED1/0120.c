//Silas Hoffmann Reis Viana - 881336
#include <stdio.h>
#include <math.h>
int main (){
    printf ("Silas Hoffmann Reis Viana - 881336\n\n");

    double raio=0, res=0;

    printf ("Digite o valor do raio: ");
    scanf ("%lf",&raio);
    getchar();

    raio=(raio*5)/8;
    res=(raio*raio*raio)*M_PI*4/3; // utilizando a math.h e necessario modificar o codigo de compilacao: gcc -o 0119.exe 0119.c -lm

    printf ("A esfera de raio %.2lf tem volume = %.2lf",raio,res);
        
    printf ("\n\nAperte ENTER para encerrar o programa");
    getchar();
    return 0;
}
