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
    vector<int>a(n);
    ll ans=0;
    vector<vector<int>>adj(n);
    vector<int>deg(n+10,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        // ans+=a[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    if(m%2==0){
        cout<<0;
        return ;
    }
    int mn=1e9;
    for(int i=0;i<n;i++){
        if(deg[i]&1){
            mn=min(mn,a[i]);
        }else if(deg[i]>=2){
            int now=a[i];
            bool ok=0;
            for(auto x:adj[i]){
                if((deg[x]-1)%2==1){
                    // ok=1;
                    mn=min(mn,now+a[x]);
                }
            }
        }
    }
    cout<<mn;
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