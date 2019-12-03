#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int pid = fork();
	if (pid) {
		waitpid(pid, NULL, 0);
		printf("A == %s", getenv("A"));
	} else {
		execl("A=10", NULL);
	}
}
