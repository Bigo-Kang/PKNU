package Section02;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Code20 {

    static String[]name;
    static String[]number;
    static int count = 0;
    public static void main(String[] args) {
        name = new String[1000];
        number = new String[1000];
        try {
            Scanner inFile = new Scanner(new File("input.txt"));
            while (inFile.hasNext()) {
                name[count] = inFile.next();
                number[count] = inFile.next();
                count++;
            }
            inFile.close();
        }catch (FileNotFoundException e) {
            System.out.println("No data file exists.");
            //return;
            System.exit(9);
        }
        bubbleSort();
        for (int i=0; i<count; i++)
            System.out.println("Name: " + name[i] + ", Phone: " + number[i]);
    }

    static void bubbleSort() {
        for(int i=count-1; i>0; i--){
            for(int j=0; j<i; j++){
                if(name[j].compareToIgnoreCase(name[j+1])>0){
                    String tmpName = name[j];
                    name[j] = name[j+1];
                    name[j+1] = tmpName;

                    String tmpNumber = number[j];
                    number[j] = number[j+1];
                    number[j+1] = tmpNumber;
                }
            }
        }
    }
}
