/*
    Autor: A00369017 Juan Antonio Melendres Villa
    Nombre de la clase: Factorial
    Fecha: 17/08/18
*/

public class Factorial{

    public static int factorial(int n){
        if (n <= 1) { //(n == 0)
            return 1;
        }
        else {
            return n*factorial(n-1);
        }
    }

    public static void main(String[] args) {
        System.out.println(factorial(4));
    }
}
