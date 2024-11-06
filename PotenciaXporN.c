#include <stdio.h>
proc (int x, int n){
    if (n==0){
        return 1;
    }
    return x*proc(x, n-1);
}
int main(){
    printf ("Esse código calcula a potência de X elevado a N, utilizando recursividade em funcao");

    int x, n;
    proc (x, n);
    printf ("\nx = ");
    scanf("%d",&x);
    printf ("n = ");
    scanf("%d",&n);
    printf("\nPotencia = %d", proc(x, n));
    return 0;
}