#include <stdio.h>
#include <string.h>

double* procedPadrao(){
    double mat[3][3];
    for (int i=0;i<3;i++){
        if (i>0){
            printf ("Digite o vetor %d\n",i);
        }
        for (int j=0;j<3;j++){
            if (i==0){
                mat[i][j]=1;
            }else {
                scanf ("%lf",&mat[i][j]);
            }
        }
    }
    getchar();
    return mat;
}
void produtoVetorial(){
    double* mat=procedPadrao();
    double prodVet[3];

    prodVet[0]=*(mat)*(*(mat+4)*(*(mat+8))-(*(mat+5)*(*(mat+7))));
    prodVet[1]=*(mat+1)*(*(mat+3)*(*(mat+8))-(*(mat+5)*(*(mat+6))));
    prodVet[2]=*(mat+2)*(*(mat+3)*(*(mat+7))-(*(mat+4)*(*(mat+6))));
    
    printf ("Produto Vetorial: ");
    for (int i=0;i<3;i++){
        printf ("%0.2lf ",prodVet[i]);
    }
    printf ("\n");
    printf ("\n");
}
void produtoMisto(){
    double* mat=procedPadrao();
    double prodmisto=0;

    prodmisto=*(mat)*(*(mat+4)*(*(mat+8))-(*(mat+5)*(*(mat+7))));
    prodmisto=prodmisto-(*(mat+1)*(*(mat+3)*(*(mat+8))-(*(mat+5)*(*(mat+6)))));
    prodmisto=prodmisto-(*(mat+2)*(*(mat+3)*(*(mat+7))-(*(mat+4)*(*(mat+6)))));
    
    printf ("Produto Misto: %0.2lf",prodmisto);
}
void produtoEscalar(){
    
}

int main (){
    char operacao={'O'};
    while (operacao!='F'){
        printf ("Qual operacao deseja realizar?\nV-Produto Vetorial\nM-Produto Misto\nE-Produto Escalar\nN-Norma\nF-Fim\nOpcao: ");
        operacao = getchar();
        
        if (operacao=='V'){
            produtoVetorial();
        }else if (operacao=='M'){
            prodMisto();
        }else if (operacao=='E'){
            
        }else if (operacao=='N'){
        
        }
    }
}