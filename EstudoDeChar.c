#include <stdio.h> //biblioteca padr�o
#include <stdlib.h> //biblioteca auxiliar. Uma das fun��es � definir o encoding para UTF-8
#include <locale.h> //biblioteca auxiliar. Uma das fun��es � definir o locale
#include <string.h> //biblioteca obrigat�ria ao utilizar string

int main (){

    system("chcp 1252 > nul"); //define a linguagem para UTF-8, sem aparecer no cmd (alternativo: system("chcp 65001"))
    setlocale(LC_ALL, "Portuguese"); //configura para portug�s brasileiro
    printf ("Teste de impress�o: ��������\n"); //teste se os acentos foram configurados corretamente

    char caractere;

    caractere = getchar(); //l� um d�gito do usu�rio e atribui na vari�vel caractere
    printf ("D�gito = %c", caractere);
    scanf ("%c",&caractere);//outra forma de ler um caractere do usu�rio
    printf ("D�gito = %c", caractere);

    return 0;
}
