#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        printf("Child Process\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        printf("Child state: Running\n");
        sleep(5);
        printf("Child state: Terminated\n");
        exit(0);
    }

    else {

        printf("Parent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
        printf("Parent state: Waiting\n");
        wait(NULL);
        printf("Parent State: Running\n");
        printf("Child process terminated\n");

        return 0;
    }
}
