#include <stdio.h>

int main()
{
    int data[25];
    int n,k,count=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);
    scanf("%d",&k);

    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int h=j+1;h<n;h++){
                if(data[i]+data[j]+data[h] == k) count++;
            }
        }
    }

    printf("%d\n",count);

    return 0;
}