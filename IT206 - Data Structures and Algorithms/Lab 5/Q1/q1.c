#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

int count(struct Node *head)
{

    int c=0;
    while(head)
    {
        c++;
        head=head->next;
        
    }
    return c;
}

void insert(struct Node **head,int x,int idx)
{
    if(idx<0 || idx>count(*head)) 
    {
        printf("Invalid Index.\n");
        return;
    }
    struct Node*temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    if(idx==0)
    {
        temp->prev=NULL;
        temp->next=*head;
        if(*head!=NULL) (*head)->prev=temp;
        *head=temp;
    }
    else
    {
        struct Node *p=*head;
        for(int i=0;i<idx-1;i++) p=p->next;
        temp->next=p->next;
        temp->prev=p;
        if(p->next) p->next->prev=temp;
        p->next=temp;
    } 
}

int delete(struct Node**head,int idx)
{
    int x=-1;
    if(idx<0 || idx>count(*head)-1)
    {
        printf("Invalid Index\n");
        return x;
    }
    struct Node *p=*head;
    if(idx==0)
    {
        (*head)=(*head)->next;
        x=p->data;
        free(p);
        if(*head) (*head)->prev=NULL;
    }
    else
    {
        for(int i=0;i<idx;i++) p=p->next;
        x=p->data;
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
        free(p);
    } 
    return x;
}

void display(struct Node* head)
{
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head=NULL;
    //put index of the place to be deleted or inserted.
    insert(&head,23,0);
    insert(&head,12,1);
    display(head);
    insert(&head,93,2);
    insert(&head,11,1);
    display(head);
    insert(&head,11,4);
    display(head);
    delete(&head,4);
    display(head);
    delete(&head,1);
    display(head);
    return 0;
}