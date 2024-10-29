#include<stdio.h>
struct student
{
    char name[20];
    int roll;
    char grade;
}s1;

void main() {
    printf("Enter Name , Roll no , Grade of a Student\n");
    gets(s1.name);
    scanf("%d %c",&s1.roll,&s1.grade);
    printf("\nName : %s\nRoll no : %d\nGrade : %c\n",s1.name,s1.roll,s1.grade);
}