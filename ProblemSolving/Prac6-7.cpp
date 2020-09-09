#include<stdio.h>
#define MAX 15

int check_data(int x,int y) {
    int a[MAX],b[MAX];
    int count1=0,count2=0;
    while(x>0){

        for(int i=count1; i>0;i--) {
            a[i] = a[i-1];
        }

        a[0]= x%10;
        x/=10;
        count1++;
    }
    a[count1++]=-1;

    while(y>0){

        for(int i=count2; i>0;i--) {
            b[i] = b[i-1];
        }

        b[0]= y%10;
        y/=10;
        count2++;
    }
    b[count2++]=-1;

    int fw=0;
    int n =count1<count2?count2:count1;
    for(int i =0; i<n;i++){
        if(a[i]<b[i]) {fw=1; break;}
        else if(a[i]==b[i])
            continue;
        else
            break;
    }
    return fw;
}

int main()
{
    int data[MAX];
    int n=0;

    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice2/input1.txt","r");
    while(!feof(fp)) {
        fscanf(fp, "%d", &data[n++]);
    }
    fclose(fp);

    for(int i=0; i<n;i++) {
        for(int j=0;j<i;j++) {
            if (check_data(data[i],data[j])) {
                int tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",data[i]);

    return 0;
}