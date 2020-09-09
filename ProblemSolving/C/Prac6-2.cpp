#include <stdio.h>
#define MAX 1000
int main()
{
    int data1[MAX], data2[MAX], data3[2000];
    int n1=0,n2=0,n3=0;

    FILE *fp1 = fopen("/Users/KangDaeWon/Clion/Practice2/input1.txt","r");
    FILE *fp2 = fopen("/Users/KangDaeWon/Clion/Practice2/input2.txt","r");
    while(!feof(fp1)) fscanf(fp1,"%d", &data1[n1++]);
    while(!feof(fp2)) fscanf(fp2,"%d", &data2[n2++]);
    fclose(fp1); fclose(fp2);

    int a=0,b=0;

    while (a < n1 && b < n2) {
        if (data1[a] <= data2[b]) data3[n3++] = data1[a++];
        else data3[n3++] = data2[b++];
    }
    if(a == n1){
        while(b<n2) data3[n3++]=data2[b++];
    }
    else if(b==n2){
        while(a<n1) data3[n3++]=data1[a++];
    }

    for(int i = 0; i < n3; i++)
        printf("%d ", data3[i]);



    return 0;
}
