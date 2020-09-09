#include <stdio.h>
//#define SWAP(x,y) {int tmp = x; x = y; y = tmp;}
int lenOfOverlap(int, int, int, int);
void swapData(int data[], int a, int b) {
    int tamp1 = data[a];
    data[a] = data[b];
    data[b] = tamp1;
}
int main()
{
    int data[8];
    int c = 0;
    while (c < 7) {
        for (int i = 0; i < 8; i++)
            scanf("%d", &data[i]);
        for (int i = 0; i < 2; i++) {
            if (data[i] > data[i + 2])  swapData(data, i, i + 2);
            if (data[i + 4] > data[i + 6]) swapData(data, i + 4, i + 6);
        }
        int area = lenOfOverlap(data[0], data[2], data[4], data[6])
            * lenOfOverlap(data[1],data[3],data[5],data[7]);
        printf("%d ", area);
        printf("\n");
        c++;
    }
    return 0;
}
int lenOfOverlap(int sa, int ta, int sb, int tb) {
    if(ta<sb) return 0;
    if(tb<sa) return 0;
    if(sa<=sb && ta>=tb) return tb-sb;
    if(sa>=sb && ta<=tb) return ta-sa;
    if(sa<=sb && ta<=tb) return ta-sb;
    if(sa>=sb && ta>=tb) return tb-sa;
    return 0;
}