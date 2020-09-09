#include <stdio.h>
#include <string.h>
#define MAXLEN 300
int readLine(char [], int);
int main()
{
    char buffer[MAXLEN];
    int sum = 0, num=0;
    int k = readLine(buffer, MAXLEN);

    for (int i = 0; i < k; i++) {
        if (buffer[i] != ' ' &&( buffer[i] >= 48 && buffer[i] <= 57)) {
            num *= 10;
            num += buffer[i]-48;
        }
        else {
            sum += num;
            num = 0;
        }
    }
    printf("%d\n", sum);
    return 0;
}
int readLine(char buf[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            buf[i++] = ch;
    buf[i] = '\0';
    return i;
} 