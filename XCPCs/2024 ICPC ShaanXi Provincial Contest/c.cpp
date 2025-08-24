#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){
    int n;
    cin>>n;
    vector<vector<int>>adj(2*n+1);
    vector<vector<int>>adj1(2*n+1);
    vector<int>in(2*n+1);
    vector<bool>vis(2*n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        in[x]++;
        adj1[x].push_back(i);
    }
    int cnt=0;
    auto dfs1=[&](auto&& dfs1,int x,int deep)->void{
        res=max(res,++deep);
        vis[x]=1;
        for(auto v:adj1[x]){
            if(!vis[v])
            dfs1(dfs1,v,deep);
        }
    };
    int res=0;
    int ans=0;
    for(int i=n+1;i<=2*n;i++){
        res=0;
        for(auto x:adj1[i]){
            dfs1(dfs1,x,0);
        }
        ans+=res;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(q.size()){
        auto x=q.front();q.pop();vis[x]=1;
        for(auto v:adj[x]){
            in[v]--;
            if(in[v]==0){
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans++;
        }
    }
    cout<<ans;
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