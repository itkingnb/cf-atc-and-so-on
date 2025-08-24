#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll mod=998244353;
    // ll dp[100][2][2][100]={0};
    vector<vector<vector<vector<ll>>>>dp(100,vector<vector<vector<ll>>>(2,vector<vector<ll>>(2,vector<ll>(100,0))));
    dp[0][0][0][0]=dp[0][1][0][0]=dp[0][0][1][0]=dp[0][1][1][0]=1;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            dp[i+1][0][0][0]+=dp[i][0][1][1]+dp[i][1][1][1];
            dp[i+1][0][0][0]%=mod;
            for(int j=1;j<=i+1;j++){
                dp[i+1][0][0][j]+=dp[i][0][0][j-1]+dp[i][1][0][j-1];
                dp[i+1][0][0][j]%=mod;
            }
        }else if(s[i]=='R'){
            dp[i+1][1][0][0]+=dp[i][0][0][1]+dp[i][1][0][1];
            dp[i+1][1][0][0]%=mod;
            for(int j=1;j<=i+1;j++){
                dp[i+1][1][1][j]+=dp[i][0][1][j-1]+dp[i][1][1][j-1];
                dp[i+1][1][1][j]%=mod;
            }
        }else{
            dp[i+1][0][0][0]+=dp[i][0][1][1]+dp[i][1][1][1];
            dp[i+1][0][0][0]%=mod;
            for(int j=1;j<=i+1;j++){
                dp[i+1][0][0][j]+=dp[i][0][0][j-1]+dp[i][1][0][j-1];
                dp[i+1][0][0][j]%=mod;
            }
            dp[i+1][1][0][0]+=dp[i][0][0][1]+dp[i][1][0][1];
            dp[i+1][1][0][0]%=mod;
            for(int j=1;j<=i+1;j++){
                dp[i+1][1][1][j]+=dp[i][0][1][j-1]+dp[i][1][1][j-1];
                dp[i+1][1][1][j]%=mod;
            }
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();    
        cout<<'\n';
    }
}