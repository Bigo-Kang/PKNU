package section4;

public class MyDate {
    public int year, month, day;

    public MyDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    public int compareTo(MyDate other) {
        if (year < other.year || year == other.year && month < other.month ||
                year == other.year && month == other.month && day < other.day) return -1;
        else if (year > other.year || year == other.year && month > other.month ||
                year == other.year && month == other.month && day > other.day) return 1;
        else
            return 0;
    }

    public String toString() {
        return year + "/ " + month + "/ " + day;
    }
}
