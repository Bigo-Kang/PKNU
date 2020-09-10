package Section1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Prob01 {

    public static int [] data;
    public static void main(String[] args) {

//        Scanner kb = new Scanner(System.in);
//        int n = kb.nextInt();
//        data = new int [n];
//        for (int i=0; i<n; i++)
//            data[i] = kb.nextInt();
//        int k = kb.nextInt();
//        kb.close();
        int num = 0;
        int n = 0, k = 0;
        try {
            Scanner fp = new Scanner(new File("input.txt"));
             n = fp.nextInt();
            data = new int [n];
            while (fp.hasNext()){
                if( num < n )
                    data[num++] = fp.nextInt();
                else
                     k = fp.nextInt();
            }
            fp.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        int start =0, end = n-1;
        int result = twoSum(start,end,k);
        System.out.println("The count is " + result);
    }

    public static int twoSum(int start, int end, int k) {
        int count = 1; //  count change 1
        if (start >= end) return 0;
        int sum = data[start] + data[end];
        if (sum > k)
            return twoSum(start,end-1, k);
        else if (sum < k)
            return twoSum(start+1, end, k);
        else {
            return count + twoSum(start+1,end-1,k);
        }
    }

}
