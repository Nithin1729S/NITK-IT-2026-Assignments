#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertLast(struct Node **head,int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(*head==NULL) *head=temp;
    else
    {
        struct Node *p=*head;
        while(p->next)
        {
            p=p->next;
        }
        p->next=temp;
    }

}

struct Node* reverse(struct Node *p)
{
    struct Node *r=NULL,*q=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    return q;
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()
{
    int n=0;
    struct Node *ll1=NULL;
    printf("Enter the No. of elements in the linked list: ");
    scanf("%d",&n);
    printf("Enter the elements seperated by spaces: ");
    while(n>0)
    {
        int num=0;
        scanf("%d",&num);
        insertLast(&ll1,num);
        n--;
    }
    printf("The entered linkedList before reversal: ");
    display(ll1);
    printf("\nThe entered linkedList after reversal: ");
    ll1=reverse(ll1);
    display(ll1);
    return 0;
}