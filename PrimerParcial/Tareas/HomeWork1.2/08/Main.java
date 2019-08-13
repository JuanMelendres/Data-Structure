/*
    Juan Antonio Melendres Villa    A00369017
8. Write a program in Java using recursion that calculates the sum of the elements in an integer
    input: an integer
    output: sum (only the value)
*/

import java.util.Scanner;

public class Main {

    public static int sumaEnteros(int num){
        int suma;
        if (num == 0) {
            return 0;
        }
        else {
            suma = num + sumaEnteros(num - 1);
        }
        return suma;
    }

    public static void main(String[] args) {
        System.out.print("Ingrese el numero: ");
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int suma = sumaEnteros(num);
        System.out.println("La suma de " + num + " es: " + suma);
    }
}
