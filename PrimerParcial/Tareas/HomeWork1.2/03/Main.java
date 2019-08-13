/*
    Juan Antonio Melendres Villa    A00369017
3. Write a program in Java using recursion that calculates the minimum value of the elements in an array of integers
    input: number of elements followed by the elements (one per line)
    output: minumum (only the value)
*/
import java.util.Scanner;

public class Main {

    public static int min(int[] elements, int index) {
        if (index == elements.length - 1) {
            return elements[index];
        }
        int val = min(elements, index + 1);
        if (elements[index] < val) {
            return elements[index];
        }
        else {
            return val;
        }
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
        System.out.println("El valor min = " + min(numeros, 0));
    }
}
