//
// Created by 강대원 on 2018. 3. 29..
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100000
#define SWAP( x, y, t ) { t=x; x=y; y=t; }

float selection (int a[],int size);
float bubble (int a[], int size);
float inserts (int a[], int size);
float mergeSort (int a[], int left, int right);
void merge (int a[], int left, int mid, int right);
float quick1 (int a[], int left, int right);
int partition1 (int *a, int left, int right);
float quick2 (int a[], int left, int right);
float quick3 (int a[], int left, int right);
void medianrule (int *a, int left, int right);
void ches (int *a, int left, int right);

float heap (int a[], int size);
void Max_heapify (int *a, int i, int size);
float library (int a[], int left, int right);
int compare(const void *p, const void *q);
int partition2 (int *a, int left, int right);

int partition3 (int *a, int left, int right);
void genrandom (int size);
void copy (int size);

void reverse (int size);

int data[MAX];
int use[MAX];
int ruse[MAX];
int mrge[MAX];

int t;

int main() {
    double table[9][6] = {0};
    char *type[] = {"Bubble","Selection","Insertion","Merge","Quick1","Quick2","Quick3","Heap","Library"};
    int size[] = {1000, 0, 10000, 0, 100000};
    float sel=0, rsel=0, bub=0, rbub=0;
    float ins=0, rins=0, mer=0, rmer=0;
    float hip=0, rhip=0, lib=0, rlib=0;
    float qik1=0, rqik1=0, qik2=0, rqik2=0, qik3=0, rqik3=0;



    for (int i = 0; i < sizeof (size) / sizeof (int) ; i+=2) {
        int k = size[i] - 1;
        for (int test = 0; test < 10; test++) {
            genrandom (size[i]);

            copy (size[i]);
            bub += bubble (use, size[i]);
            reverse (size[i]);
            rbub += bubble (ruse, size[i]);

            copy (size[i]);
            sel += selection (use, size[i]);
            reverse (size[i]);
            rsel += selection (ruse, size[i]);

            copy (size[i]);
            ins += inserts (use, size[i]);
            reverse (size[i]);
            rins += inserts (ruse, size[i]);

            copy (size[i]);
            mer += mergeSort (use, 0, size[i] - 1);
            reverse (size[i]);
            rmer += mergeSort (ruse, 0, size[i] - 1);

            copy (size[i]);
            qik1 += quick1 (use, 0, size[i] - 1);
            reverse (size[i]);
            rqik1 += quick1 (ruse, 0, size[i] - 1);

            copy (size[i]);
            qik2 += quick2 (use, 0, size[i] - 1);
            reverse (size[i]);
            rqik2 += quick2 (ruse, 0, size[i] - 1);

            copy (size[i]);
            qik3 += quick3 (use, 0, size[i] - 1);
            reverse (size[i]);
            rqik3 += quick3 (ruse, 0, size[i] - 1);

            copy (size[i]);
            hip += heap (use, size[i]);
            reverse (size[i]);
            rhip += heap (ruse, size[i]);

            copy (size[i]);
            lib += library (use, 0, size[i]);
            reverse (size[i]);
            rlib += library (ruse, 0, size[i]);
        }


        table[0][0+i] = (bub / (CLOCKS_PER_SEC)) / 10.0;
        table[0][1+i] = (rbub / (CLOCKS_PER_SEC)) / 10.0;
        table[1][0+i] = (sel / (CLOCKS_PER_SEC)) / 10.0;
        table[1][1+i] = (rsel / (CLOCKS_PER_SEC)) / 10.0;
        table[2][0+i] = (ins / (CLOCKS_PER_SEC)) / 10.0;
        table[2][1+i] = (rins / (CLOCKS_PER_SEC)) / 10.0;
        table[3][0+i] = (mer / (CLOCKS_PER_SEC)) / 10.0;
        table[3][1+i] = (rmer / (CLOCKS_PER_SEC)) / 10.0;
        table[4][0+i] = (qik1 / (CLOCKS_PER_SEC)) / 10.0;
        table[4][1+i] = (rqik1 / (CLOCKS_PER_SEC)) / 10.0;
        table[5][0+i] = (qik2 / (CLOCKS_PER_SEC)) / 10.0;
        table[5][1+i] = (rqik2 / (CLOCKS_PER_SEC)) / 10.0;
        table[6][0+i] = (qik3 / (CLOCKS_PER_SEC)) / 10.0;
        table[6][1+i] = (rqik3 / (CLOCKS_PER_SEC)) / 10.0;
        table[7][0+i] = (hip / (CLOCKS_PER_SEC)) / 10.0;
        table[7][1+i] = (rhip / (CLOCKS_PER_SEC)) / 10.0;
        table[8][0+i] = (lib / (CLOCKS_PER_SEC)) / 10.0;
        table[8][1+i] = (rlib / (CLOCKS_PER_SEC)) / 10.0;
    }

    printf ("             Random1000     Reverse1000     Random10000    Reverse10000    Random100000   Reverse100000\n");
    for (int x = 0; x < 9; ++x) {
        printf ("%10s", type[x]);
        for (int y = 0; y < 6; ++y) {
         printf ("%13lf   ", table[x][y]);
        }
        printf ("\n");
    }
}

void genrandom (int size) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++) {
        data[i] = rand () % size + 1;
    }
}

void copy (int size) {
    for (int i = 0; i < size ; i++)
        use[i] = data[i];
}

void reverse (int size) {
    for (int i = 0; i < size ; ++i)
        ruse[i] = use[size-1-i];
}

float selection (int a[], int size) {
    clock_t start, end;
    start = clock ();
    int max = 0;
    for (int i = size-1; i > 0; i--) {
        max = i;
        for (int j = i-1; j >= 0; j--) {
            if (a[j]>a[max]) max = j;
        }
        SWAP (a[i],a[max], t);
    }
    end = clock ();
    return (end-start); // /(CLOCKS_PER_SEC)
}

float bubble (int a[], int size) {
    clock_t start, end;
    start = clock ();

    for (int last = size-1; last > 0; last--) {
        for (int i = 0; i < last; i++) {
            if (a[i] > a[i+1]) {
                SWAP (a[i],a[i+1],t)
            }
        }
    }

    end = clock ();
    return (end-start);
}

float inserts (int a[], int size) {
    clock_t start, end;
    start = clock ();

    for (int i = 1; i < size; i++) {
        int tmp = a[i];
        int j = i-1;
        while ( j>=0 && a[j] > tmp ) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
    }

    end = clock ();
    return (end-start);
}

float mergeSort (int a[], int left,int right) {
    clock_t start, end;
    start = clock ();
    int mid;

    if ( left < right) {
        mid = (left+right)/2;
        mergeSort (a, left, mid);
        mergeSort (a, mid+1, right);
        merge(a, left, mid, right);
    }

    end = clock ();
    return (end-start);
}

void merge (int a[], int left, int mid, int right) {
    int fir = left, sec = mid+1, newp = left, i;
    while ( fir<=mid && sec<=right ) {
        if ( a[fir] < a[sec] )
            mrge[newp++] = a[fir++];
        else
            mrge[newp++] = a[sec++];
    }

    if ( fir > mid) {
        for ( i = sec; i <= right; i++) {
            mrge[newp++] = a[i];
        }
    }
    else {
        for ( i = fir; i <= mid; i++) {
            mrge[newp++] = a[i];
        }
    }
//    while ( fir <= mid )
//        mrge[newp++] = a[fir++];
//    while ( sec <= right )
//        mrge[newp++] = a[sec++];
    for (i = left; i <= right; i++) {
        a[i] = mrge[i];
    }

}

float quick1 (int a[], int left, int right) {
    clock_t start, end;
    start = clock ();

    int q;
    if ( left < right ) {
        q = partition1 (a, left, right);
        quick1 (a, left, q-1);
        quick1 (a, q+1, right);
    }

    end = clock ();
    return (end-start);
}

int partition1 (int *a, int left, int right) {
    int pivot = a[right];
    int i = left-1, tmp;

    for (int j = left; j < right ; j++) {
        if ( a[j] <= pivot ) {
            i++;
            SWAP (a[i], a[j], tmp);
        }
    }
    SWAP (a[i+1], a[right], tmp);
    return i+1;

//    int pivot,temp;
//    int low,high;
//    low=left;
//    high=right+1;
//    pivot=a[left];
//    do{
//        do{
//            low++;
//        }while(low<=right && a[low]<pivot);
//        do{
//            high--;
//        }while(left<=high && a[high]>pivot);
//        if(low<high) SWAP(a[low],a[high],temp);
//    }while(low<high);
//    SWAP(a[left],a[high],temp);
//    return high;
}

float quick2 (int a[], int left, int right) {
    clock_t start, end;
    start = clock ();

    int q;
    if ( left < right ) {
        medianrule(a,left,right);
        q = partition1 (a, left, right);
        quick1 (a, left, q-1);
        quick1 (a, q+1, right);
    }

    end = clock ();
    return (end-start);
}

void medianrule (int *a, int left, int right) {
    int b[5],t;
    b[1]=a[left]; b[2]=a[(left+right)/2];	b[3]=a[right];
    quick1(b,1,3);
    if(b[2]==a[(left+right)/2]) SWAP(a[right],a[(left+right)/2],t);
    if(b[2]==a[left]) SWAP(a[left],a[right],t);
}

float quick3 (int a[], int left, int right) {
    clock_t start, end;
    start = clock ();

    int q;
    if ( left < right ) {
        ches(a, left, right);
        q = partition1 (a, left, right);
        quick1 (a, left, q-1);
        quick1 (a, q+1, right);
    }

    end = clock ();
    return (end-start);
}

void ches (int *a, int left, int right) {
    int random = rand () % ((right+left)+1), tmp;
    SWAP (a[random], a[right], tmp);
}

int partition3 (int *a, int left, int right) {
    int random = rand () % ((right+left)+1);

    int pivot = a[random];
    int i = left-1, tmp;

    for (int j = left; j < right ; j++) {
        if ( a[j] <= pivot ) {
            i++;
            SWAP (a[i], a[j], tmp);
        }
    }
    SWAP (a[i+1], a[right], tmp);
    return i+1;
}

int partition2 (int *a, int left, int right) {
    int pivot, MoT;
    int begin = a[left], median = a[(left+right)/2], end = a[right];

    if ( (begin <= median && begin >= end) || (begin >= median && begin <= end) )
        MoT = begin;
    else if ( (median <= begin && median >= end) || (median >= begin && median <= end) )
        MoT = median;
    else
        MoT = end;

    pivot = a[MoT];
    int i = left-1, tmp;
    for (int j = left; j < right ; j++) {
        if ( a[j] <= pivot ) {
            i++;
            SWAP (a[i], a[j], tmp);
        }
    }
    SWAP (a[i+1], a[right], tmp);
    return i+1;
}

float heap (int a[], int size) {
    clock_t start, end;
    start = clock ();

    int i,temp;
    //build max heap
    for(i=size/2;i>=0;i--)
        Max_heapify (a,i,size);

    //heapsort
    for(i=size;i>0;i--){
        SWAP(a[0],a[i],temp);
        Max_heapify (a,0,i);
    }

    end = clock ();
    return (end-start);
}

void Max_heapify (int *a, int i, int size) {
    int k, tmp;
    int left = (2*i)+1;
    int right = (2*i)+2;
    if ( left > size-1 )
        return;
    if ( a[i] < a[left] )
        k = left;
    else
        k = i;
    if ( right <= size-1 && a[k] < a[right])
        k = right;
    if (k != i) {
        SWAP (a[i], a[k], tmp);
        Max_heapify (a, k, size);
    }
}

float library (int a[], int left, int right) {
    clock_t start, end;
    start = clock ();

    qsort ( a, right, sizeof (a[0]), compare);
    end = clock ();
    return (end-start);
}

int compare(const void *p, const void *q) {
    return *((int*)p) - *((int*)q);
}
