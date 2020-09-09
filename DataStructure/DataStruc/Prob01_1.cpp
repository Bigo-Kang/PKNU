#include<stdio.h>
void swap(int,int,int*);
void bubbleSort(int n, int *data){
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(data[i] < data[j])
                swap(i,j,data);
        }
    }
}
void swap(int a, int b, int *data){
//    int tmp = data[a];
//    data[a] = data[b];
//    data[b] = tmp;
    int tmp = *(data+a);
    *(data+a) = *(data+b);
    *(data+b) = tmp;
}
int main()
{
    int *data;
    int n=10;

    for(int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    bubbleSort(n,data);
    for(int i = 0; i < n; i++)
        printf("%d ", data[i]);


    return 0;
}