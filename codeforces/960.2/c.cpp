#include<iostream>
#include<cmath>
#include<cstring>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#define ll long long
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
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
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
void solve(){
    ll n;
    ll ans=0;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n,0);
    vector<ll>c(n,0);
    int hash[200010]={0};
    for(auto&i:a){
    cin>>i;
    ans+=i;
    }
    ll mx=0;
    for(int i=0;i<n;i++){
        hash[a[i]]++;
        if(hash[a[i]]>1)
        mx=max(mx,a[i]);
        b[i]=mx;
    }
    mx=0;
    memset(hash,0,sizeof hash);
    for(int i=0;i<n;i++){
        ans+=b[i];
        hash[b[i]]++;
        if(hash[b[i]]>1)
        mx=max(mx,b[i]);
        c[i]=mx;
    }
    for(int i=1;i<n;i++){
        ans+=(ll)(n-i)*c[i];
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}