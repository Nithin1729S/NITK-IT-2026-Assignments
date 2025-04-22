#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define fr first
#define sc second
#define INF LLONG_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define int long long
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f0(i,n)  for(int i=0;i<(int)n;i++)
#define f1(i,n)  for(int i=1;i<=(int)n;i++)
#define test int t;cin>>t;while(t--)
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << nl;

pair<int,int>divide(vector<int>nums,int lo,int hi){
    if(lo==hi){
        return {nums[lo],nums[hi]};
    }
    int mid=(lo+hi)/2;
    int max1;
    int max2;
    int min1;
    int min2;
    pair<int,int>pr1;
    pair<int,int>pr2;
    pr1=divide(nums,lo,mid);
    pr2=divide(nums,mid+1,hi);
    return {max(pr1.first,pr2.first),min(pr1.second,pr2.second)};
}
void solve()
{
    vector<int>nums{3,4,3,10,-9};
    pair<int,int>pr;
    pr=divide(nums,0,nums.size()-1);
    cout<<pr.first<<" "<<pr.second<<endl;
    cout<<(pr.first-pr.second)<<endl;
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

