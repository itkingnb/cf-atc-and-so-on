/*
题目描述
如题，给出一个有向图，请输出从某一点出发到所有点的最短路径长度。
输入格式第一行包含三个整数 n,m,s分别表示点的个数、有向边的个数、出发点的编号。
接下来 m行每行包含三个整数 u,v,w，表示一条 u→v 的，长度为 w 的边。
输出格式
输出一行 n 个整数，第 i 个表示 s 到第 i 个点的最短路径，若不能到达则输出 2^31−1。
输入输出样例
输入 #1
4 6 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
输出 #1
0 2 4 3
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define N 10000001   
ll maxll=2147483647;
int rood[N];//rood[a]=b说明a的前一个点是b
int n;//有几个点
priority_queue<pair<int,int>> q;//优先队列做大根堆
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
    q.push({0,x});
    while (q.size())
    {
        auto t=q.top();
        q.pop();
        int u=t.second;
        if(out[u])
        continue;
        out[u]=true;
        for(auto ed:e[u]){
            int to=ed.to,length=ed.length;
            if(dis[to]>dis[u]+length){
                dis[to]=dis[u]+length;
                rood[to]=u;
                q.push({-dis[to],to});
            }
        }
    }    
}
void dfs_path(int x/*找的节点*/,int s/*原点*/){
    if(x==s){cout<<s<<" ";return;}
    dfs_path(rood[x],s);//往前深搜
    cout<<x<<' ';//前面都找完了回来输出
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
    cout<<'\n';
    dfs_path(4,1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}