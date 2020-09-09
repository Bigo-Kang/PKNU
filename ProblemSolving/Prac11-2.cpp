#include <stdio.h>
#define MAT 8
int countStoneToCapture(int, int, int);
int countStoneToCaptureInDir(int, int, int, int);
void changeStoneColor(int, int, int, int);
bool againGame();
void play();
void setBoard();
void displayBoard();
bool findWin();
//void player();
void computer();
bool canPut();
int board[MAT][MAT];
int x, y, color = 1;
int d[][2] = { { 0, 1 },{ 1, 1 },{ 1, 0 },{ 1, -1 },{ 0, -1 },{ -1, -1 },{ -1, 0 },{ -1, 1 } };
int main()
{
    while (1) {
        play();
        if (!againGame()) break;
    }
    return 0;
}
// same position erorr
void play() {
    setBoard();
    while (1) {
        displayBoard();
        if (color == 1) {
            while (1) {
                printf("Put stone : ");
                scanf("%d %d", &x, &y);
                if (x == -1 || y == -1) {
                    printf("Give up\n");
                    return;
                }
                if (countStoneToCapture(x, y, color) != 0)break;
                printf("input again\n");
            }
        }
        else computer();
        for (int i = 0; i < 8; i++) {
            if (countStoneToCaptureInDir(x, y, color, i) != 0)
                changeStoneColor(x, y, color, i);
        }
        if (!canPut()) break;
    }
    displayBoard();
    if (findWin()) printf("The winner is Player\n");
    else  printf("The winner is computer\n");
}
void computer() {
    int max = 0;
    for (int i = 0; i<MAT; i++) {
        for (int j = 0; j<MAT; j++) {
            if (board[i][j] == 0) {
                int countstone = countStoneToCapture(i, j, color);
                if (max < countstone) {
                    max = countstone;
                    x = i;
                    y = j;
                }
            }
        }
    }
    printf("computer move : %d %d\n", x, y);
}
bool againGame() {
    char ch;
    printf("Play again?(Y/N)");
    scanf(" %c", &ch);
    return (ch == 'Y' || ch == 'y');
}
void setBoard() {
    for (int i = 0; i < MAT; i++)
        for (int j = 0; j < MAT; j++)
            board[i][j] = 0;
    board[3][3] = 1; board[4][4] = 1;
    board[3][4] = 2; board[4][3] = 2;
}
void displayBoard() {
    printf("   ");
    for (int i = 0; i < MAT; i++)
        printf("%2d ", i);
    printf("\n");
    for (int i = 0; i < MAT; i++) {
        printf("%2d ", i);
        for (int j = 0; j < MAT; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}
int countStoneToCapture(int a, int b, int color) {
    int countStone = 0;
    if(board[a][b] == color) return 0;
    for (int i = 0; i<8; i++) {
        countStone += countStoneToCaptureInDir(a, b, color, i);
    }
    return countStone;
}
int countStoneToCaptureInDir(int a, int b, int color, int dir) {
    int countStone = 0;
    while (1) {
        if (a < 0 || a > 7 || b < 0 || b > 7) { countStone = 0; break; }
        a += d[dir][0];
        b += d[dir][1];
        if (board[a][b] == color) break;
        if (board[a][b] == 0) { countStone = 0; break; }
        countStone++;
    }
    return countStone;
}
void changeStoneColor(int a, int b, int color, int dir) {
    board[a][b] = color;
    while (a >= 0 && a < 8 && b >= 0 && b < 8) {
        a += d[dir][0];
        b += d[dir][1];
        if (board[a][b] == color) return;
        board[a][b] = color;
    }
}
/*
void player(){
while (1) {
printf("Put stone : ");
scanf("%d %d", &x, &y);
if (x == -1 || y == -1) {
printf("Give up\n");
return;
}
if (countStoneToCapture(x, y, color) != 0) return;
printf("input again\n");
}
}
*/
bool findWin() {
    int count1 = 0, count2 = 0;
    for (int i = 0; i < MAT; i++) {
        for (int j = 0; j < MAT; j++) {
            if (board[i][j] == 1) count1++;
            else count2++;
        }
    }
    return (count1>count2);
}
bool canPut() {
    int canputstone = 0;
    for (int k = 0; k<2; k++) {
        color = (color % 2) + 1;
        for (int i = 0; i < MAT; i++) {
            for (int j = 0; j < MAT; j++) {
                if (board[i][j] == 0) {
                    if (countStoneToCapture(i, j, color) != 0) {
                        canputstone = 1;
                        break;
                    }
                }
            }
            if (canputstone == 1) break;
        }
        if (canputstone == 1) break;
    }
    return canputstone == 1;
}