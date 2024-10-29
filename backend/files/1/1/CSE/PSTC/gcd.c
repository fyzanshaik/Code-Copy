#include<stdio.h>
void main() {
    int n1,n2,factor;
    printf("Enter The Numbers : ");
    scanf("%d %d",&n1,&n2);
    for ( int i=1 ; (i<=n1 && i<=n2) ; i++ ) {
        if ( (n1%i==0) && (n2%i==0) ) {
            factor = i;
        }
    }
    printf("\nGCD of %d & %d is ==>  %d\n",n1,n2,factor);
}