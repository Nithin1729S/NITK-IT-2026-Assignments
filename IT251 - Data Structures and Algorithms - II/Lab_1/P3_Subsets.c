//This program uses inclusion exclusion principle to find all subsets of the array in O(2^n) time complesity
#include<stdio.h>


//Function to print all subsets of the given array
void PASS(int arr[],int n,int idx,int temp[],int sz)
{
    if(idx==n) //once index goes out of bound print all elements of temp array
    {
        for(int i=0;i<sz;i++)
        {
            printf("%d ",temp[i]);
        }
        printf("\n");
    }
    else
    {
        temp[sz]=arr[idx];             //filling temp array with the decided idx'th element of arr array
        PASS(arr,n,idx+1,temp,sz+1);   // decision to include the idx'th element of arr in temp array
        PASS(arr,n,idx+1,temp,sz);     //decision to not inclue the idx'th element of arr in temp array
    }
}


//Function to print all subsets of the given array which has a in it
void PASSM(int arr[],int n,int idx,int temp[],int sz,int a)
{
    
    if(idx==n) //once index goes out of bound print all elements of temp array
    {
        int containM=0;
        for(int i=0;i<sz;i++)
        {
            if(temp[i]==a)
            {
                containM=1;
                break;
            }
        }
        if(containM)
        {
            for(int i=0;i<sz;i++)
            {
            printf("%d ",temp[i]);
            }
            printf("\n");
        }
        
    }
    else
    {
        temp[sz]=arr[idx];             //filling temp array with the decided idx'th element of arr array
        PASSM(arr,n,idx+1,temp,sz+1,a);   // decision to include the idx'th element of arr in temp array
        PASSM(arr,n,idx+1,temp,sz,a);     //decision to not inclue the idx'th element of arr in temp array
    }
}



//Function to print all subsets of the given array which has a and b in it 
void PASSM2(int arr[],int n,int idx,int temp[],int sz,int a,int b)
{
    if(idx==n) //once index goes out of bound print all elements of temp array
    {
        int containM=0;
        for(int i=0;i<sz;i++)
        {
            if(temp[i]==a)
            {
                containM++;
                break;
            }
        }
        for(int i=0;i<sz;i++)
        {
            if(temp[i]==b)
            {
                containM++;
                break;
            }
        }
        if(containM==2)
        {
            for(int i=0;i<sz;i++)
            {
            printf("%d ",temp[i]);
            }
            printf("\n");
        }
        
    }
    else
    {
        temp[sz]=arr[idx];             
        PASSM2(arr,n,idx+1,temp,sz+1,a,b);   
        PASSM2(arr,n,idx+1,temp,sz,a,b);     
    }
}

int main()
{
    int arr[100];
    int temp[100];
    int a;
    int b;
    int x;
    int n;
    printf("Enter the number of elements of the array: ");    
    scanf("%d",&n);
    printf("Enter the elements:");    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    printf("All subsets:\n");
    PASS(arr,n,0,temp,0);  //To print all subsets of the array
    printf("\n");

    printf("Enter a and b values: ");
    scanf("%d %d",&a,&b);

    printf("All subsets which contain %d:\n",a);
    PASSM(arr,n,0,temp,0,a);  //To print all subsets of the array which contain a 
    printf("\n");

    printf("All subsets which contain %d and %d:\n",a,b);
    PASSM2(arr,n,0,temp,0,a,b);  //To print all subsets of the array which contain both a and b
    printf("\n");
    
    
    return 0;
    
}