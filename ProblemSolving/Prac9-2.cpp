#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double evalProbBySim(int n, int k, int T) {
    double result=0, sum = 0;
    int count = 0;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < T; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            int a = rand() % 6 + 1;
            if (a == 1) count++;
        }
        if (count >= k)
            sum++;
    }
    result = sum / T;
    return result;
}
int main()
{
    int T = 1000000;
    for(int i=1; i<6;i++) {
        double prob = evalProbBySim(i*6, i, T);
        printf("%lf\n", prob);
    }

    return 0;
}