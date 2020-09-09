#include<stdio.h>
#include<string.h>
void sort(char[]);
int main()
{
    char word[50];
    scanf("%s", word);
    sort(word);
    printf("%s\n", word);
    return 0;
}
void sort(char w[]) {
    for (int i = strlen(w) - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (w[i] < w[j]) {
                char tmp = w[i];
                w[i] = w[j];
                w[j] = tmp;
            }
        }
    }
}