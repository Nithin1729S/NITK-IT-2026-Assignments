#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test int t;cin>>t;while(t--)
#define f0(i,n) for(int i = 0; i < n; i++)
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;

int mwis(vector<int>&graph){
    int n=graph.size();
    vector<int>dp(n+1,0);
    dp[0]=0;
    if(n>0) dp[1]=graph[0];
   

    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+graph[i-1]);
       
    }
    cout<<"Max Weight Independent Subset is "<<dp[n]<<endl;

    cout<<endl;
    give(dp,graph.size()+1);

    vector<int>st;
    int i=dp.size()-1;
    while(i>=1){
        if(dp[i-1]>=dp[i-2]+graph[i-1]){
            i--;
        }else{
            st.push_back(graph[i-1]);
            i-=2;
        }
    }

    cout<<"Vertices Included: ";
    reverse(st.begin(),st.end());

    give(st,st.size());
    return dp[graph.size()];
}


void solve()
{
    vector<int>graph{5,3,1,7,2,4,6};
    mwis(graph);
    
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    fast_io;
    //test
        solve();
    return 0;
}

