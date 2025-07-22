#include<stdio.h>
int main () {
int num=2;
scanf("%d",&num);
while (num>=0){
    if ((num%2)==0){
        printf("par\n");
    }else if ((num%2)==1){
        printf("impar\n");
    }else if (num==0){
        printf("par\n");
    }
    scanf("%d",&num);
}
return 0;        
}