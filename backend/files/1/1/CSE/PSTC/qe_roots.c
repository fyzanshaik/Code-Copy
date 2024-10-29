#include<stdio.h>
#include<math.h>
int main() {
	float a,b,c,d,r1,r2,k;
	printf("Enter a,b,c for ax^2+bx+c=0\n");
	scanf("%f %f %f", &a, &b, &c);
	d = (b*b)-(4*a*c);
	if ( d<0 ) {
		printf("Roots are IMAGINARY\n");
		k=sqrt(-d)/(2*a);
		r1 = -b/(2*a);
		printf("Imaginary roots are\nx1 = %f + i*%f\nx2 = %f - i*%f\n",r1,k,r1,k);
	}  else if ( d==0 ) {
		printf("Roots are Real and Equal\n");
		r1 = -b/(2*a);
		r2 = r1;
		printf("Roots are %f and %f \n",r1,r2);
	} else {
		printf("Roots are Real and Unequal\n");
		r1 = (-b+sqrt(d))/(2*a);
		r2 = (-b-sqrt(d))/(2*a);
		printf("Roots are %f and %f \n",r1,r2);
	}
	return(88);
}