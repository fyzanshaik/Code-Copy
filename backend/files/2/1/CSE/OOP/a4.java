import java.util.Scanner;

public class a4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter string : ");
        String s = sc.nextLine();
        s = s.toLowerCase();
        boolean isPalindrome = true;
        int left = 0, right = s.length()-1;
        while ( left < right ) {
            if ( s.charAt(left) != s.charAt(right)) {
                isPalindrome = false;
                break;
            }
            left++;
            right--;
        }
        if ( isPalindrome ) {
            System.out.println(s+" is a Palindrome");
        } else {
            System.out.println(s+" is not a Palindrome");
        }
        sc.close();
    }
}
