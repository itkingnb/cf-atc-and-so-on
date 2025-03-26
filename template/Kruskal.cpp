#include<bits/stdc++.h>
using namespace std;
#define N 5010
struct e
{
    int a,b,c;
    bool operator<(const e&t)const
    {return c<t.c;}
};
vector<e>adj;
int ans,cnt,m,n,fa[N];
int find(int x){
    if(fa[x]==x)
    return x;
    return fa[x]=find(fa[x]);
}
bool Kruskal(){
    for(int i=1;i<=n;i++)
    fa[i]=i;
    sort(adj.begin(),adj.end());
    for(int i=0;i<m;i++){
        int x=find(adj[i].a);
        int y=find(adj[i].b);
        if(x!=y){
        fa[x]=y;
        ans+=adj[i].c;
        cnt++;
        }
    }
    return cnt==n-1;
}
void solve(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj.push_back({a,b,c});
    }
    Kruskal()?cout<<ans:cout<<"orz";
}
int main(){
    solve();
    return 0;
}