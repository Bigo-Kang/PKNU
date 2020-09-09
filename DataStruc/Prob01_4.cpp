#include <stdio.h>
#include <string.h>

#define MAX 500

int main()
{
    char word[30];
    int n=0;
    char *save[MAX];

    FILE*inFp = fopen("/Users/KangDaeWon/Clion/exDS/harry.txt","r");
    FILE*outFp = fopen("/Users/KangDaeWon/Clion/exDS/harry.txt","w");

    while(fscanf(inFp," %s",word) != EOF){
        char length = strlen(word);
        if(length >3){
            save[n++] = strdup(word);
        }
        if(n > 3) printf("%s %s ::",save[n],word);


    }
    printf("%s ", word);
    for(int i = 0; i < 20; i++)
        printf("%d : %s ", i, save[i]);
    fclose(inFp);
    fclose(outFp);
    



    return 0;
}