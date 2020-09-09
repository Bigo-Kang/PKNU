#include <stdio.h>
#define MAX 100

int main()
{
    int mat[MAX][MAX];
    int N;

    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice02/input6.txt","r");
    fscanf(fp,"%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            fscanf(fp,"%d",&mat[i][j]);
    fclose(fp);

    for(int i=0;i<N;i++) {
        if(i%2 == 1) {
            for (int j = N - 1; j >= 0; j--) {
                printf("%d ",mat[i][j]);
            }
        }
        else {
            for (int j = 0; j < N; j++) {
                printf("%d ", mat[i][j]);
            }
        }
    }

    return 0;
}
