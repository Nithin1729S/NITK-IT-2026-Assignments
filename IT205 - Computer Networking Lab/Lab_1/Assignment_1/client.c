#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main()
{
    int cli_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (cli_sock == -1)
    {
        perror("Error creating client socket");
        exit(1);
    }

    // Initialize server address structure
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(cli_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("Error connecting to the server");
        close(cli_sock);
        exit(1);
    }

    // Open the file for reading
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file for reading");
        close(cli_sock);
        exit(1);
    }

    // Calculate file size
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for file contents
    char *fileContents = (char *)malloc(fileSize + 1);
    if (fileContents == NULL)
    {
        perror("Error allocating memory for file contents");
        fclose(fp);
        close(cli_sock);
        exit(1);
    }

    // Read file contents into the buffer
    size_t end = fread(fileContents, 1, fileSize, fp);
    fileContents[end] = '\0';
    fclose(fp);

    // Send file contents to the server
    if (send(cli_sock, fileContents, fileSize, 0) == -1)
    {
        perror("Error sending file contents to the server");
        free(fileContents);
        close(cli_sock);
        exit(1);
    }

    // Receive the count of characters from the server
    int receivedCount;
    if (read(cli_sock, &receivedCount, sizeof(receivedCount)) == -1)
    {
        perror("Error receiving character count from the server");
        free(fileContents);
        close(cli_sock);
        exit(1);
    }

    // Convert receivedCount from network byte order to host byte order
    receivedCount = ntohl(receivedCount);

    printf("Received count of characters from server: %d\n", receivedCount - 1); // To avoid the null character at the end of the string to be counted.

    // Clean up and close the client socket
    free(fileContents);
    close(cli_sock);
    return 0;
}
