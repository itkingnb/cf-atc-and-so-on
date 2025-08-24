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
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<pair<int,ll>>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        ll d;
        cin>>u>>v>>d;
        u--;
        v--;
        adj[u].push_back({v,d});
    }
    vector<vector<__int128_t>>dp(n,vector<__int128_t>(40,1));

    for(int i=1;i<40;i++){
        for(int j=0;j<n;j++){
            if(dp[j][i-1]>1e9){
                dp[j][i]=dp[j][i-1];
            }else{
                for(auto [x,y]:adj[j]){
                    dp[j][i]=max(dp[j][i],dp[x][i-1]*y*1LL);
                }
            }
        }
    }
    while(q--){
        int p;
        ll x;
        cin>>p>>x;
        p--;
        for(int i=1;i<40;i++){
            if(dp[p][i]>x){
                cout<<i<<'\n';
                break;
            }
        }
    }
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