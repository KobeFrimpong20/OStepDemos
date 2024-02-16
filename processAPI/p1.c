#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello (pid:%d)\n", (int) getpid());
    int rc = fork();
    if(rc < 0) {
        printf("Error: Fork failed\n");
        exit(EXIT_FAILURE);
    }
    else if (rc == 0){
        printf("child pid:%d\n",(int) getpid());
    }
    else {
        printf("parent of rc: %d pid:%d\n", rc, (int)getpid());
    }
    return 0;
}
