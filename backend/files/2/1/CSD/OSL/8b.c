#include <stdio.h>
#include <stdlib.h>

// Check instructions at end of this file

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line;
    int len = 0;
    int count = 0;
    if (argc < 3) {
        printf("Insuffiecent Arguments");
        return -1;
    }
    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("File cannot be opened");
        return 1;
    }
    while (getline(&line, &len, fp) != -1) {
        count++;
        if (count > atoi(argv[1])) break;
        printf("%s", line);
        fflush(stdout);
    }
    fclose(fp);
    return (0);
}

// while compiling
// gcc 8b.c
// ./a.out 3 file1.txt