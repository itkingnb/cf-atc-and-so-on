#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll qpow(ll a,ll k,ll mod){
    ll res=1;
    while(k){
        if(k&1){
            res=(ll)res*a%mod;
        }
        a=a*a%mod;
        k>>=1;
    }     
    return res;
}
// ll fac[100];
// ll c(ll n,ll m){
//     return fac[n]/(fac[m]*fac[n-m]);
// }
void solve(){
    // for(int i=2;i<=10;i++){
    //     ll res=0;
    //     for(int j=1;j<=i;j++){
    //         cout<<c(i,j)*j<<" ";
    //         res+=c(i,j)*j;
    //     }
    //     cout<<res<<"\n";
    // }
    // cout<<qpow(2,5,100);
    ll mod=998244353;
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    ll now=0;
    ll t=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        now++;
        ans+=((t+1)*qpow(2,n-now,mod))%mod*a[i];
        t=3*t+1;
        t%=mod;
        ans%=mod;
    }
    cout<<ans;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    // fac[0]=1;
    // for(int i=1;i<100;i++){
    //     fac[i]=fac[i-1]*i;
    // }
    while(t--){
        solve();
        cout<<'\n';
    }
}