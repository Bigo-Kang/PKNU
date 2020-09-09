package Section01;

public class Code01_1 {
    public static void main(String[] args) {
        Person1 first = new Person1();
        first.name = "John";
        first.number = "202031";
        System.out.println(first.name + "," + first.number);
        Person1 second = first;
        second.name = "Tom";


        Person1[] members = new Person1[100];
        members[0] = first;
        members[1] = second;
        System.out.println(members[0].name + "," + members[0].number);
        System.out.println(members[1].name + "," + members[1].number);

        members[2] = new Person1();
        members[2].name = "David";
        members[2].number = "2048493";
        System.out.println(members[2].name + "," + members[2].number);
    }
}
