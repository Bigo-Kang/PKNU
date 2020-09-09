#include<stdio.h>
int isRelativePrime(int a, int b) {
    for (int i = 2; i <= a; i++) {
        if (a%i == 0 && b%i == 0) return 0;
    }
    return 1;
}
int main()
{
    int count = 0;
    for (int a = 2; a <= 98; a++) {
        for (int b = a + 1; b <= 99; b++) {
            if (isRelativePrime(a, b) == 1) {
                for (int c = b + 1; c <= 100; c++) {
                    if (isRelativePrime(a, c) == 1 && isRelativePrime(b, c) == 1)
                        count++;
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}