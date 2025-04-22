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


void rotate90Anticlockwise(vector<vector<int>>& dp) {
    int n = dp.size();
    int m = dp[0].size();
    vector<vector<int>> rotated(m, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rotated[m - j - 1][i] = dp[i][j];
        }
    }
    dp = rotated;
}

int knapsack(int idx,int currSz,vector<int>&values,vector<int>&sz,vector<vector<int>>&dp){
    if(idx==0){
        if(currSz>=sz[0]){
            return values[0];
        }else{
            return 0;
        }
    }
    if(dp[idx][currSz]!=-1) return dp[idx][currSz];
    int take=-1e9;
    int nottake=-1e9;
    nottake=0+knapsack(idx-1,currSz,values,sz,dp);
    if(currSz>=sz[idx]){
        take=values[idx]+knapsack(idx-1,currSz-sz[idx],values,sz,dp);
    }
    return dp[idx][currSz]=max(take,nottake);
}

void solve()
{
    vector<int>values{1,2,3,4,5};
    vector<int>sz{1,3,2,5,4};
    int maxCap=9;
    // vector<vector<int>>dp(values.size(),vector<int>(maxCap+1,-1));
    // cout<<knapsack(values.size()-1,6,values,sz,dp);
    vector<vector<int>>dp(values.size(),vector<int>(maxCap+1,0));
    for(int cap=0;cap<=maxCap;cap++)
    {
        if(sz[0]<=cap) dp[0][cap]=values[0];
    }

    for(int idx=1;idx<values.size();idx++)
    {
        for(int currSz=0;currSz<=maxCap;currSz++)
        {
            int nottake=-1e9;
            int take=-1e9;
            nottake=0+dp[idx-1][currSz];
            if(currSz>=sz[idx]){
                take=values[idx]+dp[idx-1][currSz-sz[idx]];
            }
            dp[idx][currSz]=max(take,nottake);
        }
    }
    cout<<dp[values.size()-1][maxCap]<<endl;
    //rotate90Anticlockwise(dp);
    for(auto&it:dp){
        give(it,it.size());
    }

    vector<int>sack;
    int currSz=maxCap;
    for(int idx=values.size()-1;idx>0;idx--){
        if(sz[idx]<=currSz && dp[idx][currSz]==dp[idx-1][currSz-sz[idx]]+values[idx]){
            sack.push_back(values[idx]);
            currSz-=sz[idx];
        }
    }
    if (currSz >= sz[0] && dp[0][currSz] == values[0]) {
        sack.push_back(values[0]);
    }

    give(sack,sack.size());

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

