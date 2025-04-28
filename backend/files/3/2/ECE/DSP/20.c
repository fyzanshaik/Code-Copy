#include <stdio.h>
#include <math.h>
#define N1 4 
#define N2 4

int x1[2*N1-1] = {1,2,3,4,0,0,0,0};
int h[2*N2-1] = {1, 2, 3, 4, 0, 0, 0, 0};

int y[N1+N2-1];

void main(){
    int i,j;
    for (i = 0; i < N1+N2-1; i++){
        y[i] = 0;
        for (j = 0; j <= i; j++){
            y[i] += x1[j] * h[i-j];
        }
    }
    printf("The output of the convolution is:\n");
    for (i = 0; i < N1+N2-1; i++){
        printf("%d ", y[i]);
    }
    printf("\n");
}