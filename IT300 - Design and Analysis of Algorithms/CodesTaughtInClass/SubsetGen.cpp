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

void func(int idx,vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int k){
    if(idx==nums.size()){
        ans.push_back(temp);
        return;
    }
    if (idx == k) {
        temp.push_back(nums[k]);
        func(idx + 1,nums,ans,temp,k);
        return;  // No need to exclude element at index `k`
    }
    temp.push_back(nums[idx]);
    func(idx+1,nums,ans,temp,k);
    temp.pop_back();
    while(idx+1<nums.size() && nums[idx+1]==nums[idx]) idx++;
    func(idx+1,nums,ans,temp,k);
    return;
}
void solve()
{
    vector<int>nums{1,2,3,1,5};
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;
    func(0,nums,res,vector<int>{},4);
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

