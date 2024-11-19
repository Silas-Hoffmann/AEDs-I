#include <stdio.h>
#include <string.h>

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

void produtoMisto(double* mat){
    double prodmisto=0;

    prodmisto=*(mat)*(*(mat+4)*(*(mat+8))-(*(mat+5)*(*(mat+7))));
    prodmisto=prodmisto-(*(mat+1)*(*(mat+3)*(*(mat+8))-(*(mat+5)*(*(mat+6)))));
    prodmisto=prodmisto-(*(mat+2)*(*(mat+3)*(*(mat+7))-(*(mat+4)*(*(mat+6)))));

    printf ("Produto Misto: %0.2lf",prodmisto);
}

void produtoEscalar(double* mat){
    double arr[3];
    arr[0]=*(mat+3)*(*(mat+6));
    arr[1]=*(mat+4)*(*(mat+7));
    arr[2]=*(mat+5)*(*(mat+8));
    printf ("%0.2lf %0.2lf %0.2lf\n",arr[0],arr[1],arr[2]);
}

void normal(double* mat){

}

int main (){
    double mat[3][3];
    int quantidade;
    char operacao={'O'};

    while (operacao!='F'){
        printf ("Digite a quantidade de vetores (maximo = 3): ");
        scanf ("%d",&quantidade);

        if (quantidade==2||quantidade==3){
            printf ("Qual operacao deseja realizar?\n");
            if (quantidade==3){
                 printf ("M-Produto Misto\n");
            } else if (quantidade==2){
                printf("V-Produto Vetorial\nE-Produto Escalar\n");
            }
            printf ("F-Fim\nOpcao: ");
            getchar();
            operacao = getchar();
        }
        if ((quantidade==2||quantidade==3)&&(operacao!='F')){
            printf("Digite os vetores:\n");
            procedPadrao(mat,quantidade);

            if (operacao=='V'){
                produtoVetorial(mat);
            }else if (operacao=='M'){
                produtoMisto(mat);
            }else if (operacao=='E'){
                produtoEscalar(mat);
            }else if (operacao=='N'){
                normal(mat);
            }
        } else if ((quantidade!=2||quantidade!=3)&&(operacao!='F')){
            printf ("Digite uma quantidade valida de vetores\n");
        }
    }
    return 0;
}

        
        }
    }
}
