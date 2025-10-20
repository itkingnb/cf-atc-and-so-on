#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct line{
    ll v,w;
};
void solve(){
    ll n,m,V,t;
    cin>>n>>m>>V>>t;
    vector<vector<line>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<bool>vis(n+1,0);
    vector<ll>ans(n+1,1e18);
    vector<ll>left(n+1,0);
    ans[t]=1;
    priority_queue<tuple<int,int,int>>pq;
    pq.push({-1,V,t});
    while(pq.size()){
        auto [x,y,z]=pq.top();pq.pop();
        // cerr<<x<<" "<<y<<" "<<z<<'\n';
        // if(z==1){
        //     cerr<<1111<<'\n';
        // }
        if(vis[z]){
            continue;
        }
        vis[z]=1;
        // ans[z]=min((ll)-x,ans[z]);
        for(auto [v,w]:adj[z]){
            if(w<=y&&(-x<ans[v]||-x==ans[v]&&y-w>left[v])){
                ans[v]=-x;left[v]=y-w;
                pq.push({x,y-w,v});
            }else if(w>y&&-x+1<=ans[v]){
                ans[v]=-x+1;left[v]=V-w;
                pq.push({x-1,V-w,v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==(ll)1e18){
            cout<<-1<<" ";
        }else{
            cout<<ans[i]<<" ";
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