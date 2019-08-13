import java.util.NoSuchElementException;

public class MyQueue<E> implements Queue<E> {
    private int size;
    private Node<E> first;
    private Node<E> last;

    public MyQueue() {
        this.first = this.last = null;
        this.size = 0;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public int size() {
        return this.size;
    }

    public E front() {
        if (this.first == null) {
            return null;
        }
        return this.first.element;
    }

    public E last() {
        if (this.last == null) {
            return null;
        }
        return this.last.element;
    }

    public void enqueue(E data) {
        if (this.first == null) {
            this.first = new Node<E>(data);
            this.size++;
        }
        else if (this.last == null) {
            this.last = new Node<E>(data);
            this.first.next = this.last;
            this.size++;
        }
        else {
            this.last.next = new Node<E>(data);
            this.last = this.last.next;
            this.size++;
        }
    }

    public E dequeue() {
        if (this.first = null) {
            return null
        }
        if (this.size == 0) {
            throw new NoSuchElementException();
        }
        Node<E> toReturn = this.first;
        if (this.first.equals(this.last)) {
            this.last = null;
        }
        this.first = this.first.next;
        this.size--;
        return toReturn.element;
    }

    private class Node<E> {
        E element;
        Node<E> next;

        Node(E data) {
            this.element = data;
        }
    }
}
