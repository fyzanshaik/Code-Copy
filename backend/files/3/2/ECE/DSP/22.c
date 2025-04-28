#include <stdio.h>
#include <math.h>

float pi = 3.14159;
float sumre = 0;
float sumi = 0;
float out_real[8] = {0,0};
float out_imag[8] = {0,0};
int x[32];

void main(){
    printf("Enter the input sequence:\n");
    int N ;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &x[i]);
    }
    int k;
    for (k=0;k<N;k++){
        sumre = 0;
        sumi = 0;
        for (int n=0;n<N;n++){
            sumre += x[n] * cos(2 * pi * k * n / N);
            sumi += x[n] * sin(2 * pi * k * n / N);
        }
        out_real[k] = sumre;
        out_imag[k] = sumi;

    }
    printf("The output of the DFT is:\n");
    for (int i = 0; i < N; i++){
        printf("%f + %fi\n", out_real[i], out_imag[i]);
    }

}