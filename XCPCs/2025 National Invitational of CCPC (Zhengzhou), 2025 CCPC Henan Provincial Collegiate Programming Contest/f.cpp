#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string>mp(n);
    for(int i=0;i<n;i++){
        cin>>mp[i];
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    auto check=[&](int x,int y)->bool{
        return x>=0&&y>=0&&x<n&&y<m&&mp[x][y]=='.'&&!vis[x][y];
    };
    auto check2=[&](int x,int y)->bool{
        return x>=0&&y>=0&&x<n&&y<m&&vis[x][y]!=1&&vis[x][y]!=3;
    };
    auto check3=[&](int x,int y)->bool{
        return x>=0&&y>=0&&x<n&&y<m&&vis[x][y]!=2&&vis[x][y]!=4;
    };
    int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
    q.push({0,0});
    vector<vector<int>>dp1(n,vector<int>(m,1e9));
    vector<vector<int>>dp2(n,vector<int>(m,1e9));
    queue<tuple<int,int,int>>q1,q2;
    while(q.size()){
        auto [x,y]=q.front();
        q.pop();
        if(vis[x][y]){
            continue;
        }
        vis[x][y]=1;
        q1.push({0,x,y});
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(check(nx,ny)){
                q.push({nx,ny});
            }
        }
    }
    if(vis[n-1][m-1]){
        cout<<0<<'\n';
        return ;
    }
    q.push({n-1,m-1});
    while(q.size()){
        auto [x,y]=q.front();
        q.pop();
        q2.push({0,x,y});
        if(vis[x][y]){
            continue;
        }
        vis[x][y]=2;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(check(nx,ny)){
                q.push({nx,ny});
            }
        }
    }   
    while(q1.size()){
        auto [a,x,y]=q1.front();
        q1.pop();
        if(vis[x][y]==3){
            continue;
        }
        vis[x][y]=3;
        dp1[x][y]=min(dp1[x][y],a);
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(check2(nx,ny)){
                q1.push({a+1,nx,ny});
            }
        }
    }
    vis[0][0]=1;
    while(q2.size()){
       auto [a,x,y]=q2.front();
        q2.pop();
        if(vis[x][y]==4){
            continue;
        }
        vis[x][y]=4;
        dp2[x][y]=min(dp2[x][y],a);
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(check3(nx,ny)){
                q2.push({a+1,nx,ny});
            }
        } 
    }
    ll ans=1e18;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=min(ans,(ll)dp1[i][j]+dp2[i][j]-1);
        }
    }
    cout<<ans<<'\n';


}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}