#include <stdio.h>
#include <stdlib.h>//biblioteca auxiliar
/*
r leitura
r+ leitura / escrita
w cria um arquivo ou reescreve um arquivo já existente
w+ abre o arquivo apagando o oconteúdo
a escrita no final do arquivo (não apaga o conteúdo)
a+ leitura / escrita no final do arquivo (não apaga o conteúdo)

*/
int main (){
//    FILE* arq = fopen ("nome_arquivo","modo_abertura");
    char letra;
    FILE* arquivo;
    arquivo = fopen ("arquivo_doc","w");//cria o arquivo
    printf ("Arquivo Criado\n");
    fputc('A',arquivo);//arquivo é um ponteiro
    fputc('\n',arquivo);//usar aspas simples
    fputc('B',arquivo);
    fclose(arquivo);//fecha o arquivo

    arquivo = fopen ("arquivo_doc","r+");

    while ((letra=fgetc(arquivo))!=EOF){//EOF = End of File
    //fgetc(arquivo) = ler char no arquivo
        printf ("%c",letra);//imprime a letra lida do arquivo
    }
    fclose(arquivo);
    return 0;
}
