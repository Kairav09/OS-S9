#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process ending.\n");
        return 0;
    } else {
        wait(NULL);
    }
    return 0;
}
