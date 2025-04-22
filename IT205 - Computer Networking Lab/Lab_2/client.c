#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main() {
    int cli_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (cli_sock == -1) {
        perror("Error creating client socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(cli_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("Error connecting to the server");
        close(cli_sock);
        exit(1);
    }

    while (1) {
        printf("Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 5) {
            break; // Exit the loop when the user chooses to quit
        }

        double operand1, operand2, result;
        char operator;

        printf("Enter operand 1: ");
        scanf("%lf", &operand1); // Read as a double

        printf("Enter operand 2: ");
        scanf("%lf", &operand2); // Read as a double

        switch (choice) {
            case 1:
                operator = '+';
                break;
            case 2:
                operator = '-';
                break;
            case 3:
                operator = '*';
                break;
            case 4:
                operator = '/';
                break;
            default:
                printf("Invalid choice\n");
                continue;
        }

        write(cli_sock, &operand1, sizeof(double));
        write(cli_sock, &operand2, sizeof(double));
        write(cli_sock, &operator, sizeof(char));

        read(cli_sock, &result, sizeof(double)); // Read as a double

        printf("Result: %lf\n", result); // Print as a double
    }

    close(cli_sock);
    return 0;
}
