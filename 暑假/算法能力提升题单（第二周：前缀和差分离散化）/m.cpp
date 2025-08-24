#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int m,n,mm,nn;
    cin>>n>>m>>nn>>mm;
    vector<vector<ll>>mp(n+1,vector<ll>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    vector<vector<ll>>pre(n+1,vector<ll>(m+1,0LL));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+mp[i][j];
        }
    }
    ll ans=0;
    for(int i=1;i<=nn;i++){
        for(int j=1;j<=mm;j++){
            int x=i+n-nn,y=j+m-mm;
            ans+=abs(pre[x][y]-pre[i-1][y]-pre[x][j-1]+pre[i-1][j-1]);
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}