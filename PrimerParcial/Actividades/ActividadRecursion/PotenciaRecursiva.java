public class PotenciaRecursiva {

    public static int potenciaRecursiva(int x, int y){
        if (y == 0) {
            return 1;
        }
        // else if (y == 1) {
        //     return x;
        // }
        return x * potenciaRecursiva(x, y-1);
    }

    public static void main(String[] args) {
        System.out.println(potenciaRecursiva(3, 4));
    }
}
