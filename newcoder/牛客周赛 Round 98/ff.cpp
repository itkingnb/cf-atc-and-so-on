#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX; // 2147483647
int minint = INT_MIN; // -2147483648
long long maxll = LLONG_MAX; // 9223372036854775807
long long minll = LLONG_MIN; // -9223372036854775808

const ll mod = 998244353;

ll jc(ll n) {
    if (n == 1 || n == 0)
        return (ll)1;
    else
        return n * jc(n - 1);
}

void yes() {
    cout << "Yes";
}

void no() {
    cout << "No";
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

ll qpow(ll a, ll k, ll p) {
    ll res = 1;
    while (k) {
        if (k & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin>>n;
    ll m=qpow(81,mod-2,mod);
    ll b=qpow(9,mod-2,mod);
    ll c= qpow(99,mod-2,mod);
    ll a1=49*n%mod;
    ll p100=qpow(100,n,mod);
    ll a2=400*(p100-1+mod)%mod;
    a2=a2*c%mod;
    ll p10=qpow(10,n,mod);
    ll a3=280*(p10-1+mod)%mod;
    a3=a3*b%mod;
    ll ans=(a1+a2+a3)%mod;
    ans=ans*m%mod;
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
        cout << '\n';
    }
    return 0;
}