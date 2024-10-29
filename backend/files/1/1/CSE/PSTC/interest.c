#include<stdio.h>
#include<math.h>
void main() {
    float p,t,r,si,ci,temp,amount;
    printf("Enter principle amt , time in years , rate of interest");
    scanf("%f %f %f",&p,&t,&r);
    si = (p*t*r)/100;
    temp = pow(1+(r/100),t);
    amount = p*temp;
    ci = amount-p;
    printf("\nSI = %f\nCI = %f\n",si,ci);
}