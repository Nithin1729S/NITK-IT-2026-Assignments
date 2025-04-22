#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

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

struct Node* findMiddle(struct Node*head,struct Node*end)
{
    if(head==NULL) return NULL;
    struct Node *fast=head->next;
    struct Node *slow=head;
    while(fast!=end)
    {
        fast=fast->next;
        if(fast!=end)
        {
            fast=fast->next;
            slow=slow->next;
        }
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

struct Node* binarySearch(struct Node*head,int key)
{
    struct Node*first=head;
    struct Node*last=NULL;
    do
    {
        struct Node* mid=findMiddle(first,last);
        if(mid==NULL) return NULL;
        if(mid->data==key) return mid;
        else if(mid->data>key) last=mid;
        else first=mid->next;
    } while (last==NULL||last!=first);
    return NULL;
}

bool binarySearchArray(int arr[],int key,int n)
{
    int start=0;
    int last=n-1;
    while(start<=last)
    {
        int mid=(start+last)/2;
        if(arr[mid]==key) return true;
        else if(arr[mid]>key) last=mid-1;
        else start=mid+1;
    }
    return false;

}



int main()
{
    int n=0;
    int key=0;
    char choice;
    printf("Do you want to search in an Array(A) or linkedList(L).Enter 'L' or 'A': ");
    scanf("%c",&choice);
    if(choice=='L')
    {
        struct Node *ll1=NULL;
        printf("Enter the No. of elements in the linked list: ");
        scanf("%d",&n);
        printf("Enter the elements (Integers) seperated by spaces: ");
        while(n>0)
        {
            int num=0;
            scanf("%d",&num);
            insertLast(&ll1,num);
            n--;
        }
        printf("The entered linkedList: ");
        display(ll1);
        printf("\nEnter an element to search: ");
        scanf("%d",&key);
        if(binarySearch(ll1,key)==NULL) printf("%d is not present in the linkedList.\n",key);
        else printf("%d is present in the linkedList.\n",key);
        return 0;
    }
    else if(choice=='A')
    {
        printf("Enter the No. of elements in the array: ");
        scanf("%d",&n);
        int *arr=(int*)malloc(sizeof(int)*n);
        printf("Enter the elements seperated by spaces: ");
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        
        printf("The Array contains: ");
        for(int i=0;i<n;i++)
            printf("%d ",arr[i]);
        printf("\nEnter the element to be searched: ");
        scanf("%d",&key);
        if(binarySearchArray(arr,key,n)) printf("%d is present in the linkedList.\n",key);
        else printf("%d is not present in the linkedList.\n",key);
    }
    else
    {
        printf("Invalid Choice");
        return 0;
    }
}