
/*Use HashSet to organize list of products and perform operations on them.*/
import java.util.*;

public class b9 {
    public static void main(String[] args) {
        HashSet<Product> set = new HashSet<Product>(); // Creating Products
        Product p1 = new Product(1010, "Mobile", 12345.75);
        Product p2 = new Product(1012, "Watch", 2345.75);
        Product p3 = new Product(1013, "wallet", 345.75);// Adding Books to HashSet
        set.add(p1);
        set.add(p2);
        set.add(p3); // Accessing HashSet
        System.out.println("The Products list is");
        for (Product p : set) {
            System.out.println(p.pid + " " + p.pname + " " + p.price);
        }
        set.remove(p2);
        System.out.println("The Products list after remove");
        for (Product p : set) {
            System.out.println(p.pid + " " + p.pname + " " + p.price);
        }
    }
}

class Product {
    int pid;
    String pname;
    double price;

    public Product(int pid, String pname, double price) {
        this.pid = pid;
        this.pname = pname;
        this.price = price;
    }
}