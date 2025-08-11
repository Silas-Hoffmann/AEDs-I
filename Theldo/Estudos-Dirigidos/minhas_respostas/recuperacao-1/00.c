#include <stdio.h>
#include <string.h>

int soma_divisores_pares(int valor) {
    int soma = 0;
    for (int i = 1; i <= valor; i++) {
        if (valor % i == 0 && i % 2 == 0) {
            soma++;
        }
    }
    return soma;
}

int soma_divisores_impares(int valor) {
    int soma = 0;
    for (int i = 1; i <= valor; i++) {
        if (valor % i == 0 && i % 2 != 0) {
            soma++;
        }
    }
    return soma;
}

void exercicio01() {
    int n;
    printf("Digite a quantidade de valores: ");
    scanf("%d", &n);

    int numeros[n];  // array para armazenar os valores

    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
        getchar();
    }

    for (int i = 0; i < n; i++) {
        int pares = soma_divisores_pares(numeros[i]);
        int impares = soma_divisores_impares(numeros[i]);

        printf("Valor %d: ", numeros[i]);
        if (pares > impares) {
            printf("Mais divisores pares.\n");
        } else if (impares > pares) {
            printf("Mais divisores ímpares.\n");
        } else {
            printf("Mesma quantidade de divisores pares e ímpares.\n");
        }
    }
}

int primo(int valor) {
    int i = 2, resultado = 1;

    if (valor < 2) {
        resultado = 0;
    }

    while (i * i <= valor && resultado == 1) {
        if (valor % i == 0) {
            resultado = 0;
        }
        i++;
    }

    return resultado;
}

void exercicio02() {
    int n;
    printf("Digite a quantidade de valores: ");
    scanf("%d", &n);

    int numeros[n];

    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
        getchar(); // consome o '\n'
    }

    for (int i = 0; i < n; i++) {
        int resultado = primo(numeros[i]);
        printf("Valor %d: ", numeros[i]);
        if (resultado == 1) {
            printf("É primo.\n");
        } else {
            printf("Não é primo.\n");
        }
    }
}

int testar_simbolo_logico(char c) {
    int resultado = 0;
    switch (c) {
        case '&':
        case '|':
        case '!':
            resultado = 1;
            break;
        default:
            resultado = 0;
    }
    return resultado;
}

int testar_simbolo_aritmetico(char c) {
    int resultado = 0;
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            resultado = 1;
            break;
        default:
            resultado = 0;
    }
    return resultado;
}

int testar_simbolo_relacional(char c) {
    int resultado = 0;
    switch (c) {
        case '>':
        case '<':
        case '=':
            resultado = 1;
            break;
        default:
            resultado = 0;
    }
    return resultado;
}

int testar_simbolo_separador(char c) {
    int resultado = 0;
    switch (c) {
        case ' ':
        case '.':
        case ',':
        case ';':
        case ':':
        case '_':
            resultado = 1;
            break;
        default:
            resultado = 0;
    }
    return resultado;
}

void exercicio03() {
    char cadeia[201];

    printf("Digite uma cadeia de caracteres (até 200): ");
    getchar(); // consome o '\n' pendente
    fgets(cadeia, sizeof(cadeia), stdin);
    cadeia[strcspn(cadeia, "\n")] = 0;

    for (int i = 0; cadeia[i] != '\0'; i++) {
        char c = cadeia[i];

        printf("Símbolo '%c': ", c);
        if (testar_simbolo_logico(c)) {
            printf("Operador lógico\n");
        } else if (testar_simbolo_aritmetico(c)) {
            printf("Operador aritmético\n");
        } else if (testar_simbolo_relacional(c)) {
            printf("Operador relacional\n");
        } else if (testar_simbolo_separador(c)) {
            printf("Separador\n");
        } else {
            printf("Outro símbolo\n");
        }
    }
}

int testar_maiuscula(char c) {
    int resultado = 0;
    switch (c) {
        case 'A'...'Z':
            resultado = 1;
            break;
        default:
            resultado = 0;
    }
    return resultado;
}

int testar_minuscula(char c) {
    int resultado = 0;
    switch (c) {
        case 'a'...'z':
            resultado = 1;
            break;
        default:
            resultado = 0;
    }
    return resultado;
}

int testar_digito(char c) {
    int resultado = 0;
    switch (c) {
        case '0'...'9':
            resultado = 1;
            break;
        default:
            resultado = 0;
    }
    return resultado;
}

void exercicio04() {
    char cadeia[201];
    int maiusculas = 0, minusculas = 0, digitos = 0;
    int logicos = 0, aritmeticos = 0, relacionais = 0, separadores = 0;

    printf("Digite uma cadeia de caracteres (até 200): ");
    getchar(); // consome o '\n'
    fgets(cadeia, sizeof(cadeia), stdin);
    cadeia[strcspn(cadeia, "\n")] = 0;

    for (int i = 0; cadeia[i] != '\0'; i++) {
        char c = cadeia[i];
        switch (1) {
            case 1:
                if (testar_maiuscula(c)) {
                    maiusculas++;
                    break;
                }
                if (testar_minuscula(c)) {
                    minusculas++;
                    break;
                }
                if (testar_digito(c)) {
                    digitos++;
                    break;
                }
                if (testar_simbolo_logico(c)) {
                    logicos++;
                    break;
                }
                if (testar_simbolo_aritmetico(c)) {
                    aritmeticos++;
                    break;
                }
                if (testar_simbolo_relacional(c)) {
                    relacionais++;
                    break;
                }
                if (testar_simbolo_separador(c)) {
                    separadores++;
                    break;
                }
        }
    }

    printf("Maiúsculas: %d\n", maiusculas);
    printf("Minúsculas: %d\n", minusculas);
    printf("Dígitos: %d\n", digitos);
    printf("Operadores lógicos: %d\n", logicos);
    printf("Operadores aritméticos: %d\n", aritmeticos);
    printf("Operadores relacionais: %d\n", relacionais);
    printf("Separadores: %d\n", separadores);
}

int main() {

    char opc[6];

    while (strcmp(opc, "0") != 0){
        //-----------------leitura do exercicio----------------
        printf("Escolha o metodo:\n");
        for (int i=0;i<10;i++){
            printf ("0%d - exercicio0%d\n",i,i);
        }
        printf ("10 - exerciocio10\n0 - cancelar\n");
        fgets(opc, sizeof(opc), stdin);
        opc[strcspn(opc, "\n")] = 0;
        
        //-----------------escolha do exercicio----------------
        if (strcmp(opc, "01") == 0){
            exercicio01();
        }else if (strcmp(opc, "02") == 0){
            exercicio02();
        }else if (strcmp(opc, "03") == 0){
            exercicio03();
        }else if (strcmp(opc, "04") == 0){
            exercicio04();
        }else if (strcmp(opc, "05") == 0){
            //exercicio05();
        }else if (strcmp(opc, "06") == 0){
            //exercicio06();
        }else if (strcmp(opc, "07") == 0){
            //exercicio07();
        }else if (strcmp(opc, "08") == 0){
            //exercicio08();
        }else if (strcmp(opc, "09") == 0){
            //exercicio09();
        }else if (strcmp(opc, "10") == 0){
            //exercicio10();
        }
    }
    return 0;
}

// fazer questões 5 6 7 8 9 10