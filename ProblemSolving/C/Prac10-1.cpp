#include <stdio.h>
#define MAX 100

int checkLeader(int data, int num, int leader);

int main()
{
    int data[MAX];
    int leader[MAX];
    int n = 0, count = 1;

    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice02/input6.txt","r");
    while(fscanf(fp,"%d", &data[n]) != EOF){
        if(n == 0) leader[0] = data[n];
        else if(checkLeader(data[n],n,leader[count-1])==1){
            leader[count] = data[n];
            count++;
        }
        n++;
    }
    fclose(fp);

    printf("%d : ", count);
    for(int i = 0; i < count; i++)
        printf("%d ", leader[i]);

    return 0;
}

int checkLeader(int data[], int num, int leader[]){
    if(data >= leader) return 1;
    return 0;
}

//bool type function >>> return n==1 >> n same 1 return true ;;