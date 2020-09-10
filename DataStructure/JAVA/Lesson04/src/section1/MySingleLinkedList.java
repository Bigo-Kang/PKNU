package section1;

public class MySingleLinkedList<T> {

    public Node<T> head; // head = null
    public int size = 0;

    public MySingleLinkedList() {
        head = null;
        // size = 0;
    }

    public void addFirst(T item) {
        Node<T> newNode = new Node<T>(item);  // T : type parameter
        newNode.next = head;
        head = newNode;
        size++;
    }

    public void addAfter(Node<T> before, T item) {
        Node<T> temp = new Node<T>(item);  // T : type parameter
        temp.next = before.next;
        before.next = temp;
        size++;
    }

    public T removeFirst() {
        if (head == null)
            return null;
        T temp = head.data;
        head = head.next;
        size--;
        return temp;
    }

    public T removeAfter(Node<T> before) {
        if (before.next == null)
            return null;
        T temp = before.next.data;
        before.next = before.next.next;
        size--;
        return temp;

    }

    public int indexOf( T item) {   //search
        Node<T> p = head;
        int index = 0;
        while (p != null) {
            if (p.data.equals(item))
                return index;
            p = p.next;
            index++;
        }
        return -1;
    }

    public Node<T> getNode( int index ) {
        if (index<0 || index>=size)
            return null;
        Node<T> p = head;
        for (int i=0; i<index; i++)
            p=p.next;
        return p;
    }

    public T get( int index) {
        if (index<0 || index>=size)
            return null;

//        Node<T> p = head;
//        for (int i=0; i<index; i++)
//            p=p.next;
//        return p.data;

        return getNode(index).data;
    }

    public void add(int index, T item ) {  //insert the node after index-1th node
        if (index < 0 || index > size)
            return;
        if (index == 0)
            addFirst(item);
        else {
            Node<T> q = getNode(index - 1);
            addAfter(q, item);
        }
    }

    public T remove( int index ) {   //delete
        if (index < 0 || index >= size)
            return null;
        if (index == 0)
            return removeFirst();
        Node<T> prev = getNode(index-1);
        return removeAfter(prev);

    }

    public T remove(T item) {
        Node<T> p = head, q = null;
        while (p!=null && !p.data.equals(item)) {
            q=p;
            p=p.next;
        }

        if (p==null)
            return null;
        if (q==null)
            return removeFirst();
        return removeAfter(q);
    }



    public static void main(String[] args) {
        MySingleLinkedList<String> list = new MySingleLinkedList<>();
        list.add(0,"Saturday");
        list.add(1,"Friday");
        list.add(0,"Monday"); //m s f
        list.add(2,"Tuesday"); // m s t f

        String str = list.get(2);   //str = Tuesday
        list.remove(2);
        int pos = list.indexOf("Friday");   //pos = 2
    }

}
