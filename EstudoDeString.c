#include <stdio.h> //biblioteca padr�o
#include <stdlib.h> //biblioteca auxiliar. Uma das fun��es � definir o encoding para UTF-8
#include <locale.h> //biblioteca auxiliar. Uma das fun��es � definir o locale
#include <string.h> //biblioteca obrigat�ria ao utilizar string

int main (){

    system("chcp 1252 > nul"); //define a linguagem para UTF-8, sem aparecer no cmd (alternativo: system("chcp 65001"))
    setlocale(LC_ALL, "Portuguese"); //configura para portug�s brasileiro
    printf ("Teste de impress�o: ��������\n"); //teste se os acentos foram configurados corretamente

    char string_1[100]; //100 � o tamanho m�ximo extra�do pela string (tamanho seguro)
    char string_2[100]; //string auxiliar
    size_t tamanho_S1; //tipo de vari�vel que recebe o tamanho de uma string

    printf ("Digite a string 1: ");
    fgets (string_1,sizeof(string_1),stdin); //Explica��o: leia(string 1, tamanho da string, teclado)
    string_1[strcspn(string_1, "\n")] = '\0'; //fun��o "strcspn(string, d�gito)" Descarta d�gito da string. Nesse caso, o enter

    tamanho_S1 = strlen(string_1); //essa fun��o "strlen(par�metro);" retorna o tamanho da string passada como par�metro
    //para receber o tamanho da string corretamente, a vari�vel precisa ser do tipo size_t

    strcpy(string_2,string_1); //essa fun��o copia a string 1 na string 2, string_1 = string_2

    printf ("String 1: %s\n",string_1); //imprime a string 1
    printf ("String 2 (c�pia da String 1): %s\n",string_2); //imprime a string 2

    printf ("digite a string 2: ");
    fgets (string_2,sizeof(string_2),stdin); //lendo a string 2
    string_2[strcspn(string_2, "\n")] = '\0'; //excluindo o enter lido no final da string

    if (strcmp(string_1, string_2)> 0){ //fun��o "strcmp(par�metro, par�metro)" que confere o tamanho alfab�tico
        //(string_1 > string_2) -> 1
        //(string_2 > string_1) -> -1
        //(string_1 = string_2) -> 0
    }
    return 0; //confere se o c�digo foi executado corretamente
}
