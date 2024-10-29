#include<stdio.h>
void main() {
    unsigned int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    if ( (n&(n-1)) == 0 ) {
        printf("%d can be expressed as power of 2\n",n);
    } else {
        printf("%d canoot be expressed as power of 2\n",n);
    }
}