#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define NHASH 4093
#define MULTIPLIER 31
#define MAX 100
typedef struct suffix Suffix;
struct suffix {
    char *sword;    //suffix인 단어
    int freg;       //등장횟수
    Suffix *next;   //다음 노드의 주소
};

typedef struct prefix{
    char *pword1;   //prefix를 구성하는 첫 단어
    char *pword2;   //prefix를 구성하는 두 번째 노드의 주소
    Suffix *suf;    //suffix들의 연결리스트의 첫번째 노드의 주소
    int sumFreg;    //suffix들의 등장횟수합
}Prefix;

typedef struct node Node;
typedef struct node {
    Prefix *data;
    Node *next;
};

unsigned int hash (char *key1, char *key2);
void readFile();


prefix *createPrefix (char *fword, char *sword);

Suffix *createSuffix (char *suff);

void display ();

Prefix *Findprefix (char *word1, char *word2);

Node *htable[NHASH];
char *first, *second;

int main() {
    readFile();
    display();

    return 0;
}

void display () {
    int size = 0;
    char *word1 = first, *word2 = second;
    printf( "%s %s", word1, word2);
    size += 2;

    while (1) {
        Suffix *suff, *resuff;
        Prefix *pre = Findprefix(word1,word2);
        if (pre == NULL || size > 1000) {
            break;
        }
//        srand (time(NULL));
        int result = rand() % pre->sumFreg+1;
        suff = pre->suf;
        while (result > 0) {
            resuff = suff;
            result = result - suff->freg;
            suff = suff->next;
        }
        printf (" %s", resuff->sword);
        size++;
        word1 = word2;
        word2 = resuff->sword;
    }
}

Prefix *Findprefix (char *word1, char *word2) {
    int key = hash(word1, word2);
    Node*fir = htable[key];
    while (fir != NULL) {
        if (strcmp(fir->data->pword1, word1) == 0 && strcmp(fir->data->pword2, word2) == 0)
            return fir->data;
        fir = fir->next;
    }
    return NULL;
}

void readFile() {
    FILE *fp = fopen("HarryPotter.txt", "r");
    char word1[MAX], word2[MAX], suff[MAX];
    fscanf (fp, "%s", word1);
    fscanf (fp, "%s", word2);
    int end = fscanf (fp, "%s", suff);
    first = strdup(word1);
    second = strdup(word2);
    char *fword=first, *sword=second;
    char *dsuff;
    //strdup
    while(end != EOF) {
        dsuff = strdup (suff);
        int key = hash(fword, sword);

        if(htable[key] == NULL) {
            htable[key] = (Node*)malloc(sizeof(Node));
            htable[key]->next = NULL;
            prefix *p = createPrefix(fword,sword); // make Prefix;
            p->suf = createSuffix(dsuff);
            htable[key]->data = p;
        }
        else {
            Node *nn = htable[key];
            while (nn != NULL) {
                Suffix *s = nn->data->suf;
                if (strcmp(fword, nn->data->pword1) == 0 && strcmp(sword, nn->data->pword2) == 0) {
                    while (s != NULL) {
                        if ( strcmp(s->sword, dsuff) == 0){
                            s->freg++;
                            break;
                        }
                        else
                            s = s->next;
                    }
                    if (s == NULL) {
                        Suffix *yong = createSuffix (dsuff);

                        Suffix *old = nn->data->suf;
                        nn->data->suf = yong;
                        yong->next = old; //
                    }
                    nn->data->sumFreg++;
                    break;
                }
                nn = nn->next;
            }
            if ( nn == NULL ) {
                nn = (Node*)malloc(sizeof(Node));
                nn->data = createPrefix (fword,sword);
                nn->data->suf = createSuffix (dsuff);
                nn->next = htable[key];
                htable[key] = nn;
            }
        }
        fword = sword;
        sword = dsuff;
        end = fscanf (fp, "%s", suff);
    }
    fclose (fp);
}

Suffix *createSuffix (char *suff) {
    Suffix *s = (Suffix*)malloc(sizeof(Suffix));
    s->sword = strdup (suff);
    s->freg = 1;
    s->next = NULL;
    return s;
}

prefix *createPrefix (char *fword, char *sword) {
    Prefix *p = (Prefix*)malloc(sizeof (Prefix));
    p->pword1 = strdup(fword);
    p->pword2 = strdup (sword);
    p->suf = NULL;
    p->sumFreg = 1;
    return p;
}

unsigned int hash (char *key1, char *key2) {
    unsigned int h = 0;
    unsigned char *p;

    for (p=(unsigned char *)key1; *p != '\0'; p++)
        h = MULTIPLIER * h + *p;
    for (p=(unsigned char *)key2; *p != '\0'; p++)
        h = MULTIPLIER * h + *p;
    return h % NHASH;
}

