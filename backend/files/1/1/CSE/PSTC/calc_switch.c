#include<stdio.h>
void main() {
    float a,b;
    int c,d;
    char rem = '%';
    char oper;
    printf("Enter any Two Numbers\n");
    scanf("%d %d",&c,&d);
    a = c/(1.0);
    b = d/(1.0);
    printf("MENU\nPress + for Add\n- for Sub\n* for Mul\n/ for Div\n%c for remainder\n",rem);
    scanf(" %c",&oper);
    switch (oper) {
        case '+' :  printf("%f + %f = %f",a,b,a+b);
                    break;
        case '-' :  printf("%f - %f = %f",a,b,a-b);
                    break;
        case '*' :  printf("%f * %f = %f",a,b,a*b);
                    break;
        case '/' :  if ( b == 0 ) {
                        printf("Invalid Divisor i.e 0\n");
                    } else {
                        printf("%f / %f = %f",a,b,a/b);
                    }
                    break;
        case '%' :  printf("%d %c %d = %d",c,rem,d,c%d);
                    break;
        default : printf("Invalid Operation Symbol Entered\n");
    }
}