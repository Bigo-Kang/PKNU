#include <stdio.h>
#define MAX 100

int main()
{
    int data[MAX];
    int n,value,count=0,same=0,k=0;

    scanf("%d",&n);

    while(1){
        if(k == n) break;
        scanf("%d",&value);
        k++;

        if(count>0){
            for(int j=0;j<count;j++){
                if(data[j] == value){
                    same =1; break;
                }
            }
        }
        if(same == 1){
            same = 0;
            continue;
        }

        int i = count-1;
        while(i>=0 && data[i]>value){
            data[i+1]=data[i];
            i--;
        }
        data[i+1] = value;
        count++;
    }

    for(int i = 0; i <count;i++)
        printf("%d ", data[i]);

    return 0;
}