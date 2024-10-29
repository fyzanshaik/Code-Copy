#include<stdio.h>
int fact_non_rec( int n ) {
    int fact=1;
    for ( int i=2 ; i<=n ; i++ ) {
        fact *= i;
    }
    return fact;
}
int fact_rec( int n ) {
    if ( n==1 ) {
        return 1;
    }
    return n*fact_rec(n-1);
}
void main() {
    int n,p,res;
    printf("Which Method?(Press 1 for rec [or] Press 2 for non_rec)\n");
    scanf("%d",&p);
    printf("Enter Number(>=0) : ");
    scanf("%d",&n);
    if ( n<0 ) {
        printf("Factorial Can't be Calculated\n");
    }
    if ( p==1 ) {
        res = fact_rec(n);
        printf("\n%d! = %d\n",n,res);
    } else {
        res = fact_non_rec(n);
        printf("\n%d! = %d\n",n,res);
    }
}