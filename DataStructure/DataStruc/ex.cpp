#include<stdio.h>

int main()
{
    char str[100];
    int len = 0;

    for(int i = 1; i < 10; i++){
        len+=sprintf(str+len,"3 x %3d = ",i);
        sprintf(str+len, "%d\n", 3*i);
        printf("%s",str);
        len=0;
    }

    return 0;
}