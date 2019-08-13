/*
    Juan Antonio Melendres Villa    A00369017
9. Write a program in Java using recursion that converts a number base 10 to a number base 2
    input: an integer
    output: a String of binary digits
*/

import java.util.Scanner;

public class Main {

    public static String convertirBinario(int num) {
        int base = 2;
        int cociente = num / base;
        int residuo = num % base;
        if (cociente == 0) {
            return Integer.toString(residuo);
        }
        else {
            return convertirBinario(cociente) + Integer.toString(residuo);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.print("Introduzca un número entero: ");
        n = sc.nextInt();
        System.out.println("Convertido a binario es = " + convertirBinario(n));
    }
}
