#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>

int main() {
    int fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    
    const char *data = "Hello, world!";
    ssize_t bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("Write error");
        close(fd);
        return 1;
    }

   
    if (close(fd) == -1) {
        perror("Close error");
        return 1;
    }

    printf("File closed successfully.\n");

    return 0;
}




