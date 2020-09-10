package Section2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.LinkedList;
import java.util.Scanner;

public class Prob03 {

    public static void main(String[] args) {
        LinkedList Node = new LinkedList();

        File fp = new File("input.txt");
        try {
            FileReader fr = new FileReader(fp);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }


    }

}
