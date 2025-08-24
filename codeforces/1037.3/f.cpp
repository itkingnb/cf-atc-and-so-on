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
    int n,q;
    cin>>n>>q;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<pii>>adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;ll c;
        cin>>u>>v>>c;
        u--;v--;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    vector<map<int,ll>>mp(n);
    ll ans=0;
    vector<bool>vis(n,0);
    vector<pair<int,int>>dad(n,{-1,0});
    vis[0]=1;
    auto dfs=[&](auto &&self,int u,int fa,ll c)->void{
        dad[u].first=fa;
        dad[u].second=c;
        if(fa!=-1){
            ans+=(ll)(a[u]!=a[fa])*c;
        }
        for(auto [x,y]:adj[u]){
            if(!vis[x]){
                vis[x]=1;
                self(self,x,u,y);
                mp[u][a[x]]+=y;
            }
        }
    };
    dfs(dfs,0,-1,0);
    while(q--){
        int v,x;
        cin>>v>>x;
        v--;
        if(dad[v].first!=-1){
            mp[dad[v].first][a[v]]-=dad[v].second;
            ans-=(a[v]!=a[dad[v].first])*dad[v].second;
            mp[dad[v].first][x]+=dad[v].second;
            ans+=(x!=a[dad[v].first])*dad[v].second;
            ans+=mp[v][a[v]];
            ans-=mp[v][x];
            a[v]=x;
        }else{
            ans+=(x!=a[dad[v].first])*dad[v].second;
            ans+=mp[v][a[v]];
            ans-=mp[v][x];
            a[v]=x;
        }
        cout<<ans<<'\n';
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';
    }
    return 0;
}