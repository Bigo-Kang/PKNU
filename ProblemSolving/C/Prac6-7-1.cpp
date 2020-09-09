#include<stdio.h>
#define MAX 100
int main()
{
    int data[8][8];
    int n = 0, value, ma = 0;
    int tmp[1][1], tmp1,count=0;
    int l[MAX];

    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice2/input1.txt", "r");
    while (!feof(fp)) {
        fscanf(fp, "%d", &value);
        int k = 0;
        while (value > 0){
            if (k > 0){
                for (int i = k; i > 0; i--) data[n][i] = data[n][i - 1];
            }
            data[n][0] = value % 10;
            value /= 10;
            k++;
        }
        if (ma < k) ma = k;
        l[n]=k;
        n++;
    }
    fclose(fp);

    /*
    for(int i=0; i<n;i++) {
        for(int j=0;j<i;j++) {
            int check = 0;
            //
            if (check) {
                for (int k = 0; k < ma; k++) {
                    int tmp = data[i][k];
                    data[i][k] = data[j][k];
                    data[j][k] = tmp;
                }
            }
        }
    }
    */

    for (int y = 0; y<ma; y++){
        for (int x = 0; x<n-1; x++){
            if (data[x][0]>data[x + 1][0]){
                for (int i = 0; i < ma; i++){
                    tmp1 = data[x][i];
                    data[x][i] = data[x + 1][i];
                    data[x + 1][i] = tmp1;
                }
            }
        }
    }

    for(int i = 0; i<n;i++){
        for(int j = 0; j < l[i];j++)
            printf("%d",data[i][j]);
        printf("\n");
    }

    return 0;
}