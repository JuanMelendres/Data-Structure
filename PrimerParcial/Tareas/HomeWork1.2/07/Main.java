/*
    Juan Antonio Melendres Villa    A00369017
7. Write a program in Java using recursion that writes an integer backwards (avoid leading zeros)
    input: an integer
    output: backwards integer
*/
import java.util.Scanner;

public class Main {

    public static void numInvertido(int n) {
       if (n < 10) {
           System.out.println(n);
           return;
       }
       else {
           System.out.print(n % 10);
           numInvertido(n/10);
       }
    }

    public static void main(String[] args) {
        int num = 0;
        System.out.print("Ingrese el numero: ");
        Scanner in = new Scanner(System.in);
        num = in.nextInt();
        System.out.print("El numero inverso es: ");
        numInvertido(num);
    }
}
