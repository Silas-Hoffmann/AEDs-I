#include <stdio.h>
#include <stdlib.h>
int main (){
    int cont=0;
    char texto[200];
    FILE* arquivo;
    arquivo = fopen("arquivo_a2.txt","r");

    if (arquivo==NULL){
        printf ("Erro ao ler arquivo");
        return 1;
    }

    while (fgets(texto,sizeof(texto),arquivo)!=NULL){//fgets pega uma linha inteira
    //utilizar "arquivo" ao invés de "stdin", como entrada

        printf ("%s",texto);
        cont++;
    }
    fclose(arquivo);
    printf("\n\nQuantidade de linhas: %d",cont);
    return 0;
}
