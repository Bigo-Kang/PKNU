#include <stdio.h>
int merge(int[],int[],int[],int,int);
int main()
{
    int data1[1000],data2[1000],data3[2000];
    int n1=0,n2=0,n3=0;
    FILE *fp1 = fopen("/Users/KangDaeWon/Clion/Practice02/input4_1.txt","r");
    FILE *fp2 = fopen("/Users/KangDaeWon/Clion/Practice02/input4_2.txt","r");
    while(!feof(fp1)) fscanf(fp1,"%d",&data1[n1++]);
    while(!feof(fp2)) fscanf(fp2,"%d",&data2[n2++]);
    fclose(fp1);fclose(fp2);

    n3 = merge(data1,data2,data3,n1,n2);

    for(int i=0; i<n3; i++)
        printf("%d ",data3[i]);
    printf("\n");

    return 0;
}
int merge(int a[],int b[],int c[],int n1, int n2){
    int count = 0;
    int i=0,j=0;
    bool flag = false;

    while(i < n1 && j < n2){
        if(a[i] <= b[j])     c[count++] = a[i++];
        else    c[count++] = b[j++];

        if(i == n1-1) flag = true;
    }
    if(flag){
        for(int k = i; k < n1; k++)
            c[count++] = a[k];
        return count;
    }
    else{
        for(int k = j; k < n2; k++)
            c[count++] = b[k];
        return count;
    }
}