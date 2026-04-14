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
    vector<vector<int>>adj(n);
    vector<int>deg(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        x--;
        adj[i].push_back(x);
        deg[x]++;
    }
    vector<int>cnt(n,0);
    queue<int>q;
    for(int i=0;i<n;i++){
        if(deg[i]==0){
            q.push(i);
        }
    }
    int ans=0;
    while(q.size()){
        auto x=q.front();q.pop();
        // cnt[x]++;
        ans=max(ans,++cnt[x]);
        for(auto u:adj[x]){
            cnt[u]+=cnt[x];
            if(--deg[u]==0){
                q.push(u);
            }
        }
    }
    cout<<ans+2;
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