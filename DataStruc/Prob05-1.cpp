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

Follower *create_Follower_instance(char *c);
Item *create_Item_instance(char *word);
void find_Item_Word(char *str, int i);
void print_Item();

Item *table[MAX];
int n=0;

int main()
{
    char str[MAX_BUF];
    char pstr[MAX_BUF];

    FILE*fp = fopen("harry.txt", "r");
    while (fscanf(fp, " %s", str) != EOF) {     //!feof(infp)
        bool bl = false;
        int i;
        // 왜 두번째 읽을때 table[0]->word가 chapter에서 one으로 바뀌지??
        //strdup을 사용하면 된다
        for (i = 0; i < n; i++) {
            if (strcmp(table[i]->word, str) == 0) {
                bl = true;
                break;
            }
        }
        if (!bl) {
            if(n >= MAX) break; //이거 없으면 런타임 오류가 난다 터짐
            table[n++] = create_Item_instance(str);
        }
        for(i = 0; i < n; i++) {
            if (strcmp (table[i]->word, pstr) == 0) break;
        }
        if(i != n)  find_Item_Word(str, i);

        memset(pstr, 0, MAX_BUF);
        strcpy(pstr,str); // 직전 단어를 기억해야한다
    }
    fclose(fp);
    print_Item();
    return 0;
}
Follower *create_Follower_instance(char *c) {
    Follower *t = (Follower*)malloc(sizeof(Follower));
    t->word = strdup(c);
    t->count = 1;
    t->next = NULL;
    return t;
}
Item *create_Item_instance(char *word) {
    Item *p = (Item *)malloc(sizeof(Item));
    p->word = strdup(word);
    p->size = 0;
    p->head = NULL;
    return p;
}
void find_Item_Word(char *str, int i) {
    Follower * p, *q = NULL, *r;
    if(table[i]->size == 0){
        p = create_Follower_instance (str);
        table[i]->size++;
        table[i]->head = p;
        //table[i]->head = create_Follower_instance(str);
    }
    else {
        int index = i;
        p = table[index]->head;
        for (i = 0; i < table[index]->size; i++) {
            if (strcmp (p->word, str) == 0) {
                p->count++;
                break;
            }
            q = p;
            p = p->next;
        }
        if (i == table[index]->size) {
            q->next = create_Follower_instance (str);
            table[index]->size++;
        }
    }
}
void print_Item() {
    for (int i = 0; i < n; i++) {
        Follower *p = table[i]->head;
        printf("%s : ", table[i]->word);
        for(int j = 0; j < table[i]->size; j++) {
            printf("%s (%d) ", p->word, p->count);
            p = p->next;
        }
        printf("\n");
    }
}