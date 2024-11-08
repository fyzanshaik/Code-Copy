import java.util.*;

class Emp {
    int empid;
    String empname;

    Emp(int no) {
        empid = no;
    }

    Emp(int no, String name) {
        this(no);
        empname = name;
    }
}

class Salary extends Emp {
    String designation;
    double sal;

    Salary(int no, String name, String des, double salary) {
        super(no, name);
        designation = des;
        sal = salary;
    }

    void display() {
        System.out.println(empid + ", " + empname + ", " + designation + ", " + sal);
    }
}

public class a5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of employees : ");
        int n = sc.nextInt();
        Salary s[] = new Salary[n];
        for (int i=0; i<n; i++) {
            System.out.println("Enter the Employee details of " + (i + 1));
            System.out.println("(id, name, designation, salary)");
            int id = sc.nextInt();
            String name = sc.next();
            String desg = sc.next();
            double sal = sc.nextDouble();
            s[i] = new Salary(id, name, desg, sal);
        }

        System.out.println("The Employee details having > 20000 are");
        for (int i = 0; i < n; i++) {
            if (s[i].sal > 20000) {
                s[i].display();
            }
        }
        System.out.println("The Employee details in Salary wise Sorting  are");

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i].sal > s[j].sal) {
                    Salary temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            s[i].display();
        }
        sc.close();
    }
}
