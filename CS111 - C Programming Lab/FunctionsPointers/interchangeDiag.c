#include<stdio.h>

void displayMat(int mat[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void interchangeDiag(int mat[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        int temp=mat[i][i];
        mat[i][i]=mat[i][n-i-1];
        mat[i][n-i-1]=temp;
    }
}

int main()
{
    int mat[100][100];
    int n;
    printf("Enter the size of matrix: ");
    scanf("%d",&n);
    printf("Enter the elements of matrix rowwise:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    interchangeDiag(mat,n);
    displayMat(mat,n);

    return 0;


}