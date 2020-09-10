package section5;

import java.util.Arrays;

public class MyArrayList<E> {

    private static final int INIT_CAPACITY = 10;
    private E [] theDate;
    private int size;
    private int capacity = INIT_CAPACITY;

    public MyArrayList() {
        theDate = (E [])new Object [INIT_CAPACITY];
        size = 0;
    }

    public void add(int index, E anEntry) {
        if (index < 0 || index > size)      // error or exception
            throw new ArrayIndexOutOfBoundsException(index);
        if (size >= capacity)
            reallocate();
        for (int i=size-1; i>=index; i--)
            theDate[i+1] = theDate[i];
        theDate[index] = anEntry;
        size++;
    }

    private void reallocate() {
        capacity *= 2;
        theDate = Arrays.copyOf(theDate, capacity);
    }

    public void add(E anEntry) {
        add(size, anEntry); //add last position
    }

    public int size() {
        return size;
    }

    public int indexOf(E anEntry) {
        for (int i=0; i<size; i++)
            if (theDate[i].equals(anEntry)) // == is int, char, primitive type;
                return i;
        //equals is non-primitive type... type in Object..
        //it's overriding equals method.
        return -1;
    }

    public E get (int index) {
        if (index<0 || index>=size)
            throw new ArrayIndexOutOfBoundsException(index);
        return theDate[index];
    }

    public E set (int index, E newValue) {
        if (index<0 || index>=size)
            throw new ArrayIndexOutOfBoundsException(index);
        E oldValue = theDate[index];
        theDate[index] = newValue;
        return oldValue;
    }

    public E remove (int index) {
        if (index<0 || index>=size)
            throw new ArrayIndexOutOfBoundsException(index);
        E returnValue = theDate[index];
        for (int i=index+1; i<size; i++)
            theDate[i-1] = theDate[i];
        size--;
        return returnValue;
    }

    public static void main(String[] args) {
        MyArrayList<String> test = new MyArrayList<>();
        try {
            test.add(1, "Hello");
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("---------");
        }

        System.out.println("******");
    }
}
