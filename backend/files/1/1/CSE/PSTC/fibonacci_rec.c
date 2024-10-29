#include<stdio.h>
int fib( int n ) {
    if ( n==1 || n==0 ) {
        return n;
    }
    return fib(n-1)+fib(n-2);
}
void main() {
    int num;
    printf("Enter Number : ");
    scanf("%d",&num);
    if ( num<=0 ) {
        printf("Invalid\n");
    } else {
        printf("%dth Term : %d\n",num,fib(num-1));
    }
}