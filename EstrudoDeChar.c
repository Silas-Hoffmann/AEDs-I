#include <stdio.h> //biblioteca padrão
#include <stdlib.h> //biblioteca auxiliar. Uma das funções é definir o encoding para UTF-8
#include <locale.h> //biblioteca auxiliar. Uma das funções é definir o locale
#include <string.h> //biblioteca obrigatória ao utilizar string

int main (){

    system("chcp 1252 > nul"); //define a linguagem para UTF-8, sem aparecer no cmd (alternativo: system("chcp 65001"))
    setlocale(LC_ALL, "Portuguese"); //configura para portugês brasileiro
    printf ("Teste de impressão: áéíóúãõç\n"); //teste se os acentos foram configurados corretamente

    char caractere;

    caractere = getchar(); //lê um dígito do usuário e atribui na variável caractere
    printf ("Dígito = %c", caractere);
    scanf ("%c",&caractere);//outra forma de ler um caractere do usuário
    printf ("Dígito = %c", caractere);

    return 0;
}
