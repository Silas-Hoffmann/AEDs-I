#include <stdio.h>
int main(){
    
    printf ("Nesse exemplo, 'i' foi declarado, mas nao inicializado. Dentro do cabecalho do for, 'i' recebe valor de 0 a 9, saindo com 10");
    
    int i;
    for(i=0;i<10;i++){
        printf ("\nValor de i (for): %d",i);
    }
    printf ("\nValor de i: %d",i);
    
    
    printf ("\n\nNesse exemplo, 'j' foi declarado e inicializado com 55. 'j' entra no for recebendo o valor de 0 a 9, saindo com 10");
    
    int j=55;
    printf ("\nValor de j: %d",j);
    for (j=0;j<10;j++){
        printf ("\nValor de j (for) %d",j);
    }
    printf ("\nValor de j: %d",j);
    printf ("\nO valor de j, antes do for, é perdido");
    
    
    printf ("\n\nNesse exemplo, 'k' e declarado e inicializado com 83. Dentro do cabecalho do for, 'k' é declarado e inicializado com 0 a 9, saindo com 10");
    
    int k=83;
    printf ("\nValor de k: %d",k);
    for (int k=0;k<10;k++){
        printf ("\nValor de k (for) %d",k);
    }
    printf ("\nValor de k: %d",k);
    printf ("\nO valor de 'k' antes do for e mantido, pois o 'k' presente no for, é outra variável");
    return 0;
}