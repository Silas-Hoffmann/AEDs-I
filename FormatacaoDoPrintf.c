#include<stdio.h>
void inteiro(int i){
    printf ("Decimal: %05d\n",i);
    printf ("Hexadecimal: %x\n",i);
    printf ("Octal: %o\n",i);
    printf ("Char: %c\n",i);
}

void flut (float f){
    printf ("Com 6 casas decimais: %.6f\n",f);
    printf ("Com 2 casas decimais: %.2f\n",f);
    printf ("Notação científica (lower): %.6e\n",f);
    printf ("Notação científica (upper): %.6E",f);
}

int main (){
    int i;
    float f;
    scanf ("%d",&i);
    scanf ("%f",&f);
    inteiro (i);
    flut (f);
    return 0;
}