#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ingrediente.h"
#include "pizza.h"

int main () {
	struct ingredientes ingrediente[100];
	struct formatoPizzas pizza[100];
	int quantidadePizzas, quantidadeIG;

	char operacao='a';

	while (operacao!='F' && operacao!='f') {

		leituraStruct(pizza);
		igArquivoParaStruct (ingrediente);

		FILE* arq = fopen ("cardapio","r");
		if (arq == NULL) {
			printf ("erro na leitura de arquivo");
		}
		fscanf(arq,"%d",&quantidadePizzas);
		fclose (arq);
		
		FILE* ig = fopen ("ingredientesGlobais","r");
		if (ig == NULL) {
			printf ("erro na leitura de ingredientes globais");
		}
		fscanf(ig,"%d",&quantidadeIG);
		fclose (ig);

		printf ("------------------------------------------------------\n");
		printf ("------------------Pizzaria do Silas-------------------\n");
		printf ("------------------------------------------------------\n");
		printf ("Quantidade de pizzas: %d\n",quantidadePizzas);
		printf ("Quantidade de IG: %d\n",quantidadeIG);
		printf ("------------------------------------------------------");

		printf ("\nQual operacao deseja realizar?");
		printf("\nP-Processo de Venda");
		printf("\nV-Visualizar Cardapio");
		printf ("\nE-Editar Cardapio");
		printf ("\nX-Exportar Cardapio");
		printf ("\nF-Finalizar Processo\n");
		operacao=getchar();
		getchar();

		if (operacao=='V'||operacao=='v') {
			leituraStruct(pizza);
			exibirCardapio('a',pizza, &quantidadePizzas);
		} else if (operacao=='E'||operacao=='e') {
			leituraStruct(pizza);
			editarCardapio(pizza, &quantidadePizzas, ingrediente, &quantidadeIG);
		} else if (operacao=='X'||operacao=='x') {
			leituraStruct(pizza);
			exportarCardapio(pizza, &quantidadePizzas);
		}else if (operacao=='p'||operacao=='P'){
		    processoVenda(pizza, &quantidadePizzas);
		}
	}
}

//processo de adicionar ingrediente está bugado
//processo de venda