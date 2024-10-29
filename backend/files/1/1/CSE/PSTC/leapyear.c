#include<stdio.h>
void main() {
	int y;
	printf("Enter The Year\n");
	scanf("%d",&y);
	if ( y%400 == 0 ) {
		printf("%d is a Leap Year\n",y);
	} else if ( y%4 == 0 && y%100 != 0 ) {
		printf("%d is a Leap Year\n",y);
	} else {
		printf("%d is Not a Leap Year\n",y);
	}
}