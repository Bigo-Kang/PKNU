package Section1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Prob01 {

    public static int [] data;
    public static int [] dataMin;
    public static int n = 0, M;

    public static void main(String[] args) {
        readFile();
        processing();
    }

    public static void processing() {
        int x, y, min, startGroup, endGroup;

        while (true) {
            Scanner kb = new Scanner(System.in);
            x = kb.nextInt();
            if ( x == -1 ) break;
            y = kb.nextInt();
            startGroup = x/M + 1;  endGroup = y/M - 1;
            if ( endGroup < 0 ) endGroup = 0;
            min = data[x];
            for (;startGroup <= endGroup; startGroup++)
                if (dataMin[startGroup] < min) min = dataMin[startGroup];

            for (int i = x; i < (startGroup-1)*M+(M-1); i++)
                if (data[i] < min) min = data[i];

            for (int i = (endGroup+1)*M; i <= y; i++)
                if (data[i] < min) min = data[i];

            System.out.println(min);
        }
    }

    public static void readFile() {
        int min = 0, dataSize, size = 0, minSize = 0;

        try {
            Scanner inFile = new Scanner(new File("data.txt"));
            dataSize = inFile.nextInt();
            M = (int)Math.sqrt(dataSize);
            data = new int [dataSize];
            dataMin = new int [M];
            while (inFile.hasNext()) {
                data[n] = inFile.nextInt();
                if (size == 0)
                    min = data[n];
                else {
                    if (data[n] < min)
                        min = data[n];
                }
                n++; size++;
                if (size == M) {
                    dataMin[minSize++] = min;
                    size = 0;
                }
            }
            inFile.close();
        } catch (FileNotFoundException e) {
            System.out.println("No data file exists");
        }
    }
}
