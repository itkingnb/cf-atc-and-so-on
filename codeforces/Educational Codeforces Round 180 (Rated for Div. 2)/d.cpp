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
    int n;
    cin>>n;
    vector<vector<int>>adj(n+10);
    vector<int>in(n+10,0);
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    int root=-1;
    for(int i=1;i<=n;i++){
        if(in[i]==2){
            root=i;
            break;
        }
    }
    if(root==-1){
        no();
        return ;
    }
    yes();
    cout<<'\n';
    vector<bool>vis(n+10,0);
    vis[root]=1;
    auto dfs=[&](auto &&self,int x,int op)->void{
        for(int i=0;i<adj[x].size();i++){
            if(vis[adj[x][i]]){
                continue;
            }
            vis[adj[x][i]]=1;
            if(op==1){
                cout<<x<<" "<<adj[x][i]<<'\n';
                self(self,adj[x][i],0);
            }else{
                
                cout<<adj[x][i]<<" "<<x<<'\n';
                self(self,adj[x][i],1);
            }
        }
    };
    for(int i=0;i<2;i++){
        vis[adj[root][i]]=1;
        if(i&1){
            cout<<adj[root][i]<<" "<<root<<'\n';
            dfs(dfs,adj[root][i],1);
        }else{
            cout<<root<<" "<<adj[root][i]<<'\n';
            dfs(dfs,adj[root][i],0);
        }
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