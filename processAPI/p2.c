#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("hello (process id:%d)\n", (int) getpid());
    int rc = fork();
    if (rc == 0) {
        printf("child (process id:%d)\n", (int) getpid());
    }
    else if (rc > 0) {
        int rc_wait = wait(NULL);
        printf("Parent of %d (return code of wait:%d) (parent process id:%d)\n", rc, rc_wait, (int) getpid());
    }
    else {
        printf("Error: fork() failed\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
