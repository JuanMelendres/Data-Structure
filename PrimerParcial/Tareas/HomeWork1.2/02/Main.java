/*
    Juan Antonio Melendres Villa    A00369017
2. Write a program in Java using recursion that says the number of times that a given char appears in a String
    input: char String
    output: number
*/

import java.util.Scanner;

public class Main {

    public static int contarLetra(String str, char a) {
        if (str.length() == 0) {
          return 0;
        }
        int cont = 0;
        if (str.charAt(0) == a) {
          cont++;
        }
        return cont + contarLetra(str.substring(1), a);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingresa la palabra: ");
        String palabra = sc.next();
        System.out.print("Ingresa la letra a saber: ");
        char c = sc.next().charAt(0);
        int n = contarLetra(palabra, c);
        System.out.println("En la palabra " + palabra + "la letra " + "'" + c + "'" + " aparece " + n);
    }
}
