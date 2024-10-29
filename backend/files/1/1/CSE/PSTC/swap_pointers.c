#include<stdio.h>
//Call By Value
void swap_no( int x , int y ) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("After Swapping\nInside Function\na= %d , b= %d\n",x,y);
}
//Call By Reference
void swap_address( int *p , int *q ) {
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
    printf("After Swapping\nInside Function\na = %d , b = %d\n",*p,*q);
}
void main() {
    int a,b,w;
    printf("Enter Values for a,b\n");
    scanf("%d %d",&a,&b);
    printf("Press 1 for Call by value\nPress 2 for Call by reference\n");
    scanf("%d",&w);
    printf("Before Swapping a = %d , b = %d\n",a,b);
    if ( w==1 ) {
        swap_no(a,b);
    } else if ( w==2 ) {
        swap_address( &a , &b );
    } else {
        printf("Invalid Button Pressed\n");
    }
    printf("After Swapping in main function\na = %d , b = %d",a,b);
}