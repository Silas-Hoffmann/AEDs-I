//Silas Hoffmann Reis Viana - 881336
#include <stdio.h>
#include <math.h>
int main (){
    printf ("Silas Hoffmann Reis Viana - 881336\n");

    double lado, alt, per, area;

    printf ("\nDigite o lado: ");
    scanf ("%lf",&lado);
    getchar();
    lado=lado/3;
    alt = lado * sqrt(3)/2; // utilizando a math.h e necessario modificar o codigo de compilacao: gcc -o 0116.exe 0116.c -lm
    printf ("Altura do triangulo (1/3): %.2lf",alt);
    printf ("\nArea do triangulo (1/3): %.2lf",sqrt(3)/4*lado*lado);
    printf ("\nPerimetro do triangulo (1/3): %.2lf",lado*3);
        
    printf ("\n\nAperte ENTER para encerrar o programa");
    getchar();
    return 0;
}
