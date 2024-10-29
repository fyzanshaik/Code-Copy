#include<stdio.h>
#include<string.h>
struct n_students
{
    char name[20];
    int roll;
    char grade;
};

void main() {
    
    int n,x;
    printf("Enter No.of Students : ");
    scanf("%d",&n);
    struct n_students s[n];

    //Scanning Inputs

    printf("\nEnter Name , Roll No , Grade\n");

    for ( int i=0 ; i<n ; i++ ) {
        printf("Enter Details of Student %d\n",i+1);
        scanf("%s%d %c",s[i].name,&s[i].roll,&s[i].grade);
    }

    printf("Which Student Details You Want? (Enter Serial NO.)\n");
    printf("Want All Details?(Press 0)\n");
    scanf("%d",&x);

    //Printing Details

    for ( int i=0 ; i<n ; i++ ) {
        if ( x==0 ) {
            printf("\nDetails of Student %d\n",i+1);
            printf("Name : %s\nRoll No. : %d\nGrade : %c\n",s[i].name,s[i].roll,s[i].grade);
        }
        if ( i+1 == x ) {
            printf("\nDetails of Student %d\n",x);
            printf("Name : %s\nRoll No. : %d\nGrade : %c\n",s[i].name,s[i].roll,s[i].grade);
        }
    }
}