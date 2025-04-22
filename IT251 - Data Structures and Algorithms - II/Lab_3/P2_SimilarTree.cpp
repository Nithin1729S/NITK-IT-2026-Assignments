//This code creates two Binary Trees by taking input from user and checks whether the two trees
//are similar and also prints preorder traversal of the two trees
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

//fucntion to build binary trees
void createTree(TreeNode**root)
{
    queue<TreeNode*>q;  //a queue is needed to build a Binary tree
    TreeNode *p;
    TreeNode *t;
    int x;
    cout<<"Enter the root value of the binary tree: ";
    cin>>x;
    *root=new TreeNode(x);
    q.push(*root);
    while(!q.empty())
    {
        p=q.front();q.pop();
        printf("Enter left child of %d: ", p->val);
        scanf("%d", &x);
        if (x != -1)
        {
            t=new TreeNode(x);
            p->left= t;
            q.push(t);
        }
        printf("Enter right child of %d: ", p->val);
        scanf("%d", &x);
        if (x != -1)
        {
            t=new TreeNode(x);
            p->right= t;
            q.push(t);
        }

    }

}

//funciton to preorder the traverse the tree
void preorder(TreeNode*root)
{
    if(root)
    {
        cout<<(root->val)<<" ";
        preorder(root->left);
        preorder(root->right);
    }

}

//function to check if two trees are similar
bool isSameTree(TreeNode*p,TreeNode*q)
{
    if(p==NULL && q!=NULL) return false;
    if(p!=NULL && q==NULL) return false;
    if(p==NULL && q==NULL) return true;
    if(p->val==q->val) return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    return false;
}

//main function to test the above function
int main()
{   
    cout<<"Note:Enter -1 if child is not present"<<endl;
     cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Enter the elements of the first tree"<<endl;
    TreeNode*tree1=NULL;
    createTree(&tree1);
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Enter the elements of the second tree"<<endl;
    TreeNode*tree2=NULL;
    createTree(&tree2);

    cout<<"Preorder Traversal of the first tree:";
    preorder(tree1);
    cout<<"\nPreorder Traversal of the second tree:";
    preorder(tree2);

    if(isSameTree(tree1,tree2))
    {
        cout<<"\nThe two trees are similar.";
    }
    else
    {
        cout<<"\nThe two trees are not similar.";
    }
    return 0;

}
