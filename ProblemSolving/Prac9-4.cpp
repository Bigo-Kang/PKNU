#include <stdio.h>
int compareInts(int sa, int ta, int sb, int tb);
void swapData(int x[], int y[], int a, int b);
int main()
{
    int x[50],y[50];
    int n;
    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice02/input4.txt", "r");
    fscanf(fp,"%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d %d", &x[i], &y[i]);
        //printf("%d %d\n", x[i], y[i]);
    }
    fclose(fp);
    //printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            //printf("%d %d %d %d\n", x[i], y[i], x[j], y[j]);
            //printf("\n");
            if (compareInts(x[i], y[i], x[j], y[j]) == 1)
                swapData(x, y, i, j);
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d %d\n", x[i],y[i]);
    return 0;
}
int compareInts(int sa, int ta, int sb, int tb) {
    if (sa == sb && ta == tb) return 0;
    else if (sa >= sb && ta > tb) return 1;
    return -1;

}
void swapData(int x[], int y[], int a, int b) {
    int tmpX = x[b]; x[b] = x[a]; x[a] = tmpX;
    int tmpY = y[b]; y[b] = y[a]; y[a] = tmpY;
}