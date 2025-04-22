#include <stdio.h>

int main() {
    int quantity;
    float costPerUnit = 100.0;
    float totalCost;

  
    printf("Enter the quantity of items: ");
    scanf("%d", &quantity);

    totalCost = quantity * costPerUnit;

    if (totalCost > 1000) {
        totalCost *= 0.9;  
    }

   
    printf("Total cost: Rs. %.2f\n", totalCost);

    return 0;
}
