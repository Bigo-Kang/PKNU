#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int dirMove(int[4][2],int[MAX][MAX],int,int);

int main()
{
    int mat[MAX][MAX];
    int n;

    srand((unsigned int)time(NULL));
    scanf("%d",&n);

    int count = 0;
    for(int i = 0; i < 10000; i++){
        mat[n][n]={0};
        int x = n / 2;
        int y = n / 2;

        while(1) {
            mat[x][y] = 1;
            if(x == 0 || x == n-1 || y == 0 || y == n-1){
                count++;
                break;
            }
            int dir[4][2]={{0,0},{0,0},{0,0},{0,0}};
            int check = dirMove(dir,mat,x,y);
            if(check == 0) break;
            int move = rand()%check;

            x += dir[move][0];
            y += dir[move][1];
        }
    }

    printf("%lf", count/10000.0);

    return 0;
}

int dirMove(int dir[4][2],int mat[MAX][MAX],int a,int b){
    int check = 0;
    if(mat[a+1][b] == 1)
        dir[check++][0] = 1;
    if(mat[a][b+1] == 1)
        dir[check++][1] = 1;
    if(mat[a-1][b] == 1)
        dir[check++][0] = -1;
    if(mat[a][b-1] == 1)
        dir[check++][1] = -1;

    return check;
}