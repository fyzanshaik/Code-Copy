import java.util.Arrays;
import java.util.Scanner;

public class b3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n : ");
        int n = sc.nextInt();
        int[] a = new int[n];
        System.out.println("Enter "+n+" elements");
        for ( int i=0 ; i<n ; i++ ) {
            a[i] = sc.nextInt();
        }
        System.out.println("Array before sorted");
        for ( int i : a ) {
            System.out.print(i+" ");
        }
        Arrays.sort(a);
        System.out.println("Array after sorted");
        for ( int i : a ) {
            System.out.print(i+" ");
        }
        sc.close();
    }
}
