#include <stdio.h>
int main (){
    int linhas, colunas, soma=0;
    scanf ("%d",&linhas);
    scanf ("%d",&colunas);
    int mat[linhas][colunas];
    for (int i=0;i<linhas;i++){
        for (int j=0;j<colunas;j++){
            scanf ("%d",&mat[i][j]);
        }
    }
    for (int i=0;i<linhas;i++){
        for (int j=0;j<colunas;j++){
            if (i==0||i==(linhas-1)||j==0||j==(colunas-1)){
                soma+=mat[i][j];
            }
        }
    }
    printf ("%d",soma);
    return 0;
}