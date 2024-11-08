
import java.util.Scanner;

class Rectangle {
    double length;
    double width;
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    double perimeter() {
        return (2*(length+width));
    } 
    double area() {
        return (length*width);
    }
}

public class a2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter length : ");
        double l = sc.nextDouble();
        System.out.print("Enter width : ");
        double w = sc.nextDouble();
        Rectangle r = new Rectangle(l, w);
        System.out.println("Perimeter : "+r.perimeter());
        System.out.println("Area : "+r.area());
        sc.close();
    }
}
