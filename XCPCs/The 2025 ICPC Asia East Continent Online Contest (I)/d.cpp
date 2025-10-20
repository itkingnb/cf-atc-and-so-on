#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pii>>adj(n+10);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<ll>dep(n+10,0);
    dep[0]=0;
    dep[1]=0;
    vector<bool>vis(n+10,0);
    vis[1]=1;
    ll ans=0;
    vector<int>siz(n+1,0);
    auto dfs=[&](auto &&self,int x)->void{
        for(auto [u,v]:adj[x]){
            if(vis[u]){
                continue;
            }else{
                siz[x]++;
                vis[u]=1;
                dep[u]=dep[x]+v;
                ans+=dep[u];
                self(self,u);
            }
        }
    };
    dfs(dfs,1);
    cout<<ans<<'\n';
    vector<pii>a(m);
    for(int i=0;i<m;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=1;i<=n;i++){
        ll mx=0;
        int id=-1;
        for(int j=0;j<m;j++){
            auto [x,y]=a[j];
            if(dep[y]-dep[x]>mx){
                id=j;
                mx=dep[y]-dep[x];
            }else if(dep[x]-dep[y]>mx){
                id=j;
                mx=dep[x]-dep[y];
            }
        }
        ans-=mx;
        cout<<ans<<'\n';
        if(id==-1){
            for(int k=i+1;k<=n;k++){
                cout<<ans<<"\n";
            }
            break;
        }else{
            auto [x,y]=a[id];
            if(dep[y]-dep[x]==mx){
                // id=i;
                dep[y]=dep[x];
            }else if(dep[x]-dep[y]==mx){
                // id=i;
                dep[x]=dep[y];
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}