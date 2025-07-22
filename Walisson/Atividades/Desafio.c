#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double calcular_media_disciplina(double **matriz, int alunos, int disciplina){
    double media =0.0;
    for (int i=0;i<alunos;i++){
        media += matriz[i][disciplina];
    }
    media = media/alunos;
    return media;
}

double calcular_media_aluno(double *notas, int disciplinas){
    double media=0;
    for (int i=0;i<disciplinas;i++){
        media += *(notas+i);
    }
    media = media/disciplinas;
    return media;
}

void preencher_matriz(double **matriz, int alunos, int disciplinas){
    for (int i=0;i<alunos;i++){
        for (int j=0;j<disciplinas;j++){
            printf ("Nota do aluno %d na disciplina %d: ",i+1, j+1);
            scanf ("%lf",&matriz[i][j]);
        }
    }
}

double** alocar_matriz(int linhas, int colunas){
    double** matriz = (double**)malloc(linhas*sizeof(double*));
    for (int i=0;i<linhas;i++){
        matriz[i] = (double*)malloc(colunas*sizeof(double));
    }
    return matriz;
}

int main (){
    //-------------------------------------
    //declarações importantes

    setlocale(LC_ALL, "Portuguese_Brazil.1252");// define os acentos

    int Nalunos, Ndisciplinas;
    printf ("Número de alunos: ");
    scanf ("%d",&Nalunos);
    printf ("Número de disciplinas: ");
    scanf ("%d",&Ndisciplinas);
    printf ("\n");
    double* mediaAlunos = (double*)malloc(Nalunos * sizeof(double));
    double* mediaDisciplinas = (double*)malloc(Ndisciplinas * sizeof(double));
    //-------------------------------------

    //-------------------------------------
    //processos
    double** ptrMat = alocar_matriz(Nalunos, Ndisciplinas);//define a matriz de forma dinâmica

    preencher_matriz(ptrMat, Nalunos, Ndisciplinas);//preenche a matriz criada

    for (int i=0;i<Nalunos;i++){//calcula media dos alunos
        mediaAlunos[i]=calcular_media_aluno(ptrMat[i], Ndisciplinas);
    }

    for (int i=0;i<Ndisciplinas;i++){//calcula a media das Disciplinas
        mediaDisciplinas[i] = calcular_media_disciplina(ptrMat,Nalunos, i);
    }

    //-------------------------------------
    //printa as saídas requisitadas
    printf ("\n");
    for (int i=0;i<Nalunos;i++){//printa a media dos alunos
        printf ("Media do aluno %d: %0.2lf\n",i+1,mediaAlunos[i]);
    }
    printf ("\n");
    for (int i=0;i<Ndisciplinas;i++){
        printf ("Média da disciplina %d: %0.2lf\n", i+1, mediaDisciplinas[i]);
    }

    //-------------------------------------
    //-------------------------------------
    //controle
    /*
    for (int i=0;i<Nalunos;i++){ //printa a matriz
        for (int j=0;j<Ndisciplinas;j++){
            printf("%0.2lf ",ptrMat[i][j]);
        }
        printf("\n");
    }
    */
    //-------------------------------------
    //-------------------------------------
    //liberação de memória
    for (int i=0;i<Nalunos;i++){
        free(ptrMat[i]);
    }
    free (ptrMat);
    free(mediaAlunos);
    free(mediaDisciplinas);
    //-------------------------------------
    return 0;
}
