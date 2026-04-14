#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int dx[]={-1,-1,-1,0,0,0,1,1,1},dy[]={-1,0,1,-1,0,1,-1,0,1};
    auto check=[&](int x,int y)->bool{
        return x>=0&&x<n&&y>=0&&y<m;
    };
    vector<vector<char>>ans(n,vector<char>(m,'?'));
    vector<vector<bool>>vis(n,vector<bool>(n,1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='M'){
                ans[i][j]='M';
            }else if(s[i][j]=='H'){
                for(int k=0;k<9;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(check(nx,ny)){
                        ans[nx][ny]=s[nx][ny];
                        vis[nx][ny]=0;
                    }
                }
            }else if(s[i][j]=='L'){
                bool ok=1;
                for(int k=0;k<9;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(check(nx,ny)&&s[nx][ny]!='L'||!check(nx,ny)){
                        ok=0;
                        break;
                    }
                }
                if(ok){
                    ans[i][j]='S';
                }else{
                    ans[i][j]='L';
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans[i][j]!='?'){
                continue;
            }
            if(s[i][j]=='G'){
                if(!vis[i][j]){
                    ans[i][j]='G';
                }else{
                    bool ok=0;
                    for(int k=0;k<9;k++){
                        int nx=i+dx[k],ny=j+dy[k];
                        if(check(nx,ny)&&s[nx][ny]=='L'){
                            ok=1;
                            break;
                        }
                    }
                    if(ok){
                        ans[i][j]='N';
                    }else{
                        ans[i][j]='B';
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            assert(ans[i][j]!='?');
            cout<<ans[i][j];
        }
        cout<<'\n';
    }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--){
        solve();
    }
    
}