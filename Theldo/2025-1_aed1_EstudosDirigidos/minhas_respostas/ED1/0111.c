//Silas Hoffmann Reis Viana - 881336
#include <stdio.h>
int main (){
    printf ("Silas Hoffmann Reis Viana - 881336");
    int num=0, num2=0;
    printf ("\nDigite o numero: ");
    scanf ("%d",&num);
    getchar();
    num2=num*3;
    num2=num2*num2;
    printf ("\nO quadrado de lado %d tem area = %d\n",num*3,num2);

    printf ("Aperte ENTER para encerrar o programa");
    getchar();
    return 0;
}