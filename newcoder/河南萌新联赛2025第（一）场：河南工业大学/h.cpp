#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    int idx=1;
    int pi=(n+1)/2,pj=(n+1)/2;
    int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
    vector<vector<int>>mp(n+1,vector<int>(n+1,-1));
    int k=3;
    mp[pi][pj]=0;
    auto check=[&](int x,int y)->bool{
        return x>0&&y>0&&x<=n&&y<=n&&mp[x][y]==-1;
    };
    while(idx<n*n){
        if(check(pi+dx[(k+1)%4],pj+dy[(k+1)%4])){
            mp[pi+dx[(k+1)%4]][pj+dy[(k+1)%4]]=idx++;
            pi+=dx[(k+1)%4];pj+=dy[(k+1)%4];
            k++;
            k%=4;
        }else{
            pi+=dx[k];pj+=dy[k];
            mp[pi][pj]=idx++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mp[i][j]<<' ';
        }
        cout<<'\n';
    }
}   
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
    
}