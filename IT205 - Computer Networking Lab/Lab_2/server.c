#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

double calculate(double operand1, double operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else
                return -1; // Division by zero error
        default:
            return -1; // Invalid operator
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(1);
    }
    printf("Waiting for connection...\n");

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("Error binding server socket");
        close(server_socket);
        exit(1);
    }

    if (listen(server_socket, 1) == -1) {
        perror("Error listening for connections");
        close(server_socket);
        exit(1);
    }

    int clifd = accept(server_socket, NULL, NULL);
    if (clifd == -1) {
        perror("Error accepting client connection");
        close(server_socket);
        exit(1);
    }
    printf("Client Connected.\n");

    double operand1, operand2, result;
    char operator;
    while (1) {
        int valread = read(clifd, &operand1, sizeof(double));
        if (valread <= 0)
            break;

        valread = read(clifd, &operand2, sizeof(double));
        if (valread <= 0)
            break;

        valread = read(clifd, &operator, sizeof(char));
        if (valread <= 0)
            break;

        result = calculate(operand1, operand2, operator);
        write(clifd, &result, sizeof(double));
    }
    close(server_socket);
    close(clifd);
    return 0;
}
