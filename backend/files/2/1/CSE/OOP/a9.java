
/*Use an ArrayList to manage Employee objects for insertion, display and remove.*/
import java.util.*;

public class a9 {
	public static void main(String[] args) {
		ArrayList<Employee> list = new ArrayList<Employee>();
		// Creating Employees
		Employee e1 = new Employee(101, "A.Harsha", 75000.50);
		Employee e2 = new Employee(102, "B.Varsha", 85000.50);
		Employee e3 = new Employee(103, "C.Sirisha", 95000.50);
		Employee e4 = new Employee(104, "D.Sandeep", 195000.50); // Adding Employees to list
		list.add(e1);
		list.add(e2);
		list.add(e3);
		list.add(e4);
		// Displaying Number of Employees
		System.out.println("\n The number of employees is ->" + list.size());
		// Displaying Details of Employees
		System.out.println("\n The employess data is \n");
		for (Employee e : list) {
			System.out.println(e.eid + ":" + e.ename + ":" + e.sal);
			System.out.println();
		} // Deleting an Employee
		list.remove(2);
		System.out.println("\n After removing number of employees are ->" + list.size());
		// Displaying Details of Employees
		System.out.println("\n The employess data after removing is \n");
		for (Employee e : list) {
			System.out.println(e.eid + ":" + e.ename + ":" + e.sal);
			System.out.println();
		}
	}
}

class Employee {
	int eid;
	String ename;
	double sal;

	public Employee(int x, String y, double z) {
		eid = x;
		ename = y;
		sal = z;
	}
}