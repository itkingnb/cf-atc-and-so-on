#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
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
ll qpow(ll a, ll k, ll p=maxll)
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
    vector<vector<int>>adj(n+1);
    vector<int>deg(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;deg[v]++;
    }
    bool ok=1;
    for(int i=1;i<=n;i++){
        if(deg[i]>=3){
            ok=0;
            break;
        }
    }
    if(ok){
        cout<<-1;
        return ;
    }
    int mx=0;
    vector<int>vis(n+1,0);
    vector<int>fa(n+1,0),deep(n+1,0);
    auto dfs=[&](auto &&self,int x,int p)->void{
        fa[x]=p;
        deep[x]=deep[p]+1;
        mx=max(mx,deep[x]);
        for(auto u:adj[x]){
            if(!vis[u]){
                vis[u]=1;
                self(self,u,x);
            }
        }
    };
    int root=-1;
    vis[1]=1;
    dfs(dfs,1,0);
    for(int i=1;i<=n;i++){
        if(deep[i]==mx){
            root=i;
            break;
        }
    }
    mx=0;
    // memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    vis[root]=1;
    dfs(dfs,root,0);
    for(int i=1;i<=n;i++){
        if(deep[i]==mx){
            root=i;
            break;
        }
    }
    vector<int>vis2(n+1,0);
    vector<int>path;
    while(root){
        path.push_back(root);
        vis2[root]=1;
        root=fa[root];
    }
    // cerr<<mx<<'\n';
    // for(auto x:path){
    //     cerr<<x<<'\n';
    // }
    int a=0,b=0,c=0;
    for(int i=0;i<path.size();i++){
        if(deg[path[i]]>=3){
            b=path[i];
            a=i?path[i-1]:path[i+1];
            for(auto x:adj[b]){
                if(x!=a&&!vis2[x]){
                    cout<<a<<" "<<b<<" "<<x;
                    return ;
                }
            }
        }
    }
    // cout<<a<<" "<<b<<" "<<c;
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