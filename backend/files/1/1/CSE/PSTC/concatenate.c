#include<stdio.h>
#include<string.h>
void main() {
    char str1[100], str2[100], str3[100], res[300];
    printf("Enter 3 strings : ");
    scanf("%s %s %s", str1, str2, str3);
    strcpy(res, str1);
    strcat(res, str2);
    strcat(res, str3);
    printf("Result : %s\n", res);
}