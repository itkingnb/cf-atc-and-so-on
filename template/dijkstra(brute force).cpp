/*
题目描述
如题，给出一个有向图，请输出从某一点出发到所有点的最短路径长度。
输入格式第一行包含三个整数 n,m,s分别表示点的个数、有向边的个数、出发点的编号。
接下来 m行每行包含三个整数 u,v,w，表示一条 u→v 的，长度为 w 的边。
输出格式
输出一行 n 个整数，第 i 个表示 s 到第 i 个点的最短路径，若不能到达则输出 2^31−1。
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll maxll=2147483647;
int n;
#define N 10001   //有几个点
struct edge{
    int to;//到哪条边
    ll length;//边权（路程）
};
vector<edge>e[N];
ll dis[N];//到原点距离
bool out[N];
void dijkstra(int x){
    for(int i=0;i<=n;i++)
    dis[i]=maxll;
    dis[x]=0;
    for(int i=1;i<=n;i++){ //枚举次数
        int u=0;
        for(int j=1;j<=n;j++){
            if(!out[j]&&dis[j]<dis[u])
            u=j;                //找离原点最近的点
        }
        out[u]=true;
        for(auto ed:e[u]){
            int to=ed.to;
            ll length=ed.length;
            if(dis[to]>length+dis[u])
            dis[to]=length+dis[u];
        }
    }
}
void solve(){
    int bian;
    int s;
    cin>>n>>bian>>s;
    for(int i=0;i<bian;i++){
        int start,to,length;
        cin>>start>>to>>length;
        e[start].push_back({to,length});
    }
    dijkstra(s);
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
int main(){
    solve();
    return 0;
}