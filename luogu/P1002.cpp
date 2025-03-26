#include<bits/stdc++.h>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int dx[]={-2,-2,2,2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
ll dp[30][30];
int mp[30][30];
int n,m,a,b;
int check(int x,int y){
    for(int i=0;i<8;i++){
        int aa=x+dx[i];
        int bb=y+dy[i];
        if(aa>=0&&aa<=n&&bb>=0&&bb<=m)
        mp[aa][bb]=0;
        //cout<<aa<<bb<<'\n';
    }
    mp[x][y]=0;
    return 0;
}
void solve(){
    cin>>n>>m>>a>>b;
    memset(mp,-1,sizeof(mp));
    dp[0][0]=0;
    check(a,b);
    int flag=0;
    for(int i=1;i<=n;i++){
        if(mp[i][0]==0)
        flag=1;
        if(flag)
        dp[i][0]=0;
        else
        dp[i][0]=1;
    }
    flag=0;
    for(int i=1;i<=m;i++){
        if(mp[0][i]==0)
        flag=1;
        if(flag)
        dp[0][i]=0;
        else
        dp[0][i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]!=0)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            //cout<<dp[i][j];
        }
        //cout<<'\n';
    }
    cout<<dp[n][m];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}