#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

struct Node* findMiddle(struct Node*head)
{
    struct Node* fast=head->next;
    struct Node* slow=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

bool isPalindrome(struct Node*head)
{
    struct Node* mid=findMiddle(head);
    struct Node* p=head;
    struct Node* q=mid->next;
    mid->next=NULL;
    q=reverse(q);
    while(p && q)
    {
        if(p->data!=q->data)
        {
            return false;
        }
        p=p->next;
        q=q->next;
    }
    return true;
}

int main()
{
    int n=0;
    int key=0;
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
    printf("The entered linkedList: ");
    display(ll1);
    if(isPalindrome(ll1)) printf("\nIt is a Palindrome.");
    else printf("\nIt is not a Palindrome.");
    return 0;
}
