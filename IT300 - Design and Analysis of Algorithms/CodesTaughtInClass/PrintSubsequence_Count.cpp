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

bool func(int idx,vector<int>&ds,vector<int>&nums,int sum,int n,int target){
    if(idx==n){
        if(sum==target){
            for(auto&it:ds)
            {
                cout<<it<<" ";
            }
            return true;
        }else{
            return false;
        }
    }
    ds.push_back(nums[idx]);
    sum+=nums[idx];
    if(func(idx+1,ds,nums,sum,n,target)==true){
        return true;
    }
    ds.pop_back();
    sum-=nums[idx];
    if(func(idx+1,ds,nums,sum,n,target)==true){
        return true;
    }
    return false;
}

int countSubsequences(int idx, vector<int>& nums, int sum, int n, int target) {
    if (idx == n) {
        if (sum == target) {
            return 1; 
        }
        return 0;  
    }

    sum += nums[idx];
    int includeCount = countSubsequences(idx + 1,nums, sum, n, target);
    
    sum -= nums[idx];

    int excludeCount = countSubsequences(idx + 1,nums, sum, n, target);
    return includeCount + excludeCount;
}

void solve()
{
        vector<int>nums{9,10,1};
        vector<int>res;
        //func(0,res,nums,0,5,3);
        cout<<countSubsequences(0,nums,0,3,19)<<endl;
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

