#include<bits/stdc++.h>
using namespace std;
#define N 500010
vector<int>adj[N];
int ans[N],vis[N],fa[N];
vector<pair<int,int>>query[N];
int findfather(int x){
    if(x==fa[x])
    return x;
    return fa[x]=findfather(fa[x]);//带路径压缩的并查集
}
void tarjan(int s){
    vis[s]=1;
    for(auto x:adj[s]){
        if(!vis[x]){
        tarjan(x);
        fa[x]=s;            
        }
    }
    for(auto u:query[s]){
        if(ans[u.second]==0&&vis[u.first]){//深搜完后可以有机会更新答案，如果之前出现过，那他的爸爸就是答案
            ans[u.second]=findfather(u.first);
        }
    }
}
void solve(){
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    fa[i]=i;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        query[a].push_back({b,i});
        query[b].push_back({a,i});//离线算法，把询问都记录下来
    }
    tarjan(s);
    for(int i=1;i<=m;i++)
    cout<<ans[i]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}