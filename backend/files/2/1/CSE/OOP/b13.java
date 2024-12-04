/*Create a JTable to display various fields of Student data like RollNo,Name,Branch,Year,Percentage etc.*/
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class b13 {
    JFrame f;
    JTable j;

    b13() {
        f = new JFrame();
        f.setTitle("JTable Example");
        String[][] data = {
                { "101", "Rajesh", "CSE", "II", "78.5" },
                { "102", "Harsha", "CSE", "II", "87.5" },
                { "103", "Varsha", "CSE", "II", "65.5" },
                { "104", "Kiran", "IT", "II", "75.5" },
                { "105", "Karan", "IT", "II", "87.5" },
        }; // Column Names
        String[] head = { "RollNo", "Name", "Department", "Branch", "Percentage" };
        // Initializing the JTable
        j = new JTable(data, head);
        j.setBounds(30, 40, 200, 300);
        // adding it to JScrollPane
        JScrollPane sp = new JScrollPane(j);
        f.add(sp);
        f.setSize(500, 200);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        new b13();
    }
}