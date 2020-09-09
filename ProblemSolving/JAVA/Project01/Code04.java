package Project01;

import java.util.Scanner;
public class Code04 {
    public static void main(String[] args) {
        String name = null;
        int age;
        String gender;
        Scanner kb = new Scanner(System.in);
        System.out.print("Please type your name and your age and your gender: ");
        name = kb.next();
        age = kb.nextInt();
        gender = kb.next();

        if (gender.equals("male"))
            System.out.println(name + ", you're " + age + "years old man.");
        else if (gender.equals("female"))
            System.out.println(name + ", you're " + age + "years old woman.");
        else
            System.out.println("Hmm...interesting.");
    }
}
