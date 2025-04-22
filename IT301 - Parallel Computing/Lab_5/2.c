#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

typedef struct Node{
    int data;
    struct Node*next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverseNode(Node* node) {
    if (node == NULL) return;
    printf("%d -> ", node->data);
    #pragma omp task
    {
        traverseNode(node->next);
    }
    #pragma omp taskwait
}

void traverseLinkedList(Node* head) {
    if (head == NULL) return;
    #pragma omp parallel
    {
        #pragma omp single
        {
            traverseNode(head);
        }
    }
}



int main()
{
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    printf("Linked list traversal: ");
    omp_set_num_threads(2);
    traverseLinkedList(head);
    printf("NULL\n");
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    return 0;
}

