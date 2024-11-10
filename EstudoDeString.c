#include <stdio.h> //biblioteca padrão
#include <stdlib.h> //biblioteca auxiliar. Uma das funções é definir o encoding para UTF-8
#include <locale.h> //biblioteca auxiliar. Uma das funções é definir o locale
#include <string.h> //biblioteca obrigatória ao utilizar string

int main (){

    system("chcp 1252 > nul"); //define a linguagem para UTF-8, sem aparecer no cmd (alternativo: system("chcp 65001"))
    setlocale(LC_ALL, "Portuguese"); //configura para portugês brasileiro
    printf ("Teste de impressão: áéíóúãõç\n"); //teste se os acentos foram configurados corretamente

    char string_1[100]; //100 é o tamanho máximo extraído pela string (tamanho seguro)
    char string_2[100]; //string auxiliar
    size_t tamanho_S1; //tipo de variável que recebe o tamanho de uma string

    printf ("Digite a string 1: ");
    fgets (string_1,sizeof(string_1),stdin); //Explicação: leia(string 1, tamanho da string, teclado)
    string_1[strcspn(string_1, "\n")] = '\0'; //função "strcspn(string, dígito)" Descarta dígito da string. Nesse caso, o enter

    tamanho_S1 = strlen(string_1); //essa função "strlen(parâmetro);" retorna o tamanho da string passada como parâmetro
    //para receber o tamanho da string corretamente, a variável precisa ser do tipo size_t

    strcpy(string_2,string_1); //essa função copia a string 1 na string 2, string_1 = string_2

    printf ("String 1: %s\n",string_1); //imprime a string 1
    printf ("String 2 (cópia da String 1): %s\n",string_2); //imprime a string 2

    printf ("digite a string 2: ");
    fgets (string_2,sizeof(string_2),stdin); //lendo a string 2
    string_2[strcspn(string_2, "\n")] = '\0'; //excluindo o enter lido no final da string

    if (strcmp(string_1, string_2)> 0){ //função "strcmp(parâmetro, parâmetro)" que confere o tamanho alfabético
        //(string_1 > string_2) -> 1
        //(string_2 > string_1) -> -1
        //(string_1 = string_2) -> 0
    }
    return 0; //confere se o código foi executado corretamente
}
