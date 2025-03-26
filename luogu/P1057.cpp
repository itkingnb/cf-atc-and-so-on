#include<bits/stdc++.h>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    ll dp[31][31]={0};
    dp[0][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
            if(j==1)
            dp[i][j]=dp[i-1][n]+dp[i-1][2];
            if(j==n)
            dp[i][j]=dp[i-1][n-1]+dp[i-1][1];
        }
    }
    cout<<dp[m][1];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}