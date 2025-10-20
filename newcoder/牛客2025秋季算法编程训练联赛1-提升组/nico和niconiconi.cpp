#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
void yes(){
    cout<<"Yes";
}
void no(){
    cout<<"No";
}
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
ll qpow(ll a, ll k, ll p=maxll)
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
    ll a,b,c;
    cin>>n>>a>>b>>c;
    string s;
    cin>>s;
    vector<ll>dp(n+1,0);
    for(int i=3;i<n;i++){
        dp[i+1]=dp[i];
        if(i+1>=4&&s.substr(i-3,4)=="nico"){
            dp[i+1]=max(dp[i+1],dp[i-3]+a);
        }
        if(i+1>=6&&s.substr(i-5,6)=="niconi"){
            dp[i+1]=max(dp[i+1],dp[i-5]+b);
        }
        // if(i==6){
        //     cerr<<s.substr(i-6,6)<<'\n';
        // }
        if(i+1>=10&&s.substr(i-9,10)=="niconiconi"){
            dp[i+1]=max(dp[i+1],dp[i-9]+c);
        }
    }
    cout<<dp[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}