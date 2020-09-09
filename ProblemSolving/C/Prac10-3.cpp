#include <stdio.h>
#define MAX 50
void distinct(int [], int [][4], int );
int intersect(int h[][4],int v[][4],int a,int b);
void insert(int data[][2],int n);
int main()
{
    int sect[MAX][2];
    int hori[MAX][4]; //horizontal
    int vert[MAX][4]; //vertical
    int n;
    int data[4];
    int count1 = 0, count2 = 0,count3 =0;

    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice02/input10.txt","r");
    fscanf(fp,"%d",&n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++)
            fscanf(fp,"%d",&data[j]);
        if(data[0] == data[2]) {
            distinct(data, vert, count1);
            count1++;
        }
        else if(data[1] == data[3]) {
            distinct(data, hori, count2);
            count2++;
        }
    }
    fclose(fp);
    for(int i = 0; i < count1; i++){
        for(int j = 0; j < count2; j++){
            if(intersect(hori,vert,i,j) == 1){
                sect[count3][0] = vert[i][0];
                sect[count3++][1] = hori[j][1];
                insert(sect,count3);
            }
        }
    }
    for(int i = 0; i < count3; i++) {
            printf("%2d %2d", sect[i][0],sect[i][1]);
        printf("\n");
    }
    return 0;
}

void distinct(int num[], int matData[][4], int layer){
    for(int i = 0; i < 4; i++)
        matData[layer][i] = num[i];
}

int intersect(int h[][4],int v[][4],int a,int b){
    if((h[b][0] <= v[a][0] && h[b][2] >= v[a][0]) && (h[b][1]>=v[a][1] && h[b][1]<=v[a][3]))
        return 1;
    return 0;
}

void insert(int data[][2],int n){
    for(int i =n-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(data[i][0] <= data[j][0] && data[i][1] < data[j][1]){
                int tmpX = data[i][0]; data[i][0] = data[j][0]; data[j][0] = tmpX;
                int tmpY = data[i][1]; data[i][1] = data[j][1]; data[j][1] = tmpY;
            }
        }
    }
}