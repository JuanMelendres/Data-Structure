/*
    Juan Antonio Melendres Villa    A00369017
10. Write a program in Java using recursion that says if a given phrase is a palindrome
    input: a String
    output: YES / NO
*/
import java.util.Scanner;

public class Main {

    public static boolean esPalindromo(String palabra){
        if(palabra.length() <= 1){
            return true;
        }
        else{
            if(palabra.charAt(0) == palabra.charAt(palabra.length() - 1)){
                return esPalindromo(palabra.substring(1, palabra.length() - 1 ));
            }
            else{
                return false;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingresa la palabra: ");
        String pal = sc.next();
        if (esPalindromo(pal)) {
            System.out.println("Si es palindromo");
        }
        else {
            System.out.println("No es palindromo");
        }
    }
}
