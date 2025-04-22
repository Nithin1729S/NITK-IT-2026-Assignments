#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

#define SERV_PORT 5576

int main(int argc, char **argv) {
    ssize_t n;
    char s[80];
    struct sockaddr_in servaddr, cliaddr;
    int listenfd, connfd, clilen;
    
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, 1);
    
    clilen = sizeof(cliaddr);
    connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
    
    printf("\nClient connected\n");
    
    FILE *fp;
    char received_content[1024]; // Adjust the buffer size as needed
    
    n = read(connfd, received_content, sizeof(received_content));
    received_content[n] = '\0'; // Null-terminate the received content
    
    printf("\nReceived content from client:\n%s\n", received_content);
    
    int num_chars = strlen(received_content);
    
    printf("\nNumber of characters in the received content: %d\n", num_chars);
    
    write(connfd, &num_chars, sizeof(int)); // Sending the number of characters back to client
    
    close(listenfd);
    close(connfd);
}
