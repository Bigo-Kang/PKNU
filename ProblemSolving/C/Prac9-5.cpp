#include <stdio.h>

int compareLexicographic(int, int);
void swapData(int data[],int,int);
int dataLength(int [],int);

int main()
{
    int data[20];
    int n=0;

    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice02/input6.txt","r");
    while(!feof(fp)){
        fscanf(fp,"%d",&data[n]);
        n++;
    }
    fclose(fp);

    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(compareLexicographic(data[i],data[j]) == 1){
                swapData(data,i,j);
            }
        }
    }

    for(int i=0;i<n;i++)
        printf("%d ",data[i]);

    return 0;
}
int compareLexicographic(int a, int b){
    int dataA[8],dataB[8];

    int lengthA = dataLength(dataA,a);
    int lengthB = dataLength(dataB,b);

    bool bl = true;

    while(lengthA >= 0 && lengthB >= 0) {
        if(dataA[lengthA] !=dataB[lengthB]) bl = false;
        if (dataA[lengthA] > dataB[lengthB]) return 1;
        else if (dataA[lengthA] < dataB[lengthB]) return -1;
        lengthA--; lengthB--;
    }

    if(bl && lengthA == lengthB ) return 0;
    else if(bl && lengthA > lengthB) return 1;

    return -1;
}
int dataLength(int x[],int a){
    for(int i=0;i<8;i++){
        if(a == 0)
            return i-1;
        x[i]= a%10;
        a /= 10;
    }
    return 0;
}
void swapData(int data[],int a,int b){
    int tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}