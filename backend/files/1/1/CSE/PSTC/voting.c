#include<stdio.h>
void main() {
    int a[20],n,max_count=0,canditate_no,count; //temp
    printf("Enter No.of Candidtes : ");
    scanf("%d",&n);
    for ( int i=0 ; i<n ; i++ ) {
        printf("\n%d Candidate ==> Enter YOUR VOTE : ",i+1);
        scanf("%d",&a[i]);
    }
    for ( int i=0 ; i<n ; i++ ) {
        count=1;
        for ( int j=i+1 ; j<n ; j++ ) {
            if ( a[i]==a[j] ) {
                count++;
            }
        }
        if ( count>=max_count ) {
            // if ( count == max_count ) {
            //     printf("Candidate %d , ",temp);
            // }
            max_count = count;
            canditate_no   = a[i];
            // temp = canditate_no;
        }
    }
    printf("Candidate %d Won The Election",canditate_no);
    printf("\nwith Majority of %d votes out of %d votes\n",max_count,n);
}
