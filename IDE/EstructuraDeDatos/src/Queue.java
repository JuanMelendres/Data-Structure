public interface Queue<E> {
    public boolean isEmpty();
    public int size();
    public E front();
    public E last();
    public E dequeue();
    public void enqueue(E data);
}
