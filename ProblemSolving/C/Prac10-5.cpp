#include <stdio.h>

int check(int mat[][100],int com, int val, int dir[][2],int a, int b){
    for(int i = 0; i < val; i++){
        a +=dir[com][0];
        b +=dir[com][1];
        if(mat[a][b] == 1) return 0;
    }
    return 1;
}
void map(int mat[][100],int com, int val, int dir[][2],int a, int b){
    for(int i = 0; i < val; i++){
        a +=dir[com][0];
        b +=dir[com][1];
        mat[a][b] = 1;
    }
}
int main()
{
    int mat[100][100] = {0};
    int dir[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int command, value;
    int x = 0, y = 0, rx = 100/2, ry = 100/2;
    mat[rx][ry] = 1;

    while(1){
        scanf("%d %d", &command, &value);
        if(command == -1 && value == -1) break;
        if(check(mat,command,value,dir,rx,ry) == 1){
            map(mat,command,value,dir,rx,ry);
            switch(command) {
                case 0 :
                    y += value;
                    ry += value;
                    break;
                case 1 :
                    x += value;
                    rx += value;
                    break;
                case 2 :
                    y -= value;
                    ry -= value;
                    break;
                case 3 :
                    x -= value;
                    rx -= value;
                    break;
                default: break;
            }
            printf("%d %d\n", x, y);
        }
        else
            printf("Invalid move\n");
    }
    return 0;
}