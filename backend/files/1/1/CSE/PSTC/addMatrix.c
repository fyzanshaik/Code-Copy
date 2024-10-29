#include<stdio.h>
void main() {
    int a[10][10] , b[10][10] , c[10][10] ,i,j,r1,c1,r2,c2;

    printf("Enter No. of Rows &  Columns For 1st Matrix\n");
    scanf("%d %d",&r1,&c1);
    
    printf("\nEnter No. of Rows &  Columns For 2nd Matrix\n");
    scanf("%d %d",&r2,&c2);

    if ( r1==r2 && c1==c2 ) {
        // Input 1st Matrix
        printf("\nEnter 1st Matrix Elements\n");
        for ( i=0 ; i<r1; i++ ) {
            for ( j=0 ; j<c1 ; j++ ) {
                scanf("%d",&a[i][j]);
            }
        }
        // Input 2nd Matrix
        printf("\nEnter 2nd Matrix Elements\n");
        for ( i=0 ; i<r2 ; i++ ) {
            for ( j=0 ; j<c2 ; j++ ) {
                scanf("%d",&b[i][j]);
            }
        }
        // Calculating Final Matrix
        for ( i=0 ; i<r1 ; i++ ) {
            for ( j=0 ; j<c1 ; j++ ) {
                c[i][j] = a[i][j]+b[i][j];
            }
        }
        // Printing Final Matrix
        printf("Final Matrix is\n");
        for ( i=0 ; i<r1 ; i++ ) {
            for ( j=0 ; j<c1 ; j++ ) {
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nMatrices can't be ADDED!\n");
    }
}