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
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f0(i,n)  for(int i=0;i<(int)n;i++)
#define f1(i,n)  for(int i=1;i<=(int)n;i++)
#define test int t;cin>>t;while(t--)
#define clr(x) memset(x,0,sizeof(x))
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;


int partition(vector<int>&arr,int l,int r)
{
    int randIdx=l+rand()%(r-l+1);
    swap(arr[randIdx],arr[r]);
    int pivot=arr[r];
    int i=l;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<=pivot)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;
}

void quickSort(vector<int>&arr,int l,int r){
    if(l<r){
        int h=partition(arr,l,r);
        quickSort(arr,l,h-1);
        quickSort(arr,h+1,r);
    }
}

void solve()
{
    vector<int>arr{2,3,11,2,22,9,0,11};
    int n=arr.size();
    quickSort(arr,0,n-1);
    give(arr,arr.size());
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

