#include <stdio.h>
#include <stdlib.h>// s� pra ter certeza, se precisar

// basicamente, seguindo a formata��o de uma struct e referenciando o 'apelido.atributo' nesse formato, eu consigo usar uma struct normalmente
//

struct nome { //formato simples de struct
    char titulo[50];
    char cidade[50];
    int numero;
};//necess�rio o ';'

int main (){
    struct nome apelido; //necess�rio para declarar e referenciar uma struct
    //caso queira fazer uma c�pia da struct, repita essa linha, mudando o apelido:
    //Ex.: 'struct nome codenome;'

    apelido.numero = 917; //inicializa��o do tipo inteira

    snprintf(apelido.titulo, sizeof(apelido.titulo), "O Hobbit"); //inicializa��o do tipo string
    //parecido com o fgets: 'fgets(nome,sizeof(nome),stdin)' -> 'snprintf(apelido.nome,sizeof(apelido.nome),"conte�do")'

    printf ("%d",apelido.numero);

    return 0;
}
