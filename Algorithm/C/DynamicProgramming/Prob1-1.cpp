#include<stdio.h>
#define MAX 100

int matrixChain(int n);
void display (int i, int j);
void read_text();

int matrix[MAX][MAX];
int d[MAX][MAX];
int p[MAX];
int N;
int main(){
	//read_text();
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
        scanf("%d", &p[i]);
	printf("%d\n",matrixChain(N));
    display (1, N);
	return 0;
}
void read_text() {
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
        scanf("%d", &p[i]);
}

int matrixChain(int n) {
    for (int i = 1; i <= n; i++) {
        matrix[i][i] = 0;
    }
    for (int r = 1; r <= n - 1; r++) {
        for (int i = 1; i <= n - r; i++) {
            int j = i + r;
            matrix[i][j] = matrix[i + 1][j] + p[i - 1] * p[i] * p[j];
            d[i][j] = i;
            for (int k = i + 1; k <= j - 1; k++) {
                if (matrix[i][j] > matrix[i][k] + matrix[k + 1][j] + p[i - 1] * p[k] * p[j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k + 1][j] + p[i - 1] * p[k] * p[j];
                    d[i][j] = k;
                }
            }
        }
    }
    return matrix[1][n];
}

void display (int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        int k = d[i][j];
        if (i != 1 || j != N)
            printf("(");
        display (i, k);
        display (k + 1, j);
        if (i != 1 || j != N)
            printf(")");
    }
}
