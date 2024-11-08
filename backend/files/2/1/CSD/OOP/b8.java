class NewThread extends Thread {
    NewThread(String name) {
        super(name);
    }

    public void run() {
        try {
            for (int i = 1; i <= 4; i++) {
                System.out.println("Java is object oriented" + getName());
                sleep(1000);
            }
        } catch (InterruptedException ie) {
            System.out.println("Child Thread - Exception caught");
        }
    }
}

public class b8 {
    public static void main(String args[]) {
        NewThread t1 = new NewThread("First");
        NewThread t2 = new NewThread("Second");

        t1.start();
        t2.start();
        System.out.println("Main Program");
    }
}
