#include <stdio.h>
#define MAX 100

int main()
{
    int a[MAX],b[MAX];
    int x,y,count1=0,count2=0;

    scanf("%d %d",&x,&y);

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
        else if(a[i]==b[i]) {
            //printf("%d %d\n",a[i],b[i]);
            continue;
        }
        else
            break;
    }

    count1--; count2--;
    if(fw==1) {
        for (int i = 0; i < count1; i++)
            printf("%d", a[i]);
        printf(" ");
        for (int i = 0; i < count2; i++)
            printf("%d", b[i]);
    }
    else{
        for (int i = 0; i < count2; i++)
            printf("%d", b[i]);
        printf(" ");
        for (int i = 0; i < count1; i++)
            printf("%d", a[i]);
    }

    return 0;
}

/*
    int fw=0;
    int n =count1<count2?count2:count1;
    for(int i =0; i<n;i++){
        if(a[i]<b[i]) {fw=1; break;}
        else if(a[i]==b[i]) {
            printf("%d %d\n",a[i],b[i]);
            continue;
        }
        else
            break;
    }
 */