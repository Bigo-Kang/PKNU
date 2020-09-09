package Section03;

import java.io.*;
import java.util.Scanner;

public class Code22 {

    static String [] words = new String[100000];
    static int [] count = new int[100000];
    static int n = 0;

    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        while(true){
            System.out.print("$ ");
            String command = kb.next();
            if(command.equals("read")){
                String fileName = kb.next();
                makeIndex(fileName);
            }
            else if(command.equals("find")){
                String keyword = kb.next();
                int index = findWord(keyword);
                if(index != 1)
                    System.out.println("The word" + words[index] + "appears" + count[index] + " times.");
                else
                    System.out.println("The word" + keyword + "doesn't appear.");
            }
            else if (command.equals("saveas")){
                String fileName = kb.next();
                saveAs(fileName);
            }
            else if (command.equals("exit"))
                break;
        }
        kb.close();
    }

    private static void makeIndex(String fileName) {
        try {
            Scanner theFile = new Scanner(new File(fileName));
            while(theFile.hasNext()){
                String word = theFile.next();
                addWord(word);
            }
            theFile.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not exits!");
        }
    }

    private static void addWord(String word) {
        int index = findWord(word);
        if(index > -1)
            count[index]++;
        else {
            words[n] = word;
            count[n] = 1;
            n++;
        }
    }

    private static int findWord(String keyword) {
        for (int i=0; i<n; i++)
            if (words[i].equals(keyword))
                return i;
        return -1;
    }

    private static void saveAs(String fileName) {
        try {
            PrintWriter out = new PrintWriter(new FileWriter(fileName));
            for (int i=0; i<n; i++)
                out.println(words[i] + "" + count[i]);
            out.close();
        } catch (IOException e) {
            System.out.println("Save failed. Don't ask me why !");
        }
    }
}

