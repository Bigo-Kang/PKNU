#include <stdio.h>
#include <string.h>
#define LINE 90
void readFile();
void writeFile(int, int,char []);
//void work(char* buf, int *wordC, int *len);
FILE*fpR = fopen("harry.txt", "r");
FILE*fpW = fopen("aligneed.txt", "w");
char *words[50] = {0};
int main()
{
    readFile();
    return 0;
}
void readFile(){
    char buffer[LINE];
    char blank[] = " ";
    char tmp[20] = {0};
    while (fgets(buffer, LINE, fpR) != NULL) {

        int wordCount = 0;
        int length = 0;
        int wordLen= 0;
        for(int i = 0; i < strlen(buffer); i++){

            if (buffer[i] == *blank) {
                if (i > 0 && buffer[i - 1] != *blank) {
                    words[wordCount] = strdup(tmp);
                    wordCount++;
                    wordLen = 0;
                    memset(tmp, 0, sizeof(char) * 20);
                }
            }
            else{
                ++length;
                tmp[wordLen++] = buffer[i];
            }
        }

        //work(buffer, &wordCount, &length);
        writeFile(length, wordCount,buffer);
        fprintf(fpW, "%s\n", buffer);
    }
}
void writeFile(int len, int wordC, char buf[] ) {
    int modBlank = 80 - len - 1;
    int nBlank = wordC - 1;
    int numBlank = modBlank / nBlank;
    int start = 0;
    //int wStart = 0;
    int bStart = 0;
    //char* blank = " ";
    char bufS[LINE] = {0};
    bool bl = true;
    if (wordC < 2)
        return;
    int j = 0;
    while (start < wordC) {
        for (; j < 80; j++) {
            if (!bl) {
                strcat(bufS ," ");
                bStart++;
                if (bStart > numBlank) bl = true;
            }
            else {
                strcat(bufS, words[start]);
                bStart = 0;
                j += strlen(words[start++]);
                bl = false;
            }
        }
    }
    strcpy(buf, bufS);
}