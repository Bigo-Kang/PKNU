#include<iostream>
#include <stdio.h>

int main()
{
    int a,b,c,d;

    scanf("%d %d %d %d", &a,&b,&c,&d);

    if(a<=b&&c<=d) {
        if((c>=a && c<=b)||(d>=a && d<=b))
            printf("yes\n");
        else if((a>=c && a<=d)||(b>=c && b<=d))
            printf("yes\n");
        else
            puts("No\n");
    }
    else
        puts("Input error\n");
    return 0;
}