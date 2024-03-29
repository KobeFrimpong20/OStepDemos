#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[]){
	if (argc != 2) {
		fprintf(stderr, "Usage: mem <value>\n");
		exit(1);
	}
	int *p;
        p = malloc(sizeof(int));
	assert(p != NULL);
	printf("(%d) address pointed to by p: %p\n", getpid(), p);
	*p = atoi(argv[1]);
	while (1) {
		sleep(1);
		*p = *p + 1;
		printf("(%d) value of p: %d\n", getpid(), *p);
	}
	return 0;
}
