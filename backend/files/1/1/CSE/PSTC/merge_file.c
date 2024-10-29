#include<stdio.h>
void main() {
    FILE *fp1 , *fp2 , *fp3 ;
    
    char c;
    fp1 = fopen("file1.txt","w");
    fp2 = fopen("file2.txt","w");

    fprintf(fp1,"Gnaneshwar\n548\n96.2%%\n");
    fprintf(fp2,"Siddartha\n600\n99%%\n");

    fclose(fp1);
    fclose(fp2);

    fp1 = fopen("file1.txt","r");
    fp2 = fopen("file2.txt","r");
    fp3 = fopen("file3.txt","w");

    while ( (c=fgetc(fp1)) != EOF ) {
        fputc(c,fp3);
    }
    while ( (c=fgetc(fp2)) != EOF ) {
        fputc(c,fp3);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    fp3 = fopen("file3.txt","r");

    while ( (c=fgetc(fp3)) != EOF ) {
        printf("%c",c);
    }
    fclose(fp3);
}