#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define ll long long
ll d[N];//距离
int cnt[N];
bool in[N];
queue<int>q;
struct adj
{
    int to;
    ll len;
};
vector<adj>a[N];
bool SPFA(int n,int s){
    while (q.size()) q.pop(); 
    memset(in,0,sizeof(in));
    memset(d,0x3f3f3f3f,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    d[s]=0;
    q.push(s);
    in[s]=true;
    while(q.size()){
        int u=q.front();
        q.pop();
        in[u]=false;
        for(auto ad:a[u]){
            if(d[ad.to]>d[u]+ad.len){
                cnt[ad.to]=1+cnt[u];
                if(cnt[ad.to]>=n)
                return true;
                d[ad.to]=d[u]+ad.len;
                if(in[ad.to]==false)
                q.push(ad.to),in[ad.to]=true;
            }
        }
    }
    return false;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i].clear();
    }
    for(int i=0;i<m;i++){
        int from,to;
        ll dis;
        cin>>from>>to>>dis;
        a[from].push_back({to,dis});
        if(dis>=0)
        a[to].push_back({from,dis});
    }
    SPFA(n,1)?cout<<"YES":cout<<"NO";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
        cout<<'\n';
    }
    
}