#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>

void main() {
    char msg[100];
    int fd;
    fd = open("abc", O_RDONLY);
    if ( fd == -1 ) return;
    read(fd, msg, sizeof(100));
    printf("%s", msg);
    close(fd);
}