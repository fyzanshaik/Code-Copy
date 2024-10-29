#include<stdio.h>
void main() {
    int a[20];
    int n, max = -1000, min = 1000;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter %d integers : ", n);
    for ( int i=0 ; i<n ; i++ ) {
        scanf("%d", &a[i]);
    }
    for ( int i=0 ; i<n ; i++ ) {
        min = a[i]<min ? a[i] : min;
        max = a[i]>max ? a[i] : max;
    }
    printf("Max : %d\n", max);
    printf("Min : %d\n", min);
}