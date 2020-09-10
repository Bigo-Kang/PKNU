#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI acos(-1.0)
#define MAX 100000
#define MAXLEN 300

typedef struct node Node;
typedef struct city City;
struct city {
    char*name;
    double lat;
    double lon;
    Node*next;
    bool visit;
    double dist;
    City* prev;
};

struct node {
    int index;
    double edge;
    Node*next;
};
double calDistance(double lat1, double lon1, double lat2, double lon2);
double deg2rad(double deg);
double rad2deg(double rad);
int raedAl ();
void readRl2 ();
int findIndex (char *name);
Node*CreateNode(int index, double dist);
City*createCity(char*name, double lat, double lon);
int readLine(FILE*fp, char*buffer, int max) ;

void Dijkstra (int d, int s, int minimum);
void Init ();
double Wire (int u, int v);
int Findminimum (int minimum);

City* citys[MAX];
City* map[MAX];

double Degree[MAX];
int nodePI[MAX];
int SSet[MAX];
int Snum = -1;

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

int main() {
    int noden = raedAl();
    readRl2();
    char sour[MAXLEN];
    char dest[MAXLEN];
    printf("sour? : ");
    fgets(sour, MAXLEN, stdin);
    sour[strlen(sour) - 1] = '\0';
    printf("dest? : ");
    fgets(dest, MAXLEN, stdin);
    dest[strlen(dest) - 1] = '\0';
    int s = findIndex(sour);
    int d = findIndex(dest);

    Dijkstra(d, s, noden);

}

void Init() {
    for (int i = 0; i < MAX; i++) {
         = MAX;
        nodePI[i] = NULL;
        SSet[i] = -1;
    }
}

void Dijkstra (int d, int s, int minimum) {
    int sindex = s;
    int npoint = 0;
    City* p;

    Init();




}


double Wire (int u, int v) {
    Node* b = citys[u]->next;
    while (b!=NULL) {
        if (b->index == v)
            return b->edge;
        b = b->next;
    }
    return -1;
}

void readRl2 () {
    FILE*fp = fopen("roadList2.txt", "r");
    char buffer[MAXLEN], *name1, *name2;
    char delim[] = "\t";
    int indexS, indexD;
    double dist;
    while (!feof(fp)) {
        readLine(fp, buffer, MAXLEN);
        name1 = strtok(buffer, delim);
        name2 = strtok(NULL, delim);
        if (name1 == NULL || name2 == NULL)
            break;
        indexS = findIndex (name1);
        indexD = findIndex (name2);
        dist = calDistance(citys[indexS]->lat, citys[indexS]->lon, citys[indexD]->lat, citys[indexD]->lon);
        Node*S = CreateNode(indexS, dist);
        Node*D = CreateNode(indexD, dist);

        D->next = citys[indexS]->next;
        citys[indexS]->next = D;
        S->next = citys[indexD]->next;
        citys[indexD]->next = S;
    }
    fclose(fp);
}
int findIndex (char *name) {
    int i = 0;
    while (citys[i] != NULL) {
        if (strcmp(citys[i]->name, name) == 0)
            return i;
        i++;
    }
    if (citys[i] == NULL)
        return -1;
}
Node*CreateNode(int index, double dist) {
    Node* set = (Node*)malloc(sizeof(Node));
    set->index = index;
    set->edge = dist;
    set->next = NULL;
    return set;
}

int raedAl () {
    FILE*fp = fopen("alabama.txt", "r");
    char buffer[MAXLEN], *name, *lat, *lon;
    int i = 0;
    double Dlat, Dlon;//double로 변환한것 입력
    char delim[] = "\t";
    while (!feof(fp)) {
        readLine(fp, buffer, MAXLEN);
        name = strtok(buffer, delim);
        lat = strtok(NULL, delim);
        lon = strtok(NULL, delim);
        Dlat = atof(lat);
        Dlon = atof(lon);
        City*nn = createCity(name, Dlat, Dlon);
        citys[i++] = nn;
    }
    fclose(fp);
    return --i;
}

City*createCity(char*name, double lat, double lon) {
    City*set = (City*)malloc(sizeof(City));
    set->name = strdup(name);
    set->lat = lat;
    set->lon = lon;
    set->next = NULL;
    set->visit = false;
    set->prev = NULL;
    return set;
}

int readLine(FILE*fp, char*buffer, int max) {
    int ch, i = 0;
    while ((ch = fgetc(fp)) != '\n'&&ch != EOF)
        if (i < max - 1)
            buffer[i++] = ch;
    buffer[i] = '\0';
    return i;
}