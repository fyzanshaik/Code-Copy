#include<stdio.h>
void main() {
    FILE *fo ;
    int n,i;
    char c;
    fo = fopen("file_org.txt","w");
    fprintf(fo,"C Programming Language");
    fclose(fo);

    fo = fopen("file_org.txt","r");

    fseek(fo,0,2);
    n = ftell(fo);
    i = n/2;
    printf("Size = %d\n",n);
    printf("From %d to %d \n",i,n);
    while ( i<=n ) {
        fseek(fo,i,0);
        c = fgetc(fo);
        i++;
        printf("%c",c);
    }
    fclose(fo);
}