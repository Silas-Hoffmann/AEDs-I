#include <stdio.h>

void retirarN(char *texto){ // retira o \n do final das strings, evitando a utilização da biblioteca string.h
    while (*texto!='\n' || *texto!='\0'){
        //printf ("%c",*texto);
        texto++;
    }
    *texto='\0';
}

void contador(int* cont){ // funcao contadora
    *cont=*cont+1;
}

void maiCmenP(char* pointer){
    int cont=0;
    char novaString[50];
    printf ("\nc < caracteres < p: ");
    while (*pointer!='\0'){
        if (*pointer>99 && *pointer<112){
            printf ("|%c| ",*pointer);
            novaString[cont]=*pointer;
            contador(&cont);
        }
        pointer++;
    }
    novaString[cont+1]='\0';
    char* pointer2=&novaString[0];
    printf("\nValores na Nova String: ");
    while (*pointer2!='\0'){
        printf("|%c| ",*pointer2);
        pointer2++;
    }
    
    printf ("\nTotal: %d", cont);
    printf ("\n\n");
}

void maiCmenP2(char* pointer){
    int cont=0;
    while (*pointer!='\0'){
        if ((*pointer>67 && *pointer<80) || (*pointer>99 && *pointer<112)){
            contador(&cont);
        }
        pointer++;
    }
    
    printf ("\nTotal: %d", cont);
    printf ("\n\n");
}

void maiCmenP3(char* pointer){
    printf ("\nc ou C < caracteres < p ou P: ");
    while (*pointer!='\0'){
        if ((*pointer>67 && *pointer<80) || (*pointer>99 && *pointer<112)){
            printf ("|%c| ",*pointer);
        }
        pointer++;
    }
    printf ("\n\n");
}

void maiCmenP4(char* pointer){
    printf ("\nDigitos pares: ");
    while (*pointer!='\0'){
        if (*pointer%2==0){
            printf ("|%c| ",*pointer);
        }
        pointer++;
    }
    printf ("\n\n");
}

void maiCmenP5(char* pointer){
    printf ("\nDigitos alfanumericos: ");
    while (*pointer!='\0'){
        if ((*pointer>47 && *pointer<58) || (*pointer>64 && *pointer<91) || (*pointer>96 && *pointer<123)){
            printf ("%c ",*pointer);
        }
        pointer++;
    }
    printf ("\n\n");
}

void maiCmenP6(char* pointer, char* pointer2, int* pos) {
    while (*pointer != '\0') {
        if ((*pointer > 47 && *pointer < 58) || (*pointer > 64 && *pointer < 91) || (*pointer > 96 && *pointer < 123)) {
            *(pointer2 + *pos) = *pointer;
            (*pos)++;
        }
        pointer++;
    }
}

void metoth0411(){
    int quant=0;
    double m=0.0, n=(double)0.0;
    int cont=0;
    
    printf ("Digite a quantidade de valores: ");
    scanf ("%d",&quant);
    printf ("Digite o intervalo: ");
    scanf ("%lf",&m);
    scanf ("%lf",&n);
    
    if (m>n){ // organizar a crescente nas variaveis
        cont=m;
        m=n;
        n=cont;
        cont=0;
    }
    
    printf ("Digite os valores: ");
    double arr[quant];
    for (int i=0 ; i<quant ; i++){
        scanf ("%lf",&arr[i]);
    }
    printf ("\nValores no intervalo fechado (%.2lf %.2lf):  ",m,n);
    for (int i=0 ; i<quant ; i++){
        if (arr[i]>m && arr[i]<n){
            printf ("%.2lf ",arr[i]);
            cont=cont+1;
        }
    }
    printf ("\nTotal: %d",cont);
    printf("\n\n");
}

void metoth0412(){
    printf ("Digite o texto: ");
    char string[50];
    fgets(string,50,stdin);
    retirarN(&string[0]);
    char* pointer=&string[0];
    int cont=0;

    printf ("\nc < caracteres < p: ");
    while (*pointer!='\0'){
        if (*pointer>99 && *pointer<112){
            printf ("|%c| ",*pointer);
            cont=cont+1;
        }
        pointer++;
    }
    printf ("\nTotal: %d", cont);
    printf ("\n\n");
}

void metoth0413(){
    printf ("Digite o texto: ");
    char string[50];
    fgets(string,50,stdin);
    retirarN(&string[0]);
    int cont=0;
    char* pointer = &string[0];

    printf ("\nc < caracteres < p: ");
    while (*pointer!='\0'){
        if (*pointer>99 && *pointer<112){
            printf ("|%c| ",*pointer);
            contador(&cont);
        }
        pointer++;
    }
    printf ("\nTotal: %d", cont);
    printf ("\n\n");
}

void metoth0414(){
    char string[50];
    int cont=0;
    
    printf ("Digite o texto: ");
    fgets(string,50,stdin);
    
    retirarN(&string[0]);
    maiCmenP(&string[0]);
}

void metoth0415(){
    char string[50];
    int cont=0;
    
    printf ("Digite o texto: ");
    fgets(string,50,stdin);
    
    retirarN(&string[0]);
    maiCmenP2(&string[0]);
}

void metoth0416(){
    char string[50];
    int cont=0;
    
    printf ("Digite o texto: ");
    fgets(string,50,stdin);
    
    retirarN(&string[0]);
    maiCmenP3(&string[0]);
}

void metoth0417(){
    char string[50];
    int cont=0;
    
    printf ("Digite o texto: ");
    fgets(string,50,stdin);
    
    retirarN(&string[0]);
    maiCmenP4(&string[0]);
}

void metoth0418(){
    char string[50];
    int cont=0;
    
    printf ("Digite o texto: ");
    fgets(string,50,stdin);
    
    retirarN(&string[0]);
    char* pointer=&string[0];

    printf ("\nDigitos nao alfanumericos: ");
    while (*pointer!='\0'){
        if (!((*pointer>47 && *pointer<58) || (*pointer>64 && *pointer<91) || (*pointer>96 && *pointer<123))){
            printf ("%c ",*pointer);
        }
        pointer++;
    }
    printf ("\n\n");
}

void metoth0419(){
    char string[50];
    int cont=0;
    
    printf ("Digite o texto: ");
    fgets(string,50,stdin);
    
    retirarN(&string[0]);
    maiCmenP5(&string[0]);
}

void metoth0420(){
    char string[50], string2[50];
    int palav = 0, pos = 0;

    printf("Quantidade de palavras: ");
    scanf("%d", &palav);
    getchar();
    
    for (int i = 0; i < palav; i++) {
        printf("Digite as palavras: ");
        fgets(string, 50, stdin);
        maiCmenP6(string, string2, &pos);
    }

    int i = 0;
    printf("\nAlfanuméricos: ");
    while (string2[i] != '\0') {
        printf("%c ", string2[i]);
        i++;
    }
    printf("\nQuantidade: %d",pos);
    printf("\n\n");
}


int main (){
    int opc=-1;

    while (opc!=0){
        printf ("Escolha o metodo:\n");
        for (int i=0;i<10;i++){
            printf ("0%d\n",411+i);
        }
        printf ("0 = Cancelar\n");
        printf ("Escolha: ");
        scanf ("%d",&opc);
        getchar();
    
        switch (opc) {
            case 411:
                metoth0411();
                break;
            case 412:
                metoth0412();
                break;
            case 413:
                metoth0413();
                break;
            case 414:
                metoth0414();
                break;
            case 415:
                metoth0415();
                break;
            case 416:
                metoth0416();
                break;
            case 417:
                metoth0417();
                break;
            case 418:
                metoth0418();
                break;
            case 419:
                metoth0419();
                break;
            case 420:
                metoth0420();
                break;
            default:
                break;
        }
    }
}