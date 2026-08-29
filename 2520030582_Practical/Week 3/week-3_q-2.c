#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Process PID: %d\n", getpid());
    
    printf("Waiting State (30s).\n");
    sleep(30);

    printf("Exiting process.\n");
    return 0;
}
