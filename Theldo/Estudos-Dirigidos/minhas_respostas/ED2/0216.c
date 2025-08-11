//Silas Hoffmann Reis Viana
//26/02/25
#include <stdio.h>

void imparPar(int* num){
    if ((*num%2)==0){
        printf ("%d e par",*num);
    } else if ((*num%2)!=0){
        printf ("%d e impar",*num);
    }
    printf ("\n");
}

int main (){

    printf ("Silas Hoffmann Reis Viana - 26/02/25\n");//identificacao

    int num1=0, num2=(int)0;

    printf ("Digite dois numero inteiros: ");
    scanf ("%d",&num1);
    scanf ("%d",&num2);

    imparPar(&num1);
    imparPar(&num2);
    
    return 0;
}