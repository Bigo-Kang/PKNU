#include<stdio.h>
//생각좀할것...
int main()
{
    int count = 0, a=1;

    for(int x = 2; x <= 98; x++){
        for(int y = x+1; y <= 99; y++){
            for(int z = y+1; z <= 100; z++){
                a=1;
                for(int n = 2; n <= y; n++){
                    if((x%n == 0 && y%n == 0) || (x%n == 0 && z%n == 0) || (y%n == 0 && z%n == 0)) {
                        a = 0;
                        break;
                    }
                }
                if(a==1) count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
