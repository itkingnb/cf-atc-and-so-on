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
// const int N = 100010;
void solve(){
    int n,st,en;
    cin>>n>>st>>en;
    vector<vector<int>>adj(n+1);
    vector<bool>vis(n+1,false);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pii>depth;
    auto dfs=[&](auto&& dfs,int u,int d)->void{
        depth.push_back({d,u});
        for(auto v:adj[u]){
            if(!vis[v]){
                vis[v]=1;
                dfs(dfs,v,d+1);
            }
        }
    };
    vis[en]=true;
    for(auto x:adj[en]){
        if(!vis[x]){
            vis[x]=1;
            dfs(dfs,x,1);
        }
    }
    auto cmp=[&](pii a,pii b)->bool{
        return a.first>b.first;
    };
    depth.push_back({0,en});
    sort(all(depth),cmp);
    for(auto x:depth){
        cout<<x.second<<' ';
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