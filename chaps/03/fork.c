#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;
    
    printf("The main program PID is %d\n", (int) getpid());

    child_pid = fork();
    if (child_pid != 0) {
        printf("This is the parent process, with PID %d\n", getpid());
        printf("The child's PID is %d\n", child_pid);
    } else {
        printf("This is the child process, with PID %d\nSleeping...\n", getpid());
        sleep(10);
    }

    return 0;
}