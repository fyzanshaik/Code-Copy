#include<stdio.h>
#include<string.h>

void main() {
    char *p , *q;
    char str[100];
    int len,flag=0;
    printf("Enter a String\n");
    gets(str);
    len = strlen(str);
    p = str;
    q = str+len-1;
    while ( p<q ) {
        if ( *p!=*q) {
            flag=1;
            break;
        }
        p++;
        q--;
    }
    if ( flag==0 ) {
        printf("Palindrome\n");
    } else {
        printf("Not a Palindrome\n");
    }
}