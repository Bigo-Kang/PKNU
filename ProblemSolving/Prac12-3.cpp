#include<stdio.h>
#include<string.h>
void trans(char[]);
void sort(char[]);
bool compare(char[], char[]);
int main()
{
    char wordA[50];
    char wordB[50];
    scanf("%s %s", wordA, wordB);
    if (strlen(wordA) != strlen(wordB)) {
        printf("No\n"); return 0;
    }
    trans(wordA); trans(wordB);
    sort(wordA); sort(wordB);
    if (compare(wordA,wordB)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
void trans(char w[]){
    for(int i =0; i < strlen(w);i++){
        if(w[i] < 97) w[i]+=32;
    }
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
bool compare(char wA[], char wB[]) {
    for (int i = 0; i < strlen(wA); i++) {
        if (wA[i] != wB[i]) return 0;
    }
    return 1;
}

//strcmp
//toupper
//tolower