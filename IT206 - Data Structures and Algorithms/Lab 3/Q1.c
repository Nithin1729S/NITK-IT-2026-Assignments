#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int x;
    int y;
    struct Node *next;
};

struct Node* push(struct Node *top,int x, int y)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
        printf("Stack Overflow.\n");     //heap is full
    else
    {
        temp->x = x;
        temp->y = y;
        temp->next = top;
        top = temp;
    }
}


void pop(struct Node **top) 
{
    int x,y=-1;
    if (*top == NULL) {
        printf("Stack is Empty\n"); 
    } else {
        struct Node *t = *top;
        x = t->x;
        y = t->y;
        *top = (*top)->next;
        free(t);
    }
    printf("(%d, %d) is removed.\n",x,y);
}

void display(struct Node *top)
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("(%d, %d) ", p->x, p->y);
        p = p->next;
    }
    printf("\n");
}


int main()
{

    struct Node *top=NULL;
    top=push(top,10,3);
    top=push(top,12,5);
    display(top);
    pop(&top);
    top=push(top,0,9);
    display(top);
    return 0;
}




