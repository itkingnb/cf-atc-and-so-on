#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll a,b,c1,c2,c3;
    cin>>a>>b>>c1>>c2>>c3;
    if(a>=b){
        cout<<(a-b)*c2;
        return ;
    }
    vector<ll>dp(2010,1e18);
    dp[a]=0;
    for(int i=0;i<2000;i++){
        for(int j=1;j<=1000;j++){
            dp[j]=min(dp[j],dp[j-1]+c1);
            dp[j]=min(dp[j],dp[j+1]+c2);
            if(j%2==0){
                dp[j]=min(dp[j],dp[j/2]+c3);
            }
        }
    }
    cout<<dp[b];
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