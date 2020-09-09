#include <stdio.h>
int main()
{
    int x;
    double y=1, e = 0.00001, newy =0.0;
    scanf("%d", &x);
    while (1) {
        newy = (y + (x / y)) / 2.0;
        e = 0.00001*newy;
        printf("%d %lf %lf %lf %.12lf\n", x, y, x / y, newy, e);
        if(y>newy && (y-newy) < e) break;
        else if(y <=newy && (newy-y) < e) break;
        y = newy;
    }
    return 0;
}
