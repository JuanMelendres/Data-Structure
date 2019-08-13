/*
------------>>>> Problemas de recursion
*/


public class Recursion {

    public static int factorial(int n) {
        if (n == 0) {
            return 1;
        }
        return n * factorial(n-1);
    }

    public static int fibonaci(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        return fibonaci(n - 1) + fibonaci(n - 2);
    }

    //restas sucesivas
    public static int division(int a, int b) {
        if (b > a) {
            return 0;
        }
        return division(a - b, b) + 1;
    }

    //numero invertido
    public static void invertir(int n) {
        if (n < 10) {
            System.out.print(n);
        }else {
            System.out.print(n % 10);
            invertir(n / 10);
        }
    }

    //sumar digitos de un numero
    public static int sumarDig(int n) {
        if (n == 0) {
            return n;
        }
        return sumarDig(n / 10) + (n % 10);
    }

    public static int sumaArray(int arr[], int n) {
        if (n == 0 ) {
            return arr[n];
        }
        return sumaArray(arr, n - 1) + arr[n];
    }

    //invertir una palabra
    public static String invertirPal(String pal, int n) {
        if (n == 0) {
            return pal.charAt(n) + "";
        }
        return pal.charAt(n) + (invertirPal(pal, n - 1));
    }

    //chear si un strign es igual a otro
    public static boolean checarString(String s1, String s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        if (s1.length() == 0) {
            return true;
        }
        if (s1.charAt(0) == s2.charAt(0)) {
            return checarString(s1.substring(1), s2.substring(1));
        }
        else if (s1.charAt(0) != s2.charAt(0)) {
            return checarString(s1, s2.substring(1));
        }
        return false;
    }

    public static boolean palindromo(String pal) {
        if (pal.length() <= 1) {
            return true;
        }
        else {
            if (pal.charAt(0) == pal.charAt(pal.length() - 1)) {
                return palindromo(pal.substring(1, pal.length() - 1));
            }
            else {
                return false;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println(factorial(5));
        System.out.println(fibonaci(5));
        System.out.println(division(10, 2));
        invertir(123);
        System.out.println();
        System.out.println(sumarDig(123));
        int arr[] = {1,2,3,4,5};
        System.out.println(sumaArray(arr, 4));
        String pal = "Hola";
        System.out.println(invertirPal(pal, pal.length() - 1));
        if (checarString("Pato", "Pata")) {
            System.out.println("Son iguales");
        }
        else {
            System.out.println("No son iguales");
        }
        if (palindromo("civic")) {
            System.out.println("Es palindromo");
        }
        else {
            System.out.println("No es palindromo");
        }
    }
}
