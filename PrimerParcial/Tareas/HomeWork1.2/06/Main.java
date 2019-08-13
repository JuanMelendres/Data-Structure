/*
    Juan Antonio Melendres Villa    A00369017
6. Write a program in Java using recursion that inverts a String
    input: String
    output: invertedString
*/

import java.util.Scanner;

public class Main {

    public static String stringInversa(String palabra){
        if (palabra.isEmpty()){
            return palabra;
        }
        return stringInversa(palabra.substring(1)) + palabra.charAt(0);
    }

    public static void main(String[] args) {
        String palabraInversa;
        System.out.print("Ingresa una palabra: ");
        Scanner sc = new Scanner(System.in);
        palabraInversa = sc.nextLine();
        sc.close();
        String inversa = stringInversa(palabraInversa);
        System.out.println("La palabra inversa es: " + inversa);
    }
}
