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
#define N 5010
vector<ll>prim;
int ok[N];
void get_prim(){
    for(ll i=2;i<N;i++){
        if(!ok[i])
        prim.push_back(i);
        for(int j=0;j<prim.size();j++){
            if(i*prim[j]<N)
            ok[i*prim[j]]=true;
            else
            break;
            if(i%prim[j]==0)
            break;
        }
    }
}
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
    int n,m;
    cin>>n>>m;
    if(m==1){
        cout<<n-1;
        return;
    }
    ll ans=0;
    for(int i=0;i<prim.size();i++){
        ll cnt=n/prim[i];
        if(cnt>=m){
            ans+=getC(cnt,m);
            ans%=mod;
        }
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    get_prim();
    init();
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}