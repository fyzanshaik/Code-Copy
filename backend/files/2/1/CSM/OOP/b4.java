import java.util.Scanner;

public class b4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter string : ");
        String s = sc.nextLine();
        System.out.print("Enter n : ");
        int n = sc.nextInt();
        if ( n>s.length() ) {
            System.out.println("Invalid n");
            sc.close(); return;
        }
        String sub_s = s.substring(s.length()-n);
        for ( int i=0 ; i<n ; i++ ) {
            System.out.println(sub_s);
        }
        sc.close();
    }
}
