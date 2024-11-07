import Measure.*;

public class a6 {
    public static void main(String args[]) {
        Converter c = new Converter();
        System.out.println(" mm to m is  " + c.mmtom(100));
        System.out.println(" cm to m is  " + c.cmtom(1000));
        System.out.println(" m to km is  " + c.mtokm(3000));
    }
}

// download -  /2/1/CSE/OOP/Converter.java
// create "Measure" directory in current directory
// store Converter.java in "Measure" directory
// compile this Converter.java file using javac
// now run this a6.java file using both javac and java