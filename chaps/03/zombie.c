#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;

    /* Create a child process */
    child_pid = fork();
    if (child_pid > 0) {
        /* this is the parent process */
        sleep(60);
    } else {
        /* This is the child */
        exit(0);
    }
    return 0;
}