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
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];;
    }
    a.insert(a.begin(),0);
    ll mod=998244353;
    vector<array<int,2>>dp(n+10);
    dp[1][0]=1; dp[1][1]=(a[1]?0:1);//1真0假
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][1];
        dp[i][1]=(a[i-2]+1==a[i]?dp[i-1][0]:0)+(a[i]==a[i-1]?dp[i-1][1]:0);
        dp[i][1]%=mod;
    }
    cout<<(dp[n][0]+dp[n][1])%mod;
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