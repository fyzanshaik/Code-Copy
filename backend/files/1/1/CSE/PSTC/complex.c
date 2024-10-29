#include<stdio.h>
struct complex
{
    float real;
    float imag;
}c1,c2,res;
struct complex addComplex( struct complex n1 , struct complex n2 ) {
    res.real = n1.real+n2.real;
    res.imag = n1.imag+n2.imag;
    return res;
}
void main() {
    printf("Enter First Number (i,j) : ");
    scanf("%f %f",&c1.real,&c1.imag);
    printf("Enter Second Number (i,j) : ");
    scanf("%f %f",&c2.real,&c2.imag);
    addComplex(c1,c2);
    printf("Addition of Complex : (%.2f , %.2f*i)\n",res.real,res.imag);
}