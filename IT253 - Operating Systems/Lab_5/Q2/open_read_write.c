#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h> 

int main() {
    int fd = open("file.txt", O_WRONLY | O_CREAT);
    if (fd == -1) {
        
    }
    const char *data = "Hello, World!";
    ssize_t bytesWritten = write(fd, data, strlen(data));
    if (bytesWritten == -1) {
        
    }
    close(fd);

    
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        
    }

    char buffer[100]; 
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        // Handle error
    }
    buffer[bytesRead] = '\0'; 
    printf("Read from file: %s\n", buffer);

    close(fd);
    return 0;
}



