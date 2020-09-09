#include <stdio.h>
#include <string.h>
#define MAXWORD 4000
#define MAXLEN 20

char dict[MAXWORD][MAXLEN];
char grid[MAXLEN][MAXLEN];
int nWord;
int n;

void readGrid()
{
    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice02/input4.txt","r");
    fscanf(fp,"%d",&n);
    for(int i =0; i < n; i++)
            fscanf(fp,"%s",grid[i]);
    fclose(fp);
}
void readDictionary(){
    nWord = 0;
    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice02/dictionary.txt","r");
    while(!feof(fp))
        fscanf(fp,"%s",dict[nWord++]);
    fclose(fp);
}
char getChar(int a,int b, int d, int dist){
    int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    char ch = '\0';
    for(int i=0;i<dist;i++) {
        a +=dir[d][0];
        b +=dir[d][1];
    }
    /*
     * a += dir[d][0] * dist;
     * b += dir[d][1] * dist;
     */
    if(a>=0&&a<n&&b>=0&&b<n)
        ch = grid[a][b];
    return ch;
}
bool serch(int a){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != dict[a][0]) continue;
            for(int dir = 0; dir<8; dir++){
                int dist = 1;
                //int check = 1;
               for(; dist < strlen(dict[a]); dist++){
                   char ch = getChar(i,j,dir,dist);
                   if(ch == '\0'|| ch!=dict[a][dist]) break; //check = 0;
               }
                if(dist >= strlen(dict[a])){
                    return 1;
                }
                //if(check == 1) return 1;

            }
        }
    }
    return 0;
}
int main()
{
    readDictionary();
    readGrid();
    for(int i =0; i<nWord;i++){
        if(serch(i)) printf("%s\n",dict[i]);
    }
    return 0;
}