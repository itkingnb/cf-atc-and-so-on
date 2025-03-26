#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
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
//int dp[1000][1000][1000];
void solve(){
    int n;
    cin>>n;
    int m=n;
    int ans=0;
    ans+=n/2;
    if(n&1){
        m--;
        ans++;
    }
    ans+=(m+1)/2;
    n+=2;
    ans+=(n-((m+1)/2))/3;
    cout<<ans;
    /*vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,3*n)));
    dp[3][0][0]=dp[0][2][0]=dp[0][0][2]=dp[2][1][0]=dp[0][1][1]=dp[1][0][1]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(i>=3){
                    dp[i][j][k]=min(dp[i][j][k],dp[i-3][j][k]+1);
                }
                if(j>=2){
                    dp[i][j][k]=min(dp[i][j][k],dp[i][j-2][k]+1);
                }
                if(k>=2){
                    dp[i][j][k]=min(dp[i][j][k],dp[i][j][k-2]+1);
                }
                if(j&&k){
                    dp[i][j][k]=min(dp[i][j][k],dp[i][j-1][k-1]+1);
                }
                if(j&&i>=2){
                    dp[i][j][k]=min(dp[i][j][k],dp[i-2][j-1][k]+1);
                }
                if(i&&k){
                    dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k-1]+1);
                }
            }
        }
    }*/
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}