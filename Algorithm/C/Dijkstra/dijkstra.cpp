#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 15000
#define PI acos(-1.0)
#define BUFFER 300

typedef struct city City;
struct city {
    int index;
    double edge_value;
    City* next;
};

typedef struct node Node;
struct node {
    char* place;
    double longitude;
    double latitude;
    City* next;
    bool visit;
    double d;
    Node* prev;
};

Node ary[MAX];
Node minpath[MAX];

void dijkstra (int S, int D);
void relax(int u, int v, City* p);
int find_mind();
void init();
void input_alabama();
City* new_neighbor();
int search_index(char* place_name);
double calDistance(double lat1, double lon1, double lat2, double lon2);
double deg2rad(double deg);
double rad2deg(double rad);
void print(char* start, char* arrival);
int read_line(FILE *fp, char str[], int n);

int main()
{
    char start[BUFFER];
    char dest[BUFFER];

    input_alabama();

    printf("<최단 경로 구하기>\n");
    printf("출발 지명을 입력하세요 : ");
    read_line(stdin, start, BUFFER);
    printf("도착 지명을 입력하세요 : ");
    read_line(stdin, dest, BUFFER);

    int S=search_index(start);
    int D = search_index(dest);

    dijkstra (S, D);

    print(start, dest);

    return 0;
}

void dijkstra (int S, int D)
{

    int mind_index=S;
    int npoint=0;
    City* p;

    init();

    ary[S].d = 0;

    while (npoint < MAX) {
        if (npoint != 0) {
            mind_index = find_mind();
        }
        ary[mind_index].visit = true;
        if (D == mind_index) {
            break;
        }

        p = ary[mind_index].next;
        while (p != NULL) {
            if (ary[p->index].visit == false)
                relax(mind_index, p->index, p);
            p = p->next;
        }
        npoint++;
    }

}

void relax(int u, int v, City* p)
{
    if (ary[v].d > ary[u].d + p->edge_value) {
        ary[v].d = ary[u].d + p->edge_value;
        ary[v].prev = &ary[u];
    }
}

int find_mind()
{
    double mind=INFINITY;
    int mind_index=0;

    for (int i = 0; i < MAX; i++) {
        if (ary[i].visit == false && mind > ary[i].d) {
            mind = ary[i].d;
            mind_index = i;
        }
    }

    return mind_index;
}

void init()
{
    for (int i = 0; i < MAX; i++) {
        ary[i].d = INFINITY;
        ary[i].prev = NULL;
    }
}

void input_alabama() {

    FILE *data_file = fopen("alabama.txt", "r");
    char line[BUFFER];
    char*place;
    double longitude, latitude;

    int i = 0;
    while (1) {
        char* res = fgets(line, BUFFER, data_file);
        if (res == NULL) break;

        place = strtok(line, "\t");
        longitude = atof(strtok(NULL, "\t"));
        latitude = atof(strtok(NULL, "\t"));

        ary[i].place = strdup(place);
        ary[i].longitude = longitude;
        ary[i].latitude = latitude;
        ary[i].visit = false;
        ary[i].prev = NULL;
        i++;
    }
    fclose(data_file);

    FILE *file = fopen("roadList2.txt", "r");
    char *first_place_name, *second_place_name;

    while (1) {
        char* res = fgets(line, BUFFER, data_file);
        if (res == NULL) break;

        first_place_name = strtok(line, "\t");
        second_place_name = strtok(NULL, "\n");
        int tmp_findex = search_index(first_place_name);
        int tmp_sindex = search_index(second_place_name);

        City* nei = new_neighbor();
        nei->index = tmp_sindex;
        nei->edge_value = calDistance(ary[tmp_findex].longitude, ary[tmp_findex].latitude, ary[tmp_sindex].longitude, ary[tmp_sindex].latitude);
        if (ary[tmp_findex].next != NULL) {
            nei->next = ary[tmp_findex].next;
            ary[tmp_findex].next = nei;
        }
        else
            ary[tmp_findex].next = nei;

        nei = new_neighbor();
        nei->index = tmp_findex;
        nei->edge_value = calDistance(ary[tmp_sindex].longitude, ary[tmp_sindex].latitude, ary[tmp_findex].longitude, ary[tmp_findex].latitude);
        if (ary[tmp_sindex].next != NULL) {
            nei->next = ary[tmp_sindex].next;
            ary[tmp_sindex].next = nei;
        }
        else
            ary[tmp_sindex].next = nei;
    }

    fclose(file);
}

City* new_neighbor()
{
    City* nei = (City*)malloc(sizeof(City));
    nei->index = 0;
    nei->edge_value = 0;
    nei->next = NULL;
    return nei;
}

int search_index(char* place_name)
{
    for (int i = 0; i < MAX; i++) {
        if (strcmp(ary[i].place, place_name) == 0) {
            return i;
        }
    }
}

double calDistance(double lat1, double lon1, double lat2, double lon2)
{
    double theta, dist;
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2))
           + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;
    dist = dist * 1.609344;
    dist = dist * 1000.0;
    return dist;
}

double deg2rad(double deg) {
    return (double)(deg * PI / (double)180);
}

double rad2deg(double rad) {
    return (double)(rad * (double)180 / PI);
}

void print(char* start, char* arrival)
{
    double path_length = 0;
    int s_index = search_index(start);
    int a_index = search_index(arrival);

    int i = 0;
    Node* p = &ary[a_index];

    path_length = p->d;
    while (p != NULL) {
        minpath[i] = *p;
        i++;
        p = p->prev;
    }

    i--;
    int k = 0;
    while (k <= i) {
        printf("%d. %s\n", k,minpath[i-k].place);
        k++;
    }
    printf("%lf\n", path_length);

}

int read_line(FILE *fp, char str[], int n) {
    int ch, i = 0;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
        if (i < n - 1)
            str[i++] = ch;

    str[i] = '\0';
    return i;
}