#include<stdio.h>
void main() {
    int n,ans=0,rem,temp;
    printf("Enter Number : ");
    scanf("%d",&n);
    temp = n;
    while (n!=0) {
        rem = n%10;
        ans =(ans*10)+rem;
        n=n/10;
    }
    printf("Reverse of %d is = %d\n",temp,ans);
}