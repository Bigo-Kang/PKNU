package Section2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Prob01a {

    private static final int PATHWAY = 0;
    private static final int WALL = 1;
    private static final int BLOCKED = 2;
    private static final int PATH = 3;
    private static final int DIR = 4;

    private static int[][] maze;
    private static int n, k;
    private static int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public static void main(String[] args) {
        readFile();
    }

    private static int findMazePath(int x, int y, int dist) {

        if (x < 0 || x >= n || y < 0 || y >= n || maze[x][y] != PATHWAY)
            return 0;
        else if (dist > k)
            return 0;
        else if (x == n - 1 && y == n - 1)
            return 1;
        else {
            maze[x][y] = PATH;
            int sum = 0;

            for (int i=0; i<DIR; i++)
                sum += findMazePath(x+dir[i][0], y+dir[i][1], dist + 1);

            maze[x][y] = PATHWAY;
            return sum;
        }
    }

    private static void readFile() {
        try {
            Scanner fp = new Scanner(new File("input1.txt"));
            int t = fp.nextInt();
            for (int count = 0; count < t; count++) {
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