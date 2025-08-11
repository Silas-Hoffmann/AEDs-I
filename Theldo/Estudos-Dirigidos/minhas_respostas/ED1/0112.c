//Silas Hoffmann Reis Viana - 881336
#include <stdio.h>
int main (){
    printf ("Silas Hoffmann Reis Viana - 881336");
    double num=0, num2=0, per=0;
    printf ("\nDigite o numero: ");
    scanf ("%lf",&num);
    getchar();
    num2=num/2;
    per=num2*4;
    num2=num2*num2;
    printf ("\nO quadrado de lado %.2lf tem area = %.2lf e perimetro = %.2lf\n",num/2.0,num2,per);

    printf ("Aperte ENTER para encerrar o programa");
    getchar();
    return 0;
}