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
    ll l,r,y;
    ll mod=1e9+7;
    cin>>l>>r>>y;
    auto get=[&](ll x,ll t,int n)->ll{
        x++;
        ll res=0;
        if(n==0){
            ll T=x/t;
            res+=t/2*T;
            res+=min(t/2,x%t);
        }else{
            ll T=x/t;
            res+=t/2*T;
            res+=max(0LL,x%t-t/2);
        }
        return res;
    };
    // cout<<get(8,8,0)-get(0,8,0)<<'\n';
    ll ans=0;
    for(int i=0;i<60;i++){
        if((y>>i)&1){
            ll cnt=get(r,(1LL<<(i+1)),0)-get(l-1,(1LL<<(i+1)),0);
            ans+=cnt*qpow(r-l+1,mod-2,mod)%mod;
            ans%=mod;
        }else{
            ll cnt=get(r,(1LL<<(i+1)),1)-get(l-1,(1LL<<(i+1)),1);
            ans+=cnt*qpow(r-l+1,mod-2,mod)%mod;
            ans%=mod;
        }
    }
    // cout<<get(1,8,0)<<'\n';
    cout<<ans%mod;
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