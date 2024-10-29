#include<stdio.h>
void main() {
    int x,y,*p,*q;
    printf("Enter values for x,y : ");
    scanf("%d%d",&x,&y);
    p = &x;
    q = &y;
    printf("Address of %d is %p\n",*p,p);
    printf("Address of %d is %p\n",*q,q);
    p++;
    q++;
    printf("Address of %d after is %p\n",*p,p);
    printf("Address of %d after is %p\n",y,q);
}