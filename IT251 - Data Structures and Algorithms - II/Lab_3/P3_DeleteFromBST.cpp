//This code creates a BST by taking input from users and takes a input on which element is to be 
//deleted and deletes it...simultaneoulsy showing the inorder traversal
#include<bits/stdc++.h>
using namespace std;

//Tree Node Struture
struct TreeNode
{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

//Funtion to insert elements into BST
TreeNode*insert(TreeNode*root,int key)
{
    TreeNode*temp=NULL;
    if(root==NULL)
    {
        temp=new TreeNode(key);
        return temp;
    }
    if(key<root->val) root->left=insert(root->left,key);
    else if(key>root->val) root->right=insert(root->right,key);
    return root;
}

//Function to search for a key in a BST
TreeNode*Search(TreeNode*root,int key)
{
    TreeNode*temp=root;
    while(temp)
    {
        if(key==temp->val) return temp;
        else if(key<temp->val) temp=temp->left;
        else temp=temp->right;
    }
    return NULL;
}

//function to calculate the height of the BST
int height(TreeNode* root)
{
    int x=0,y=0;
    if(root==NULL) return 0;
    x=height(root->left);
    y=height(root->right);
    if(x>y) return x+1;
    else return y+1;
}

//Funciton to find out the inorder predecessor
TreeNode* InPre(TreeNode*p )
{
    while(p && p->right!=NULL)
        p=p->right;
    return p;
}

//Function to find out the inorder successor
TreeNode *InSucc(TreeNode*p)
{
    while(p && p->left!=NULL)
    {
        p=p->left;
    }
    return p;
}

//The funcion to delete a node from bst
TreeNode*Delete(TreeNode*root,int key)
{
    TreeNode*q=NULL;
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
    if(key<root->val) root->left=Delete(root->left,key);
    else if(key>root->val) root->right=Delete(root->right,key);
    else
    {
        //if height in left is more that we will delete inorder predecessor
        //doing this the BST will maintain same height everywhere almost!!
        if(height(root->left)>height(root->right))
        {
            q=InPre(root->left);
            root->val=q->val;
            root->left=Delete(root->left,q->val);
        }
        //else we go with inorder successor
        else
        {
            q=InSucc(root->right);
            root->val=q->val;
            root->right=Delete(root->right,q->val);
        }
    }
    return root;
}

//Function to inorder travverse the tree
void inorder(TreeNode*root)
{
    if(root)
    {
        inorder(root->left);
        cout<<(root->val)<<" ";
        inorder(root->right);
    }
}


int main()
{
    TreeNode*bst1=NULL;
    int n;
    cout<<"Enter the number of elements to be inserted in the BST:";
    cin>>n;
    cout<<"Enter the elements of the BST seperated by spaces:";
    for(int i=0;i<n;i++)
    {
        int n;
        cin>>n;
        bst1=insert(bst1,n);
    }
    cout<<"The Inorder traversal of the BST: ";
    inorder(bst1);
    cout<<"\nEnter the element to be deleted from the BST: ";
    int ele;
    cin>>ele;
    if(Search(bst1,ele)==NULL)
    {
        cout<<"The element "<<ele<<" is absent.";
    }
    else
    {
        bst1=Delete(bst1,ele);
    }
    cout<<"The Inorder traversal of the BST after deletion: ";
    inorder(bst1);
    return 0;


    // bst1=insert(bst1,50);
    // bst1=insert(bst1,10);
    // bst1=insert(bst1,40);
    // bst1=insert(bst1,20);
    // bst1=insert(bst1,30);

    //bst1=delete(bst1,50);

    
}

