package Section2;

import java.util.Scanner;

public class Prob01LCS {

    private static final int MAX = 1000;
    private static int [][] c = new int [MAX][MAX];
    private static char [] str1 = new char [MAX];
    private static char [] str2 = new char [MAX];


    public static void main(String[] args) {

        Scanner kb = new Scanner(System.in);
        String str = kb.nextLine();
        str1 = str.toCharArray();

        str = kb.nextLine();
        str2 = str.toCharArray();

        System.out.println(LCS(str1.length, str2.length));
        printLCS(str1.length, str2.length);

    }

    private static void printLCS(int m, int n) {
        if (m==0 || n==0)
            return;
        if (c[m][n] > c[m-1][n] && c[m][n] > c[m][n-1] && c[m][n] > c[m-1][n-1]) {
            printLCS(m-1,n-1);
            System.out.print(str1[m-1]);
        }
        else if (c[m][n] > c[m-1][n] && c[m][n] == c[m][n-1])
            printLCS(m, n-1);
        else
            printLCS(m-1, n);
    }

    private static int LCS(int m, int n) {
        for (int i=0; i<=m; i++)
            c[i][0] = 0;
        for (int j=0; j<=n; j++)
            c[0][j] = 0;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (str1[i-1] == str2[j-1]) // false pdf file.. not x[i],y[i]
                    c[i][j] = c[i-1][j-1]+1;
                else
                    c[i][j] = Math.max(c[i-1][j], c[i][j-1]);
            }
        }
        return c[m][n];
    }
}
