#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int **allocateIntMatrix(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }
    return matriz;
}

void printIntMatrix(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void metodo_1011(){
    printf ("------------Gravar intervalo em um arquivo------------\n");
    int quant=1, max=(int)0, min=(int)0;
    
    while (quant>0){
        printf ("Digite o intervalo: ");
        scanf ("%d",&min);
        scanf ("%d",&max);
        
        if (min>max){ //ordena o intervalo de forma crescente
            int aux=min;
            min=max;
            max=aux;
        }
        
        printf ("Digite a quantidade de elementos (0 = interromper): ");
        scanf ("%d",&quant);
        
        if (quant>0){
            int numero;
            
            FILE *arquivo = fopen("DADOS.txt", "a+");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return;
            }
            
            for (int i=0;i<quant;i++){
                numero = (rand() % (max - min + 1)) + min;
                printf ("rand = %d\n",numero);
                fprintf(arquivo, "%d ",numero);
            }
             fclose(arquivo);
            
        }else if (quant==0){
            printf ("processo interrompido\n\n");
        }else if (quant<0){
            printf ("Digite uma quantidade válida\n");
            quant=1;
        }
    }
}
void metodo_1012(){
    printf ("------------Procurar valor em arquivo------------\n");

    char arquivo[20];
    printf ("digite o nome do arquivo: ");
    
    fgets(arquivo, 20, stdin);
    for (int i=0;i<20;i++){
        if (arquivo[i]=='\n'){
            arquivo[i]='\0'; //retira o \n do final
        }
    }
    FILE *arq = fopen(arquivo, "r");
        if (arq == NULL) {
            printf("Arquivo nao encontrado\n");
            return;
        } else {
            printf("Arquivo encontrado\n");
            int valor=0, valorarq[100], cont=(int)0;
            char ledados[10];
            printf ("Digite o valor que deseja procurar: ");
            scanf ("%d",&valor);
            while (fgets(ledados, sizeof(ledados), arq)){
                sscanf(ledados, "%d", &valorarq[cont]);
                if (valorarq[cont]==valor){
                    printf ("valor encontrado na linha %d\n",cont+1);
                }
                cont=cont+1;
            }
        }
    fclose(arq);
}

// Função para ler um vetor de um arquivo
int* readArrayFromFile(const char *nomeArquivo, int *tamanho) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        *tamanho = 0;
        return NULL;
    }

    int capacidade = 10;
    int *vetor = (int *) malloc(capacidade * sizeof(int));
    *tamanho = 0;

    int valor;
    while (fscanf(arquivo, "%d", &valor) == 1) {
        if (*tamanho >= capacidade) {
            capacidade *= 2;
            vetor = (int *) realloc(vetor, capacidade * sizeof(int));
        }
        vetor[*tamanho] = valor;
        (*tamanho)++;
    }

    fclose(arquivo);
    return vetor;
}


// Função 1013: comparar dois vetores
int arrayCompare(int *v1, int tam1, int *v2, int tam2) {
    if (tam1 != tam2){
        return 0;
    }

    return 1;
}

// Função principal
void metodo_1013() {
    printf ("------------Comparar array------------\n");
    
    int tam1, tam2;
    char arquivo1[20], arquivo2[20];
    
    printf ("digite o nome do primeiro arquivo: ");
    fgets(arquivo1, 20, stdin);
    for (int i=0;i<20;i++){
        if (arquivo1[i]=='\n'){
            arquivo1[i]='\0'; //retira o \n do final
        }
    }
    printf ("digite o nome do segundo arquivo: ");
    fgets(arquivo2, 20, stdin);
    for (int i=0;i<20;i++){
        if (arquivo2[i]=='\n'){
            arquivo2[i]='\0'; //retira o \n do final
        }
    }
    
    int *arranjo1 = readArrayFromFile(arquivo1, &tam1);
    int *arranjo2 = readArrayFromFile(arquivo2, &tam2);

    int resposta = arrayCompare(arranjo1, tam1, arranjo2, tam2);

    printf("%d\n",tam1);
    printf("%d\n",tam2);

    if (resposta)
        printf("Os arranjos tem tamanhos iguais.\n");
    else
        printf("Os arranjos tem tamanhos diferentes.\n");

    free(arranjo1);
    free(arranjo2);
}

int* arrayAdd(int *v1, int *v2, int tam1, int tam2, int constante, int *tamanhoResultado) {
    if (tam1 != tam2) {
        *tamanhoResultado = 0;
        return NULL;
    }

    int *soma = (int *) malloc(tam1 * sizeof(int));
    for (int i = 0; i < tam1; i++) {
        soma[i] = v1[i] + constante * v2[i];
    }

    *tamanhoResultado = tam1;
    return soma;
}


void metodo_1014() {
    printf("------------Somar arrays (com constante)------------\n");

    int tam1, tam2;
    char arquivo1[20], arquivo2[20];

    printf("Digite o nome do primeiro arquivo: ");
    fgets(arquivo1, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (arquivo1[i] == '\n') {
            arquivo1[i] = '\0';
            break;
        }
    }

    printf("Digite o nome do segundo arquivo: ");
    fgets(arquivo2, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (arquivo2[i] == '\n') {
            arquivo2[i] = '\0';
            break;
        }
    }

    int *arranjo1 = readArrayFromFile(arquivo1, &tam1);
    int *arranjo2 = readArrayFromFile(arquivo2, &tam2);

    if (arranjo1 == NULL || arranjo2 == NULL) {
        printf("Erro ao ler os arquivos.\n");
        return;
    }

    int constante;
    printf("Digite a constante multiplicadora: ");
    scanf("%d", &constante);
    getchar(); // consome o '\n' deixado pelo scanf

    int tamResultado;
    int *soma = arrayAdd(arranjo1, arranjo2, tam1, tam2, constante, &tamResultado);

    if (soma == NULL) {
        printf("Os tamanhos dos arranjos são incompatíveis.\n");
    } else {
        printf("Resultado da soma:\n");
        for (int i = 0; i < tamResultado; i++) {
            printf("%d ", soma[i]);
        }
        printf("\n");
        free(soma);
    }

    free(arranjo1);
    free(arranjo2);
}

int isArrayDecrescent(int *v, int tamanho) {
    int resposta = 1; // Começa assumindo que está em ordem decrescente
    for (int i = 1; i < tamanho; i++) {
        if (v[i - 1] < v[i]) {
            resposta = 0;
        }
    }
    return resposta;
}

void metodo_1015() {
    printf("------------Verificar ordem decrescente------------\n");

    int tamanho;
    char nomeArquivo[20];

    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (nomeArquivo[i] == '\n') {
            nomeArquivo[i] = '\0';
            break;
        }
    }

    int *arranjo = readArrayFromFile(nomeArquivo, &tamanho);

    if (arranjo == NULL) {
        printf("Erro ao ler o arquivo.\n");
        return;
    }

    int resultado = isArrayDecrescent(arranjo, tamanho);

    if (resultado)
        printf("O arranjo está em ordem decrescente.\n");
    else
        printf("O arranjo NÃO está em ordem decrescente.\n");

    free(arranjo);
}

int** readMatrixFromFile(const char *nomeArquivo, int *linhas, int *colunas) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        *linhas = *colunas = 0;
        return NULL;
    }

    fscanf(arquivo, "%d %d", linhas, colunas);
    int **matriz = (int **)malloc((*linhas) * sizeof(int *));
    for (int i = 0; i < *linhas; i++) {
        matriz[i] = (int *)malloc((*colunas) * sizeof(int));
        for (int j = 0; j < *colunas; j++) {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    fclose(arquivo);
    return matriz;
}

int** matrixTranspose(int **matriz, int linhas, int colunas) {
    int **transposta = (int **)malloc(colunas * sizeof(int *));
    for (int i = 0; i < colunas; i++) {
        transposta[i] = (int *)malloc(linhas * sizeof(int));
        for (int j = 0; j < linhas; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }
    return transposta;
}

void freeMatrix(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void metodo_1016() {
    printf("------------Transpor matriz------------\n");

    char nomeArquivo[20];
    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (nomeArquivo[i] == '\n') {
            nomeArquivo[i] = '\0';
            break;
        }
    }

    int linhas, colunas;
    int **matriz = readMatrixFromFile(nomeArquivo, &linhas, &colunas);
    if (matriz == NULL) {
        return;
    }

    int **transposta = matrixTranspose(matriz, linhas, colunas);

    printf("Matriz transposta:\n");
    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    freeMatrix(matriz, linhas);
    freeMatrix(transposta, colunas);
}

int matrixZero(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

void metodo_1017() {
    printf("------------Testar se matriz é nula------------\n");

    char nomeArquivo[20];
    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (nomeArquivo[i] == '\n') {
            nomeArquivo[i] = '\0';
            break;
        }
    }

    int linhas, colunas;
    int **matriz = readMatrixFromFile(nomeArquivo, &linhas, &colunas);
    if (matriz == NULL) {
        return;
    }

    if (matrixZero(matriz, linhas, colunas) == 1) {
        printf("A matriz é nula (todos os elementos são zero).\n");
    } else {
        printf("A matriz NÃO é nula (possui algum valor diferente de zero).\n");
    }

    freeMatrix(matriz, linhas);
}

int matrixCompare(int **matriz1, int linhas1, int colunas1,
                  int **matriz2, int linhas2, int colunas2) {
    if (linhas1 != linhas2 || colunas1 != colunas2) {
        return 0; // Tamanhos incompatíveis
    }

    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas1; j++) {
            if (matriz1[i][j] != matriz2[i][j]) {
                return 0; // Encontrou diferença
            }
        }
    }

    return 1; // Matrizes iguais
}

void metodo_1018() {
    printf("------------Comparar duas matrizes------------\n");

    char arquivo1[20], arquivo2[20];

    printf("Digite o nome do primeiro arquivo: ");
    fgets(arquivo1, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (arquivo1[i] == '\n') {
            arquivo1[i] = '\0';
            break;
        }
    }

    printf("Digite o nome do segundo arquivo: ");
    fgets(arquivo2, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (arquivo2[i] == '\n') {
            arquivo2[i] = '\0';
            break;
        }
    }

    int linhas1, colunas1, linhas2, colunas2;
    int **matriz1 = readMatrixFromFile(arquivo1, &linhas1, &colunas1);
    int **matriz2 = readMatrixFromFile(arquivo2, &linhas2, &colunas2);

    if (matriz1 == NULL || matriz2 == NULL) {
        printf("Erro ao ler uma das matrizes.\n");
        return;
    }

    int resultado = matrixCompare(matriz1, linhas1, colunas1, matriz2, linhas2, colunas2);

    if (resultado == 1) {
        printf("As matrizes são iguais.\n");
    } else {
        printf("As matrizes são diferentes.\n");
    }

    freeMatrix(matriz1, linhas1);
    freeMatrix(matriz2, linhas2);
}

int **matrixAdd(int **matriz1, int linhas1, int colunas1,
                int constante, int **matriz2, int linhas2, int colunas2) {
    if (linhas1 != linhas2 || colunas1 != colunas2) {
        return NULL; // Tamanhos incompatíveis
    }

    int **resultado = allocateIntMatrix(linhas1, colunas1);

    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas1; j++) {
            resultado[i][j] = matriz1[i][j] + constante * matriz2[i][j];
        }
    }

    return resultado;
}

void metodo_1019() {
    printf("------ Soma de matrizes com constante multiplicadora ------\n");

    char arquivo1[20], arquivo2[20];
    int constante;

    printf("Digite o nome do primeiro arquivo: ");
    fgets(arquivo1, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (arquivo1[i] == '\n') {
            arquivo1[i] = '\0';
            break;
        }
    }

    printf("Digite o nome do segundo arquivo: ");
    fgets(arquivo2, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (arquivo2[i] == '\n') {
            arquivo2[i] = '\0';
            break;
        }
    }

    printf("Digite o valor da constante multiplicadora: ");
    scanf("%d", &constante);
    getchar(); // Limpa o '\n' restante

    int linhas1, colunas1, linhas2, colunas2;
    int **matriz1 = readMatrixFromFile(arquivo1, &linhas1, &colunas1);
    int **matriz2 = readMatrixFromFile(arquivo2, &linhas2, &colunas2);

    if (matriz1 == NULL || matriz2 == NULL) {
        printf("Erro ao ler uma das matrizes.\n");
        return;
    }

    int **soma = matrixAdd(matriz1, linhas1, colunas1, constante, matriz2, linhas2, colunas2);

    if (soma == NULL) {
        printf("Matrizes com tamanhos diferentes.\n");
    } else {
        printf("Resultado da soma:\n");
        printIntMatrix(soma, linhas1, colunas1);
        freeMatrix(soma, linhas1);
    }

    freeMatrix(matriz1, linhas1);
    freeMatrix(matriz2, linhas2);
}

int **matrixProduct(int **matriz1, int l1, int c1,
                    int **matriz2, int l2, int c2) {
    if (c1 != l2) {
        return NULL; // Dimensões incompatíveis
    }

    int **resultado = allocateIntMatrix(l1, c2);

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

void metodo_1020() {
    printf("------ Produto de matrizes ------\n");

    char arquivo1[20], arquivo2[20];
    
    printf("Digite o nome do primeiro arquivo: ");
    fgets(arquivo1, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (arquivo1[i] == '\n') {
            arquivo1[i] = '\0';
            break;
        }
    }

    printf("Digite o nome do segundo arquivo: ");
    fgets(arquivo2, 20, stdin);
    for (int i = 0; i < 20; i++) {
        if (arquivo2[i] == '\n') {
            arquivo2[i] = '\0';
            break;
        }
    }

    int l1, c1, l2, c2;
    int **matriz1 = readMatrixFromFile(arquivo1, &l1, &c1);
    int **matriz2 = readMatrixFromFile(arquivo2, &l2, &c2);

    if (matriz1 == NULL || matriz2 == NULL) {
        printf("Erro ao ler uma das matrizes.\n");
        return;
    }

    int **produto = matrixProduct(matriz1, l1, c1, matriz2, l2, c2);

    if (produto == NULL) {
        printf("As matrizes não podem ser multiplicadas. Dimensões incompatíveis.\n");
    } else {
        printf("Resultado da multiplicação:\n");
        printIntMatrix(produto, l1, c2);
        freeMatrix(produto, l1);
    }

    freeMatrix(matriz1, l1);
    freeMatrix(matriz2, l2);
}

int main (){
    int escolha = -1;
    while (escolha!=0){
        printf("Escolha o metodo:\n0 - interromper\n");
        for (int i=1;i<10;i++){
            printf("%d - metodo_101%d\n",i,i);
        }
        printf("10 - metodo_1020\n");
        scanf ("%d",&escolha);
        getchar();
        
        switch (escolha) {
            case 1:
                metodo_1011();
                break;
            case 2:
                metodo_1012();
                break;
            case 3:
                metodo_1013();
                break;
            case 4:
                metodo_1014();
                break;
            case 5:
                metodo_1015();
                break;
            case 6:
                metodo_1016();
                break;
            case 7:
                metodo_1017();
                break;
            case 8:
                metodo_1018();
                break;
            case 9:
                metodo_1019();
                break;
            case 10:
                metodo_1020();
                break;
            case 0:
                printf("processo interrompido\n");
                break;
            default:
                printf("digite um valor valido\n");
                break;
        }
    }
    return 0;
}