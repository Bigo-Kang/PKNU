#include <iostream>
#include <stdio.h>

int main()
{
    int a,b,c,d,e,f,g,h;

    for(int i = 0; i<14;i++) {
        scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);

        if (a == c && e == g) {
            if (a == g) {
                if ((b <= g <= d) || (b <= h <= d))
                    printf("Yes\n");
                else if ((g <= b <= h) || (g <= d <= h))
                    printf("Yes\n");
                else
                    printf("No\n");
            } else
                printf("No\n");
        } else if (b == d && f == h) {
            if (b == f) {
                if ((a <= g <= c) || (a <= e <= c))
                    printf("Yes\n");
                else if ((e <= a <= g) || (e <= c <= g))
                    printf("Yes\n");
                else
                    printf("No\n");
            } else
                printf("No\n");
        } else if (a == c && f == h) {
            if ((b <= f <= d) && (e <= a <= g))
                printf("Yes\n");
            else
                printf("No\n");
        } else if (b == d && e == g) {
            if ((h <= b <= f) && (a <= g <= c))
                printf("Yes\n");
            else
                printf("No\n");
        } else
            printf("Input error\n");
    }
    return 0;
}