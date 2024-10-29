#include<stdio.h>
#include<math.h>
void main() {
    int a[20],n;
    float mean=0 , var=0 , stdDev;
    printf("Enter size of Array : ");
    scanf("%d",&n);
    printf("\nEnter Array Elements : ");
    for ( int i=0 ; i<n ; i++ ) {
        scanf("%d",&a[i]);
        mean = mean+a[i];
    }
    mean = mean/n;
    for ( int i=0 ; i<n ; i++ ) {
        var = var+((a[i]-mean)*(a[i]-mean));
    }
    var = var/n;
    stdDev = sqrt(var);
    printf("\nMean = %f\nVariance = %f\nStandard Deviation = %f\n",mean,var,stdDev);
}