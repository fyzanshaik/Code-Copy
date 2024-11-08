#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>

void main() {
    int fd, x;
    x = mkfifo("abc", 0666);
    if ( x==-1 ) return;
    fd = open("abc", O_WRONLY);
    if ( fd == -1 ) return;
    char msg[100];
    scanf("%s", msg);
    write(fd, msg, sizeof(msg));
    close(fd);
    sleep(5);
    printf("msg written");
}