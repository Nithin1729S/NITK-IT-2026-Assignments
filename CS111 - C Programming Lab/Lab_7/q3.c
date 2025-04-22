#include <stdio.h>
#include <string.h>


struct Customer {
    int customerId;
    char firstName[50];
    char lastName[50];
    char address[100];
    int prevUnits;
    int presentUnits;
    float totalAmount;
};


void calculateBill(struct Customer *customer) {
    int unitsConsumed = customer->presentUnits - customer->prevUnits;

    if (unitsConsumed <= 199) {
        customer->totalAmount = unitsConsumed * 1.20;
    } else if (unitsConsumed >= 200 && unitsConsumed < 400) {
        customer->totalAmount = unitsConsumed * 1.50;
    } else if (unitsConsumed >= 400 && unitsConsumed < 600) {
        customer->totalAmount = unitsConsumed * 1.80;
    } else {
        customer->totalAmount = unitsConsumed * 2.00;
    }

    
    if (customer->totalAmount > 400) {
        customer->totalAmount += customer->totalAmount * 0.15;
    }

    
    if (customer->totalAmount < 100) {
        customer->totalAmount = 100;
    }
}

int main() {
    
    struct Customer customer;

    
    printf("Enter Customer ID: ");
    scanf("%d", &customer.customerId);

    printf("Enter First Name: ");
    scanf("%s", customer.firstName);

    printf("Enter Last Name: ");
    scanf("%s", customer.lastName);

    printf("Enter Address: ");
    scanf(" %[^\n]s", customer.address);

    printf("Enter Previous Units Consumed: ");
    scanf("%d", &customer.prevUnits);

    printf("Enter Present Units Utilized: ");
    scanf("%d", &customer.presentUnits);

    
    calculateBill(&customer);

    
    printf("\nElectricity Bill:\n");
    printf("Customer ID: %d\n", customer.customerId);
    printf("Name: %s %s\n", customer.firstName, customer.lastName);
    printf("Address: %s\n", customer.address);
    printf("Previous Units Consumed: %d\n", customer.prevUnits);
    printf("Present Units Utilized: %d\n", customer.presentUnits);
    printf("Total Amount to Pay: Rs. %.2f\n", customer.totalAmount);

    return 0;
}
