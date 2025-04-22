#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    char recvContent[1024];
    int count;

    // Create a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        perror("Error creating server socket");
        exit(1);
    }
    printf("Waiting for connection...\n");

    // Initialize server address structure
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("Error binding server socket");
        close(server_socket);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 1) == -1)
    {
        perror("Error listening for connections");
        close(server_socket);
        exit(1);
    }

    // Accept a client connection
    int clifd = accept(server_socket, NULL, NULL);
    if (clifd == -1)
    {
        perror("Error accepting client connection");
        close(server_socket);
        exit(1);
    }

    printf("Client Connected.\n");

    // Receive data from the client
    ssize_t end = read(clifd, recvContent, sizeof(recvContent));
    if (end == -1)
    {
        perror("Error reading data from client");
        close(clifd);
        close(server_socket);
        exit(1);
    }
    recvContent[end] = '\0';

    printf("Received Data: %s\n", recvContent);

    // Count the characters received
    for (count = 0; recvContent[count] != '\0'; count++)
    {
    }

    // Convert count to network byte order
    int countToSend = htonl(count);

    // Send the character count back to the client
    if (send(clifd, &countToSend, sizeof(countToSend), 0) == -1)
    {
        perror("Error writing data to client");
        close(clifd);
        close(server_socket);
        exit(1);
    }

    // Close the client and server sockets
    close(clifd);
    close(server_socket);

    return 0;
}
