#include <stdio.h>

int main()
{
    int data[100];
    int n,k,mod,sml;

    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d",&data[n]);
    printf("\n");
    scanf("%d", &k);

    mod = k-data[0];
    if(mod<0) mod *=-1;
    sml = data[0];

    for(int i=1;i<n;i++){
        int tmp = k - data[i];
        if(tmp < 0) tmp *=-1;
        if(tmp<mod){ mod=tmp; sml = data[i];}
    }
    printf("%d\n", sml);

    return 0;
}