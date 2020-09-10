#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"queueADT.h"

#define PI acos(-1.0)
#define MAX 100000
#define MAXLEN 300

typedef struct node Node;
typedef struct city {
    char*name;
    double lat;
    double lon;
    Node*list;
}City;

struct node {
    int index;
    double dist;
    Node*next;
};

City*citys[MAX];
int BoollforA[MAX];
int BoolforB[MAX];

double calDistance(double lat1, double lon1, double lat2, double lon2);
double deg2rad(double deg);
double rad2deg(double rad);
void input_alabama();
void input_radList2();
int searchCity(char*name);
Node*CreateNode(int index, double dist);
int readLine(FILE*fp, char*arr, int n);
City* createCity(char*name, double lat, double lon);
void SolveTheFirst();
Queue pushqueue(Queue q, int num);
void printCitys(int index);
void SolveTheSecond();
void DFG(FILE*fp, int num);


int main() {
    input_alabama();
    input_radList2();
    SolveTheFirst();
    SolveTheSecond();
    return 0;
}

double calDistance(double lat1, double lon1, double lat2, double lon2)
{                       //위도, 경도,            위도,경도
    double theta, dist;
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1))*sin(deg2rad(lat2)) + cos(deg2rad(lat1))*cos(deg2rad(lat2))*cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;//단위mile에서 km변환
    dist = dist * 1000.0;//단위km에서 m로 변환
    return dist;
}
double deg2rad(double deg) {
    return (double)(deg*PI / (double)180);
}
double rad2deg(double rad) {
    return (double)(rad*(double)180 / PI);
}
void input_alabama() {
    FILE*fp = fopen("alabama.txt", "r");
    char buffer[MAXLEN], *name, *lat, *lon;
    int i = 0;
    double Dlat, Dlon;
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

}
void input_radList2() {
    FILE*fp = fopen("roadList2.txt", "r");
    char buffer[MAXLEN], *name1, *name2;
    char delim[] = "\t";
    int indexOf1, indexOf2;
    double dist;
    while (!feof(fp)) {
        readLine(fp, buffer, MAXLEN);
        name1 = strtok(buffer, delim);
        name2 = strtok(NULL, delim);
        if (name1 == NULL || name2 == NULL)break;
        indexOf1 = searchCity(name1);
        indexOf2 = searchCity(name2);
        dist = calDistance(citys[indexOf1]->lat, citys[indexOf1]->lon, citys[indexOf2]->lat, citys[indexOf2]->lon);
        Node*nn2 = CreateNode(indexOf1, dist);
        Node*nn1 = CreateNode(indexOf2, dist);
        nn1->next = citys[indexOf1]->list;
        citys[indexOf1]->list = nn1;
        nn2->next = citys[indexOf2]->list;
        citys[indexOf2]->list = nn2;
    }
    fclose(fp);
}
void SolveTheFirst() {
    Queue q = create();
    char buffer[MAXLEN];
    int inputindex;
    printf("임의의 한 지점의 이름을 입력하세요:");
    fgets(buffer, MAXLEN, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    inputindex = searchCity(buffer);
    if (inputindex == -1) {
        printf("지점이름이 없습니다.\n");
        return;
    }
    BoollforA[inputindex] = 1;
    q = pushqueue(q, inputindex);
    printCitys(inputindex);
    while (1) {
        int InTheQ = dequeue(q);
        pushqueue(q, InTheQ);
        if (BoollforA[InTheQ] == 12)break;
        printCitys(InTheQ);
    }
}
Queue pushqueue(Queue q, int num) {
    Node* pp = citys[num]->list;
    int prepath = BoollforA[num];
    while (pp != NULL) {
        if (BoollforA[pp->index] == 0) {
            enqueue(q, pp->index);
            BoollforA[pp->index] = prepath + 1;
        }
        pp = pp->next;
    }
    return q;
}
void printCitys(int index) {
    City*visited = citys[index];
    printf("%d..", BoollforA[index] - 1);
    printf("%s\n", visited->name);
    printf("\t %lf\n\t %lf\n", visited->lat, visited->lon);
}
void SolveTheSecond() {
    FILE*fp = fopen("SecondProb.txt", "w");
    char buffer[MAXLEN];
    int inputnum;
    printf("임의의 한 지점의 이름을 입력하세요:");
    fgets(buffer, MAXLEN, stdin);
    buffer[strlen(buffer) - 1] = '\0';
    inputnum = searchCity(buffer);
    if (inputnum == -1) {
        printf("지점이름이 없습니다.\n");
    }
    else
        DFG(fp, inputnum);
    fclose(fp);
}
void DFG(FILE*fp, int num) {
    BoolforB[num] = 1;
    City*visited = citys[num];
    fprintf(fp, "%s", visited->name);
    fprintf(fp, "\t %lf \t %lf \n", visited->lat, visited->lon);
    Node*nn = citys[num]->list;
    while (nn != NULL) {
        if (BoolforB[nn->index] == 0)
            DFG(fp, nn->index);
        nn = nn->next;
    }
}

int searchCity(char*name) {
    int i = 0;
    while (citys[i] != NULL) {
        if (strcmp(citys[i]->name, name) == 0) {
            return i;
        }
        i++;
    }
    if (citys[i] == NULL)
        return -1;
}
Node*CreateNode(int index, double dist) {
    Node* nset = (Node*)malloc(sizeof(Node));
    nset->index = index;
    nset->dist = dist;
    nset->next = NULL;
    return nset;
}
int readLine(FILE*fp, char*arr, int n) {
    int ch, i = 0;
    while ((ch = fgetc(fp)) != '\n'&&ch != EOF)
        if (i < n - 1)
            arr[i++] = ch;
    arr[i] = '\0';
    return i;
}
City* createCity(char*name, double lat, double lon) {
    City*set = (City*)malloc(sizeof(City));
    set->name = strdup(name);
    set->lat = lat;
    set->lon = lon;
    set->list = NULL;
    return set;
}
