#include <stdio.h>

struct Items
{
    int itemNo;
    char name[100];
    int price;
    int quantity;
};

int main()
{
    struct Items items[200] = {
        {1, "Apple", 20, 500},
        {2, "Banana", 15, 300},
        {3, "Orange", 25, 400},
        {4, "Grapes", 30, 200},
        {5, "Mango", 40, 100},
        {6, "Carrot", 10, 600},
        {7, "Potato", 12, 700},
        {8, "Tomato", 18, 350},
        {9, "Cucumber", 22, 250},
        {10, "Lettuce", 8, 800}
        
    };

    
    printf("Items with price less than 100:\n");
    for (int i = 0; i < 10; ++i)
    {
        if (items[i].price < 100)
        {
            printf("Item No: %d\n", items[i].itemNo);
            printf("Name: %s\n", items[i].name);
            printf("Price: %d\n", items[i].price);
            printf("Quantity: %d\n\n", items[i].quantity);
        }
    }

    return 0;
}
