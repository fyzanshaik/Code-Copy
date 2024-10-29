#include<stdio.h>
void main() {
    int n,flag=1;
    printf("Enter The Number : ");
    scanf("%d",&n);
    for ( int i=2 ; i<=n/2 ; i++ ) {
        if ( n%i == 0 ) {
            printf("\n%d is NOT a Prime Number\n",n);
            flag++;
            break;
        }
    }
    if (flag==1) {
        printf("\n%d is a Prime Number\n",n);
    }
}