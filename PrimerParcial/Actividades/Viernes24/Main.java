/*
    Juan Antonio Melendres Villa    A00369017
1.Write a program in Java that reads an integer n followed by n fractions
    then read an integer m followed by m other fractions

    The first n fractions are the array elements
    the m fractions will be used to test your binary search implementation

    You can implement Binary search in a recursive way or in an iterative way
*/

import java.util.Scanner;

public class Main {

    public static int binarySearch(int[] arr, int l, int r, int x){
        if (r >= l) {
            int mid = l + (r - l)/2;
            if (arr[mid] == x) {
                return mid;
            }
            if (arr[mid] > x) {
                return binarySearch(arr, l, mid-1, x);
            }
            return binarySearch(arr, mid+1, r, x);
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.print("Fracciones del array : ");
        Scanner num = new Scanner(System.in);
        int n = num.nextInt();
        int[] numerator = new int[n];
        int[] denumerator = new int[n];
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < numerator.length; i++) {
            numerator[i] = sc.nextInt();
            denumerator[i] = sc.nextInt();
        }
        Main ob = new Main();
        int n = numerator.length;
        int n2 = denumerator.length;
        int x = 10;
        int result = ob.binarySearch(numerator, 0, ((n + n2) - 1), x);
        if (result == -1) {
            System.out.println("Element not present");
        }
        else {
            System.out.println("Element found at index " + result);
        }
    }

}
