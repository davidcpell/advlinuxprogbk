#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// int spawn(char* program, char** arg_list)
int spawn(char** arg_list)
{
    pid_t child_pid;

    child_pid = fork();
    if (child_pid != 0) {
        return child_pid;
    } else {
        execvp(arg_list[0], arg_list);
        /* execvp returns only if an error occurred. */
        fprintf(stderr, "an error occurred in execvp\n");
        abort();
    }
}

int main()
{
    char* arg_list[] = {
        "ls",
        "-l",
        "/",
        NULL
    };

    int child_status;
    // spawn("ls", arg_list);
    spawn(arg_list);
    wait(&child_status);
    printf("Done with main program\n");
    return 0;
}