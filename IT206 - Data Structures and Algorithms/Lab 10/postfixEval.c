#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *stk1 = NULL;

void push(struct Stack **head, int x)
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

int pop(struct Stack **head)
{
    int x;
    struct Stack *p = *head;
    (*head) = (*head)->next;
    x = p->data;
    free(p);
    return x;
}

int isEmpty(struct Stack *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

int stackTop(struct Stack *head)
{
    int x = 0;
    if (head == NULL)
        return x;
    return (head->data);
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == ')' || x == '(')
        return 0;
    else
        return 1;
}

int eval(char *postfix)
{
    int i, x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
            push(&stk1, postfix[i] - '0'); // Convert character to integer
        else
        {
            x2 = pop(&stk1);
            x1 = pop(&stk1);
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                if (x2 != 0) // Check for division by zero
                    r = x1 / x2;
                else
                {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                break;
            }
            push(&stk1, r);
        }
    }
    return pop(&stk1);
}

int main()
{
    char *postfix = "35*62/+4-";
    printf("%s  = ",postfix);
    int res = eval(postfix);
    printf("%d ", res);
    return 0;
}
