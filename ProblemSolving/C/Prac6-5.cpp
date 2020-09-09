#include<stdio.h>
#define MAX 100
int main()
{
    int x[MAX],y[MAX];
    int n;

    scanf("%d",&n);

    for(int i=0; i<n;i++) {
        scanf("%d %d", &x[i], &y[i]);
        if(i>0){
            for(int j=0;j<i;j++){
                if(x[i]<x[j]){
                    int tmpx = x[j];
                    x[j] = x[i];
                    x[i] = tmpx;
                    int tmpy = y[j];
                    y[j] = y[i];
                    y[i] = tmpy;
                }
            }

        }

    }
    for(int i=0; i<n;i++) {
            for(int j=0;j<i;j++) {
                if (x[i] == x[j]) {
                    if (y[i] < y[j]) {
                        int tmpy = y[j];
                        y[j] = y[i];
                        y[i] = tmpy;
                        int tmpx = x[j];
                        x[j] = x[i];
                        x[i] = tmpx;
                    }
                }
            }
    }
    for(int i=0;i<n;i++)
        printf("%d %d\n",x[i],y[i]);

    return 0;
}