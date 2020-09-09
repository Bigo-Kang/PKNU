#include <stdio.h>

int main()
{
    int data[14]={0};
    int n;

    for(int i = 0; i<7;i++) {
        scanf("%d", &n);

        data[n] = 1;

    }
    int count=0,check = 0;
    for(int i=1;i<14;i++){
        if(data[i] == 1)
            count++;
        else
            count = 0;

        if(count > 4){ check = 1;}

    }
    if(check == 1)
        printf("yes\n");
    else
        printf("No\n");


    return 0;
}