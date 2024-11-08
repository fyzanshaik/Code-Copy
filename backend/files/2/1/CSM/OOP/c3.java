import java.util.Scanner;

public class c3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter dimensions for first matrix (m, n) : ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        System.out.print("Enter dimensions for first matrix (p, q) : ");
        int p = sc.nextInt();
        int q = sc.nextInt();
        if ( n!=p ) {
            System.out.println("Matrix Multiplication is not possible!");
            sc.close();
            return;
        }
        int[][] a = new int[m][n];
        int[][] b = new int[p][q];
        int[][] c = new int[m][q];

        System.out.println("Enter elements for matrix A");
        for ( int i=0 ; i<m ; i++ ) {
            for ( int j=0 ; j<n ; j++ ) {
                a[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter elements for matrix B");
        for ( int i=0 ; i<p ; i++ ) {
            for ( int j=0 ; j<q ; j++ ) {
                b[i][j] = sc.nextInt();
            }
        }

        // Calculation
        for ( int i=0 ; i<m ; i++ ) {
            for ( int j=0 ; j<q ; j++ ) {
                for ( int k=0 ; k<n ; k++ ) {
                    c[i][j] += (a[i][k]*b[k][j]);
                }
            }
        }

        System.out.println("Final Matrix C");
        for ( int i=0 ; i<m ; i++ ) {
            for ( int j=0 ; j<q ; j++ ) {
                System.out.print(c[i][j]+" ");
            }
            System.out.println();
        }
        sc.close();
    }
}
