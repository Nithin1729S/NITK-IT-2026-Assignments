#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *stk1 = NULL;

void push(struct Node **head, char x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

char pop(struct Node **head)
{
    char x;
    struct Node *p = *head;
    (*head) = (*head)->next;
    x = p->data;
    free(p);
    return x;
}

int isEmpty(struct Node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

char stackTop(struct Node *head)
{
    char x = '\0';
    if (head == NULL)
        return x;
    return (head->data);
}

int outStackprecedence(char x)
{
    if (x == '\0') return -1;
    if (x == '+' || x == '-') return 1;
    else if (x == '*' || x == '/') return 3;
    else if (x == '^') return 6;
    else if (x == '(') return 7;
    else if (x == ')') return 0;
    else return -1;
}

int inStackprecedence(char x)
{
    if (x == '\0') return -1;
    if (x == '+' || x == '-') return 2;
    else if (x == '*' || x == '/') return 4;
    else if (x == '^') return 5;
    else if (x == '(') return 0;
    else return -1;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == ')' || x == '(') return 0;
    else return 1;
}

char *infixToPostfix(char *infix)
{
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 1));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (outStackprecedence(infix[i]) > inStackprecedence(stackTop(stk1)))
            {
                push(&stk1, infix[i++]);
            }
            else if (outStackprecedence(infix[i]) == inStackprecedence(stackTop(stk1)))
            {
                pop(&stk1);
                i++;
            }
            else
            {
                postfix[j++] = pop(&stk1);
            }
        }
    }
    while (!isEmpty(stk1))
    {
        postfix[j++] = pop(&stk1);
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char infix[] = "((a+b)*c-d^e^f)";
    printf("Infix: %s \n", infix);
    char *postfix = infixToPostfix(infix);
    printf("Postfix: %s \n", postfix);
    free(postfix);
    return 0;
}
