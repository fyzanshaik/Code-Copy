#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main() {
    char str[100], ch;
    int lines = 1, words = 0, characters = 0;

    printf("Enter string with end * : ");
    scanf("%[^*]", str);

    int len = strlen(str);
    for ( int i=0 ; i<len ; i++ ) {
        ch = str[i];
        if ( ch == '\n' ) {
            words++;
            lines++;
        } else if ( ch == ' ' ) {
            words++;
        } else {
            characters++;
        }
    }

    printf("\nLines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
}
