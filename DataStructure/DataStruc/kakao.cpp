#include<stdio.h>

int main(){

    int n=5;
    int arr1[]={9,20,28,18,11};
    int arr2[]={30,1,21,17,28};

    int arr3[5];

    for(int i=0;i<n;i++){
        arr3[i] = arr1[i]|arr2[i];
    }
    int arr4[n][n];

    for(int i =0; i < n; i++) {
        int j = n-1;
        while (arr3[i] > 0) {
            int tmp = arr3[i]%2;

            arr4[i][j--] =tmp;
            arr3[i]= arr3[i]/2;

        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j <n; j++){
           if(arr4[i][j] == 1)
               printf("#");
            else
               printf(" ");
        }
        printf("\n");
    }
}