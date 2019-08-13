public class ProductoRecursivo {

    public static int productoRecursivo(int x, int y){
        if (y == 0) {
            return 0;
        }
        return x + productoRecursivo(x, y-1);
    }

    public static void main(String[] args) {
        System.out.println(productoRecursivo(3, 4));
    }
}
