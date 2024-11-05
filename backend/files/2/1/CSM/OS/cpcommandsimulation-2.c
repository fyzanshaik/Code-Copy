#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int count = 0;

    if (argc < 3)
    {
        printf("Insufficient arguments.\nUsage: ./a.out N filename\n");
        return 1;
    }

    // Open the file in read mode
    fp = fopen(argv[2], "r");
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    // Read and print the first N lines
    while (getline(&line, &len, fp) != -1)
    {
        count++;
        if (count > atoi(argv[1]))
            break;
        printf("%s", line);
    }

    fclose(fp);
    free(line); // Free allocated memory for line
    return 0;
}
