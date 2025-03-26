#include<bits/stdc++.h>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
ll jc(ll n){
    if(n==1||n==0)
    return (ll)1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes";
}
void no(){
    cout<<"No";
}
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
ll qpow(ll a, ll k, ll p)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
using namespace std;

const int N = 1e6 + 10;
ll mod = 2;
// typedef long long LL;
ll f[N], g[N];
ll quick_power(ll a, ll b, ll p)
{
    int res=1;
    while (b)
    {
        if (b&1) res = res * a % p;
        a =a*a % p;
        b >>= 1;
    }
    return res%p;
}
void init()
{
    f[0] = g[0] = 1;
    for (int i=1; i < N; i ++)  //打表记录！
    {
        f[i] = f[i-1] * i % mod;
        g[i] =g[i-1] * quick_power(i, mod-2, mod) % mod;
    }
}
void solve(){
    init();
    ll n,k;
    cin>>n>>k;
    n--;
    for(int j=0;j<n+1;j++){
        if((f[n-1]*g[j]%mod * g[n-1-j]%mod)&1){
            cout<<k<<' ';
        }else{
            cout<<0<<' ';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}