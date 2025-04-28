#include <stdio.h>
#include <math.h>
#define FREQ 500

float m[128];

void main(){
    int i = 0;
    for (i = 0;i<127;i++){
        m[i] = sin(2 * (22/7) * FREQ * i / 24000);
        printf("%f\n", m[i]);
    }
}