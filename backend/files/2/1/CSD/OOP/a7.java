import java.util.Scanner;

public class a7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number num1");
        String s1 = sc.next();
        System.out.println("Enter the number2");
        String s2 = sc.next();
        try {
            int num1 = Integer.parseInt(s1);
            int num2 = Integer.parseInt(s2);
            System.out.println("num1 is " + num1);
            System.out.println("num2 is " + num2);
            if (num2 == 0)
                throw new ArithmeticException("Division Error");

            int res = num1 / num2;
            System.out.println("The result is " + res);
        } catch (NumberFormatException e) {
            System.out.println("The numbers must be numeric data");
            System.out.println("Exception " + e);
        }

        catch (ArithmeticException e) {
            System.out.println("num2 must not be zero");
            System.out.println("Exception" + e);
        }

        finally {
            System.out.println("Finally block is executed");
        }
        System.out.println("Remaining statements");
        sc.close();
    }
}
