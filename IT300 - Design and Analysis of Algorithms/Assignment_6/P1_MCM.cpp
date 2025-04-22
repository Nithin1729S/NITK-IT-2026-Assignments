#include<bits/stdc++.h>
using namespace std;

void parenthesis(int i,int j,vector<vector<int>>&splits){
    if(i==j ){
        cout<<"A"<<i;
    }else{
        cout<<"(";
        parenthesis(i,splits[i][j],splits);
        parenthesis(splits[i][j]+1,j,splits);
        cout<<")";
    }
}
int helper(vector<int>&arr, int n) {
        vector<vector<int>> dp (n , vector<int> (n , -1)) ;
        vector<vector<int>> splits (n , vector<int> (n , -1)) ;
        for(int i =0 ; i < n ; i++) {
            dp[i][i] = 0;
        }
        for(int i = n -1 ; i >= 1 ; i--) {
            for(int j = i +1 ; j < n ; j++) {
                int mini = INT_MAX ;
                for(int k = i ; k < j ; k++) {
                    int curr = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]  ;
                    if(curr<mini){
                        mini=curr;
                        splits[i][j]=k;
                    }
                }
                dp[i][j] = mini ;
            }
        }
        cout<<"Optimal Parenthesis: ";
        parenthesis(1,n-1,splits);
        cout<<endl;
        cout<<"Minimum Cost: "<<dp[1][n-1];
        cout<<endl;
        return 0;
    }



void solve()
{
    int n;
    vector<int>dims;
    cout<<"Enter no of elements in dims :";
    cin>>n;
    cout<<"Enter dims: ";
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        dims.push_back(ele);
    }
    helper(dims,dims.size());

}

int32_t main()
{
    solve();
    return 0;
}
