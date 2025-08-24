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
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
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
    int n,k,z;
    cin>>n>>k>>z;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>>dp(k+1,vector<int>(z+1,0));
    dp[0][0]=a[1];
    for(int i=1;i<=k;i++){
        dp[i][0]=dp[i-1][0]+a[i+1];
        // cerr<<dp[i][0]<<" ";
    }
    for(int i=1;i<=z;i++){
        for(int j=i+1;j<=k;j++){
            // dp[j][i]
            if(1+j-1-i-i+1>=1){
                dp[j][i]=dp[j-1][i]+a[1+j-1-i-i+1];
            }
            if(1+j-1-2*(i-1)-1>=1){
                dp[j][i]=max(dp[j][i],dp[j-1][i-1]+a[1+j-1-2*(i-1)-1]);
            }
            // cerr<<j<<" "<<i<<" "<<dp[j][i]<<'\n';
            
        }
    }
    cout<<*max_element(dp[k].begin(),dp[k].end());
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