#include <stdio.h>

int main()
{
    int day[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int b_year,b_mon,b_day,t_year,t_mon,t_day,b_sum=0,t_sum=0;

    scanf("%d %d %d %d %d %d",&b_year,&b_mon,&b_day,&t_year,&t_mon,&t_day);

    b_sum += b_year * 365+b_day;
    for(int i=0;i<b_mon-1;i++)b_sum+=day[i];

    t_sum += t_year * 365+t_day;
    for(int i=0;i<t_mon-1;i++)t_sum+=day[i];

    printf("%d\n", t_sum-b_sum);
    return 0;
}