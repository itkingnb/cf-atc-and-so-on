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
    int n,m;
    cin>>n>>m;
    // vector<vector<pii>>a(n);
    // vector<int>deg(n);
    vector<vector<tuple<int,int,int>>>adj(n);
    for(int i=0;i<m;i++){
        int u,v,a,b;
        cin>>u>>v>>a>>b;
        u--;v--;
        adj[u].push_back({v,a,b});
        // deg[v]++;
    }
    vector<vector<ll>>dp(n,vector<ll>(60000+10,2e18));
    for(int i=0;i<60000+10;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<60000+10;i++){
        for(int j=0;j<n;j++){
            for(auto [to,xx,yy]:adj[j]){
                if(xx+i<200*n+10){
                    dp[to][xx+i]=min(dp[to][xx+i],dp[j][i]+yy);
                }
            }
        }
    }
    ll ans1=1e9,ans2=1e9;
    for(int i=1;i<60000+10;i++){
        if(dp[n-1][i]!=(ll)2e18&&i*dp[n-1][i]<ans1*ans2){
            ans1=i;ans2=dp[n-1][i];
        }
    }
    cout<<ans1<<" "<<ans2;
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