#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
       int p1fd[2], p2fd[2];
       pid_t pid;
       char msg[100];

       // Create the first pipe
       if (pipe(p1fd) == -1)
       {
              printf("Pipe 1 creation failed\n");
              return 1;
       }

       // Create the second pipe
       if (pipe(p2fd) == -1)
       {
              printf("Pipe 2 creation failed\n");
              return 1;
       }

       pid = fork();

       if (pid < 0)
       {
              printf("Fork failed\n");
              return 1;
       }

       if (pid > 0)
       {                      // Parent process
              close(p2fd[1]); // Close write end of the second pipe
              close(p1fd[0]); // Close read end of the first pipe

              printf("Enter the message to child (Client) --> Parent: ");
              scanf("%s", msg);
              write(p1fd[1], msg, strlen(msg) + 1);
              sleep(5); // Sleep for 5 seconds

              read(p2fd[0], msg, 100);
              printf("The message given by child (client) is %s --> Parent\n", msg);
       }
       else
       {                      // Child process
              close(p2fd[0]); // Close read end of the second pipe
              close(p1fd[1]); // Close write end of the first pipe

              sleep(3); // Sleep for 3 seconds
              read(p1fd[0], msg, 100);
              printf("The message given by parent is %s --> Child\n", msg);

              printf("Enter the message to parent --> Child: ");
              scanf("%s", msg);
              write(p2fd[1], msg, strlen(msg) + 1);
       }

       return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
       int fd, x;
       char msg[100];

       // Create a FIFO named "abc" with permissions 0666
       x = mkfifo("abc", 0666);
       if (x == -1)
       {
              printf("FIFO could not be created\n");
              return 1;
       }

       fd = open("abc", O_WRONLY);
       if (fd == -1)
       {
              printf("FIFO could not be opened\n");
              return 1;
       }

       printf("Enter the message to FIFO: ");
       scanf("%s", msg);

       write(fd, msg, strlen(msg) + 1); // Write message to FIFO
       close(fd);

       printf("Message written to FIFO\n");

       // Remove the FIFO file after writing
       unlink("abc");

       return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define SIZE 1024

int main()
{
       int fd;
       char buf[SIZE];

       fd = open("abc", O_RDONLY);
       if (fd == -1)
       {
              printf("FIFO could not be opened\n");
              return 1;
       }

       read(fd, buf, SIZE); // Read from FIFO
       printf("\nThe message received from FIFO is --> %s\n", buf);

       close(fd);
       return 0;
}
