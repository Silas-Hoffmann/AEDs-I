#include <stdio.h>

int main(){
    int n;
    double c1 = 0, c2 = 0, c3 = 0, c4 = 0, b = 0, nul = 0;
    printf ("1 - Candidato 1\n2 - Candidato 2\n3 - Candidato 3\n4 - Candidato 4\n5 - Voto nulo\n6 - Voto branco\n");
    
    scanf("%d", &n);
    
    while (n > 0){
        switch (n){
            case 1:
                c1 += 1;
                break;
            case 2:
                c2 += 1;
                break;
            case 3:
                c3 += 1;
                break;
            case 4:
                c4 += 1;
                break;
            case 5:
                nul += 1;
                break;
            case 6:
                b += 1;
                break;
            default:
                printf("Voto inválido!\n");
                break;
        }
        
        scanf("%d", &n);
    }

    double total = c1 + c2 + c3 + c4 + b + nul;
    double perc = (b / total) * 100;

    printf("\nResultado da votação:\n");
    printf("Candidato 1: %.0lf voto(s)\n", c1);
    printf("Candidato 2: %.0lf voto(s)\n", c2);
    printf("Candidato 3: %.0lf voto(s)\n", c3);
    printf("Candidato 4: %.0lf voto(s)\n", c4);
    printf("Votos nulos: %.0lf\n", nul);
    printf("Porcentagem de votos em branco: %.2lf%%\n", perc);

    return 0;
}
