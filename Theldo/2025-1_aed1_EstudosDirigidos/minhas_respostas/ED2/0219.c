//Silas Hoffmann Reis Viana
//26/02/25
#include <stdio.h>

void numComp (double* num1, double* num2, double* num3){
    if (*num2==*num1){
        printf ("Primeiro e segundo numeros sao iguais");
    }else if (*num2==*num3){
        printf ("Segundo e Terceiro numeros sao iguais");
    }else if (*num1==*num3){
        printf ("Primeiro e Terceiro numeros sao iguais");
    }else if ((*num2>*num1 && *num2<*num3) || (*num2>*num3 && *num2<*num1)){
        printf ("%.2lf esta entre %.2lf e %.2lf",*num2, *num1, *num3);
    }else if((*num2<*num1&&*num2<*num3) || (*num2>*num1 && *num2>*num3)){
        printf ("%.2lf nao esta entre %.2lf e %.2lf",*num2, *num1, *num3);
    }
    printf ("\n");
}


int main (){

    printf ("Silas Hoffmann Reis Viana - 26/02/25\n\n"); // identificacao

    double num1=(double)0.0, num2=(double)0.0, num3=(double)0.0;

    printf ("Digite 3 numeros inteiros diferentes para comparacao: ");
    scanf("%lf",&num1);
    scanf("%lf",&num2);
    scanf("%lf",&num3);

    numComp (&num1, &num2, &num3);
    
    return 0;
}