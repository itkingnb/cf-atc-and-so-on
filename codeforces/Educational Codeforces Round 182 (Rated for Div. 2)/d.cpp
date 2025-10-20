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
    int n;
    ll y;
    cin>>n>>y;
    vector<int>a(n);
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    vector<int>cnt(mx+1);
    vector<int>pre(mx+1);
    for(int i=0;i<n;i++){
        pre[a[i]]++;
        cnt[a[i]]++;
    }
    for(int i=1;i<=mx;i++){
        pre[i]=pre[i-1]+cnt[i];
    }
    ll ans=minll;
    for(int x=2;x<=max(2,mx);x++){
        ll res=0;
        int t=1;
        for(int i=0;i<=mx;i+=x){
            res+=1LL*(pre[min(mx,i+x)]-pre[i])*t;
            ll need=(pre[min(mx,i+x)]-pre[i])-cnt[t];
            res-=max(0LL,need)*y;
            t++;
        }
        ans=max(ans,res);
    }
    cout<<ans;
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