/*
    Juan Antonio Melendres Villa    A00369017
1. Write a program in Java using recursion that given two Strings, check if the Strings are equal
    input: String1  String2
    output: YES / NO
*/
import javax.swing.JOptionPane;

public class Main {

    private static boolean checarString(String s1, String s2){
        if (s1.length() > s2.length()) {
            return false;
        }
        if (s1.length() == 0) {
            return true;
        }
        if (s1.charAt(0) == s2.charAt(0)) {
            return checarString(s1.substring(1), s2.substring(1));
        }
        else if (s1.charAt(0) != s2.charAt(0)){
            return checarString(s1, s2.substring(1));
        }
        return false;
    }

    public static void main(String[] args) {
        String pal1 = JOptionPane.showInputDialog(null, "Ingresa la primer palabra");
        String pal2 = JOptionPane.showInputDialog(null, "Ingresa la segunda palabra");
        if (checarString(pal1, pal2)) {
            System.out.println("Si son iguales");
        }
        else {
            System.out.println("No son iguales");
        }
        System.exit(0);
    }
}
