#include <stdio.h>
#include <stdlib.h>
int main (){
    char letra;
    int contadorA=0, contLetra=0, contCaractere=0;
    FILE* arquivo;
    arquivo = fopen ("arquivo_a1","r");
    printf ("Arquivo aberto\n");

    while ((letra=fgetc(arquivo))!=EOF){
        printf ("%c",letra);
        if (letra=='a'||letra=='A'){
            contadorA+=1;
        }
        if (letra!=' '){
            contLetra+=1;
        }
    contCaractere+=1;
    }
    printf ("\n\nquantidade de A: %d",contadorA);
    printf ("\nquantidade de Letras: %d",contLetra);
    printf ("\nquantidade de Caracteres: %d",contCaractere);
    fclose (arquivo);
    return 0;
}
