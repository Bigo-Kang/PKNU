#include <stdio.h>

int main()
{
    int n, tmp1 = -2, tmp2 = -2, tmp3 = -2, count = 0, con = 0;

    while(1){
        scanf("%d", &n);

        if(n == -1) break;
        if(n == tmp1) continue;

        tmp3 = tmp2;
        tmp2 = tmp1;
        tmp1 = n;

        if(tmp3 != -2 && (tmp2>tmp3 && tmp2>tmp1)){
            count++; con = 1; //con=1 convex
        }
        else if(tmp3 != -2 && (tmp2<tmp3 && tmp2<tmp1)){
            count++; con = 2; //con=2 concave
        }
    }

    if(count == 1){
        if(con ==1 ) printf("Convex\n");
        else printf("Concave\n");
    }
    else if(count>1) printf("None\n");
    else
        printf("Both\n");

    return 0;
}