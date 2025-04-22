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

void combinationSum(int idx,int tot,vector<int>&nums,vector<int>play,vector<vector<int>>&res,int target){
    if(tot==target){
        res.push_back(play);
        return;
    }
    if(tot>target || idx>=nums.size()){
        return;
    }
    play.push_back(nums[idx]); //take
    combinationSum(idx+1,tot+nums[idx],nums,play,res,target);
    play.pop_back();
    while(idx+1<nums.size() && nums[idx+1]==nums[idx]) idx++;  // to remove dups
    combinationSum(idx+1,tot,nums,play,res,target);  //nottake
}
void solve()
{
    vector<int>nums{1,2,3,1,5};
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;
    combinationSum(0,0,nums,vector<int>{},res,5);
    for(auto&it:res){
        give(it,it.size());
    }

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

