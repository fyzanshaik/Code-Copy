
/*Create a user interface to insert employee details, Display the data in Text Area.*/
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class a13 implements ActionListener {
    String data = "EMP:";
    JFrame jf;
    JPanel jp;
    JLabel l1, l2, l3, l4, l5, l6;
    JTextField t1, t2, t3;
    JRadioButton r1, r2;
    ButtonGroup bg;
    @SuppressWarnings("rawtypes") // comment out this line
    JComboBox jc;
    JCheckBox c1, c2, c3;
    JButton b1;
    JTextArea ta1;
    String cities[] = { "HYD", "BNGL", "PUNE", "DELHI" };

    @SuppressWarnings({ "rawtypes", "unchecked" }) // comment out this line 
    a13() {
        jf = new JFrame();
        // Top or High Level Window
        jf.setSize(300, 300);
        jf.setTitle("Demo");
        jp = new JPanel();
        // lower or second level window
        l1 = new JLabel("EMP-ID");
        l2 = new JLabel("EMP-NAME");
        l3 = new JLabel("Designation");
        l4 = new JLabel("Gender");
        l5 = new JLabel("CITY");
        l6 = new JLabel("COMPANY");
        t1 = new JTextField(30);
        t2 = new JTextField(30);
        t3 = new JTextField(30);
        r1 = new JRadioButton("Male");
        r2 = new JRadioButton("FeMale");
        bg = new ButtonGroup();
        bg.add(r1);
        bg.add(r2);
        jc = new JComboBox(cities);
        c1 = new JCheckBox("Apple");
        c2 = new JCheckBox("Google");
        c3 = new JCheckBox("Microsoft");
        b1 = new JButton("Submit");
        ta1 = new JTextArea(30, 10);
        jf.setLayout(new GridLayout(5, 4));
        jp.add(l1);
        jp.add(t1);
        jp.add(l2);
        jp.add(t2);
        jp.add(l3);
        jp.add(t3);
        jp.add(l4);
        jp.add(r1);
        jp.add(r2);
        jp.add(l5);
        jp.add(jc);
        jp.add(l6);
        jp.add(c1);
        jp.add(c2);
        jp.add(c3);
        jp.add(b1);
        jp.add(ta1);
        jf.add(jp);
        jf.setSize(1000, 600);
        jf.setVisible(true);
        b1.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        data = data + t1.getText() + ":";
        data = data + t2.getText() + ":";
        data = data + t3.getText() + ":";
        if (r1.isSelected())
            data = data + "Male" + ";";
        else
            data = data + "FeMale" + ";";
        String str = (String) jc.getSelectedItem();
        data = data + str + ":";
        if (c1.isSelected())
            data = data + c1.getText();
        else if (c2.isSelected())
            data = data + c2.getText();
        else
            data = data + c3.getText();
        ta1.setText(data);
    }

    public static void main(String args[]) {
        new a13();
    }
}