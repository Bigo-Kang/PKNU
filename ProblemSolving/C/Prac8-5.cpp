#include <stdio.h>
#define MAX 100

int main()
{
    int mat[MAX][MAX];
    int n;
    FILE *fp = fopen("/Users/KangDaeWon/Clion/practice02/input4.txt","r");
    fscanf(fp,"%d",&n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            fscanf(fp, "%d", &mat[i][j]);
    fclose(fp);

    int maxSum = mat[0][0];

    for(int startX = 0; startX < n; startX++){
        for(int startY = 0; startY < n; startY++){

            for(int endX = startX; endX < n; endX++){
                for(int endY = startY; endY < n; endY++){

                    int sum = 0;
                    for(int x = startX; x <= endX; x++)
                        for(int y = startY; y <= endY; y++)
                            sum += mat[x][y];
                    if(maxSum < sum) maxSum = sum;
                }
            }
        }
    }
    printf("%d\n",maxSum);

    return 0;
}