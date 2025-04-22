//Maximum Weighted Independent Set 
// Time Complexity O(n)
// Space Complexity O(n)

#include<bits/stdc++.h>
using namespace std;

long long mwis(vector<long long>&graph){
    long long  n=graph.size();
    vector<long long >dp(n+1,0);
    dp[0]=0;
    if(n>0) dp[1]=graph[0];
   

    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+graph[i-1]);
       
    }
    cout<<"Max Weight of Independent Subset is "<<dp[n]<<endl;
    cout<<endl;
    vector<long long>st;
    int i=dp.size()-1;
    while(i>=1){
        if(dp[i-1]>=dp[i-2]+graph[i-1]){
            i--;
        }else{
            st.push_back(i);
            i-=2;
        }
    }

    cout<<"Vertices Included: ";
    reverse(st.begin(),st.end());
    for(auto&it:st){
        cout<<it<<" ";
    }
    cout<<endl;
    return dp[graph.size()];
}


void solve()
{
    long long n;
    cin>>n;
    vector<long long>graph;
    for(int i=0;i<n;i++){
        long long v;
        cin>>v;
        graph.push_back(v);
    }
    
    mwis(graph);
    
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    solve();
    return 0;
}

