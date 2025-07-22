#include <stdio.h>

int expo(int i){
    if (i == 0){
        return 1;
    }
    int result = 1;
    for (int j = 0; j < i; j++){
        result *= 2;
    }
    return result;
}

int bindec(int bin, int dec, int i){
    if (bin == 0){
        return dec;
    }
    int dig = bin % 10;
    dec += dig * expo(i);
    return bindec(bin / 10, dec, i+1);
}

int main(){
    int numbin;
    printf("Insira um número binário: ");
    scanf("%d", &numbin);
    printf("Resultado: %d", bindec(numbin, 0, 0));
    return 0;
}
