#include <stdio.h>
#include <string.h>

void painel(){
printf ("--------------------------------------------\n----------Estudo de Gaal (Vetores)----------\n--------------------------------------------\n");
}

void procedPadrao(double* mat, int quant){
    for (int i=0;i<9;i++){
        if (i<3 && quant==2){
            *(mat+i)=1;
        } else {
            scanf ("%lf",&*(mat+i));
        }
    }
    getchar();
}

void produtoVetorial(double* mat){
    double prodVet;

    prodVet=*(mat)*(*(mat+4)*(*(mat+8))-(*(mat+5)*(*(mat+7))));
    prodVet=prodVet+(*(mat+1)*(*(mat+3)*(*(mat+8))-(*(mat+5)*(*(mat+6)))));
    prodVet=prodVet+(*(mat+2)*(*(mat+3)*(*(mat+7))-(*(mat+4)*(*(mat+6)))));
    
    printf ("%0.2lf",prodVet);
    printf ("\n--------------------------------------------\n");
}

void produtoMisto(double mat[3][3]){
    double prodmisto=0;

    prodmisto = mat[0][0]*((mat[1][1]*mat[2][2])-(mat[1][2]*mat[2][1]));
    prodmisto = prodmisto - (mat[0][1]*((mat[1][0]*mat[2][2])-(mat[1][2]*mat[2][0])));
    prodmisto = prodmisto + (mat[0][2]*((mat[1][0]*mat[2][1])-(mat[1][1]*mat[2][0])));
    
    printf ("%0.2lf",prodmisto);
    printf ("\n--------------------------------------------\n");
}

void produtoEscalar(double* mat){
    double arr[3];
    arr[0]=*(mat+3)*(*(mat+6));
    arr[1]=*(mat+4)*(*(mat+7));
    arr[2]=*(mat+5)*(*(mat+8));
    printf ("(%0.2lf , %0.2lf , %0.2lf)",arr[0],arr[1],arr[2]);
    printf ("\n--------------------------------------------\n");
}

void normal(double* mat){
    double prodVet[3];

    prodVet[0]=*(mat)*(*(mat+4)*(*(mat+8))-(*(mat+5)*(*(mat+7))));
    prodVet[1]=*(mat+1)*(*(mat+3)*(*(mat+8))-(*(mat+5)*(*(mat+6))));
    prodVet[2]=*(mat+2)*(*(mat+3)*(*(mat+7))-(*(mat+4)*(*(mat+6))));
    
    printf ("(%0.2lf , %0.2lf , %0.2lf)",prodVet[0], prodVet[1], prodVet[2]);
    printf ("\n--------------------------------------------\n");
}

int main (){
    double mat[3][3];
    int quantidade;
    char operacao={'O'};
    
    painel();

    while (operacao!='F'&&operacao!='f'){
        printf ("\nDigite a quantidade de vetores (maximo = 3): ");
        scanf ("%d",&quantidade);

        if (quantidade==2||quantidade==3){
            printf ("\nQual operacao deseja realizar?\n");
            if (quantidade==3){
                 printf ("M-Produto Misto\n");
            } else if (quantidade==2){
                printf("V-Produto Vetorial\nE-Produto Escalar\nN-Vetor Normal\n");
            }
            printf ("F-Fim\nOpcao: ");
            getchar();
            operacao = getchar();
        }
        if ((quantidade==2||quantidade==3)&&operacao!='F'&&operacao!='f'){
        
            if ((operacao=='V'||operacao=='v')&&quantidade==2){
                printf("\nDigite os vetores:\n");
                procedPadrao(mat,quantidade);
                printf ("\nProduto Vetorial: ");
                produtoVetorial(mat);
            }else if ((operacao=='M'||operacao=='m')&&quantidade==3){
                printf("\nDigite os vetores:\n");
                procedPadrao(mat,quantidade);
                printf ("\nProduto Misto: ");
                produtoMisto(mat);
            }else if ((operacao=='E'||operacao=='e')&&quantidade==2){
                printf("\nDigite os vetores:\n");
                procedPadrao(mat,quantidade);
                printf ("\nproduto Escalar: ");
                produtoEscalar(mat);
            }else if ((operacao=='N'||operacao=='n')&&quantidade==2){
                printf("\nDigite os vetores:\n");
                procedPadrao(mat,quantidade);
                printf ("\nVetor Normal: ");
                normal(mat);
            }
        } else if ((quantidade!=2||quantidade!=3)&&(operacao!='F'&&operacao!='f')){
            printf ("Digite uma quantidade valida\n");
            printf ("--------------------------------------------\n");
        }
    }
    return 0;
}
