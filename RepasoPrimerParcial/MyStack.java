import java.util.EmptyStackException;

public class MyStack<E> implements Stack<E> {
    private Node<E> first;
    private Node<E> size;

    public MyStack() {
        this(null, 0);
    }

    public MyStack(int n) {
        this(null, n);
    }

    public MyStack(Node<E> data, int n) {
        this.first = data;
        this.size = n
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public E peek() {
        if (this.size == 0) {
            throw new EmptyStackException();
        }
        return this.first.element;
    }

    public E pop() {
        if (this.size == 0) {
            throw new EmptyStackException();
        }
        Node<E> toReturn = this.first;
        this.first = this.first.next;
        this.size--;
        return toReturn.element;
    }

    public void push(E data) {
        Node<E> toPush = new Node<E>(data, this.first);
        this.first = toPush;
        this.size++;
    }

    private static class Node<E> {
        protected E element;
        protected Node<E> next;

        public Node(E data, Node<E> next) {
            this.element = data;
            this.next = next;
        }
    }
}
