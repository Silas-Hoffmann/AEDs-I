/*
 Exemplo0002 - v0.0. - 13/02/2025
 Author: Silas Hoffmann Reis Viana
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dados / resultados
 int opcao = 0;
// identificar
 printf ( "%s\n", "Exemplo0002 - Programa = v0.0" );
 printf ( "%s\n", "Autor: Silas Hoffmann Reis Viana" );
 printf ( "\n" ); // mudar de linha
    
// acoes
// ler a opcao do teclado
 printf ( "\n%s", "Opcao = " );
 scanf ( "%d", &opcao );
 getchar( ); // para limpar a entrada de dados
    
// para mostrar a opcao lida
 printf ( "\n%s%d", "Opcao = ", opcao );
    
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao       Data       Modificacao
 0.2         13/02      esboco
---------------------------------------------- testes
Versao       Teste
0.0          01. (OK)       identificacao de programa
0.1          01. (OK)       identificacao de programa
0.2          01. (OK)       identificacao de programa
                            leitura e exibicao de inteiro
*/