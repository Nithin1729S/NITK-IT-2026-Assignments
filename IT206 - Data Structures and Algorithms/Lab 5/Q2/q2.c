#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
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

void insert(struct Node **head,char x,int idx)
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

void reverse(struct Node**head)
{
    struct Node *p=*head;
    struct Node *temp=NULL;
    while(p)
    {
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        p=p->prev;
    }
    if(temp) (*head)=temp->prev;
}

void display(struct Node* head)
{
    while(head)
    {
        printf("%c",head->data);
        head=head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    printf("Enter the string: ");
    
    char ele;
    int count=0;
    
    while (1) {
        ele = getchar();
        if (ele == '\n') {
            break;
        }
        insert(&head, ele, count);
        count++;
    }

    printf("The Entered String (before reversal) is: ");
    display(head);

    printf("The Entered String (after reversal) is: ");
    reverse(&head);
    display(head);

    return 0;
}