#include <stdio.h>
#define MAX 100

int main()
{
    int data[MAX];
    int n=0;

    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice2/input1.txt","r");
    while(!feof(fp)) fscanf(fp,"%d",&data[n++]);
    fclose(fp);
    int last = n;

    while(1){
        if(n<0) break;
        int k=data[0];
        int sel =0;
        for(int i=0;i<n;i++){
            if(k < data[i]) {k =data[i]; sel = i;}
        }
        int tmp = data[n-1];
        data[n-1] = data[sel];
        data[sel] = tmp;
        n--;
    }
    for(int i =0;i<last;i++)
        printf("%d ", data[i]);
    return 0;
}
