#include <stdio.h>
#include "stackADT.h"
#include "pos.h"

#define MAX 100
#define PATH 0;
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

int maze[MAX][MAX];
int n;

void read_maze();
void print_maze();
bool movable(Position pos, int dir);

int main () {
    read_maze ();

    Stack s = create();
    Position cur;
    cur.x = 0;
    cur.y = 0;

    while(1) {
        maze[cur.x][cur.y] = VISITED;
        if(cur.x == n-1 && cur.y == n-1){
            printf("Found the path.\n");
            break;
        }

        bool forwarded = false;
        for(int dir = 0; dir<4; dir++){
            if(movable(cur,dir)){
                push(s,cur);
                cur = move_to(cur, dir);
                forwarded = true;
                break;
            }
        }
        if(!forwarded){
            maze[cur.x][cur.y] = BACKTRACKED;
            if(is_empty(s)){
                printf("No path exists.\n");
                break;
            }
            cur = pop(s);
        }
    }
    print_maze ();
    return 0;
}

void read_maze() {
    FILE *fp = fopen("maze.txt", "r");
    fscanf(fp,"%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf (fp, "%d", &maze[i][j]);
        }
    }
}

void print_maze() {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf ("%d", maze[i][j]);
        }
        printf("\n");
    }
}

bool movable(Position pos, int dir) {
    int offset[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
   //pos > 0 or pos < n or not 1..
    if ( pos.x + offset[dir][0] < 0 || pos.y + offset[dir][1] < 0 ||
            pos.x + offset[dir][0] >= n || pos.y + offset[dir][1] >= n ||
            maze[pos.x + offset[dir][0]][pos.y + offset[dir][1]] != 0 )
        return false;
    return true;
}