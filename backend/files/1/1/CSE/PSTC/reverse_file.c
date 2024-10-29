#include<stdio.h>
void main() {
    FILE *fo , *fr ;
    int n,i=1;
    char c;
    fo = fopen("file_org.txt","w");
    fprintf(fo,"C Programming Language\n");
    fclose(fo);

    fo = fopen("file_org.txt","r");
    fr = fopen("file_rev.txt","w");

    fseek(fo,0,2);
    n = ftell(fo);
    while ( i<=n ) {
        fseek(fo,-i,2);
        c = fgetc(fo);
        fputc(c,fr);
        i++;
    }
    fclose(fo);
    fclose(fr);
    fr = fopen("file_rev.txt","r");
    i=0;
    while ( i<=n ) {
        fseek(fr,i,0);
        printf("%c",fgetc(fr));
        i++;
    }
    fclose(fr);
}