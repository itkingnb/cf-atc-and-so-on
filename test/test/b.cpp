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
void solve(){
    ll n,h;
    cin>>n>>h;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    vector<array<ll,10>>dp(n+1);
    dp[0][0]=h;dp[0][1]=2*h;dp[0][2]=4*h;dp[0][3]=3*h;dp[0][4]=6*h;dp[0][5]=12*h;
    int i;
    for(i=0;i<n;i++){
        dp[i+1]=dp[i];
        if(*max_element(dp[i].begin(),dp[i].end())<=a[i])
        break;
        if(dp[i+1][0]>a[i]){
            dp[i+1][0]=dp[i][0]+a[i]/2;dp[i+1][1]=2*dp[i+1][0];dp[i+1][2]=4*dp[i+1][0];dp[i+1][3]=3*dp[i+1][0];dp[i+1][4]=6*dp[i+1][0];dp[i+1][5]=12*dp[i+1][0];
        }
        if(dp[i+1][1]>a[i]){
            dp[i+1][1]=max(dp[i+1][1],dp[i][1]+a[i]/2);dp[i+1][2]=max(dp[i+1][2],(dp[i+1][1])*2);dp[i+1][4]=max(dp[i+1][4],(dp[i+1][1])*3);dp[i+1][5]=max(dp[i+1][5],(dp[i+1][1])*6);
        }
        if(dp[i+1][2]>a[i]){
            dp[i+1][2]=max(dp[i+1][2],dp[i][2]+a[i]/2);dp[i+1][5]=max(dp[i+1][5],(dp[i+1][2])*3);
        }
        if(dp[i+1][3]>a[i]){
            dp[i+1][3]=max(dp[i+1][3],dp[i][3]+a[i]/2);dp[i+1][4]=max(dp[i+1][4],(dp[i+1][3])*2);dp[i+1][5]=max(dp[i+1][5],(dp[i+1][3])*4);
        }
        if(dp[i+1][4]>a[i]){
            dp[i+1][4]=max(dp[i+1][4],dp[i][4]+a[i]/2);dp[i+1][5]=max(dp[i+1][5],(dp[i+1][4])*2);
        }
        if(dp[i+1][5]>a[i]){
            dp[i+1][5]=max(dp[i+1][5],dp[i][5]+a[i]/2);
        }
    }
    cout<<i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}