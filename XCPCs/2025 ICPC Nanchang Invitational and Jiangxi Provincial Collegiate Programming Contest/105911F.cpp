#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void yes(){
    cout<<"Yes";
}
void no(){
    cout<<"No";
}
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
ll qpow(ll a, ll k, ll p=maxll)
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
void solve(){
    int n,k;
    cin>>n>>k;
    double r0,c0,p,L,R;
    cin>>r0>>c0>>p>>L>>R;
    vector<double>r(n+1,L);
    r[0]=r0;
    vector<double>c(n+1);
    c[0]=c0;
    for(int i=0;i<k;i++){
        int pos;
        double v;
        cin>>pos>>v;
        r[pos]=v;
    }
    long double ans=0;
    for(int i=1;i<=n;i++){
        ans+=p*c[i-1]+(1-p)*r[i-1]-r[i];
        c[i]=p*c[i-1]+(1-p)*r[i-1];
    }
    cout<<fixed<<setprecision(10)<<ans;
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