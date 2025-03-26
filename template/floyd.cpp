/*【模板】Floyd
题目描述
给出一张由n个点m条边组成的无向图。
求出所有点对(i,j)之间的最短路径。
输入格式
第一行为两个整数n,m,分别代表点的个数和边的条数。
接下来m行，每行三个整数u,v,w，代表u,v之间存在一条边权为w的边。
输出格式
输出n行每行n个整数。
第i行的第j个整数代表从i到j的最短路径。
样例 
样例输入 
4 4
1 2 1
2 3 1
3 4 1
4 1 1
样例输出
0 1 2 1
1 0 1 2
2 1 0 1
1 2 1 0
**数据中可能存在重边。**
*/
#include<bits/stdc++.h>
using namespace std;
#define N 101
int dis[N][N],p[N][N];//用于记录i,j两点之间是否要绕路到达
int n;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            if(dis[i][j]>dis[i][k]+dis[k][j]){
                dis[i][j]=dis[i][k]+dis[k][j];
                p[i][j]=k;
            }
        }
    }
}
void solve(){
    int m;
    cin>>n>>m;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        if(dis[a][b]&&dis[b][a])
        dis[a][b]=dis[b][a]=min(x,dis[a][b]);
        else
        dis[a][b]=dis[b][a]=x;
    }
    floyd();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<'\n';
    }
}
int main(){
    solve();
    return 0;
}