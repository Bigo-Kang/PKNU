#include <stdio.h>
#include <math.h>

int main()
{
    int data[100],n;
    double sd=0,avg=0;

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &data[i]);
        avg+=data[i];
    }
    avg /= n;

    for(int i=0;i<n;i++)
        sd += ((data[i]-avg)*(data[i]-avg));
    sd /= n;

    printf("avg : %f  SD : %f\n", avg, sqrt(sd));

    return 0;
}