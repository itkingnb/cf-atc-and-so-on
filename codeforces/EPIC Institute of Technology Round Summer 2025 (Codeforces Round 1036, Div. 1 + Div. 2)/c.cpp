#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
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
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
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
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // for(int i=1;i<n;i++){
    //     cout<<gcd(a[i],a[i-1])<<' ';
    //     cout<<a[i-1]/gcd(a[i],a[i-1])<<' '<<a[i]/gcd(a[i],a[i-1])<<'\n';
    //     // return ;
    // }
    // return ;
    ll ans=1;
    // bool ok=false;
    for(int i=1;i<n;i++){
        ll g=gcd(a[i],a[i-1]);
        ans=lcm(ans,a[i-1]/g);
        // cout<<g<<' ';
    }
    cout<<ans;
    // ll g=0;
    // for(int i=0;i<n;i++){
    //     g=gcd(g,a[i]);
    // }
    // ll ans=0;
    // for(int i=0;i<n;i++){
    //     a[i]/=g;
    //     // cout<<a[i]<<' ';
    // }
    // // bool ok=0;
    // vector<ll>t;
    // for(int i=0;i<n-1;i++){
    //     if(a[i+1]%a[i]!=0){
    //         t.push_back(a[i]);
    //     }
    // }
    // g=0;
    // for(int i=0;i<t.size();i++){
    //     g=gcd(g,t[i]);
    // }
    // g==0?cout<<1:cout<<g;
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