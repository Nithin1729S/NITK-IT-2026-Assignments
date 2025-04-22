//Both the stacks are implemented using linked list.Please read the comment over the top of dequeue function to know the algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack    //Node Structure
{
    int data;
    struct Stack *next;
};


//Globally declared 2 Stacks
struct Stack *stk1 = NULL;    
struct Stack *stk2= NULL;


//Push function of the Stack
void push(struct Stack **head, int x)
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

//Pop function for the stack
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


//The enqueue function pushes the element passed into the stack stk1
void enqueue(int x)    
{
    push(&stk1,x);
}

//The dequeue function first checks if stack stk2 is empty ,if stack 2 is not empty it will pop an element from stack stk2
//if stack stk 2 is empty it will check whether stack stk 1 is empty , if both are empty then queue is empty
//if stack stk 2 is empty and stack stk 1 is not empty, it will pop elements from stack 1 and push it to stack 2
//This algorithm will make the two stacks imitate a queue data structure
int dequeue()
{
    int x=-1;
    if(isEmpty(stk2))
    {
        if(isEmpty(stk1)) printf("Queue Empty");
        else
        {
            while(!isEmpty(stk1)) push(&stk2,pop(&stk1));
        }

    }
    return pop(&stk2);
}



//using both enqueue and dequeue function a queue can be imitated
int main()
{
    int x;
    int n;
    printf("Enter the number of elements you need to store in the Queue: ");    //n=5
    scanf("%d",&n);
    printf("Enter the elements:");     // 1 2 3 4 5
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }
    printf("Dequeued Element %d\n",dequeue());  //1 is the output
    printf("Dequeued Element %d\n",dequeue());  //2 is the output

    return 0;
}