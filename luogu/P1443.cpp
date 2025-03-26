#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define N 410
ll jc(ll n){
    if(n==1||n==0)
    return (ll)1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
}
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
ll qpow(ll a, ll k, ll p)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
int dx[]={-2,-2,2,2,1,-1,1,-1};
int dy[]={1,-1,1,-1,2,2,-2,-2};
int mp[N][N];
int me[N][N];
queue<pii>q;
int n,m;
bool check(int x,int y){
    if(x>0&&x<=n&&y>0&&y<=m)
    return true;
    return false;
}
void bfs(int x,int y){
    q.push({x,y});
    mp[x][y]=0;
    me[x][y]=1;
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int xx=u.first+dx[i];
            int yy=u.second+dy[i];
            if(check(xx,yy)&&me[xx][yy]==0)
            q.push({xx,yy}),mp[xx][yy]=mp[u.first][u.second]+1,me[xx][yy]=1;
        }
    }
}
void solve(){
    int x,y;
    cin>>n>>m>>x>>y;
    memset(mp,-1,sizeof(mp));
    bfs(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<mp[i][j]<<" ";
        }
        cout<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}