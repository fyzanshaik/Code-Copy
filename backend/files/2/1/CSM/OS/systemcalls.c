#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h> // Include this for `wait` function
#include <unistd.h>

int main() // Change `void main()` to `int main()` for proper return type
{
    int pid;

    pid = fork(); // Fork a child process

    if (pid < 0) // Check if fork failed
    {
        printf("\n Fork failed to create a child \n");
        return 1;
    }
    else if (pid > 0) // Parent process
    {
        printf("\n The parent process id is %d \n", getpid());
        printf("\n Parent Process Running \n");
        wait(NULL); // Parent waits for child to complete
        printf("\n Child Completed \n");
    }
    else // Child process
    {
        printf("\n Child Process running \n");
        printf("\n The child process id is %d", getpid());
        printf("\n The parent of child is %d", getppid());

        // Fix quotation marks for "-l" argument
        execlp("/bin/ls", "ls", "-l", NULL);
    }

    return 0;
}
