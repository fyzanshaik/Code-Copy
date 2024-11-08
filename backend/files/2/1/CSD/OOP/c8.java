class Buffer {
    int item;
    boolean produced = false;

    synchronized void produce(int x) {
        if (produced) {
            try {
                wait();
            } catch (InterruptedException ie) {
                System.out.println("Exception Caught");
            }
        }

        item = x;
        System.out.println("Producer - Produced-->" + item);
        produced = true;
        notify();
    }

    synchronized int consume() {
        if (!produced) {
            try {
                wait();
            } catch (InterruptedException ie) {
                System.out.println("Exception Caught " + ie);
            }
        }

        System.out.println("Consumer - Consumed " + item);
        produced = false;
        notify();
        return item;
    }
}

class Producer extends Thread {

    Buffer b;

    Producer(Buffer b) {
        this.b = b;
        start();
    }

    public void run() {
        b.produce(10);
        b.produce(20);
        b.produce(30);
        b.produce(40);
        b.produce(50);

    }
}

class Consumer extends Thread {
    Buffer b;

    Consumer(Buffer b) {
        this.b = b;
        start();
    }

    public void run() {

        b.consume();
        b.consume();
        b.consume();
        b.consume();

    }
}

public class c8 {
    public static void main(String args[]) {
        Buffer b = new Buffer(); // Synchronized Object
        new Producer(b);
        new Consumer(b);
    }
}
