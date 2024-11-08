class NegativeAgeException extends Exception {
    NegativeAgeException(String s) {
        super(s);
    }

    public String toString() {
        return "Age Exception";
    }
}

public class b7 {
    static void validate(int age) throws NegativeAgeException {
        if (age < 0)
            throw new NegativeAgeException("  not valid  " + age);
        else
            System.out.println("  welcome to the world  " + age);
    }

    public static void main(String args[]) {
        try {
            validate(23);
            validate(17);
            validate(-12);
            validate(25); // Not Executed
        } catch (Exception m) {
            System.out.println("Exception occured: No Negative Age");
            System.out.println(m); // Description of Message
        } finally {
            System.out.println("Finally block executed");
        }
        System.out.println("rest of the code...");
    }
}
