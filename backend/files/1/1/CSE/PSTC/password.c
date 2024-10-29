#include<stdio.h>
void main() {
    int pass,flag=1;
    do {
        printf("\nEnter The Password\n");
        scanf("%d",&pass);
        if (pass==1234) {
            printf("\nCorrect Password\n");
            flag++;
            break;
        } else {
            printf("\nIncorrect Password\nTry Again\n");
        }
        
    } while(flag==1);
}