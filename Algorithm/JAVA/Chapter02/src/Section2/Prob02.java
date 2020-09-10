package Section2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Prob02 {
    private static final int PATHWAY = 0;
    private static final int WALL = 1;
    private static final int BLOCKED = 2;
    private static final int PATH = 3;

    private static int n, t;
    private static int [][] maze;
    private static int [][] dir = {{-1,0},{0,1},{1,0},{0,-1} };

    public static void main(String[] args) {
        readFile();
    }

    private static boolean findMazePath(int x, int y, int d) {
        if (x<0 || y<0 || x>=n || y>=n || maze[x][y] != PATHWAY)
            return false;
        else if (x==n-1 && y==n-1){
            maze[x][y] = PATH;
            return true;
        }
        else {
            maze[x][y] = PATH;
            if (check(x+dir[d][0], y+dir[d][1]))
                return findMazePath(x + dir[d][0], y + dir[d][1], d) ? true : false;
            else {
                if (findMazePath(x - 1, y, 0) || findMazePath(x, y + 1, 1)
                        || findMazePath(x + 1, y, 2) || findMazePath(x, y - 1, 3))
                    return true;
            }
            maze[x][y] = BLOCKED;
            return false;
        }
    }

    private static boolean check(int x, int y) {
        if (x<0 || y<0 || x>=n || y>=n || maze[x][y] != PATHWAY)
            return false;
        return true;
    }

    private static void readFile() {
        try {
            Scanner fp = new Scanner(new File("input2.txt"));
            t =fp.nextInt();
            for (int cnt=0; cnt<t; cnt++) {
                n = fp.nextInt();
                maze = new int[n][n];
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        maze[i][j] = fp.nextInt();
                System.out.println(findMazePath(0,0,0) ? n+": "+"Yes" : n+": "+"No");
            }
            fp.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

}
