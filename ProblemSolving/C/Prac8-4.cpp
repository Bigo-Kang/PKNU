#include <stdio.h>
#include <math.h>
#define MAX 100

int main()
{
    int mat[MAX][MAX];
    int n;

    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice02/input4.txt","r");
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fscanf(fp,"%d",&mat[i][j]);
    fclose(fp);

    double tmat[MAX][MAX];

    //column
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            tmat[i][j]=mat[i][j];
            sum += mat[i][j];
        }
        double avg=(double)sum/n;
        tmat[i][n]=avg;
        double stdev=0;
        for(int j=0;j<n;j++){
            stdev += pow(mat[i][j]-avg,2.0);
        }
        stdev /= (double)n;
        tmat[i][n+1]= sqrt(stdev);

    }
    //row
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum += mat[j][i];
        }
        double avg=(double)sum/n;
        tmat[n][i]=avg;
        double stdev=0;
        for(int j=0;j<n;j++){
            stdev += pow(mat[j][i]-avg,2.0);
        }
        stdev /= (double)n;
        tmat[n+1][i]= sqrt(stdev);

    }

    for(int i=0;i<n+2;i++){
        for(int j=0;j<n+2;j++){
            printf("%9lf ",tmat[i][j]);
        }
        printf("\n");
    }

    return 0;
}