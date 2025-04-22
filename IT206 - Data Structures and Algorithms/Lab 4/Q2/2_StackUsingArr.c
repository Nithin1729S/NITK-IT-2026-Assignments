#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

void push(int x)
{
    if(top == MAX_SIZE - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow.\n");
        exit(1);
    }
    return stack[top--];
}

bool isEmpty()
{
    return (top == -1);
}

void display()
{
    for(int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n"); 
}

int main()
{
    char choice; 
    int num;

    while(1) 
    {
        printf("Enter:\n1 to Push, 2 to Pop, q to Quit\n");
        scanf(" %c", &choice); 

        if(choice == 'q') 
        {
            break; 
        }
        else if(choice == '1')
        {
            printf("Enter the element to push: ");
            scanf("%d", &num);
            push(num);
            printf("Stack : ");
            display();
        }
        else if(choice == '2')
        {
            pop(num);
            printf("Stack : \n");
            display();
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}
