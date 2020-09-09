#include <stdio.h>
int find(int n, int data[],int count);
//void insert(int data[], int count);
void inserT(int data[],int count, int num);
int main()
{
    int data[100];
    int num, count = 1;

    while(1){
        scanf("%d", &num);
        if(num == -1) break;
        int result = find(num,data,count);
        if(result == -1) {
            inserT(data,count,num);
            //data[count-1] = num;
            //insert(data,count);
            for(int i = 0; i < count; i++)
                printf("%d ", data[i]);
            printf("\n");
            count++;
        }
        else
            printf("duplicate entry : %d\n", result);
    }
    return 0;
}

int find(int n, int data[],int count){
    for(int i = 0; i < count; i++)
        if(n == data[i]) return i;
    return -1;
}
/*
void insert(int data[], int count){
    for(int i = 0; i < count; i++){
        for(int j = count-1; j > i;j--){
            if(data[i] > data[j]){
                int tmp = data[j];
                data[j] = data[i];
                data[i] = tmp;
            }
        }
    }
}
*/
void inserT(int data[],int count, int num){
    if(count < 2) data[count-1] = num;
    for(int i = count; i > 0 ; i--){
        if(data[i-1] > num){
            data[i] = data[i-1];
            data[i-1] = num;
        }
        else {
            data[i] = num;
            break;
        }
    }
}