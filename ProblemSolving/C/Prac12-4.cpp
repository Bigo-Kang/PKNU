#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    FILE *infp = fopen("/Users/KangDaeWon/Clion/Practice02/input.txt","r");
    FILE *outfp = fopen("/Users/KangDaeWon/Clion/Practice02/output.txt","w");
    char buffer[MAX];
    int count = 0,i=0;
    while(fscanf(infp,"%s",buffer) != EOF) {
        count += strlen(buffer)+1;
        if(count <= 80) fprintf(outfp,"%s ",buffer);
        else {
            fprintf(outfp, " : %d\n%s ", count-(strlen(buffer)+1),buffer);
            count = strlen(buffer)+1;
        }

    }
    fclose(infp); fclose(outfp);
    return 0;
}