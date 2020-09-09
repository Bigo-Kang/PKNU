//
// Created by 강대원 on 2017. 5. 31..
//

#include <stdio.h>
#define MAT 8

int countStoneToCapture(int,int,int);
int countStoneToCaptureInDir(int,int,int,int);
void changeStoneColor(int,int,int,int);
bool againGame();
void play();
void setBoard();
void displayBoard();
bool findWin();
void computer();

int board[MAT][MAT];
int d[][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

int main()
{
    while(1){
        play();
        if(!againGame()) break;
    }
    return 0;
}
bool againGame(){
    char ch;
    printf("Play again?(Y/N)");
    scanf(" %c", &ch);
    return (ch == 'Y' || ch == 'y');
}
void play(){
    int x,y;
    setBoard();
    int color = 1;
    while(1) {
        displayBoard();
        while (color < 2) {
            printf("Put stone : ");
            scanf("%d %d", &x, &y);
            if (x == -1 || y == -1) {
                printf("Give up\n");
                return;
            }
            if(countStoneToCapture(x, y, color)!=0) break;
        }
        int max = 0;
        if(color == 2){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(board[i][j] == 0) {
                        int countstone = countStoneToCapture(i, j, color);
                        if (max < countstone) {
                            max = countstone;
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            if (countStoneToCaptureInDir(x, y, color, i) != 0)
                changeStoneColor(x, y, color, i);
        }
        int canputstone = 0;
        for(int k=0;k<2;k++) {
            color = (color % 2) + 1;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (board[i][j] == 0) {
                        if (countStoneToCapture(i, j, color) != 0) {
                            canputstone = 1;
                            break;
                        }
                    }
                }
                if(canputstone == 1) break;
            }
            if(canputstone == 1) break;
        }
        if(canputstone == 0) break;
        color = (color % 2) + 1;
    }
    if(findWin())
        printf("The winner is Player\n");
    else
        printf("The winner is computer\n");

}
void setBoard(){
    for(int i = 0;i < MAT;i++)
        for(int j = 0; j < MAT; j++)
            board[i][j] = 0;
    board[3][3] = 1; board[4][4] = 1;
    board[3][4] = 2; board[4][3] = 2;
}
int countStoneToCapture(int x, int y, int color){
    int countStone = 0;
    for(int i=0;i<8;i++) {
        countStone += countStoneToCaptureInDir(x, y, color, i);
    }
    return countStone;
}
int countStoneToCaptureInDir(int x, int y, int color, int dir){
    int countStone = 0;
    while(1){
        x += d[dir][0];
        y += d[dir][1];
        if(board[x][y] == color || board[x][y] == 0) break;
        countStone++;
    }
    return countStone;
}
void changeStoneColor(int x,int y,int color,int dir){
    while(1){
        board[x][y] = color;
        x += d[dir][0];
        y += d[dir][1];
        if(board[x][y] == color) return;
    }
}
void displayBoard(){
    printf("   ");
    for(int i = 0; i < MAT; i++)
        printf("%2d ", i);
    printf("\n");
    for(int i = 0; i < MAT; i++){
        printf("%2d ", i);
        for(int j = 0; j < MAT; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}
void computer(){
    int max=0,x,y;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j] == 0) {
                int countstone = countStoneToCapture(i, j, 2);
                if (max < countstone) {
                    max = countstone;
                    x = i;
                    y = j;
                }
            }
        }
    }
}
bool findWin(){
    int count1=0,count2=0;
    for(int i = 0; i < MAT; i++){
        for(int j = 0; j < MAT; j++){
            if(board[i][j] == 1) count1++;
            else count2++;
        }
    }
    return (count1>count2);
}