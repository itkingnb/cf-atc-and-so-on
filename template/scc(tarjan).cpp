#include<bits/stdc++.h>
using namespace std;
#define N 20010
int low[N],dfn[N],tot;//tot计数，dfn时间戳，low最早时间戳
int stk[N],in[N],top;//栈，是否在栈内，栈的指针
int cnt,siz[N],scc[N];//编号，大小，强连通的编号
vector<int>adj[N];//邻接点
int ans;
void tarjan(int x){
    dfn[x]=low[x]=++tot;
    in[x]=1;stk[++top]=x;
    for(auto u:adj[x]){
        if(!dfn[u]){
            tarjan(u);
            low[x]=min(low[x],low[u]);
        }
        else if(in[u])
        low[x]=min(low[x],dfn[u]);
    }
    if(low[x]==dfn[x]){
        int y; cnt++;
        do{
            y=stk[top--];
            scc[y]=cnt;
            in[y]=0;
            siz[cnt]++;
        }while(x!=y);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    if(!dfn[i])
    tarjan(i);
    for(int i=1;i<=cnt;i++)
    if(siz[i]>1)
    ans++;
    cout<<ans;
}
int main(){
    solve();
    return 0;
}