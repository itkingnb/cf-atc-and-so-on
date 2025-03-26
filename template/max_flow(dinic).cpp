#include<bits/stdc++.h>
using namespace std;
#define N 210
#define ll long long 
struct e
{
    int to;
    ll c;
    int ne;
}adj[10010];//边要两倍m因为还有反向边
int h[N],d[N],cur[N];//第一条出边;d是第几层;cur是出边
int idx=1;
int n,m,s,t;//s开始，t结束
void add(int a,int b,int c){
    adj[++idx]={b,c,h[a]};
    h[a]=idx;
}
bool bfs(){
    memset(d,0,sizeof(d));
    queue<int>q;
    d[s]=1; q.push(s);
    while(q.size()){
        int u=q.front();q.pop();
        for(int i=h[u];i;i=adj[i].ne){
            int v=adj[i].to;
            if(d[v]==0&&adj[i].c){
                d[v]=d[u]+1;
                q.push(v);
                if(v==t) return true;
            }
        }
    }
    return false;
}

ll dfs(int u,ll maxflow){
    if(u==t) return maxflow;
    ll sum=0;
    for(int i=cur[u];i;i=adj[i].ne){
        cur[u]=i; //当前弧优化
        int v=adj[i].to;
        if(d[v]==d[u]+1&&adj[i].c){
            ll f=dfs(v,min(maxflow,adj[i].c));
            adj[i].c-=f;
            adj[i^1].c+=f;
            sum+=f;
            maxflow-=f;
            if(maxflow==0) break;
        }
    }
    if(sum==0) d[u]=0;
    return sum;
}

ll dinic(){
    ll res=0;
    while(bfs()){
        memcpy(cur,h,sizeof(h));
        res+=dfs(s,LONG_LONG_MAX);
    }
    return res;
}
void solve(){
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++){
        int u,v,value;
        cin>>u>>v>>value;
        add(u,v,value);
        add(v,u,0);
    }
    ll ans=0;
    ans+=dinic();
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0), cout.tie(0);
    solve();
}

