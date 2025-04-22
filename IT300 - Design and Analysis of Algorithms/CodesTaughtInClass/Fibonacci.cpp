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
#define f0(i,n) for(int i = 0; i < n; i++)
#define test int t;cin>>t;while(t--)
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;


int func(int idx,vector<int>&dp){
    if(idx==0 || idx==1 ) return 1;
    if(dp[idx]!=-1) return dp[idx];
    return dp[idx]=func(idx-1,dp)+func(idx-2,dp);
}

int tabulation(int idx){
    vector<int>dp(idx+1,-1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=idx;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    give(dp,idx+1);
    return dp[idx];
}
void solve()
{
    vector<int>dp(1000,-1);
    cout<<tabulation(14)<<endl;
    //cout<<func(14,dp)<<endl;
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

