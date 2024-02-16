#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
    printf("Main process ID: %d\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        printf("Error: fork() failed\n");
        exit(EXIT_FAILURE);
    }
    else if (rc == 0) {
        printf("Child process ID: %d\n", (int) getpid());

        char *args[2];
        args[0] = strdup("ls");
        args[1] = NULL;
        execvp(args[0], args);
        printf("Code should not get here\n");        
    }
    else {
        int rc_wait = wait(NULL);
        printf("Parent process ID: %d, parent of process: %d, wait's return val: %d\n", (int) getpid(), rc, rc_wait);
    }
    return 0;
}
