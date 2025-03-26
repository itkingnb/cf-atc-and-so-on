#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 160
#define pii pair<int,int>
struct e{ int u,v;};//u，v分别表示起点和终点
vector<e>es;
int dfn[N],low[N],tot;
int cnt,n,m;
vector<int>h[N];
vector<pii>bridge;
void add(int a,int b){
    es.push_back({a,b});
    h[a].push_back(es.size()-1);//链式邻接表
}
void tarjan(int x,int in_edge){
    dfn[x]=low[x]=++tot;
    for(int i=0;i<h[x].size();i++){
        int j=h[x][i];
        int y=es[j].v;
        if(!dfn[y]){
            tarjan(y,j);
            low[x]=min(low[x],low[y]);
            if(low[y]>dfn[x])//割边条件
            bridge.push_back({x,y});
        }else if(j!=(in_edge^1))//不是反边 奇数:x^1=x-1,因为边从0开始成对出现，所以反向的一条边必是奇数，正向边就会使这个条件成立
        low[x]=min(low[x],dfn[y]);//实测low[y]也能AC,但是数据看上去很水，还是写dfn比较好
    }
}
bool cmp(pii a,pii b){
    if(a.first==b.first)
    return a.second<b.second;
    return a.first<b.first;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    cnt--;
    for(int i=1;i<=n;i++){
        if(!dfn[i])
        tarjan(i,0);
    }
    sort(bridge.begin(),bridge.end(),cmp);
    for(int i=0;i<bridge.size();i++)
    cout<<bridge[i].first<<" "<<bridge[i].second<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}