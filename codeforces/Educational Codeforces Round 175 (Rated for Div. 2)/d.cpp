#include<bits/stdc++.h>
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
    int n;
    cin>>n;
    int fa=0;
    vector<vector<int>>adj(n+10);
    vector<int>dad(n+10,0);
    for(int i=2;i<=n;i++){
        cin>>fa;
        adj[fa].emplace_back(i);
        dad[i]=fa;
    }
    ll mod=998244353;
    vector<int>depth(n+10,0);
    depth[0]=0;
    map<int,vector<int>>mp;
    // map<int,int>cnt;
    int mxd=0;
    auto dfs=[&](auto &&self,int x,int fa)->void{
        depth[x]=depth[fa]+1;
        mxd=max(depth[x],mxd);
        // cnt[depth[x]]++;
        // cerr<<depth[x]<<'\n';
        mp[depth[x]].emplace_back(x);
        for(auto u:adj[x]){
            self(self,u,x);
        }
    };
    dfs(dfs,1,0);
    vector<ll>ans(n+10,1);
    ans[1]=1;
    ll tot=0;
    while(mxd){
        if(mxd==1){
            ans[1]+=2*tot;
            break;
        }
        ll temp=0;
        for(auto u:mp[mxd]){
            ans[u]+=tot;
            ans[u]%=mod;
            ans[dad[u]]-=ans[u];
            ans[dad[u]]+=mod;
            ans[dad[u]]%=mod;
            temp+=ans[u];
            temp%=mod;
        }
        tot=temp;
        mxd--;
    }
    cout<<ans[1]%mod;
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