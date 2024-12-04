/*Using   CardLayout   design   a   user   interface   to   access   the   Programs   and   Courses offered by the College and use appropriate event handling.*/
import java.awt.*;
import java.awt.event.*;

public class b12 extends Frame implements ActionListener, MouseListener {
    Checkbox c1, c2, c3, c4; // B.Tech
    Checkbox c5, c6, c7; // M.Tech
    Panel deck; // deck-main panel
    Panel p1, p2; // cards
    CardLayout cl;
    Button b1, b2;

    public b12() {
        setSize(400, 400);
        setVisible(true);
        setLayout(new FlowLayout());
        b1 = new Button("B.Tech");
        b2 = new Button("M.Tech");
        add(b1); // Frame window
        add(b2); // Frame Window
        cl = new CardLayout(5, 5);
        deck = new Panel();
        deck.setLayout(cl); // set main panel layout to card layout
        c1 = new Checkbox("CSE", true);
        c2 = new Checkbox("ECE");
        c3 = new Checkbox("EEE");
        c4 = new Checkbox("MECH");
        p1 = new Panel(); // first card as Panel
        p1.add(c1);
        p1.add(c2);
        p1.add(c3);
        p1.add(c4);
        c5 = new Checkbox("Neural Networks", true);
        c6 = new Checkbox("Digital Image Processing");
        c7 = new Checkbox("Machine Design");
        p2 = new Panel(); // second card as panel
        p2.add(c5);
        p2.add(c6);
        p2.add(c7);
        // Adding panel cards to main panel
        deck.add(p1, "B.Tech");
        deck.add(p2, "M.Tech");
        // add main panel (deck) to Frame
        add(deck);
        b1.addActionListener(this);
        b2.addActionListener(this);

        addMouseListener(this);
    }

    public void mousePressed(MouseEvent me) {
        cl.next(deck);
    }

    public void mouseClicked(MouseEvent me) {
    }

    public void mouseEntered(MouseEvent me) {
        cl.first(deck);
    }

    public void mouseExited(MouseEvent me) {
        cl.last(deck);
    }

    public void mouseReleased(MouseEvent me) {
    }

    public void actionPerformed(ActionEvent ae) {
        if (ae.getSource() == b1) // returns the clicked button object
            cl.show(deck, "B.Tech");
        else
            cl.show(deck, "M.Tech");
    }

    public static void main(String args[]) {
        new b12();
    }
}
