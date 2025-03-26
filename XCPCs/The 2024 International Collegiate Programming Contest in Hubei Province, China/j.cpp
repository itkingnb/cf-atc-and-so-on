#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll qpow(ll a,ll x,ll mod){
    ll res=1;
    while(x){
        if(x&1)
            res=res*a%mod;
        a*=a;
        a%=mod;
        x>>=1;
    }
    return res;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    ll mod=998244353;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll mid=accumulate(a.begin(),a.end(),0LL);
    mid%=mod;
    ll gc=__gcd(mid,n);
    mid/=gc;
    n/=gc;
    cout<<mid*qpow(n,mod-2,mod)%mod;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}