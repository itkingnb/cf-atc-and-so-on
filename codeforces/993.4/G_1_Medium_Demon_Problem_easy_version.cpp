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
        adj[x].push_back(i);
        adj[i].push_back(x);
        deg[i]++;
        deg[x]++;
    }
    vector<int>cnt(n);
    queue<int>q;
    bool ok=0;
    for(int i=0;i<n;i++){
        if(deg[i]==1){
            q.push(i);
            cnt[i]=1;
            ok=1;
        }
    }
    vector<bool>vis(n);
    while(q.size()){
        auto x=q.front();q.pop();
        vis[x]=1;
        for(auto u:adj[x]){
            if(!vis[u]){
                cnt[u]=cnt[x]+1;
                if(--deg[u]==1){
                    q.push(u);
                }
            }
        }
    }
    cout<<(ok?*max_element(cnt.begin(),cnt.end())+1:2);
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