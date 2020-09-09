#include <stdio.h>
#define swap(a,b){int tmp = a; a=b; b=tmp;}
int main()
{
    int x[50],y[50];
    int n=0;

    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice2/input1.txt","r");
    while(!feof(fp)) {
        fscanf(fp, "%d  %d", &x[n],&y[n++]);
    }
    fclose(fp);

    int xa,xb,ya,yb;
    int xl,xll;
    int length,lengthMax=0;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            xa=x[i]; xb=x[j]; ya=y[i]; yb=y[j];
            if(xa>xb) swap(xa,xb);
            if(ya>yb) swap(ya,yb);

            length = ya-xb+1;

            if(length>lengthMax){
                lengthMax = length;
                xl = i; xll = j;
            }

        }
    }
    printf("[%d, %d], [%d, %d]\n", x[xl],y[xl],x[xll],y[xll]);

    return 0;
}