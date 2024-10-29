#include<stdio.h>
void main() {
    int a,b,temp;
    printf("Enter any Two Numbers\n");
    scanf("%d %d",&a,&b);
    printf("Before Swap\na = %d , b = %d\n",a,b);
    // Swapping using 3rd Variable
    temp = a;
    a = b;
    b = temp;
    printf("After Swap\na = %d , b = %d\n",a,b);
}