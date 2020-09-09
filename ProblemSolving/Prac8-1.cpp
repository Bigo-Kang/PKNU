#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int can_move(int move[4][2],int mat[100][100],int x,int y)
{
    int dir=0;
    if(mat[x-1][y]==0)
        move[dir++][0]=-1;
    if(mat[x][y-1]==0)
        move[dir++][1]=-1;
    if(mat[x+1][y]==0)
        move[dir++][0]=1;
    if(mat[x][y+1]==0)
        move[dir++][1]=1;
    return dir;
}

int main() {
    int mat[MAX][MAX];
    int n;

    scanf("%d", &n);

    int count = 0;

    for (int i = 0; i < 10000; i++) {
        int x = n / 2;
        int y = n / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = 0;
            }
        }
        while (1) {
            mat[x][y] = 1;
            if (x == 0 || x == n - 1 || y == 0 || y == n - 1) {
                count ++;
                break;
            }
            int move[4][2]={{0,0},{0,0},{0,0},{0,0}};
            int dir = can_move(move,mat,x,y);
            if(dir == 0)
                break;
            int random = rand() % dir;
            x += move[random][0];
            y += move[random][1];
        }
    }

    printf("%f",(double)count/10000.0);

    return 0;
}