//
// Created by 강대원 on 2018. 4. 9..
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100000
#define SWAP( x, y, t ) { t=x; x=y; y=t; }
int heapsize = 0;
int arraysize = 0;

void testHeap (int n, int m, int a[]);
void maxHeapInsert (int *a, int n);
void maxHeapExtract (int *a);
void maxHeapify (int *a, int i);

void testArray (int n, int m, int a[]);
void insertArray (int *a, int num);
void extractArray (int *a);

int main() {
    int N,M;
    printf ("N and M ?");
    scanf ("%d %d", &N, &M);

    int heapqueue[MAX];
    int heaparray[MAX];

    clock_t start, end;
    start = clock ();
    testHeap(N, M, heapqueue);
    end = clock ();
    printf ("%f\t", (double)(end-start)/CLOCKS_PER_SEC);

    start = clock ();
    testArray(N, M, heaparray);
    end = clock ();
    printf ("%f\t", (double)(end-start)/CLOCKS_PER_SEC);




    return 0;
}

void testHeap (int n, int m, int a[]) {
    srand ((unsigned)time (NULL));

    for (int i = 0; i < n; ++i)
        maxHeapInsert( a, rand() % n );
    for (int i = 0; i < m; ++i) {
        if ( rand () % 2 == 0 || heapsize == 0) {
            int num = rand () % n;
            maxHeapInsert( a, num );
        }
        else
            maxHeapExtract( a );
    }
}

void maxHeapInsert (int *a, int key) {
    heapsize++;
    a[heapsize] = key;
    int i = heapsize;
    int tmp;
    while ( i > 0 && a[(i-1)/2] < a[i] ){
        SWAP (a[i], a[(i-1)/2], tmp);
        i = (i-1)/2;
    }
}

void maxHeapExtract (int *a) {
    if ( heapsize < 0) {
        printf ("Heap underflow\n");
        return;
    }
//    int max = a[0];
    a[0] = a[heapsize];
    heapsize--;
    maxHeapify(a, 0);
//    return max;
}

void maxHeapify (int *a, int i) {
    int left, right, k, tmp;
    left = (i+1)*2 -1;
    right = (i+1)*2;

    if (left > heapsize)
        return;
    if (heapsize == left)
        k = left;
    else {
        if ( a[left] > a[right] )
            k = left;
        else
            k = right;
    }
    if ( a[i] >= a[k] )
        return;
    SWAP (a[i],a[k],tmp);
    maxHeapify (a, k);
}

void testArray (int n, int m, int a[]) {
    srand ((unsigned)time (NULL));
    for (int i = 0; i < n; ++i)
        insertArray( a, rand() % n );
    for (int i = 0; i < m; ++i) {
        if ( rand () % 2 == 0 || heapsize == 0) {
            int num = rand () % n;
            insertArray( a, num );
        }
        else
            extractArray( a );
    }
}

void insertArray (int *a, int num) {
    a[arraysize++] = num;
}

void extractArray (int *a) {
    int max = a[0];
    int index = 0;

    for (int i = 0; i < arraysize; ++i) {
        if (max < a[i]) {
            index = i;
            max = a[i];
        }
    }
    arraysize--;
    a[index] = a[arraysize];
}
