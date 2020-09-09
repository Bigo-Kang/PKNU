#include <stdio.h>

void maxMin(int n, int *a, int *min, int *max){
    *min = *max = a[0];
    for(int i = 1; i < n; i++){
        if(*max < a[i]) *max = a[i];
        if(*min > a[i]) *min = a[i];
    }
}
int main()
{
    int data[100];
    int n, min = 0, max = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    maxMin(n,data,&min,&max);
    printf("the min is %d and the max is %d.\n", min, max);
    return 0;
}