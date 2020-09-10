package section2;

public class MyDate {
    public int year, month, day;

    public MyDate(int y, int m, int d){
        year = y;
        month = m;
        day = d;
    }

    public String toString()
    {
        return year + ", " + month + ", "+ day;
    }
}
