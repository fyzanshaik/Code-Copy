import java.util.Scanner;


public class a3 {

    // Volume of Sphere
    public static double volume(double r) {
        return (Math.PI)*r*r*r*(4/3.0);
    }

    // Volume of Cylinder
    public static double volume(double r, double h) {
        return (Math.PI)*r*r*h;
    }

    // Volume of Cone
    public static double volume(double r, double h, int dummy) {
        return volume(r, h)*(1/3.0);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean process = true;
        System.out.println("**Volume Calculator**");
        while ( process ) {
            System.out.println("1.Sphere\n2.Cylinder\n3.Cone");
            int choice = sc.nextInt();
            switch(choice) {
                case 1 : {
                    System.out.print("Enter radius : ");
                    double r = sc.nextDouble();
                    System.out.println("Volume of Sphere : "+volume(r));
                    break;
                }
                case 2 : {
                    System.out.print("Enter radius : ");
                    double r = sc.nextDouble();
                    System.out.print("Enter height : ");
                    double h = sc.nextDouble();
                    System.out.println("Volume of Cylinder : "+volume(r, h));
                    break;
                }
                case 3 : {
                    System.out.print("Enter radius : ");
                    double r = sc.nextDouble();
                    System.out.print("Enter height : ");
                    double h = sc.nextDouble();
                    System.out.println("Volume of Cone : "+volume(r, h, 0));
                    break;
                }
                default:
                    System.out.println("Invalid choice\nExit");
                    process = false;
            }
        }
        sc.close();
    }
}
