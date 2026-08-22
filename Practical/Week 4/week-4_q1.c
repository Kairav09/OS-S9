#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p1, p2;

    p1 = fork();
    if (p1 == 0) {
        sleep(2);
        return 0;
    }

    p2 = fork();
    if (p2 == 0) {
        sleep(1);
        return 0;
    }

    pid_t finished = wait(NULL);
    printf("wait() finished: %d\n", finished);

    waitpid(p1, NULL, 0);
    printf("waitpid() finished: %d\n", p1);

    return 0;
}
