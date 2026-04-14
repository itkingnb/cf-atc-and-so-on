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
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    vector<int>col(n,-1);
    for(int i=0;i<n;i++){
        if(col[i]!=-1){
            continue;
        }
        queue<int>q;
        vector<int>cnt(2);
        q.push(i);
        col[i]=0;
        cnt[0]=1;
        bool ok=1;
        while(q.size()){
            auto x=q.front();q.pop();
            for(auto u:adj[x]){
                if(col[u]==-1){
                    col[u]=col[x]^1;
                    cnt[col[u]]++;
                    q.push(u);
                }else if(col[u]==col[x]){
                    ok=0;
                    // break;
                }
            }
        }
        if(ok){
            ans+=max(cnt[0],cnt[1]);
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