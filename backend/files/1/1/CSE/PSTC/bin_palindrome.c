#include<stdio.h>
void main() {
    int n,k,rev=0;
    printf("Enter Number : ");
    scanf("%d",&n);
    k=n;
    while(k>0) {
        rev = (rev<<1)|(k&1);
        k=k>>1;
    } 
    if ( rev==n ) {
        printf("\nYES , it is Palindrome\n");
    } else {
        printf("\nNO , it is not Palindrome\n");
    }
}