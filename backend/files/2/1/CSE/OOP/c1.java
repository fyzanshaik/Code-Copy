
import java.util.Scanner;

public class c1 {

    public static boolean isPrime(int n) {
        if ( n<=1 ) return false;
        for ( int i=2 ; i*i<=n ; i++ ) {
            if ( n%i == 0 ) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter m : ");
        int m = sc.nextInt();
        System.out.print("Enter  n: ");
        int n = sc.nextInt();
        for ( int i=m ; i<=n ; i++ ) {
            if ( isPrime(i) ) {
                System.out.print(i+" ");
            }
        }
        sc.close();
    }
}
