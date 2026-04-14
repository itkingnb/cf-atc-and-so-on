#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
#define int ll
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
    vector<ll>l(n+1),r(n+1),l1(n+1),r1(n+1);
    vector<vector<tuple<int,int,int>>>adj(n+1);
    vector<int>deg(n+1);
    for(int i=1;i<n;i++){
        int f,l,r;
        cin>>f>>l>>r;
        adj[i+1].push_back({f,l,r});
        adj[f].push_back({i+1,l,r});
        deg[i+1]++;
        deg[f]++;
    }
    vector<int>fa(n+1);
    // vector<int>deep(n+1);
    // deep[1]=1;
    auto dfs=[&](auto &&self,int u,int nowl,int nowr)->void{
        for(auto [x,y,z]:adj[u]){
            if(x==fa[u]){
                continue;
            }else{
                // deep[x]=deep[u]+1;
                fa[x]=u;
                l[x]=nowl+y;
                r[x]=nowr+z;
                l1[x]=y;
                r1[x]=z;
                self(self,x,l[x],r[x]);
            }
        }
    };
    dfs(dfs,1,0,0);
    queue<int>q;
    ll mx=0;
    vector<bool>vis(n+1);
    for(int i=1;i<=n;i++){
        if(deg[i]==1){
            mx=max(mx,l[i]);
            q.push(i);
            // vis[i]=1;
        }
    }
    vector<ll>w(n+1);
    for(int i=1;i<=n;i++){
        w[i]=r[i];
        if(deg[i]==1){
            w[i]=mx;
        }
    }
    while(q.size()){
        auto x=q.front();q.pop();
        // cerr<<x<<" ";
        if(x==1){
            continue;
        }
        w[fa[x]]=min(w[fa[x]],max(l[fa[x]],min(r[fa[x]],w[x]-l1[x])));
        if(--deg[fa[x]]==1&&fa[x]!=1){
            q.push(fa[x]);
        }
    }
    ll ans=0;
    for(int i=2;i<=n;i++){
        ans+=w[i]-w[fa[i]];
    }
    cout<<ans;

}

signed main(){
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