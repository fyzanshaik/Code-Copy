#include<stdio.h>
void main() {
    int roll,math,chem,comp;
    float per;
    printf("Enter your Roll Number\n");
    scanf("%d",&roll);
    printf("Enter Marks of 3 Subjects\n");
    scanf("%d %d %d",&math,&chem,&comp);
    if ( comp<0 || comp>100 || chem<0 || chem>100 || math<0 || math>100 ) {
        printf("Invalid Marks Entered\n");
    } else {
        per = (chem+comp+math)/(3.0);
        if ( per>=91) {
            printf("Grade = O(Outstanding)\n");
        } else if ( per>=81 ) {
            printf("Grade = A\n");
        } else if ( per>=71 ) {
            printf("Grade = B\n");
        } else if ( per>=61 ) {
            printf("Grade = C\n");
        } else {
            printf("You Failed\n");
        }
    }
}