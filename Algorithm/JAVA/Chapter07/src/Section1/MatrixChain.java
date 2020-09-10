package Section1;

import java.util.Scanner;

public class MatrixChain {

    private static final int MAX = 100;
    public static int [][] data = new int [MAX][MAX];
    public static int [][] matrix = new int [MAX][MAX];
    public static int [] p = new int [MAX];
    public static int N;
    public static void main(String[] args) {

        Scanner kb = new Scanner(System.in);
        N = kb.nextInt();
        for (int i=0; i<=N; i++)
            p[i] = kb.nextInt();

        System.out.println(matrixChain(N));
        display(1, N);
    }

    private static void display(int i, int j) {
        if (i==j)
            System.out.print("A"+i);
        else {
            int k=data[i][j];
            if (i != 1 || j != N)
                System.out.print("(");
            display(i,k);
            display(k+1,j);
            if (i != 1 || j != N)
                System.out.print(")");
        }
    }

    private static int matrixChain(int n) {
        for (int i=1; i<=n; i++)
            matrix[i][i] = 0;
        for (int r=1; r<=n-1; r++) {
            for (int i=1; i<=n-r; i++) {
                int j = i+r;
                matrix[i][j] = matrix[i+1][j] + p[i-1] * p[i] * p[j];
                data[i][j] = i;
                for (int k=i+1; k<=j-1; k++) {
                    if (matrix[i][j] > matrix[i][k] + matrix[k+1][j] + p[i-1] * p[k] * p[j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k+1][j] + p[i-1] * p[k] * p[j];
                        data[i][j] = k;
                    }

                }
            }
        }
        return matrix[1][n];
    }
}
