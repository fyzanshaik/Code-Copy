
import java.util.Scanner;

class Student {
    String name;
    int roll_no;
    double CGPA;
    Student(String name, int roll_no, double CGPA) {
        this.name = name;
        this.roll_no = roll_no;
        this.CGPA = CGPA;
    }
    void printDetails() {
        System.out.println("Student Name : "+name);
        System.out.println("Roll Number : "+roll_no);
        System.out.println("CGPA : "+CGPA);
        System.out.println("----------------------");
    }
}

public class c2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no. of students : ");
        int n = sc.nextInt();
        Student[] list = new Student[n];
        String name;
        int roll_no;
        double CGPA;
        for ( int i=0 ; i<n ; i++ ) {
            System.out.println("For student "+(i+1));
            System.out.print("Enter name : ");
            name = sc.nextLine();
            sc.nextLine(); // Flush
            System.out.print("Enter Roll Number : ");
            roll_no = sc.nextInt();
            System.out.print("Enter CGPA : ");
            CGPA = sc.nextDouble();
            list[i] = new Student(name, roll_no, CGPA);
        }
        System.out.println("Student Details : ");
        int sl_no = 0;
        for ( Student s : list ) {
            System.out.println("Serial No "+(++sl_no));
            System.out.println("Name : "+s.name);
            System.out.println("Roll No : "+s.roll_no);
            System.out.println("CGPA : "+s.CGPA);
        }
        sc.close();
    }
}
