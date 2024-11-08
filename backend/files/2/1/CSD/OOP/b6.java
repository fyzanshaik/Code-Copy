interface Student {
    void displayGrade();

    void attendence();
}

class PGStudent implements Student {
    String name;
    int rollno;
    String grade;
    double att;

    PGStudent(String n, int r, String g, double a) {
        name = n;
        rollno = r;
        grade = g;
        att = a;
    }

    public void display() {
        System.out.println("The PG Student data is ");
        System.out.println(" Name : " + name + " : " + "Rollno " + rollno);
    }

    public void displayGrade() {
        System.out.println("The Grade of PG Student is " + grade);
    }

    public void attendence() {
        System.out.println("The attendence of  PG Student is " + att);
    }

}

class UGStudent implements Student {
    String name;
    int rollno;
    String grade;
    double att;

    UGStudent(String n, int r, String g, double a) {
        name = n;
        rollno = r;
        grade = g;
        att = a;
    }

    public void display() {
        System.out.println("The UG Student data is ");
        System.out.println(" Name : " + name + " : " + "Rollno " + rollno);
    }

    public void displayGrade() {
        System.out.println("The Grade of UG Student is    :" + grade);
    }

    public void attendence() {
        System.out.println("The attendence of UG Student is  :  " + att);
    }

}

public class b6 {
    public static void main(String[] args) {
        PGStudent s = new PGStudent("Harsha", 1101, "A", 78.5);
        s.display();
        s.attendence();
        s.displayGrade();
        
        UGStudent u = new UGStudent("Varsha", 5101, "B", 68.5);
        u.display();
        u.attendence();
        u.displayGrade();
    }
}
