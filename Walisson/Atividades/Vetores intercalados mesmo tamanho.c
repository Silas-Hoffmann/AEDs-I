#include <stdio.h>
int main(){
    int n12,n3;
    printf ("tamanho do primeiro e segundo vetor: ");
    scanf ("%d",&n12);
    n3=n12*2;
    int v1[n12],v2[n12],v3[n3],sm1=0, sm2=1;
    
    for (int i=1;i<=n12;i++){
        printf("número do primeiro vetor: ");
        scanf("%d",&v1[i]);
     v3[i+sm1]=v1[i];
        sm1++;
        
    }    
    for (int i=1;i<=n12;i++){    
        printf("número do segundo vetor: ");
        scanf("%d",&v2[i]);
        v3[i+sm2]=v2[i];
        sm2++;
    }
    for (int i=1;i<=n3;i++){
    printf ("%d \n",v3[i]);
    }

    return 0;
}