#include <stdio.h>

int main()
{
    int data[20];
    int n,k;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);
    scanf("%d",&k);

    int count=0,maxCount=0;
    int sum=0;
    for(int i=0;i<n;i++){
        count = 0;
        for(int j=i;j<n;j++){
            sum += data[j];
            if(sum > k){
                sum = 0;
                break;
            }
            count++;
            if(count > maxCount) maxCount = count;
        }
    }
    printf("%d\n",maxCount);


    return 0;
}