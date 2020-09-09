#include <stdio.h>

int main()
{
    int data[20];
    int n,count=1,max=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);

    for(int i=0;i<n-1;i++){
        if(data[i] <= data[i+1])count++;
        else count=1;

        if(count>max)max = count;
    }

    printf("%d\n",max);

    return 0;
}