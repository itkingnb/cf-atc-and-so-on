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
    ll x,y;
    cin>>x>>y;
    ll res=x*y/__gcd(x,y)/__gcd(x,y);
    cout<<1<<" "<<res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}