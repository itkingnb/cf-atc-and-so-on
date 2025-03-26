#include<bits/stdc++.h>
using namespace std;
#define N 500010
vector<int> adj[N];
int fa[N][20];//int fa[i][j]表示i这个点向上跳2的j次方层的父节点
int deep[N];
void dfs(int x,int father){
    deep[x]=deep[father]+1;
    fa[x][0]=father;
    for(int i=1;i<20;i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    for(auto u:adj[x])
    if(u!=father)
    dfs(u,x);
}
int LCT(int x,int y){
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=19;i>=0;i--)//注意取等！！！！！！！
    if(deep[fa[x][i]]>=deep[y])
    x=fa[x][i];         //先到同一层
    if(x==y)
    return x;//相同则返回，不同继续向上找
    for(int i=19;i>=0;i--){
        if(fa[x][i]!=fa[y][i])
        x=fa[x][i],y=fa[y][i];//找到答案的下一层
    }
    return fa[x][0];//这层的爸爸就是答案
}
void solve(){
    int n,m,father;
    cin>>n>>m>>father;
    for(int i=0;i<n-1;i++){//n-1条边！！！！！！！！！
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(father,father);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cout<<LCT(a,b)<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}