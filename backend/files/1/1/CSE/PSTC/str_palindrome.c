#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main() {
    char str[100], rev[100];
    printf("Enter string : ");
    gets(str);
    int len = strlen(str);
    for ( int i=0 ; i<len ; i++ ) {
        str[i] = tolower(str[i]); // ctype.h
        rev[len-i-1] = str[i];
    }
    rev[len] = '\0';
    int comparison = strcmp(rev, str);
    if ( comparison == 0 ) {
        printf("It is Palindrome\n");
    } else {
        printf("It is not Palindrome\n");
    }
}