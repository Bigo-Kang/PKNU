#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
int m[MAX][MAX];
int p[MAX];
int min_k[MAX][MAX];

int matrixChain(int n);
void print(int i, int j);

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
        scanf("%d", &p[i]);
    int res = matrixChain(N);
    printf("%d\n", res);
    print(1, N);
    return 0;

}
int matrixChain(int n)
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int r = 1; r <= n - 1; r++) {
        for (int i = 1; i <= n - r; i++) {
            int j = i + r;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            for (int k = i + 1; k <= j - 1; k++) {
                if (m[i][j] > m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]) {
                    m[i][j] = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    min_k[i][j] = k;
                }
            }
            if (m[i][j] == m[i + 1][j] + p[i - 1] * p[i] * p[j]) {
                min_k[i][j] = i;
            }
        }
    }
    return m[1][n];
}
void print(int i, int j) {
    int num = min_k[i][j];

    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    print(i, num);
    print(num + 1, j);
    printf(")");
}