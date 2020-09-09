#include <stdio.h>

int main()
{
    int n,m,count=0;
    scanf("%d %d", &n,&m);

    for(int i =0 - n; i <= m; i++){
        if(i>=1)
            printf(" %3d",i);
        else
            printf("    ");
        count++;
        if(count%7 == 0)
            printf("\n");
    }

    return 0;
}