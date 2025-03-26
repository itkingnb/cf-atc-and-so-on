#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10010
vector<pair<ll,ll>>adj[N];
ll dis[N];
int n,m;
int s,t;
bool out[N];
priority_queue<pair<ll,ll>>q;
void dijkstra(){
    dis[s]=0;
    q.push({0,s});
    while (!q.empty())
    {
        auto u=q.top();
        q.pop();
        if(out[u.second]) continue;
        out[u.second]=true;
        for(auto t:adj[u.second]){
            if(dis[t.first]>dis[u.second]+t.second){
                dis[t.first]=dis[u.second]+t.second;
                q.push({-dis[t.first],t.first});
            }
        }
    }
    
}
void solve(){
    //memset(dis,0x3f3f3f3f,sizeof(dis));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        adj[a].push_back({b,x});
        adj[b].push_back({a,x});
    }
    cin>>s>>t;
    dfs(s);
    cout<<maxw;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}