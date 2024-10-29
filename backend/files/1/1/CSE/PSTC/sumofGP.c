#include<stdio.h>
void main() {
    int a,r,n,sum=0,temp;
    printf("Enter The First Term : ");
    scanf("%d",&a);
    printf("Enter The Number Of Terms : ");
    scanf("%d",&n);
    printf("\nEnter The Common Ratio : ");
    scanf("%d",&r);
    temp=a;
    for ( int i=1 ;  i<=n ; i++ ) {
        sum += temp;
        temp *= r;
    }
    printf("\nSum of GP ==> %d\n",sum);
}