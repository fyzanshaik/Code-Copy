/*Create a Simple login window to validate a user with name and password.*/
// import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
// import javax.swing.event.*;

public class a12 extends JFrame implements ActionListener {
    JLabel l1, l2, l3;
    JTextField t1, t2;
    JButton b1;

    a12(String name) {
        super(name);
        l1 = new JLabel("User Name");
        l1.setBounds(20, 50, 100, 20);
        // x,y -> top left point , width,height are dimensions
        l2 = new JLabel("Password");
        l2.setBounds(20, 100, 100, 20);
        t1 = new JTextField();
        t1.setBounds(130, 50, 100, 20);
        t2 = new JTextField();
        t2.setBounds(130, 100, 100, 20);
        // t2.setEchoChar('*');
        b1 = new JButton("login");
        b1.setBounds(80, 150, 80, 20);
        l3 = new JLabel("->");
        l3.setBounds(80, 200, 200, 20);
        add(l1);
        add(t1);
        add(l2);
        add(t2);
        add(b1);
        add(l3);
        b1.addActionListener(this);
        setSize(400, 400);
        setLayout(null);
        setVisible(true);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    public void actionPerformed(ActionEvent e) {
        String uname = t1.getText();
        String pwd = t2.getText();
        if (uname.equals("vce") && pwd.equals("root"))
            l3.setText("Welcome to VCE");
        else
            l3.setText("Invalid Username or Password");
    }

    public static void main(String[] args) {
        new a12("Login Window");
    }
}