/*
    Juan Antonio Melendres Villa    A00369017
5. Write a program in Java using recursion that invert the order of the elements in an array of integers
    input:number of elements elements (one per line)
    output: inverted order elements (one per line)
*/
import java.util.Scanner;

public class Main {

    public static int[] arrayInvertido(int[] a,int i,int j){
        if(i < j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            arrayInvertido(a, i+1, j-1);
        }
        return a;
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
        System.out.print("\n");
        int[] revArray = arrayInvertido(numeros, 0, numeros.length-1);
        for(int i: revArray){
            System.out.println(i);
        }
    }
}
