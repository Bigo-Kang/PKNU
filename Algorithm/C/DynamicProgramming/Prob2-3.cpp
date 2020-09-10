#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct nnodee {
    int nextnodenum;
    int weight;
    nnodee*next;
}Node;
typedef struct edgeee {
    int Ss;
    int Ee;
    int Weight;
}edge;
edge* edGes[MAX];
int Nedge = 0;
Node*grape[MAX];
int d[MAX];
int Count[MAX];


int read_line(FILE*fp, char*arr, int N);
void start();
Node*addenode(int s, int e, int w);
int Dijkstra (int N, int Sno, int Eno);
int Wire(int U, int V);

int main() {
    start();
    return 0;
}
int read_line(FILE*fp, char*arr, int N) {
    int ch, i = 0;
    while ((ch = fgetc(fp)) != '\n'&&ch!=EOF) {
        arr[i++] = ch;
    }
    arr[i] = '\0';
    return i;
}
void start() {
    char buffer[MAX];
    FILE*fp = fopen("input.txt", "r");
    read_line(fp, buffer, MAX);
    char *po = strtok(buffer, " ");
    int N = atoi(po);
    po = strtok(NULL, " ");
    int M = atoi(po);
    for (int i = 0; i < M; i++) {
        read_line(fp, buffer, MAX);
        po = strtok(buffer, " ");
        int Sno = atoi(po);
        po = strtok(NULL, " ");
        int Eno = atoi(po);
        po = strtok(NULL, " ");
        int weight = atoi(po);
        addenode(Sno,Eno,weight);
    }
    read_line(fp, buffer, MAX);
    po = strtok(buffer, " ");
    int Sno = atoi(po);
    po = strtok(NULL, " ");
    int Eno = atoi(po);
    int rew=Dijkstra(M, Sno, Eno);
    printf("%d\n", rew);
}
Node*addenode(int s,int e,int w) {
    edGes[Nedge] = (edge*)malloc(sizeof(edge));
    edGes[Nedge]->Ss = s;
    edGes[Nedge]->Ee = e;
    edGes[Nedge++]->Weight = w;
    Node*nn = (Node*)malloc(sizeof(Node));
    nn->weight = w;
    nn->nextnodenum = e;
    nn->next = NULL;
    Node*now= grape[s];
    if (now != NULL)
    {
        now->next = grape[s]->next;
        grape[s]->next = nn;
    }
    else
        grape[s] = nn;
    return nn;
}
int Dijkstra(int N, int Sno, int Eno) {
    int S[MAX];
    for (int i = 0; i < N; i++) {
        d[i] = 1000;
        Count[i] = 0;
        S[i] = 0;
    }
    d[Sno] = 0;
    Count[Sno] = 1;
    S[Sno] = true;
    Node*nn = grape[Sno];
    while ((nn) != NULL) {
        d[nn->nextnodenum] = nn->weight;
        Count[nn->nextnodenum] = 1;
        nn = nn->next;
    }
    for (int ii = 0; ii < N;ii++) {
        int minW = MAX, Ei;
        for (int i = 0; i < N; i++) {
            if (S[i] == false && d[i] < minW)
            {
                minW = d[i];
                Ei = i;
            }
        }
        S[Ei] = true;
        for (int i = 0; i < N; i++)
        {
            if (S[i] == true) {
                Node*nn = grape[i];
                while (nn != NULL) {
                    int des = nn->nextnodenum;
                    if (d[des] > d[Ei] + Wire(Ei, des)) {
                        d[des] = d[Ei] + Wire(Ei, des);
                        Count[des] = Count[Ei];
                    }
                    else if (d[des] == d[Ei] + Wire(Ei, des)) {
                        Count[des] += Count[Ei];
                    }
                    nn = nn->next;
                }
            }
        }
    }
    return Count[Eno];
}
int Wire(int U, int V){
    Node* b = grape[U];
    while (b != NULL) {
        if (b->nextnodenum == V)
            return b->weight;
        b = b->next;
    }
    return -1;
}