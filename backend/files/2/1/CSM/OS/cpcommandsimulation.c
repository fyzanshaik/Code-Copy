//cp command simulation 
#include <stdlib.h> 
int main(int argc , int argv[]) { 
   char ch; 
   FILE *fp1, *fp2; 
 
   fp1 = fopen(argv[1], "r"); 
 
   if (fp1 == NULL) { 
      printf("Press any key to exit...\n"); 
      exit(1); 
   } 
   fp2 = fopen(argv[2], "w"); 
   if (target == NULL) { 
      fclose(source); 
      printf("Press any key to exit...\n"); 
      exit(0); 
   } 
   while ((ch = fgetc(fp1))! = EOF) 
          fputc(ch, fp2); 
   printf("File copied successfully.\n"); 
 
   fclose(source); 
   fclose(target); 
   return 0; 
} 
 
cc copy.c -> to compile 
./a.out.  demo1.txt demo2.txt 
 
// Create demo1.txt file. 
//Can use unix system calls also for simulation. 
 
 
 
 
 
 
 
 
 
 
 
//head command simulation 
Create a directory 
Create a text file with content. [eg: demo.txt] 
Create a C programme using gedit editor. 
 cc head.c -> to compile 
 ./a.out.  3  demo.txt => to execute. (command line args) 
#include<stdio.h> 
#include<stdlib.h> 
int main(int argc , char *argv[]) 
   { 
     FILE *fp; 
     char *line; 
     int len=0; 
     int count=0; 
     if(argc < 3)       { 
         printf("Insuffiecent Arguments"); 
         return -1; 
       } 
     fp = fopen(argv[2] , "r"); 
     if(fp == NULL)       { 
          printf("File cannot be opened"); 
          return 1;   
      } 
     while(getline(&line,&len,fp)!= -1)        { 
           count++; 
           if(count > atoi(argv[1])) 
             break; 
              printf("%s", line); 
           fflush(stdout); 
         } 
    fclose(fp); 
    return (0); 
} 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//tail command simulation 
 cc tail.c -> to compile 
 ./a.out.  3 demo.txt => to execute. (command line args) 
#include<stdio.h> 
#include<stdlib.h> 
int main(int argc , char *argv[])   { 
     FILE *fp; 
     char *line; 
      int len=0; 
     int count=0,n,i; 
     if(argc < 3)       { 
         printf("Insuffiecent Arguments"); 
         return -1; 
       } 
     fp = fopen(argv[2] , "r"); 
     if(fp == NULL)       { 
          printf("File cannot be opened"); 
          return 1;   
      } 
     while(getline(&line,&len,fp)!= -1)        { 
           count++; 
         } 
     printf("\n Total number of lines is %d \n", count);  
     rewind(fp); 
     n =  count - atoi(argv[1]); 
     i=0; 
       while(getline(&line , &len , fp) !=-1)           { 
              i++; 
              if(i > n) 
                 printf("%s",line); 
            } 
 fclose(fp); 
   return (0); 
} 