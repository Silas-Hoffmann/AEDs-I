//Silas Hoffmann Reis Viana
//26/02/25
#include <stdio.h>

void pertence(double* num){
    //intervalos: [10:30] e (20:40)
    //intercessao: x>20 && x<=30
    //apenas primeiro grupo: x>=10 && x<=20
    //apenas segundo grupo: x>30 && x<40
    //nenhum: x<10 || x>=40

    if (*num>20 && *num<=30){
        printf ("%.2lf Pertence a intercessao de [10:30] e (20:40)",*num);
    } else if (*num>=10 && *num<=20){
        printf ("%.2lf Pertence apenas a [10:30]",*num);
    }else if (*num>30 && *num<40){
        printf ("%.2lf Pertence apenas a (20:40)",*num);
    }else if (*num<10 || *num>=40){
        printf ("%.2lf nao pertence a [10:30] e (20:40)",*num);
    }
    printf ("\n");
}

int main (){

    printf ("Silas Hoffmann Reis Viana - 26/02/25\n"); // identificacao
    
    double num=0.0;
    printf ("digite o numero inteiro: ");
    scanf("%lf",&num);
    pertence(&num);
    
    return 0;
}