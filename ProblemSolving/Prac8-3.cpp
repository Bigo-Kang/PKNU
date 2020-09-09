#include<stdio.h>
#define MAX 100

int main()
{
    int a[MAX][MAX];
    int n,k;
    bool bl=false;
    scanf("%d %d", &n,&k);

    //a[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0||a[i-1][j] == 0) a[i][j]=1;
            else{
                a[i][j]= a[i-1][j-1]+a[i-1][j];
            }
            if(i==n&&j==k){bl= true; break;}
        }
        if(bl) break;
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n%d\n", a[n][k]);



    return 0;
}