#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100010
ll mod= 1e9+7;
ll f[N],g[N];//f存模意义下的阶乘，g存模意义下的阶乘逆元
ll qpow(ll a, ll k){
    ll res=1;
    while(k){
        if (k&1)
            res=(ll)res*a%mod;
        a=(ll)a*a%mod;
        k>>=1;
    }
    return res;
}
void init(){
    f[0]=g[0]=1;
    for(int i=1;i<N;i++){
        f[i]=f[i-1]*i%mod;
        g[i]=g[i-1]*qpow(i,mod-2)%mod;
    }
}
ll getC(ll n,ll m){//n在下
    return f[n]*g[m]%mod*g[n-m]%mod;
}
void solve(){
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}