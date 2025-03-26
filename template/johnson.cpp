#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 3010
vector<pair<int,int>>adj[N];
int n,m;
int cnt[N];//SPFA计数
bool in[N],out[N];//in 用来判断SPFA的时候点是不是在队列中，out是跑dj的时候有没有打标记出队
int d[N];//势能函数，SPFA跑的距离
int dis[N];//加点后跑的距离=旧图距离+d[from]-d[to];
bool SPFA(){
    queue<int>q;
    q.push(0);
    memset(d,0x3f3f3f3f,sizeof(d));
    d[0]=0;
    while(q.size()){
        int u=q.front();q.pop();
        in[u]=0;
        for(auto x:adj[u]){
            if(d[x.first]>d[u]+x.second){
                d[x.first]=d[u]+x.second;
                cnt[x.first]=cnt[u]+1;//这里是记录边数！！！
                if(cnt[x.first]>n){//因为加了虚拟点，所以要严格大于n
                    cout<<-1;
                    return true;//exit(0);直接结束
                }
                if(!in[x.first])
                q.push(x.first),in[x.first]=1;
            }
        }
    }
    return false;
}
void dijkstra(int x){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(out,false,sizeof(out));//这个别忘了每次dj开始初始化
    dis[x]=0;
    priority_queue<pair<int,int>>q;
    q.push({0,x});
    while(q.size()){
        auto u=q.top();q.pop();
        if(out[u.second]) continue;
        out[u.second]=true;
        for(auto ed:adj[u.second]){
            if(dis[ed.first]>dis[u.second]+ed.second){
                dis[ed.first]=dis[u.second]+ed.second;
                q.push({-dis[ed.first],ed.first});
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    for(int i=1;i<=n;i++)
    adj[0].push_back({i,0});//加虚拟点
    bool yes=SPFA();
    if(yes)
    return ;
    else{
        for(int i=1;i<=n;i++){
            for(auto &u:adj[i]){//一定一定要加引用，不然值改不掉
                u.second+=d[i]-d[u.first];//修改新边权
            }
        }
         for(int i=1;i<=n;i++){
            dijkstra(i);
            ll ans=0;
            for(int j=1;j<=n;j++){
                if(dis[j]==0x3f3f3f3f)
                ans+=(ll)j*1e9;
                else
                ans+=(ll)j*(dis[j]+d[j]-d[i]);//dis=原来+d[i]-d[j]->原来=dis+d[j]-d[i]!!!
            }
            cout<<ans<<'\n';
        }    
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}