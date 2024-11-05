#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char ch;
  FILE *fp1, *fp2;

  if (argc < 3)
  {
    printf("Insufficient arguments.\nUsage: ./a.out source_file target_file\n");
    return 1;
  }

  // Open the source file in read mode
  fp1 = fopen(argv[1], "r");
  if (fp1 == NULL)
  {
    printf("Source file cannot be opened.\n");
    return 1;
  }

  // Open the target file in write mode
  fp2 = fopen(argv[2], "w");
  if (fp2 == NULL)
  {
    fclose(fp1);
    printf("Target file cannot be opened.\n");
    return 1;
  }

  // Copy content from source to target
  while ((ch = fgetc(fp1)) != EOF)
    fputc(ch, fp2);

  printf("File copied successfully.\n");

  fclose(fp1);
  fclose(fp2);
  return 0;
}
