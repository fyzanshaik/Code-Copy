#include<stdio.h>
void main() {
    long int n,fact=1,i;
    printf("Enter Number : ");
    scanf("%ld",&n);
    if ( n<0 ) {
        printf("Invalid for factorial\n");
    } else {
        for ( i=1 ; i<=n ; i++ ) {
            fact *= i;
        }
        printf("\nFactorial of %ld = %ld\n",n,fact);
    }
}