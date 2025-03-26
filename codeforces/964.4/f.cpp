#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
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
ll jcc[200010];
ll mod=1e9+7;
ll jc(int n){
    if(jcc[n])
    return jcc[n];
    if(n==1||n==0)
    return jcc[n]=(ll)1;
    else
    return jcc[n]=n*jc(n-1)%mod;

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
ll c(ll n,ll m){
    return jc(n)*qpow(jc(m)*jc(n-m)%mod,mod-2,mod)%mod;
}
void solve(){
    int n,k;
    cin>>n>>k;
    ll c1=0,c0=0;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        if(m)
        c1++;
        else
        c0++;
    }
    ll ans=0;
    for(int i=(k)/2+1;i<=min(c1,(ll)k);i++){
        if(i+c0<k)
        continue;
        else
        ans=(ans+(c(c1,i))*(c(c0,k-i)))%mod;
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