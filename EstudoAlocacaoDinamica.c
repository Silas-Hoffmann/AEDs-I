#include <stdio.h>
#include <stdlib.h>
//*****TODAS TRABALHAM OM PONTEIROS*****
// malloc(): aloca memória e não inicializa
// calloc(): aloca memória e inicializa com bits zerados
// realloc(): altera o tamanho da memória alocada
// free(): libera a memória alocada
int main (){
    int* prt;
    int variavel;
    
    printf ("Digite o tamanho de prt: ");
    scanf ("%d",&variavel);//definir tamanho de prt
    
    prt = (int*)malloc(variavel*sizeof(int));//aloca 'variavel' espaços na memória (5*4=20 bytes), para o ponteiro
    //malloc e calloc são usados da mesma forma, só mudando a forma de alocação (consultar linhas 4 e 5)
    
    for (int i=0;i<variavel;i++){
        printf ("Digite um valor em prt: ");
        scanf ("%d",prt+i);//escaneia o valor pra prt no i° endereço
    }
    for (int i=0;i<(variavel+5);i++){
        printf ("prt %d = %d\n",i,*(prt+i));//printa os variavel+5 valores dentro de prt
    }
    prt = (int*)realloc(prt,5*sizeof(int));//realoca mais 5 espaços na memória para o ponteiro
    printf ("Foi alocado mais 5 espaços em prt\n");
    
    for (int i=variavel;i<(variavel+5);i++){
        printf ("Digite um valor em prt: ");
        scanf ("%d",prt+i);// escaneia os valores restantes para prt
    }
    
    for (int i=0;i<10;i++){
        printf ("prt %d = %d\n",i,*(prt+i));//printa os 10 valores dentro de prt
    }
    
    free(prt);//libera a memória de prt
    printf ("prt foi liberada\n");
    
    return 0;
}