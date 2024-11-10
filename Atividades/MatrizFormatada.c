#include <stdio.h>
int main (){
    int num;
    printf("digite o número para construir a matriz: ");
    scanf ("%d",&num);
    
    int colin = num*2+1;//número de linhas e colunas da matriz resultante
    int mat[colin][colin]; //cria a matriz
    int aux[colin]; //cria o array auxiliar
    
    //preenche array auxiliar
    for (int i=0;i<num;i++){
        aux[i]=num-i;
    }
    for (int i=0;i<=num;i++){
        aux[num+i]=i;
    }
    
    //conferir array auxiliar
    for (int i=0;i<colin;i++){
        printf ("%d ",aux[i]);
    }
    printf ("\n");
    printf ("\n");
    
    //preencher a matriz
    for (int i=0;i<colin;i++){
        for (int j=0;j<colin;j++){
            mat[i][j]=aux[j];
        }
    }
    for (int i=0;i<colin;i++){
        for (int j=0;j<colin;j++){
            if (aux[i]>mat[i][j]){
            //se o número que devia estar naquela posição, for maior do número que está no momento,
                mat[i][j]=aux[i]; // troque o número
            }
        }
    }
    
    //printar a matriz
    for (int i=0;i<colin;i++){
        for (int j=0;j<colin;j++){
        printf ("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}