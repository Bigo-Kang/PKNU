#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI acos(-1.0)
#define MAX 1000000
#define MAXLEN 300

typedef  struct node Node;
typedef  struct city {
    char* name;
    double lat;
    double lon;
    Node*list;
}City;

struct node {
    int index;
    double dist;
    Node *next;
};

typedef struct edge {
    double dist;
    int left, right;
}Edge;

City *citys[MAX];
Edge edges[MAX];
int MST[MAX];
int MSTSIZE[MAX];
Edge E[MAX];

double calDistance(double lat1, double lon1, double lat2, double lon2);
double deg2rad(double deg);
double rad2deg(double rad);
int readAl ();
int readRl2 ();
City *createCity (char *name, double lat, double lon);
int compare_edges(const void *p, const void *q);
int searchCity (char *name);
Node *CreateNode (int index, double dist);
int readLine(FILE*fp, char*arr, int n);
int kruskalMst (int last, int Enum);
void makeSet (int last);
int findSetPc (int x);
void WeightedUnion (int u, int v);
int findSet (int x);
void process (int last, int ksk);
void findCityNum (FILE *fp, int i, int ksk);

int main () {
    int last = readAl();
    int Enum = readRl2();
    int ksk = kruskalMst(last, Enum);
    process(last, ksk);
    return 0;
}

void process (int last, int ksk) {
    FILE*fp = fopen ("MST.txt", "w");
    for (int i = 0; i<=last; i++) {
        fprintf (fp, "%d - %lf %lf", i, citys[i]->lat, citys[i]->lon);
        findCityNum(fp,i, ksk);
        fprintf(fp, "\n");
    }
}

void findCityNum (FILE * fp, int i, int ksk) {
    for (int j=0; j < ksk; j++) {
        if ((E+j)->left == i)
            fprintf(fp, " %d ", (E+j)->right);
        else if ((E+j)->right == i)
            fprintf(fp, " %d ", (E+j)->left);
    }
}

int kruskalMst (int last, int Enum) {
    int k = 0;
    makeSet(last);
    qsort (edges, Enum, sizeof (Edge), compare_edges);
    for ( int i=0; i<Enum; i++) {
        if ((findSetPc((edges+i)->left) - findSetPc((edges+i)->right)) != 0) {
            E[k++] = *(edges+i);
            WeightedUnion((edges+i)->left, (edges+i)->right);
        }
        if ( k > last)
            break;
    }
    return k;
}

void WeightedUnion (int u, int v) {
    int x = findSet(u);
    int y = findSet(v);
    if (MSTSIZE[x] < MSTSIZE[y]) {
        MST[y] = x;
        MSTSIZE[x] = MSTSIZE[x] + MSTSIZE[y];
        MSTSIZE[y] = MSTSIZE[x];
    }
    else {
        MST[x] = y;
        MSTSIZE[x] = MSTSIZE[x] + MSTSIZE[y];
        MSTSIZE[y] = MSTSIZE[x];
    }
}

int findSet (int x) {
    if(MST[x] != x)
        MST[x] = findSet (MST[x]);
    return MST[x];
}

int findSetPc (int x) {
    while (MST[x] != x) {
        MST[x] = MST[MST[x]];
        x = MST[x];
    }
    return MST[x];
}

void makeSet (int last) {
    for ( int i=0; i<=last; i++) {
        MST[i] = i;
        MSTSIZE[i] = 1;
    }
}

double calDistance(double lat1, double lon1, double lat2, double lon2)
{                       //위도, 경도,            위도,경도
    double theta, dist;
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1))*sin(deg2rad(lat2)) + cos(deg2rad(lat1))*cos(deg2rad(lat2))*cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;//단위mile에서 km변환
    dist = dist*1000.0;//단위km에서 m로 변환
    return dist;
}
double deg2rad(double deg) {
    return (double)(deg*PI / (double)180);
}
double rad2deg(double rad) {
    return (double)(rad*(double)180 / PI);
}

int readRl2 () {
    FILE*fp = fopen ("roadList2.txt", "r");
    char buf[MAXLEN], *name1, *name2;
    char delim[] = "\t";
    int i = 0, index1, index2;
    double dist;
    while (!feof (fp)) {
        //fgets (buf, MAXLEN, fp);
        readLine(fp, buf, MAXLEN);
        name1 = strtok (buf, delim);
        name2 = strtok (NULL, delim);
        if (name1 == NULL || name2 == NULL)
            break;
        index1 = searchCity(name1);
        index2 = searchCity(name2);
        dist = calDistance (citys[index1]->lat, citys[index1]->lon,
                            citys[index2]->lat, citys[index2]->lon);
        Node*nn2 = CreateNode(index1, dist);
        Node*nn1 = CreateNode(index2, dist);
        (edges + i)->dist = dist;
        (edges + i)->left = index1;
        (edges + i++)->right = index2;
        nn1->next = citys[index1]->list;
        citys[index1]->list = nn1;
        nn2->next = citys[index2]->list;
        citys[index2]->list = nn2;
    }
    fclose (fp);
    return i-1;
}

Node *CreateNode (int index, double dist) {
    Node* nset = (Node*) malloc (sizeof (Node));
    nset->index = index;
    nset->dist = dist;
    nset->next = NULL;
    return nset;
}

int searchCity (char *name) {
    int i=0;
    while (citys[i] != NULL) {
        if (strcmp(citys[i]->name, name) == 0)
            return i;
        i++;
    }
    if (citys[i] == NULL)
        return -1;
}

int readAl () {
    FILE*fp = fopen("alabama.txt", "r");
    char buf[MAXLEN], *name, *lat, *lon;
    int i=0;
    double Dlat, Dlon;
    char delim[] = "\t";
    while(!feof (fp)) {
        readLine(fp, buf, MAXLEN);
        //fgets (buf, MAXLEN, fp);
        name = strtok (buf, delim);
        //printf("%s\n", name);
        lat = strtok (NULL, delim);
        lon = strtok(NULL, delim);
        Dlat = atof (lat);
        Dlon = atof (lon);

        City * nn = createCity(name,Dlat, Dlon);
        citys[i++] = nn;
    }
    fclose (fp);
    return (i-1);
}

City *createCity (char *name, double lat, double lon) {
    City* set = (City*)malloc (sizeof (City));
    set->name = strdup (name);
    set->lat = lat;
    set->lon = lon;
    set->list = NULL;
    return set;
}

int compare_edges(const void *p, const void *q) {
    double one = (((Edge*)p)->dist )- (((Edge*)q)->dist);
    if (one > 0)
        return 1;
    else
        return -1;
}

int readLine(FILE*fp, char*arr, int n) {
    int ch, i = 0;
    while ((ch = fgetc(fp)) != '\n'&&ch != EOF)
        if (i < n - 1)
            arr[i++] = ch;
    arr[i] = '\0';
    return i;
}