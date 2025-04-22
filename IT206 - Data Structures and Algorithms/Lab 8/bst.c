#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lChild;
    struct Node *rChild;
};

struct Node *insert(struct Node *p, int key)
{
    if (p == NULL)
    {
        struct Node *temp = NULL;
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = key;
        temp->lChild = temp->rChild = NULL;
        return temp;
    }
    if (key > p->data)
        p->rChild = insert(p->rChild, key);
    else if (key < p->data)
        p->lChild = insert(p->lChild, key);
    return p;
}

int height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == NULL)
        return 0;
    x = height(root->lChild);
    y = height(root->rChild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

struct Node *InPre(struct Node *p)
{
    while (p && p->rChild != NULL)
        p = p->rChild;
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while (p && p->lChild != NULL)
    {
        p = p->lChild;
    }
    return p;
}

struct Node *delete(struct Node *root, int key)
{
    struct Node *q = NULL;
    if (root == NULL)
        return NULL;
    if (root->lChild == NULL && root->rChild == NULL) // ie a leaf node
    {
        free(root);
        return NULL;
    }
    if (key < root->data)
        root->lChild = delete (root->lChild, key);
    else if (key > root->data)
        root->rChild = delete (root->rChild, key);
    else // ie when the key is found
    {
        if (height(root->lChild) > height(root->rChild))
        {
            q = InPre(root->lChild);
            root->data = q->data;
            root->lChild = delete (root->lChild, q->data);
        }
        else
        {
            q = InSucc(root->rChild);
            root->data = q->data;
            root->rChild = delete (root->rChild, q->data);
        }
    }
    return root;
}

void inOrder(struct Node *p)
{
    if (p)
    {
        inOrder(p->lChild);
        printf("%d ", p->data);
        inOrder(p->rChild);
    }
}

int main()
{
    struct Node *bst1 = NULL;
    int n;
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &n);
    printf("Enter the elements to insert in the BST: ");
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        bst1 = insert(bst1, x);
    }
    printf("The Inorder Traversal of the BST: ");
    inOrder(bst1);
    int del;
    printf("\nEnter the number you want to delete from the BST: ");
    scanf("%d", &del);
    bst1 = delete (bst1, del);
    printf("The Inorder Traversal of the BST: ");
    inOrder(bst1);
    return 0;
}