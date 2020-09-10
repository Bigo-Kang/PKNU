package Section2;

import java.util.Scanner;

public class Prob02 {

    private static final int MAX = 100;
    private static int [][] MM = new int [MAX][MAX];

    public static void main(String[] args) {
        int N;
        int [] d = new int [MAX];

        Scanner kb = new Scanner(System.in);
        N = kb.nextInt();

        for (int i=0; i<N; i++)
            d[i] = kb.nextInt();

        System.out.println(maxDiff(N, d));

    }

    private static int maxDiff(int n, int[] d) {
        for (int i=0; i<=n; i++)
            MM[0][i] = 0;
        for (int j=1; j<=n; j++)
            MM[j][0] = d[j-1];
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (j>i)
                    MM[i][j] = MM[i][j-1];
                else {
                    if (MM[i-j][j] + d[j-1] >= MM[i][j-1])
                        MM[i][j] = MM[i-j][j] + d[j-1];
                    else
                        MM[i][j] = MM[i][j-1];
                }
            }
        }
        return MM[n][n];
    }
}
