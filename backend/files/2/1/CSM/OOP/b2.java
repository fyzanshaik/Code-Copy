
import java.util.Scanner;

class Account {
    String name;
    int acc_no;
    double balance;
    Account(String name, int acc_no, double balance) {
        this.name = name;
        this.acc_no = acc_no;
        this.balance = balance;
    }
    void deposit(double amount) {
        if ( amount > 0 ) {
            balance += amount;
        }
        System.out.println("Updated balance : "+balance);
    }
    void withdrawl(double amount) {
        if ( amount > balance ) {
            System.out.println("Not enough balance!");
        } else {
            balance -= amount;
            System.out.println("Successfully withdrawed "+amount);
        }
        System.out.println("Updated balance : "+balance);
    }
    void checkBalance() {
        System.out.println("Account number : "+acc_no);
        System.out.println("Name : "+name);
        System.out.println("Balance : "+balance);
    }
}

public class b2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name : ");
        String name = sc.nextLine();
        sc.nextLine(); // Flush
        System.out.print("Enter account number : ");
        int acc_no = sc.nextInt();
        System.out.print("Enter initial balance : ");
        double balance = sc.nextDouble();
        Account a = new Account(name, acc_no, balance);
        do { 
            System.out.println("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit");
            int choice = sc.nextInt();
            switch(choice) {
                case 1 : {
                    System.out.print("Enter amount : ");
                    double amount = sc.nextDouble();
                    a.deposit(amount);
                    break;
                }
                case 2 : {
                    System.out.print("Enter amount : ");
                    double amount = sc.nextDouble();
                    a.withdrawl(amount);
                    break;
                }
                case 3 : {
                    a.checkBalance();
                    break;
                }
                case 4 : {
                    sc.close();
                    return;
                }
                default: System.out.println("Invalid Choice !");
            }
        } while (true);
    }
}