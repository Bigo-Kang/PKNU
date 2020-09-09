#include <iostream>
#include <stdio.h>

int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4;
    for(int i =0; i<7;i++) {
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        if (x1 == x2 && y2 == y3 && x3 == x4 && y4 == y1)
            puts("Yes\n");
        else if (y1 == y2 && x2 == x3 && y3 == y4 && x4 == x1)
            puts("Yes\n");
        else
            puts("No\n");
    }
    return 0;
}