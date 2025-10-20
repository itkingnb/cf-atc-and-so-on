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
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>>adj(n);
    vector<vector<ll>>cnt(n,vector<ll>(2,0));
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(s[u]=='C'&&s[v]=='S'){
            cnt[u][0]++;
        }
        if(s[u]=='S'&&s[v]=='C'){
            cnt[v][0]++;
        }
        if(s[u]=='P'&&s[v]=='C'){
            cnt[u][1]++;
        }
        if(s[u]=='C'&&s[v]=='P'){
            cnt[v][1]++;
        }
    }
    vector<vector<ll>>dp(n,vector<ll>(2,0));
    ll ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='C'){
            for(auto u:adj[i]){
                if(s[u]=='C'){
                    dp[i][0]+=cnt[u][0];
                }else if(s[u]=='P'){
                    dp[i][1]+=cnt[u][1]-1;
                }
            }
            ans+=dp[i][0]*dp[i][1];
        }
    }
    cout<<ans;
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