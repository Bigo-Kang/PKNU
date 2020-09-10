package Section2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Prob02a {

    private static final int PATHWAY = 0;
    private static final int WALL = 1;
    private static final int BLOCKED = 2;
    private static final int PATH = 3;
    private static final int DIR = 4;

    private static int n, t;
    private static int[][] maze;
    private static int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public static void main(String[] args) {
        readFile();
    }

    private static boolean findMazePath(int x, int y) {

        if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] != PATHWAY)
            return false;
        else if (x == n - 1 && y == n - 1) {
            maze[x][y] = PATH;
            return true;
        }
        else {
            maze[x][y] = PATH;
            for (int i = 0; i < DIR; i++) {
                int dist = go(x, y, i);
                if (findMazePath(x + dir[i][0] * dist, y + dir[i][1] * dist))
                    return true;
            }
            maze[x][y] = BLOCKED;
            return false;
        }
    }

    private static int go(int x, int y, int d) {
        int count = 0;
        while (true) {
            x += dir[d][0];
            y += dir[d][1];
            if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == WALL)
                return count;
            count++;
        }
    }

    private static void readFile() {
        try {
            Scanner fp = new Scanner(new File("input2.txt"));
            t = fp.nextInt();
            for (int cnt = 0; cnt < t; cnt++) {
                n = fp.nextInt();
                maze = new int[n][n];
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        maze[i][j] = fp.nextInt();
                System.out.println(findMazePath(0, 0) ? n + " : " + "Yes" : n + " : " + "No");
            }
            fp.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}

