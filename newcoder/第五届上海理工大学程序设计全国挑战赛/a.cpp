#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
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
    vector<ll>a(n+1,0);
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<pii>>adj(n+1);
    vector<bool>inf(n+10,0);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        if(2*w<a[u]+a[v]){
            inf[u]=inf[u]|(a[u]>=w);
            inf[v]=inf[v]|(a[v]>=w);
        }
    }
    inf[1]=0;
    vector<bool>vis(n+10,0);
    vis[1]=1;
    vector<ll>ans(n+10,0);
    auto dfs=[&](auto &&self,int x,ll now,ll duo)->void{
        ans[x]=now;
        for(auto u:adj[x]){
            if(!vis[u.first]){
                vis[u.first]=1;
                self(self,u.first,now+max(u.second-duo-a[x],0LL),max(0LL,a[x]+duo-u.second));
            }
        }
    };
    dfs(dfs,1,0,0);
    ll mincost=1e18;
    for(int i=2;i<=n;i++){
        if(inf[i]){
            mincost=min(mincost,ans[i]);
        }
    }
    for(int i=2;i<=n;i++){
        cout<<min(ans[i],mincost)<<" ";
    }

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