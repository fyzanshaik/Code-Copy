#include<stdio.h>
int main() {
	int a,b,c,max,min;
	printf("Enter any Three numbers\n");
	if (scanf("%d%d%d",&a,&b,&c) == 1 ) {
		printf("j");
	}
	 
	// For MAXIMUM
	if ( a==b && a==c ) {
		printf("All are Equal\n");
		max = a;
	} else if ( b>=a && b>=c ) {
		max = b;
	} else if ( c>=a && c>=b ) {
		max = c;
	} else if ( a>=b && a>=c ) {
		max = a;
	}
	printf("Maximum is = %d\n",max);
	
	//For MINIMUM
	if ( a==b && a==c ) {
		printf("All are Equal\n");
		min = a;
	} else if ( b<=a && b<=c ) {
		min = b;
	} else if ( c<=a && c<=b ) {
		min = c;
	} else if ( a<=b && a<=c ) {
		min = a;
	}
	printf("Minimum is = %d\n",min);
		
	return(100);
}
