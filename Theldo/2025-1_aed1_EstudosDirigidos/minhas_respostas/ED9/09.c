#include <stdio.h>
#include <string.h>

void gravar_matriz_em_arquivo(double matriz[][100], int m, int n, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivo, "%d %d\n", m, n); // salva dimensões
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(arquivo, "%.2lf ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Matriz salva em '%s'\n", nome_arquivo);
}

void ler_matriz_do_arquivo(double matriz[][100], int* m, int* n, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    fscanf(arquivo, "%d %d", m, n);
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(arquivo, "%lf", &matriz[i][j]);
        }
    }

    fclose(arquivo);
}

void leitura (int* m, int* n, int* verificacao){
    if (*verificacao==2 || *verificacao==4){
        printf ("Digite a altura da matriz: ");
        scanf("%d",m);
        getchar();
        if (*verificacao==4){
            *verificacao=3;
        }
    }

    //printf ("confirmacao: %d\n",*m);
    //printf ("verificacao: %d\n\n",*verificacao);
    
    if (*verificacao==3){
        printf ("Digite a largura da matriz: ");
        scanf("%d",n);
        getchar();
        *verificacao=4;
    }
    
    //printf ("confirmacao: %d\n",*n);
    //printf ("verificacao: %d\n\n",*verificacao);
    //printf ("\n\n");
}

void positivo (int* m, int* n, int* verificacao){
    if (*m<=0){
        printf ("altura invalida: digite um valor maior que 0\n");
        *verificacao=2;
    }
    if (*n<=0){
        printf ("largura invalida: digite um valor maior que 0\n");
        if (*verificacao==2){
            *verificacao=4;
        } else if (*verificacao==4){
            *verificacao=3;
        }
    }
    if (*n>0 && *m>0){
        *verificacao=1;
    }else {
        printf ("\n");
    }

    //printf ("verificacao positivo: %d\n",*verificacao);
    //printf ("termino do void positivo\n\n");
}

void metoth_0911 (int* m, int* n, int* verificacao,char* terminar){
    while (*verificacao!=1){
        leitura(m,n,verificacao);
        positivo(m,n,verificacao);

        if (*verificacao==1){
            printf ("matriz %dx%d criada\nconfirmar? [s][n]\n",*m,*n);
            *terminar=getchar();
            getchar();
            if (*terminar=='n'){
                *verificacao=4;
            }
        }
    }
}

void metoth_0912() {
    double matriz_original[100][100];
    int m, n;
    char nome_arquivo[50];

    printf("Digite o nome do arquivo para salvar a matriz (ex: matriz.txt): ");
    fgets(nome_arquivo, sizeof(nome_arquivo), stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;

    printf("Digite as dimensões da matriz (linhas e colunas): ");
    scanf("%d %d", &m, &n);
    getchar();

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matriz_original[i][j]);
        }
    }
    getchar();

    gravar_matriz_em_arquivo(matriz_original, m, n, nome_arquivo);

    double matriz_lida[100][100];
    int m_lida, n_lida;
    ler_matriz_do_arquivo(matriz_lida, &m_lida, &n_lida, nome_arquivo);

    printf("Matriz lida do arquivo:\n");
    for (int i = 0; i < m_lida; i++) {
        for (int j = 0; j < n_lida; j++) {
            printf("%.2lf ", matriz_lida[i][j]);
        }
        printf("\n");
    }
}

void metoth_0913() {
    int m, n;
    double matriz[100][100];

    printf("Digite as dimensões da matriz (linhas e colunas): ");
    scanf("%d %d", &m, &n);
    getchar();

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    getchar();

    if (m != n) {
        printf("A matriz nao é quadrada. Nao há diagonal principal.\n");
        return;
    }

    printf("Diagonal principal:\n");
    for (int i = 0; i < m; i++) {
        printf("%.2lf ", matriz[i][i]);
    }
    printf("\n");
}

void metoth_0914() {
    int m, n;
    double matriz[100][100];

    printf("Digite as dimensões da matriz (linhas e colunas): ");
    scanf("%d %d", &m, &n);
    getchar();

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    getchar();

    if (m != n) {
        printf("A matriz nao é quadrada. Nao há diagonal secundaria.\n");
        return;
    }

    printf("Diagonal secundaria:\n");
    for (int i = 0; i < m; i++) {
        printf("%.2lf ", matriz[i][n - 1 - i]);
    }
    printf("\n");
}

void metoth_0915() {
    int m, n;
    double matriz[100][100];

    printf("Digite as dimensões da matriz (linhas e colunas): ");
    scanf("%d %d", &m, &n);
    getchar();

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    getchar();

    if (m != n) {
        printf("A matriz nao é quadrada. Nao há região abaixo da diagonal principal definida.\n");
        return;
    }

    printf("Valores abaixo da diagonal principal:\n");
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
    }
    printf("\n");
}

void metoth_0916() {
    int m, n;
    double matriz[100][100];

    printf("Digite as dimensões da matriz (linhas e colunas): ");
    scanf("%d %d", &m, &n);
    getchar();

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    getchar();

    if (m != n) {
        printf("A matriz nao é quadrada. Nao há região acima da diagonal principal definida.\n");
        return;
    }

    printf("Valores acima da diagonal principal:\n");
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
    }
    printf("\n");
}

void metoth_0917() {
    int m, n;
    double matriz[100][100];

    printf("Digite as dimensões da matriz (linhas e colunas): ");
    scanf("%d %d", &m, &n);
    getchar();

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    getchar();

    if (m != n) {
        printf("A matriz nao é quadrada. Nao há região abaixo e na diagonal secundária definida.\n");
        return;
    }

    printf("Valores abaixo e na diagonal secundária:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // A condição para valores abaixo ou na diagonal secundária
            if (i + j >= n - 1) {
                printf("%.2lf ", matriz[i][j]);
            }
        }
    }
    printf("\n");
}

void metoth_0918() {
    int m, n;
    double matriz[100][100];

    printf("Digite as dimensões da matriz (linhas e colunas): ");
    scanf("%d %d", &m, &n);
    getchar();

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    getchar();

    if (m != n) {
        printf("A matriz nao é quadrada. Nao há região acima e na diagonal secundária definida.\n");
        return;
    }

    printf("Valores acima e na diagonal secundária:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // A condição para valores acima ou na diagonal secundária
            if (i + j <= n - 1) {
                printf("%.2lf ", matriz[i][j]);
            }
        }
    }
    printf("\n");
}

void metoth_0919() {
    int m, n;
    double matriz[100][100];
    int todos_zeros = 1;  // Variável para indicar se todos os valores abaixo da diagonal principal são zero

    printf("Digite as dimensões da matriz (linhas e colunas): ");
    scanf("%d %d", &m, &n);
    getchar();

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    getchar();

    if (m != n) {
        printf("A matriz nao é quadrada. Não é possível verificar os valores abaixo da diagonal principal.\n");
        return;
    }

    // Verificar se todos os valores abaixo da diagonal principal são zero
    for (int i = 1; i < m; i++) {  // Começa em 1 porque a diagonal principal está na linha i == j
        for (int j = 0; j < i; j++) {
            if (matriz[i][j] != 0) {
                todos_zeros = 0;  // Encontrou um valor diferente de zero
                break;
            }
        }
        if (!todos_zeros) break;  // Sai do laço se encontrar um valor não zero
    }

    if (todos_zeros) {
        printf("Todos os valores abaixo da diagonal principal são zeros.\n");
    } else {
        printf("Existem valores diferentes de zero abaixo da diagonal principal.\n");
    }
}

void metoth_0920() {
    int m, n;
    double matriz[100][100];
    int nao_sao_zeros = 1;  // Variável para indicar se todos os valores acima da diagonal principal são diferentes de zero

    printf("Digite as dimensões da matriz (linhas e colunas): ");
    scanf("%d %d", &m, &n);
    getchar();

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    getchar();

    if (m != n) {
        printf("A matriz nao é quadrada. Não é possível verificar os valores acima da diagonal principal.\n");
        return;
    }

    // Verificar se todos os valores acima da diagonal principal são diferentes de zero
    for (int i = 0; i < m; i++) {  // Percorrer todas as linhas
        for (int j = i + 1; j < n; j++) {  // A coluna j deve ser maior que i (acima da diagonal principal)
            if (matriz[i][j] == 0) {
                nao_sao_zeros = 0;  // Encontrou um valor zero
                break;
            }
        }
        if (!nao_sao_zeros) break;  // Sai do laço se encontrar um valor zero
    }

    if (nao_sao_zeros) {
        printf("Todos os valores acima da diagonal principal são diferentes de zero.\n");
    } else {
        printf("Existem valores iguais a zero acima da diagonal principal.\n");
    }
}

int main (){
    
    char opc[6];

    while (strcmp(opc, "0") != 0){

        //------------------leitura do metodo------------------
        printf("Escolha o metodo:\n");
        for (int i=0;i<10;i++){
            printf ("09%d - metoth09%d\n",11+i,11+i);
        }
        printf ("0 - cancelar\n");
        fgets(opc, sizeof(opc), stdin);
        opc[strcspn(opc, "\n")] = 0;
        
        //------------------escolha do metodo------------------

        //-------------------------0911------------------------
        if (strcmp(opc, "0911") == 0){
            int m=0.0, n=(int)0.0, verificacao=(int)4;
            char terminar;
    
            metoth_0911(&m, &n, &verificacao, &terminar);
            double matriz[m][n];
            printf ("Digite os valores da matriz:\n");
            for (int i=0;i<m;i++){
                printf ("Linha %d:\n",i+1);
                for (int j=0;j<n;j++){
                    scanf ("%lf",&matriz[i][j]);
                }
            }

            printf ("Impressao da matriz:\n");
            for (int i=0;i<m;i++){
                for (int j=0;j<n;j++){
                    printf ("%.2lf ",matriz[i][j]);
                }
                printf("\n");
            }
        }

        //-------------------------0912------------------------
        else if (strcmp(opc, "0912") == 0){
            metoth_0912();
        }

        //-------------------------0913------------------------
        else if (strcmp(opc, "0913") == 0){
            metoth_0913();
        }

        //-------------------------0914------------------------
        else if (strcmp(opc, "0914") == 0){
            metoth_0914();
        }

        //-------------------------0915------------------------
        else if (strcmp(opc, "0915") == 0){
            metoth_0915();
        }

        //-------------------------0916------------------------
        else if (strcmp(opc, "0916") == 0){
            metoth_0916();
        }

        //-------------------------0917------------------------
        else if (strcmp(opc, "0917") == 0){
            metoth_0917();
        }

        //-------------------------0918------------------------
        else if (strcmp(opc, "0918") == 0){
            metoth_0918();
        }

        //-------------------------0919------------------------
        else if (strcmp(opc, "0919") == 0){
            metoth_0919();
        }

        //-------------------------0920------------------------
        else if (strcmp(opc, "0920") == 0){
            metoth_0920();
        }

    }
    return 0;
}