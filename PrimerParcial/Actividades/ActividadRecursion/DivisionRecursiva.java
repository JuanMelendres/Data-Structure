public class DivisionRecursiva {

    public static int divisionRecursiva(int x, int y){
        if (x < y) {
            return 0;
        }
        return 1 + divisionRecursiva(x-y, y);
    }

    public static void main(String[] args) {
        System.out.println(divisionRecursiva(8, 3));
    }
}
