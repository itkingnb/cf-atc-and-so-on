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
priority_queue<pair<int,int>>q;
bool prim(){
    dis[1]=0;
    int cnt=0;
    q.push({0,1});
    while(!q.empty()){
        auto u=q.top();
        q.pop();
        if(out[u.second]) continue;
        out[u.second]=true;
        cnt++;
        ans-=u.first;
        for(auto x:e[u.second]){
            if(dis[x.to]>x.len){
                dis[x.to]=x.len;
                q.push({-dis[x.to],x.to});
            }
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