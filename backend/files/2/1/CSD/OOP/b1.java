
import java.util.Scanner;

public class b1 {
    public static int digits(int n) {
        int cnt = 0;
        while ( n>0 ) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }

    public static boolean armstrong(int n) {
        int cnt = digits(n);
        int m = n;
        int res = 0;
        while ( n>0 ) {
            int rem = n%10;
            res += Math.pow(rem, cnt);
            n /= 10;
        }
        return res==m;
    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n : ");
        int n = sc.nextInt();

        if ( armstrong(n) ) {
            System.out.println("Yes, "+n+" is a Armstrong Number");
        } else {
            System.out.println("No, "+n+" is not a Armstrong Number");
        }
        sc.close();
    }
}
