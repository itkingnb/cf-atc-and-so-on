#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 20010
int n,m;
int root,idx,low[N],dfn[N];
vector<int>adj[N];
vector<int>cut;
void tarjan(int x){
    low[x]=dfn[x]=++idx;
    int kid=0;
    for(auto u:adj[x]){
        if(!dfn[u]){
        tarjan(u);
        low[x]=min(low[u],low[x]);
        if(low[u]>=dfn[x]){
            kid++;
            if(kid>1||x!=root){//条件：要么儿子有两个要么不是根节点有一个儿子
                cut.push_back(x);
            }
        }
    }
        else low[x]=min(low[x],dfn[u]);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
        root=i,tarjan(i);
    }
    sort(cut.begin(),cut.end());
    cut.erase(unique(cut.begin(),cut.end()),cut.end());
    cout<<cut.size()<<'\n';
    for(int i=0;i<cut.size();i++)
    cout<<cut[i]<<" ";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}