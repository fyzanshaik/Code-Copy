#include <stdio.h>
#include <math.h>
#define N 5

int x[N] = {1,2,3,4,0};
int h[N] = {2,1,4,5,6};

int y[N];

int main(){
    int i,j,p;
    for (i = 0;i<N;i++){
        y[i] = 0;
        for (j = 0;j<N;j++){
           y[i] += x[j] * h[i-j];
        }
    }
    printf("The output of the convolution is:\n");
    for (i = 0;i<N;i++){
        printf("%d ",y[i]);
    }
    printf("\n");
    return 0;
}