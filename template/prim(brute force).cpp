#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define N 5010
struct node{
    int to;
    int len;
};
vector<node>e[N];
int dis[N],ans;
bool out[N];
int n,m;
bool prim(){
    dis[1]=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        int j=0,u=0;
        for(j=1;j<=n;j++)
            if(!out[j]&&dis[j]<dis[u]) u=j;
        out[u]=1;
        if(dis[u]!=0x3f3f3f3f) cnt++,ans+=dis[u];
        for(auto x:e[u]){
            if(dis[x.to]>x.len)
            dis[x.to]=x.len;
        }
    }
    return cnt==n;
}
    
void solve(){
    cin>>n>>m;
    memset(dis,0x3f3f3f3f,sizeof(dis));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back({b,c});
        e[b].push_back({a,c});
    }
    prim()?cout<<ans:cout<<"orz";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}