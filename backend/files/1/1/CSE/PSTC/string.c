#include <stdio.h>
#include <string.h>
void main() {
    char str1[100], str2[100], str3[100];
    printf("Enter the first string: ");
    gets(str1); 
    gets(str2);
    printf("\nLength of first string (%s): %lu\n", str1, strlen(str1));
    printf("Length of second string (%s): %lu\n", str2, strlen(str2));
    strcpy(str3, str1);
    printf("\nAfter copying, str3 contains: %s\n", str3);
    strcat(str1, str2);
    printf("\nAfter concatenation of str1 and str2, str1 contains: %s\n", str1);
    int comparison = strcmp(str1, str2);
    if (comparison == 0) {
        printf("\nStrings are equal.\n");
    } else if (comparison > 0) {
        printf("\nFirst string is greater than the second.\n");
    } else {
        printf("\nFirst string is less than the second.\n");
    }
}