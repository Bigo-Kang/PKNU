#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5000
#define MAX_BUF 20

struct follower {
    char *word;
    int count;
    struct follower *next;
};
typedef struct follower Follower;

typedef struct item {
    char *word;
    int size;
    Follower *head;
}Item;

Item *table[MAX];
int n = 0;

int main()
{
    char str[MAX_BUF] = { 0 };
    char pstr[MAX_BUF] = { 0 };

    FILE *fp = fopen("harry.txt","r");
    while (fscanf(fp,"%s", str) != EOF) {
        int i;
        for (i = 0; i < n; i++) {
            if (strcmp(table[i]->word, str) == 0) {   break;}
        }
        if(i==n){
            if (n >= MAX) break;
            Item *tmp;
            tmp = (Item*)malloc(sizeof(Item));
            tmp->size = 0;
            tmp->word = strdup(str);
            tmp->head = NULL;
            table[n++] = tmp;
        }
        for (i = 0; i < n; i++) {
            if (strcmp(table[i]->word, pstr) == 0) { break; }
        }
        if (i == n) {}
        else {
            Follower *p,*q;
            if (table[i]->size == 0) {
                p = (Follower*)malloc(sizeof(Follower));
                p->word = strdup(str);
                p->count = 1;
                p->next = NULL;
                table[i]->head = p;
                table[i]->size++;
            }
            else {
                int index = i;
                Follower *q = NULL;
                p = table[index]->head;
                for (i = 0; i < table[index]->size; i++) {
                    if (strcmp(str, p->word) == 0) { p->count++; break; }
                    q = p;
                    p = p->next;
                }
                if (i == table[index]->size) {
                    Follower *tmp;
                    tmp = (Follower*)malloc(sizeof(Follower));
                    tmp->word = strdup(str);
                    tmp->count = 1;
                    tmp->next = NULL;
                    q->next = tmp;
                    table[index]->size++;
                }
            }
        }
        memset(pstr, 0, MAX_BUF);
        strcpy(pstr, str);
    }
    fclose(fp);
    FILE *fpout = fopen("output.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fpout, "%s : ", table[i]->word);
        Follower *p=table[i]->head;
        for (int j = 0; j < table[i]->size; j++) {
            fprintf(fpout, "%s(%d) ", p->word, p->count);
            p = p->next;
        }
        fprintf(fpout, "\n");
    }
    fclose(fpout);

    return 0;
}