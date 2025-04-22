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


int phi(int n, vector<int>& res) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {  // Only consider distinct prime factors
            res.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;  
        }
    }
    if (n > 1) { 
        res.push_back(n);
        result -= result / n;
    }
    return result;
}

vector<int> coprimes(int n) {
    vector<int> coprimeNumbers;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) { 
            coprimeNumbers.push_back(i);
        }
    }
    return coprimeNumbers;
}

void solve() {
    vector<int> res;
    int n = 123456;

    cout << "Euler Totient Function (ϕ(" << n << ")) = " << phi(n, res) << endl;

    cout << "Prime Factors of " << n << ": ";
    for (int p : res) {
        cout << p << " ";
    }
    cout << endl;
}


int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    fast_io;
    solve();
    return 0;
}

