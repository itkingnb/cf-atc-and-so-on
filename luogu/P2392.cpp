#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
int s[4];
int bag(vector<int>& a,int sum){
    sum/=2;
    vector<int>dp(sum+1,0);
    for(int i=0;i<a.size();i++){
        for(int j=sum;j>=a[i];j--){
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
    }
    return dp[sum];
}
void solve(){
    for(int i=0;i<4;i++)
    cin>>s[i];
    int ans=0;
    for(int i=0;i<4;i++){
        vector<int>a(s[i]);
        int sum=0;
        for(int j=0;j<s[i];j++){
        cin>>a[j];
        sum+=a[j];
        }
        int x=bag(a,sum);
        ans+=(sum-x);
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}