#include<stdio.h>
void main() {
    int n,c,a=0,b=1;
    printf("Enter Number of terms : ");
    scanf("%d",&n);
    if ( n<=0 ) {
        printf("Invalid\n");
    } else if ( n==1 ) {
        printf("\n%d",a);
    } else {
        printf("\n%d %d ",a,b);
        for ( int i=1 ; i<=n-2 ; i++ ) {
        c=a+b;
        printf("%d ",c);
        a=b;
        b=c;
        }
    }
    printf("\n");
}