package Section1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Prob02 {

    public static int[] data;
    public static int n = 0;

    public static void main(String[] args) {
        int k = 0;

        try {
            Scanner inFile = new Scanner(new File("input.txt"));
            n = inFile.nextInt();
            data = new int[n];
            for (int i = 0; i < n; i++)
                data[i] = inFile.nextInt();
            k = inFile.nextInt();

            inFile.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        int less = floor(data, k, 0, n - 1);
        int more = ceiling(data, k, 0, n - 1);
        System.out.println("The floor is " + less + ", The more is " + more);
    }

    //(n%2 != 0 ? data[end] : data[end-1])
//more thinking.. example2..why not?...
//floor is the largest of the smaller or the same value
    public static int floor(int[] data, int target, int begin, int end) {
        if (begin > end) return (begin < n) ? data[end] : -1;
        else if (begin == n - 1) return data[begin];
        else {
            int middle = (begin + end) / 2;
            if (data[middle] == target)
                return data[middle];
            else if (data[middle] > target)
                return floor(data, target, begin, middle - 1);
            else
                return floor(data, target, middle + 1, end);
        }
    }

    //??????
    public static int ceiling(int[] data, int target, int begin, int end) {
        if (begin > end) return (begin < n) ? data[begin] : -1;
        else if (end != n - 1 && data[end] < target) return data[end + 1];
        else {
            int middle = (begin + end) / 2;
            if (data[middle] == target)
                return data[middle];
            else if (data[middle] > target)
                return ceiling(data, target, begin, middle - 1);
            else
                return ceiling(data, target, middle + 1, end);
        }
    }
}
