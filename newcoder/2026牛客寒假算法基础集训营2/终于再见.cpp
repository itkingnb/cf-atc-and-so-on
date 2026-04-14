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
    vector<vector<int>>adj(n);
    vector<int>deg(n);
    vector<int>ans(n,2e9);
    vector<bool>vis(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;deg[v]++;
    }
    vector<int>t=deg;
    sort(t.begin(),t.end());
    map<int,int>mp;
    int idx=0;
    t.erase(unique(t.begin(),t.end()),t.end());
    for(int i=0;i<t.size();i++){
        mp[t[i]]=idx++;
    }
    auto bfs=[&](int id)->void{
        queue<pii>q;
        vector<bool>v(n);
        int mx=0;
        for(int i=0;i<n;i++){
            if(mp[deg[i]]==id){
                q.push({i,0});
                mx=deg[i];
                v[i]=1;
            }
        }
        while(q.size()){
            auto [u,vv]=q.front();q.pop();
            for(auto x:adj[u]){
                if(!v[x]&&deg[x]<mx){
                    ans[x]=min(ans[x],vv+1);
                    q.push({x,vv+1});
                    v[x]=1;
                }
            }
        }
    };
    for(int i=idx-1;i>=0;i--){
        bfs(i);
    }
    for(int i=0;i<n;i++){
        if(ans[i]==(int)2e9){
            cout<<-1<<" ";
        }else{
            cout<<ans[i]<<" ";
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}