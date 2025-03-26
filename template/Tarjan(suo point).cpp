#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10010
int n,m;
int low[N],dfn[N],idx,w[N],stk[N],top,cnt,scc[N],sccw[N];
ll dp[N];
vector<int>adj[N],ne[N];
bool instk[N];
void tarjan(int x){
    ll ans=0;
    dfn[x]=low[x]=++idx;
    instk[x]=true,stk[++top]=x;
    for(auto u:adj[x]){
        if(!dfn[u]){
        tarjan(u);
        low[x]=min(low[u],low[x]);
        }else if(instk[u])
        low[x]=min(low[x],low[u]);//dfn[u]也可以
    }
    if(dfn[x]==low[x]){
        int y;
        cnt++;
        do{
            y=stk[top--];
            scc[y]=cnt;
            instk[y]=0;
        }while(x!=y);
    }
}
void solve(){
    ll ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>w[i];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])
        tarjan(i);
    }
    for(int i=1;i<=n;i++){
        sccw[scc[i]]+=w[i];
        for(auto u:adj[i]){
            int x=scc[i],y=scc[u];
            if(x!=y)
            ne[x].push_back(y);
        }
    }
    for(int i=cnt;i>0;i--){
        if(dp[i]==0)
        dp[i]=sccw[i];
        for(int x:ne[i]){
            dp[x]=max(dp[x],dp[i]+sccw[x]);
        }
    }
    for(int i=1;i<=cnt;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}