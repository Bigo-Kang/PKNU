#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//입력이 정확하다는 전제..
#define MAX_TERMS 100
#define MAX 100
int readLine(char str[], int limit);
void create(char *);
void add(char *str);
void calc(char *,char *);
void print(char *);
int search(char *);
void realAdd(int num, int coe, int exp);
int checkSearch(int num, int exp);
typedef struct {
    int coef;
    int expo;
} Term;
typedef struct {
    char name;
    int nbrTerms;
    Term terms[MAX_TERMS];
}Polynomial;
Polynomial polys[MAX];
int n = 0;

int main()
{
    char commandLine[MAX_TERMS];
    char *command, *argument,*argument1;
    while (1) {
        printf("$ ");
        if (readLine(commandLine, MAX_TERMS) <= 0)
            continue;
        command = strtok(commandLine, " ");
        if (strcmp(command, "create") == 0) {
            argument = strtok(NULL, " ");
            create(argument);
        }
        else if (strcmp(command, "add") == 0) {
            add(commandLine);
        }
        else if (strcmp(command, "calc") == 0) {
            argument = strtok(NULL, " ");
            argument1 = strtok(NULL, " ");
            calc(argument,argument1);
        }
        else if (strcmp(command, "print") == 0) {
            argument = strtok(NULL, " ");
            print(argument);
        }
        else if (strcmp(command, "exit") == 0)
            break;
    }
    return 0;
}
int readLine(char str[], int limit) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < limit - 1) str[i++] = ch;
    str[i] = '\0';
    return i;
}
void create(char *name) {
    char ch = *name;
    polys[n].name = ch;
    polys[n].nbrTerms = 0;
    n++;
}
void add(char *str) {
    char *ptr;
    int coe, exp;
    ptr = strtok(NULL, " ");
    int index = search(ptr);
    if (index == -1)
        printf("Not found.\n");
    else {
        ptr = strtok(NULL, " ");
        coe = atoi(ptr);
        ptr = strtok(NULL, " ");
        exp = atoi(ptr);
        realAdd(index, coe, exp);
    }
}
void realAdd(int num, int coe, int exp) {
    int check = checkSearch(num, exp);
    int i = polys[num].nbrTerms - 1;
    if (check  > -1) {
        polys[num].terms[check].coef += coe;

        if(polys[num].terms[check].coef == 0){
            for(int j = check; j < polys[num].nbrTerms-1; j++){
                polys[num].terms[j] = polys[num].terms[j+1];
            }
            polys[num].nbrTerms--;
        }

    }
    else {
        while (i >= 0 && polys[num].terms[i].expo < exp) {
            polys[num].terms[i + 1] = polys[num].terms[i];
            i--;
        }
        polys[num].terms[i + 1].coef = coe;
        polys[num].terms[i + 1].expo = exp;
        polys[num].nbrTerms++;
    }
}
int checkSearch(int num, int exp) {
    for (int i = 0; i < polys[num].nbrTerms; i++) {
        if (polys[num].terms[i].expo == exp) return i;
    }
    return -1;
}
int search(char *nm) {
    char ch = *nm;
    for (int i = 0; i < n; i++)
        if (ch == polys[i].name)
            return i;
    return -1;
}
void print(char * nm) {
    int index = search(nm);
    int i = 0;
    char str[100]={0};
    int len=0;
    while (i < polys[index].nbrTerms) {
        if(i!=0){
            if(polys[index].terms[i].coef>0)
                len += sprintf(str+len,"+");
            //printf("+";
        }
        if(polys[index].terms[i].coef!=1){
            len+=sprintf(str+len,"%d",polys[index].terms[i].coef);
            //printf("%d",polys[index].terms[i].coef);
        }
        else if(polys[index].terms[i].expo==0){
            len+=sprintf(str+len,"%d",polys[index].terms[i].coef);
            //printf("%d","%d",polys[index].terms[i].coef);
        }
        if(polys[index].terms[i].expo==1){
            len+=sprintf(str+len,"x");
        }
        else if(polys[index].terms[i].expo!=0){
            len+=sprintf(str+len,"x^%d",polys[index].terms[i].expo);
        }
        i++;
            /*
        if (polys[index].terms[i].expo > 1) {
            if (polys[index].terms[i].coef > 1 || polys[index].terms[i].coef < 0)
                printf("%dx^%d", polys[index].terms[i].coef, polys[index].terms[i].expo);
            else
                printf("x^%d", polys[index].terms[i].expo);
        }
        else if (polys[index].terms[i].expo == 1) {
            if (polys[index].terms[i].coef > 1 || polys[index].terms[i].coef < 0)
                printf("%dx", polys[index].terms[i].coef);
            else
                printf("x");
        }
        else
            printf("%d", polys[index].terms[i].coef);
        if (i < polys[index].nbrTerms - 1)
            printf("+");
        i++;
             */
    }
    printf("%s",str);
    printf("\n");
}

void calc(char *nm, char *fx) {
    int sum = 0;
    int x = atoi(fx);
    int index = search(nm);
    for (int i = 0; i < polys[index].nbrTerms; i++) {
        double result = pow(x, polys[index].terms[i].expo);
        sum += polys[index].terms[i].coef * (int)result;
    }
    printf("%d\n", sum);
}