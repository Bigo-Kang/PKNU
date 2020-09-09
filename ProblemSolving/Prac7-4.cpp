#include <stdio.h>

int main()
{
    int data[30];
    int n,prime,maxPrime;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);

    maxPrime = 0;
    for(int i=0;i<n;i++){
        prime=0;
        int count=0;
        for(int j=i;j<n;j++){
            int check=0;
            prime += data[j];
            for(int k=2;k<=prime/2;k++){
                if(prime%k == 0){ check=1; break; }
            }
            if(check != 1 && prime != 1 && maxPrime < prime) maxPrime=prime;
            prime *=10;
            count++;
            if(count == 8) break;
        }
    }
    printf("%d\n",maxPrime);

    return 0;
}