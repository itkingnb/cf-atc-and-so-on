#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    int l,r;
    cin>>l>>r;
    vector<string>mp(n);
    for(int i=0;i<n;i++){
        cin>>mp[i];
    }
    int ans=-1;
    int dx[]={0,0,1,-1,1,1,-1,-1};
    int dy[]={1,-1,0,0,1,-1,1,-1};
    queue<tuple<int,int,int>>q;
    q.push({0,0,0});
    vector<vector<vector<int>>>dis(n,vector<vector<int>>(m,vector<int>(2,1e9)));
    dis[0][0][0]=0;
    dis[0][0][1]=0;
    auto check=[&](int x,int y,int step)->bool{
        return x>=0&&y>=0&&x<n&&y<m&&mp[x][y]=='1'&&dis[x][y][(step+1)%2]>step+1;
    };
    while(q.size()){
        auto [x,y,step]=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(check(nx,ny,step)){
                dis[nx][ny][(step+1)%2]=step+1;
                q.push({nx,ny,step+1});
            }
        }
    }
    if(dis[n-1][m-1][0]==(int)1e9&&dis[n-1][m-1][1]==(int)1e9){
        cout<<-1;
        return ;
    }
    if(l!=r){
        cout<<(min(dis[n-1][m-1][0],dis[n-1][m-1][1])+r-1)/r;
    }else if(l%2==0){
        if(dis[n-1][m-1][0]==(int)1e9){
            cout<<-1;
        }else{
            cout<<(dis[n-1][m-1][0]+l-1)/l;
        }
    }else{
        int t1=(dis[n-1][m-1][0]+l-1)/l;
        int t2=(dis[n-1][m-1][1]+l-1)/l;
        if(t1%2!=dis[n-1][m-1][0]%2){
            t1++;
        }
        if(t2%2!=dis[n-1][m-1][1]%2){
            t2++;
        }
        cout<<min(t2,t1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}