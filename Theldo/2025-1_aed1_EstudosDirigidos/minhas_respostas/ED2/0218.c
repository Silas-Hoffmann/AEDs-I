//Silas Hoffmann Reis Viana
//26/02/25
#include <stdio.h>

void numComp (double* num1, double* num2){
    if (*num1==(*num2)){
        printf ("%.2lf e %.2lf sao iguais",*num1, *num2);
    }else if (*num1>*num2){
        printf ("%.2lf e maior que %.2lf",*num1, *num2);
    }else if (*num2>*num1){
        printf ("%.2lf e maior que %.2lf",*num2, *num1);
    }else {
        printf ("ERRO NA LEITURA DE DADOS");
    }
    printf ("\n");
}


int main (){

    printf ("Silas Hoffmann Reis Viana - 26/02/25\n\n");//identificacao

    double num1=(double)0.0, num2=(double)0.0, num3=(double)0.0;

    printf ("Digite dois numeros inteiros para comparacao: ");
    scanf("%lf",&num1);
    scanf("%lf",&num2);

    num3=num2/4;
    printf ("1/4 de %.2lf = %.2lf\n",num2, num3);

    numComp(&num1, &num3);
    
    return 0;
}