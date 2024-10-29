#include<stdio.h>
void main() {
    int n;
    printf("Enter Number of Cities\n");
    scanf("%d",&n);
    char cities[n][20];
    char *p[n];
    for ( int i=0 ; i<n ; i++ ) {
        scanf("%s",p[i]);
    }
    for ( int i=0 ; i<n ; i++ ) {
        printf("%s\n",*p[i]);
    }
}