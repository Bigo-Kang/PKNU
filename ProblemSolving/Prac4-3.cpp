#include <stdio.h>

int main()
{
    int num,count=0,j;

    scanf("%d", &num);

    for(int i = num; i > 0; i--){
        j=i;
        if(j< 10)break;
        while(j > 0){
            if(j%10 == 0) count++;
            j /= 10;
        }
    }
    printf("%d\n", count);

    return 0;
}