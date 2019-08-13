/*
    Juan Antonio Melendres Villa    A00369017
4. Write a program in Java using recursion that calculates the sum of the elements in an array of integers
    input: number of elements elements (one per line)
    output: sum (only the value)
*/
import java.util.Scanner;

public class Main {

    public static int suma(int array[], int index) {
        if (index <= 0) {
            return 0;
        }
        return (suma(array, index - 1) + array[index - 1]);
    }

    public static void main(String[] args) {
        System.out.print("ingrese el numero de elementos del array = ");
        Scanner num = new Scanner(System.in);
        int n = num.nextInt();
        int[] numeros = new int[n];
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < numeros.length; i++){
            numeros[i] = sc.nextInt();
        }
        System.out.println("La suma = " + suma(numeros, numeros.length));
    }
}
