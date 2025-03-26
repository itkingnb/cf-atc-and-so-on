#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2010
int n,m;
bool flag[N];
double ex[N];
int A,B;
priority_queue<pair<double,int>>q;
vector<pair<double,int>>adj[N];
void dijkstra(){
    ex[A]=1.0;
    q.push({1,A});
    while (!q.empty())
    {
        auto t=q.top();
        q.pop();
        if(flag[t.second]) continue;
        else
        flag[t.second]=true;
        for(auto &[x,y]:adj[t.second]){
            if(ex[y]<x*ex[t.second]){
                ex[y]=x*ex[t.second];
                q.push({ex[y],y});
            }
        }
    }
    
}
void solve(){
    cin>>n>>m;
    memset(ex,0,sizeof(ex));
    for(int i=0;i<m;i++){
        int a,b;
        double cost;
        cin>>a>>b>>cost;
        cost=1-cost/100.0;
        adj[a].push_back({cost,b});
        adj[b].push_back({cost,a});
    }
    cin>>A>>B;
    dijkstra();
    cout<<fixed<<setprecision(8)<<100.0/ex[B];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}