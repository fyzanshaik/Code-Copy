#include<stdio.h>
void main() {
    int n,sum=0;
    printf("Enter Number : ");
    scanf("%d",&n);
    for ( int i=1 ; i<=n ; i++ ) {
        sum += i;
    }
    printf("\nSum = %d\n",sum);
}