#include<stdio.h>
struct books
{
    char name[30];
    char author[30];
    int pages;
}b1;
void main() {
    printf("Enter Book Name , Author , No.of Pages\n");
    gets(b1.name);
    gets(b1.author);
    scanf("%d",&b1.pages);
    printf("\nName of Book : %s\nAuthor Name : %s\nNo.of Pages : %d\n",b1.name,b1.author,b1.pages);
}
