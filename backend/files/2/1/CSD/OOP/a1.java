
import java.util.Scanner;


public class a1 {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        double math, c, java, ads, avg;
        System.out.print("Enter Math marks : ");
        math = sc.nextDouble();
        System.out.print("Enter C marks : ");
        c = sc.nextDouble();
        System.out.print("Enter Java marks : ");
        java = sc.nextDouble();
        System.out.print("Enter ADS marks : ");
        ads = sc.nextDouble();
        avg = (ads+math+c+java)/4.0;
        System.out.println("Average : "+avg);
        sc.close();
    }
}