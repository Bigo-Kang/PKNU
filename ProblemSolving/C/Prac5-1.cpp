#include <stdio.h>

int main()
{
    int data[100];
    int n,min1,min2,a=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);
    //min1 = first min2 = second
    if(data[0]>data[1]){ min1=data[1]; min2=data[0];}
    else{ min1=data[0]; min2=data[1];}

    for(int i = 2; i < n; i++) {
        if(data[i]<=min2)min2=data[i];
        if (data[i] <= min1) { min2 = min1; min1 = data[i]; a = 1; }
        if (a == 0) {
            for (int j = 3; j < n; j++) {
                if (data[j] <= min2) { min2 = data[j]; }
            }
        }
    }
    printf("%d %d/n", min1,min2);

    return 0;
}