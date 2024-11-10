#include <stdio.h>
int main (){
    printf ("Esse código traz dados sobre a matriz montada pelo usuário, como a soma dos valores de cada linha\n");
    printf ("--------------------------------------------------------------------------------------------------\n");
    int l, c, somadp=0;
    printf("numero de linhas: ");
    scanf("%d",&l);
    printf("numero de colunas: ");
    scanf("%d",&c);
    int matriz[l][c], somacl[l], somacc[c];
    for(int i=0;i<c;i++){
        somacc[i]=0;
    }
    printf ("Digite os valores dentro da matriz:\n");
    for (int i=0;i<l;i++){
        somacl[i]=0;
        for(int j=0;j<c;j++){
            scanf("%d",&matriz[i][j]);
            somacl[i]=somacl[i]+matriz[i][j];
            somacc[j]=somacc[j]+matriz[i][j];
                if (i==j){
                somadp=somadp+matriz[i][j];
            }
        }
    }
    for (int i=0;i<l;i++){
        printf("soma da linha %d: %d\n",i,somacl[i]);
    }
    for (int j=0;j<c;j++){
        printf("soma da coluna %d: %d\n",j,somacc[j]);
    }
    printf("soma da diagonal principal: %d\n",somadp);
    /*for (int i=0;i<l;i++){
        for(int j=0;j<c;j++){
        printf("%d",matriz[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}