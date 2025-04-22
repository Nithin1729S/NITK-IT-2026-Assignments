#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<ctype.h>

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

void display(struct Node* head)
{
    while(head)
    {
        printf("%c",head->data);
        head=head->next;
    }
    printf("\n");
}

bool isPalindrome(struct Node  *head)
{
    struct Node *start=head;
    struct Node *end=head;
    if(start==NULL || start->next==NULL) return true;
    while(end->next)
    {
        end=end->next;
    }
    while(start!=end)
    {
        if(start->data != end->data) return false;
        if(start->next==end) break;
        start=start->next;
        end=end->prev;
    } 
    return true;
}


int main() {
    struct Node* head = NULL;
    printf("Enter the String: ");
    
    char ele;
    int count = 0;
    
    while (1) {
        ele = tolower(getchar()); 
        if (ele == '\n') {
            break;
        }
        insert(&head, ele, count);
        count++;
    }

    if (isPalindrome(head)) {
        printf("\nThe Entered String is a Palindrome.\n");
    } else {
        printf("The entered string is not a Palindrome.\n");
    }

    return 0;
}