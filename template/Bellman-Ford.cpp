#include<bits/stdc++.h>
using namespace std;
#define N 2010
#define ll long long
ll d[N];//距离
struct adj
{
    int to;
    ll len;
};
vector<adj>a[N];
bool Bellman_Ford(int n,int s){
    memset(d,0x3f3f3f3f,sizeof(d));
    d[s]=0;
    bool flag=false;
    for(int i=0;i<n;i++){
        flag=false;
        for(int j=1;j<=n;j++){
            for(auto ad:a[j]){
                if(d[ad.to]>d[j]+ad.len){
                    d[ad.to]=d[j]+ad.len;
                    flag=true;
                }
            }
        }
        if(!flag)
        break;
    }
    return flag;
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
    Bellman_Ford(n,1)?cout<<"YES":cout<<"NO";

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
    return 0;
}