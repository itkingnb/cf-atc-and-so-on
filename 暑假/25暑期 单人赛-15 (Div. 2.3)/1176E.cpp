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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>ans(2);
    vector<vector<int>>adj(n);
    vector<bool>vis(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dep(n);
    auto dfs=[&](auto &&self,int x,int d)->void{
        // cerr<<x<<" "<<d<<"\n";
        ans[d&1].push_back(x+1);
        for(auto u:adj[x]){
            if(!vis[u]){
                vis[u]=1;
                self(self,u,d+1);
            }
        }
    };
    vis[0]=1;
    dfs(dfs,0,0);
    if(ans[0].size()>ans[1].size()){
        swap(ans[0],ans[1]);
    }
    cout<<ans[0].size()<<'\n';
    for(auto x:ans[0]){
        cout<<x<<" ";
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