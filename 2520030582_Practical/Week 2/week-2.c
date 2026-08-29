#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char source[100], destination[100];
    char buffer[1024];
    int src_fd, dest_fd;
    ssize_t n;

    printf("Enter source file name: ");
    scanf("%99s", source);

    printf("Enter destination file name: ");
    scanf("%99s", destination);

    src_fd = open(source, O_RDONLY);
    dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while ((n = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, n);
    }

    close(src_fd);
    close(dest_fd);

    printf("File copied successfully.\n");

    return 0;
}
