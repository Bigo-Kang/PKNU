#include <stdio.h>
#define MAX 100
int main()
{
    int data[100];
    int value,n=0,same=0;

    while(1){
        scanf("%d",&value);

        if(value==-1) break;

        for(int k=0;k<n;k++) {
            if (data[k] == value) {
                printf("duplicate entry\n");
                same = 1;
            }
        }
        if(same==1){
            same=0; continue;
        }

        int i = n-1;
        while(i>=0 && data[i]>value){
            data[i+1]=data[i];
            i--;
        }
        data[i+1]=value;
        n++;

        for(int j=0;j<n;j++)
            printf("%d ", data[j]);
        printf("\n");
    }
    return  0;
}