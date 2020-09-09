#include <stdio.h>
#include <string.h>

#define MAX 10000
void readFile(char **ptrW, int*ptrC, char*buf);
void sort(char **ptrW, int *ptrC);
void writeFile(char **ptrW, int *ptrC);
int n = 0;

int main()
{
    char buffer[20];
    char *words[MAX];
    int count[MAX] = { 0 };

    readFile(words, count, buffer);     //read file
    sort(words, count);   //working..
    writeFile(words, count);    //write file..
    return 0;
}
void readFile(char **ptrW, int*ptrC, char*buf) {
    bool bl;
    FILE*fp = fopen("harry.txt", "r");
    while (fscanf(fp, " %s", buf) != EOF) {     //!feof(infp)

        bl = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(ptrW[i], buf) == 0) {
                ++ptrC[i];
                bl = true;
                break;
            }
        }
        if (!bl && strlen(buf) > 3) {
            ptrW[n] = strdup(buf);
            ++ptrC[n];
            n++;
        }
    }
    // if strlen < 4 == pass
    // else strlen >= 4 and count == 0
    // save .. and count != 0 >> count++
    // structure word : count >> array
    fclose(fp);
}
void sort(char **ptrW, int *ptrC) {
    // use strcmp
    for (int end = n - 1; end > 0; end--) {
        for (int start = 0; start < end; start++) {
            if (strcmp(ptrW[start], ptrW[end]) > 0) {
                char *tmpW = ptrW[start];
                ptrW[start] = ptrW[end];
                ptrW[end] = tmpW;
                int tmpC = ptrC[start];
                ptrC[start] = ptrC[end];
                ptrC[end] = tmpC;
            }
        }
    }
}
void writeFile(char **ptrW, int *ptrC) {
    FILE*outfp = fopen("words.txt", "w");
    //save
    for (int i = 0; i < n; i++)
        fprintf(outfp, "%s : %d\n", ptrW[i], ptrC[i]);
    fclose(outfp);
}