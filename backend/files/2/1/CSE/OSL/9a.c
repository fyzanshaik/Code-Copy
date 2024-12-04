#include <stdio.h>
#include <stdlib.h>

// cp
// Check instructions at end of this file

int main(int argc, int argv[]) {
    char ch;
    FILE *fp1, *fp2;

    fp1 = fopen(argv[1], "r");

    if (fp1 == NULL) {
        printf("Press any key to exit...\n");
        exit(1);
    }
    fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
        fclose(fp1);
        printf("Press any key to exit...\n");
        exit(0);
    }
    while ((ch = fgetc(fp1)) != EOF) fputc(ch, fp2);
    printf("File copied successfully.\n");

    fclose(fp1);
    fclose(fp2);
    return 0;
}


// while compiling
// gcc 9a.c
// ./a.out file1.txt file2.txt