#include <iostream>
#include <stdio.h>

int main()
{
    int n,tmp1=-2,tmp2=-2,tmp3=-2,count = 0;

    while(1){
        scanf("%d", &n);

        if(n == -1){
            if(tmp1 >tmp2) count++;
            printf("%d\n",count);
            break;
        }
        tmp3 = tmp2;
        tmp2 = tmp1;
        tmp1 = n;

        if(tmp2>tmp1 && tmp3 == -2) count++;
        if(tmp3 != -2 && tmp2>tmp3 && tmp2>tmp1) count++;
    }
    printf("%d\n", count);
    return 0;
}