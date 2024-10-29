#include<stdio.h>
void main() {
	int a,b,m,n,p,q,r,s;
	// a=p ; b=q ; m = r ; n = s ; 
	printf("Enter The value of p , q for INCREMENT & DECREMENT\n");
	scanf("%d%d",&p,&q);
	r = p;
	s = q;
	
	// Pre-Increment
	printf("\nPre-Increment \n");
	printf("++%d  =  %d \n",p,++r);
	printf("++%d  =  %d \n",q,++s);
	r = p;
	s = q;
	
	// Post-Increment
	printf("\nPost-Increment \n");
	printf("%d++  =  %d \n",p,r++);
	printf("%d++  =  %d \n",q,s++);
	r = p;
	s = q;
	
	// Pre-Decrement
	printf("\nPre-Decrement \n");
	printf("--%d  =  %d \n",p,--r);
	printf("--%d  =  %d \n",q,--s);
	r = p;
	s = q;
	
	// Post-Decrement
	printf("\nPost-Decrement \n");
	printf("%d--  =  %d \n",p,r--);
	printf("%d--  =  %d \n",q,s--);
	
	printf("\nEnter The Values of a , b for BITWISE OPERATORS\n");
	scanf("%d%d",&a,&b);
	
	// AND Operator
	printf("\nAND Operator of %d , %d : \n",a,b);
	printf("%d & %d = %d \n",a,b,a&b);
	
	// OR Operator
	printf("\nOR Operator of %d , %d : \n",a,b);
	printf("%d | %d = %d \n",a,b,a|b);
	
	// XOR Operator
	printf("\nXOR Operator of %d , %d : \n",a,b);
	printf("%d ^ %d = %d \n",a,b,a^b);
	
	// Left Shift
	m=a;
	n=b;
	printf("\nLeft Shift of %d : \n",a);
	printf("%d<<1 = %d \n",a,m<<1);
	printf("\nLeft Shift of %d : \n",b);
	printf("%d<<1 = %d \n",b,n<<1);
	
	// Right Shift
	m=a;
	n=b;
	printf("\nRight Shift of %d : \n",a);
	printf("%d>>1= %d \n",a,m>>1);
	printf("\nRight Shift of %d : \n",b);
	printf("%d>>1 = %d \n",b,n>>1);
	
	// Complement
	m=a;
	n=b;
	printf("\nComplement of %d : \n",a);
	printf("~%d = %d \n",a,~m);
	printf("\nComplement of %d : \n",b);
	printf("~%d = %d \n",b,~n);
}
