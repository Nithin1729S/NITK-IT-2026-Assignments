#include <stdio.h>

int main() {
    int n, T;
    scanf("%d", &T); // how many inputs in the input file

    while (T--) {
        scanf("%d", &n); // each input

        /* --- Start your solution here --- */

        // Coffee Vending Machine Menu
        printf("Coffee Vending Machine Menu:\n");
        printf("1. Espresso\n");
        printf("2. Cappuccino\n");
        printf("3. Latte\n");
        printf("4. Hot Chocolate\n");
        printf("5. Tea\n");
        printf("6. Exit\n");

        // User's choice
        printf("Please enter your choice (1-6): ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Preparing Espresso\n");
                printf("Your Espresso is ready!\n");
                break;
            case 2:
                printf("Preparing Cappuccino\n");
                printf("Your Cappuccino is ready!\n");
                break;
            case 3:
                printf("Preparing Latte\n");
                printf("Your Latte is ready!\n");
                break;
            case 4:
                printf("Preparing Hot Chocolate\n");
                printf("Your Hot Chocolate is ready!\n");
                break;
            case 5:
                printf("Preparing Tea\n");
                printf("Your Tea is ready!\n");
                break;
            case 6:
                printf("Exiting the Coffee Vending Machine\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option (1-6).\n");
        }

        /* --- End of the solution --- */
    }

    return 0;
}
