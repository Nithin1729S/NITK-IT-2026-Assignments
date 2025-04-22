#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define SERV_PORT 5576

int main() {
    ssize_t n;
    char filename[80];
    struct sockaddr_in servaddr;
    int sockfd;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    
    printf("\nEnter the filename: ");
    scanf("%s", filename);
    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    char file_content[1024]; // Adjust the buffer size as needed
    size_t read_size = fread(file_content, 1, sizeof(file_content), fp);
    
    write(sockfd, file_content, read_size); // Sending the file content to server
    
    int num_chars;
    read(sockfd, &num_chars, sizeof(int)); // Receiving the number of characters from server
    
    printf("\nNumber of characters in the file content: %d\n", num_chars);
    
    close(sockfd);
}
