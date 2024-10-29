#include<stdio.h>
void main() {
    float x1, x2, y1, y2, m, c;
    printf("Enter first point (x1, y1) : ");
    scanf("%f %f", &x1, &y1);
    printf("Enter second point (x2, y2) : ");
    scanf("%f %f", &x2, &y2);
    if ( x2 == x1 ) {
        printf("Equation\n");
        printf("x = %.2f", x1);
        return;
    }
    m = (y2-y1)/(x2-x1);
    c = y2-(m*x2);
    printf("Equation\n");
    printf("y = %.2f * x + %.2f", m, c);
}