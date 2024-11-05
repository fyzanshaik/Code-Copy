#include<stdio.h> 
#include<string.h> 
#include<sys/types.h> 
#include<unistd.h> 
void main() 
 { 
 int n,p1fd[2],p2fd[2]; 
 pid_t pid; 
 char msg[100]; 
 if(pipe(p1fd)==-1) { 
  printf("pipe failed\n"); 
  return; 
 } 
  
          if(pipe(p2fd)==-1) { 
  printf("pipe failed\n"); 
  return; 
 } 
  
 pid=fork(); 
  
   if(pid<0)  
          { 
  printf("fork failed\n"); 
  return; 
 } 
 if(pid>0)//parent 
 { 
  close(p2fd[1]); 
  close(p1fd[0]); 
  printf("enter the msg to  child (Client)--->Parent\n"); 
  scanf("%s",msg); 
  write(p1fd[1],msg,strlen(msg)+1); 
                       sleep(5);//sleep of 5 seconds 
  read(p2fd[0],msg,100); 
 printf("the msg given by child (client) is %s --->Parent\n",msg); 
 } 
  
 
else 
 { 
  close(p2fd[0]); 
  close(p1fd[1]); 
                       sleep(3);   
                read(p1fd[0],msg,100); 
 printf("the msg given  by parent is %s --->child\n",msg); 
                sleep(3);//sleep of 3 seconds 
  printf("enter the msg to parent --->child\n"); 
  scanf("%s",msg); 
  write(p2fd[1],msg,strlen(msg)+1); 
  
 } 
} 

#include<stdio.h> 
#include<sys/types.h> 
#include<fcntl.h> 
#include<unistd.h> 
int main() 
{ 
 int fd,x; 
 char msg[100]; 
 x=mkfifo("abc",0666); 
 if(x==-1) 
 { 
  printf("fifo not created\n"); 
  return 0; 
 } 
 fd=open("abc",O_WRONLY); 
 if(fd==-1) 
 { 
  printf("fifo not opened\n"); 
  return 0; 
 } 
 printf("Enter the Message to FIFO "); 
 scanf("%s",msg); 
 write(fd,msg,sizeof(msg)); 
 close(fd); 
 sleep(4); 
        printf("Message written to FIFO \n");   
 unlink("abc"); 
 return 0; 
}




#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<fcntl.h> 
#define size 1024 
int main() 
{ 
 int fd; 
 char buf[size]; 
 fd=open("abc",O_RDONLY); 
 if(fd==-1){ 
  printf("fifo not opened\n"); 
  return 0; 
 } 
 read(fd,buf,size); 
 printf("\nthe message received from FIFO is --->%s",buf); 
 close(fd); 
 return 0; 
}