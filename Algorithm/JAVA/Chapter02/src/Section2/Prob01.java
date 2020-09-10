package Section2;

//자바에서 boolean and int 는 다르다... 복잡하네..

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Prob01 {

    private static final int PATHWAY = 0;
    private static final int WALL = 1;
    private static final int BLOCKED = 2;
    private static final int PATH = 3;

    private static int[][] maze;
    private static int n, k;

    public static void main(String[] args) {
        readFile();
    }

    private static int findMazePath(int x, int y, int len) {

        int sum = 0;
        if (x < 0 || x >= n || y < 0 || y >= n || maze[x][y] != PATHWAY)
            return 0;
        else if (x == n - 1 && y == n - 1 && len <= k)
            return 1;
        else {
            maze[x][y] = PATH;
            sum = findMazePath(x - 1, y, len + 1) + findMazePath(x, y + 1, len + 1)
                    + findMazePath(x + 1, y, len + 1) + findMazePath(x, y - 1, len + 1);
            maze[x][y] = PATHWAY;
            return sum;
        }
    }

    private static void readFile() {
        try {
            Scanner fp = new Scanner(new File("input1.txt"));
            int t =fp.nextInt();
            for (int count = 0; count<t; count++) {
                n = fp.nextInt();
                maze = new int[n][n];
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        maze[i][j] = fp.nextInt();
                k = fp.nextInt();
                processing();
            }
            fp.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static void processing() {
        int result = findMazePath(0, 0, 0);
        System.out.println("The count is " + result);
    }
}
