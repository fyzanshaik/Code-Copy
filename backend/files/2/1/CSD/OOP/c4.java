import java.util.Scanner;

public class c4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter string : ");
        String s = sc.nextLine();
        int count = 0;
        for ( int i=0 ; i<s.length()-2 ; i++ ) {
            if ( s.charAt(i) == s.charAt(i+1) && s.charAt(i) == s.charAt(i+2) ) {
                count++; 
            }
        }
        System.out.println("Count : "+count);
        sc.close();
    }
}
