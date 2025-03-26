#include<bits/stdc++.h>
using namespace std;
#define N 300
#define ll long long 
struct e
{
    int to;
    ll c;
    int ne;
};
vector<e>adj(10010);//边要两倍m因为还有反向边
int h[N],pre[N];//第一条出边;前驱边，边，边！！！
ll max_flow[N];//到x点最大流量
int idx=1;
int n,m,s,t;//s开始，t结束
void add(int a,int b,int c){
    adj[++idx]={b,c,h[a]};
    h[a]=idx;
}
bool bfs(){
    memset(max_flow,0,sizeof(max_flow));
    queue<int>q;
    q.push(s); max_flow[s]=LONG_LONG_MAX;
    while(q.size()){
        auto u=q.front();q.pop();
        for(int i=h[u];i;i=adj[i].ne){
            int v=adj[i].to;
            if(max_flow[v]==0&&adj[i].c){
                max_flow[v]=min(adj[i].c,max_flow[u]);
                pre[v]=i;//注意这里存的是边！
                q.push(v);
                if(v==t) return true;
            }
        }
    }
    return false;
}
ll EK(){
    ll res=0;
    while(bfs()){   
        int v=t;
        while(v!=s){
            int i=pre[v];
            adj[i].c-=max_flow[t];
            adj[i^1].c+=max_flow[t];
            v=adj[i^1].to;
        }
        res+=max_flow[t];
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
    ans+=EK();
    cout<<ans;
}

int main(){
    solve();
}

