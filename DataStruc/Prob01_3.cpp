#include <stdio.h>
#include <stdlib.h>
int main()
{
    int capacity = 4;
    int size = 0;
    int *array = (int *)malloc(capacity*sizeof(int));
    int k;
    int *tmp;
    scanf("%d",&k);
    while(k!=-1){
        if(size>=capacity){
            tmp = (int *)malloc(2*capacity*sizeof(int));
            for(int i = 0; i < capacity; i++)
                tmp[i]=array[i];
            array = tmp;
            capacity*=2;
        }
        array[size++]= k;
        scanf("%d",&k);
    }
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
    return 0;
}