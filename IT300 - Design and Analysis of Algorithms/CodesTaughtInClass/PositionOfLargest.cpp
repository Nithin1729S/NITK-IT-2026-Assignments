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
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;

int partition(vector<int>& arr, int l, int r) {
    int randIdx = l + rand() % (r - l + 1);
    swap(arr[randIdx], arr[r]);
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int quickSelect(vector<int>& arr, int l, int r, int k) {
    if (l <= r) {
        int pivotIndex = partition(arr, l, r);
        if (pivotIndex == k)
            return arr[k];
        if (pivotIndex > k)
            return quickSelect(arr, l, pivotIndex - 1, k);
        return quickSelect(arr, pivotIndex + 1, r, k);
    }
    return INT_MAX;
}


void solve()
{
    vector<int>arr{1,5,6,2,3,4,88,0,4,5};
    int n=arr.size();
    cout<<quickSelect(arr,0,n-1,n-1)<<endl;
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

