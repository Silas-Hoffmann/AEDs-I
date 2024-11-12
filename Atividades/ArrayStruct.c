#include <stdio.h>
struct carro {
    char marca[20];
    int ano;
    double preco;
};
int main (){
    int n;
    double valorMaximo;
    scanf ("%d",&n);
    getchar();
    struct carro veiculo[n];
    for (int i=0;i<n;i++){
        fgets(veiculo[i].marca,sizeof(veiculo[i].marca),stdin);
        veiculo[i].marca[strcspn(veiculo[i].marca, "\n")] = '\0';
        scanf ("%d",&veiculo[i].ano);
        scanf ("%lf",&veiculo[i].preco);
        getchar();
    }
    scanf ("%lf",&valorMaximo);
    printf ("Carros com preco menor que %0.2lf:\n",valorMaximo);
    for (int i=0;i<n;i++){
        if (veiculo[i].preco<=valorMaximo){
            printf ("Marca: %s, Ano: %d, Preco: %0.2lf\n",veiculo[i].marca, veiculo[i].ano, veiculo[i].preco);
        }
    }
}
