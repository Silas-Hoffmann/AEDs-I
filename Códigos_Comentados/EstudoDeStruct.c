#include <stdio.h>
#include <stdlib.h>// só pra ter certeza, se precisar

// basicamente, seguindo a formatação de uma struct e referenciando o 'apelido.atributo' nesse formato, eu consigo usar uma struct normalmente
//

struct nome { //formato simples de struct
    char titulo[50];
    char cidade[50];
    int numero;
};//necessário o ';'

int main (){
    struct nome apelido; //necessário para declarar e referenciar uma struct
    //caso queira fazer uma cópia da struct, repita essa linha, mudando o apelido:
    //Ex.: 'struct nome codenome;'

    apelido.numero = 917; //inicialização do tipo inteira

    snprintf(apelido.titulo, sizeof(apelido.titulo), "O Hobbit"); //inicialização do tipo string
    //parecido com o fgets: 'fgets(nome,sizeof(nome),stdin)' -> 'snprintf(apelido.nome,sizeof(apelido.nome),"conteúdo")'

    printf ("%d",apelido.numero);

    return 0;
}
