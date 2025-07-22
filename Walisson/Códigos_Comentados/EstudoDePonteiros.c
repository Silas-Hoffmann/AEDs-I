#include <stdio.h>
#include <stdlib.h>
//Execute para ver a explicação do código

void exemp1 ();
void exemp2 ();
void exemp3 ();
void exemp4 ();
void f1(int a, int *b, int *c);

int main (){
    printf ("-\n-\n-\n----------- Estudo 1 -----------\n");
    exemp1 ();
    printf ("-\n-\n-\n----------- Estudo 2 -----------\n");
    exemp2 ();
    printf ("-\n-\n-\n----------- Estudo 3 -----------\n");
    exemp3 ();
    printf ("-\n-\n-\n----------- Estudo 4 -----------\n");
    exemp4 ();
}

void exemp1 (){
    printf ("------------------------------\n");
    printf ("Estudo de Ponteiro com números\n");
    printf ("------------------------------\n");
    int x=5, y=6;
    int *px=&x;
    int *py=&y;
    printf ("px(%d) != py(%d)\n", *px, *py);
    printf ("px(%d) != py(%d)\n", px, py);
    printf ("\n");
    px=py;
    printf ("px(%d) = py(%d)\n", *px, *py);
    printf ("px(%d) = py(%d)\n", px, py);
    *py=(*py)*(*px);
    *px=*px+2;
    printf ("operação: *py=(*py)*(*px)\n");
    printf ("operação: *px=*px+2\n");
    printf ("\n");
    printf ("resultado: x=%d, y=%d, px=%d, py=%d\n", x, y, *px, *py);
    printf ("\n");
    printf ("-> Esse código mostra que quando fazemos a igualdade px=py, estamos indicando que o py aponte para o endereço que px já está apontando\n");
    printf ("-> Ao usar ponteiro:\n\t Utilizar '*': referencia o valor da variável que o ponteiro aponta\n\t Utilizar '&': referencia o endereço do próprio ponteiro\n\t Sem símbolo: referencia o endereço que o ponteiro aponta");
    printf ("\n");
    printf ("\n");
}

void exemp2 (){
    printf ("---------------------------\n");
    printf ("Estudo de Ponteiro com Char\n");
    printf ("---------------------------\n");
    char c = 'z';
    char *pc = &c;
    printf ("Conteudo de c (%c)\n",c);
    printf ("Endereço de c (%p)\n",&c);
    printf ("Conteudo de pc (%p)\n",pc);
    printf ("Conteúdo de *pc (%c)\n", *pc);
    printf ("\n");
    pc=pc+1;
    printf ("operaçao: pc=pc+1\n");
    printf ("\n");
    printf ("Conteudo de pc (%p)\n",pc);
    printf ("Conteudo de *pc (%c)\n", *pc);    
}

void f1(int a, int *b, int *c){
    printf ("\na=x");
    printf ("\na+2\n");
    a=a+2;
    printf ("y = y+1\n");
    *b=*b+1;
    printf ("z = a+z");
    *c=*c+a;
}

void exemp3 (){
    printf ("-----------------------------\n");
    printf ("Estudo de Ponteiro com função\n");
    printf ("-----------------------------\n");
    int x=2, y=3, z=1;
    printf ("inicio:  x%d y%d z%d\n", x, y, z);
    
    while (y<10){
        f1(x, &y, &z);
        printf ("\nresultado: x%d y%d z%d", x, y, z);
        printf ("\n");
    }
}

void exemp4 (){
    printf ("----------------------------------\n");
    printf ("Ponteiros sem inicialização (ERRO)\n");
    printf ("----------------------------------\n");
    int *ptr1= NULL, *ptr2;
    printf ("%p %p", ptr1, ptr2);
    printf ("%d %d", *ptr1, *ptr2);
}