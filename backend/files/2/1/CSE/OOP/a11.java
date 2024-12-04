/*Implement MouseListener and MouseMotionListener to handle various   mouse events.*/
import java.awt.*;
import java.awt.event.*;

public class a11 extends Frame implements MouseListener, MouseMotionListener {
    int x = 0, y = 0;
    String msg = "";

    a11(String title) {
        super(title);
        addMouseListener(this);
        addMouseMotionListener(this);
        setSize(500, 500);
        setVisible(true);
    }

    public void mouseClicked(MouseEvent e) {
        msg = "MouseClicked";
        x = e.getX();
        y = e.getY();
        repaint();
    }

    public void mousePressed(MouseEvent e) {
        msg = "MousePressed";
        x = e.getX();
        y = e.getY();
        repaint();
    }

    public void mouseReleased(MouseEvent e) {
        msg = "MouseReleased";
        x = e.getX();
        y = e.getY();
        repaint();
    }

    public void mouseEntered(MouseEvent e) {
        msg = "MouseEntered";
        x = e.getX();
        y = e.getY();
        repaint();
    }

    public void mouseExited(MouseEvent e) {
        msg = "MouseExited";
        x = e.getX();
        y = e.getY();
        repaint();
    }

    public void mouseMoved(MouseEvent e) {
        msg = "*";
        x = e.getX();
        y = e.getY();
        repaint();
    }

    public void mouseDragged(MouseEvent e) {
        msg = "#";
        x = e.getX();
        y = e.getY();
        repaint();
    }

    public void paint(Graphics g) {
        g.drawString(msg + " at " + x + "," + y, 100, 50);
    }

    public static void main(String[] args) {
        a11 f = new a11("Mouse Events Handling");
        f.paint(null);
    }
}