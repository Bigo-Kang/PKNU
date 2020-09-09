#include <iostream>
#include <stdio.h>

int main()
{
    int x, y,GCD = 0;

    scanf("%d %d", &x, &y);

    while(1) {
        if (x <= y){int tmp = x; x = y; y = tmp;}
        if(x%y==0){
            GCD = y;
            printf("%d, %d GCD is %d\n", x, y, GCD);
            return 0;
        }
        

    }



    return 0;
}