#include <stdio.h>
#include <math.h>
int main() {
    int x[]={1,4,-7,3,-17};
    int y[]={2,-5,8,10,5};
    int n=5;
    double sum=0,avgx=0,avgy=0,d=0;

    for(int i =0;i<n;i++) sum += x[i];
    avgx = sum/n;
    sum=0;
    for(int i =0;i<n;i++) sum+=y[i];
    avgy=sum/n;

    for(int i =0;i<n;i++)
        d+=sqrt(((avgx-(double)x[i])*(avgx-(double)x[i]))+((avgy-(double)y[i])*(avgy-(double)y[i])));
    printf("%lf %lf\n%lf\n",avgx,avgy,d/n);

    return 0;
}