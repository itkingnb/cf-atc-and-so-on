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
vector<int>adj[200010];
void solve(){
    int n;
    cin>>n;
    vector<int>deg(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;deg[v]++;
    }
    multiset<int>ms;
    for(int i=1;i<=n;i++){
        ms.insert(deg[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int res=deg[i];
        ms.erase(ms.find(deg[i]));
        for(auto x:adj[i]){
            ms.erase(ms.find(deg[x])); ms.insert(deg[x]-1);
        }
        res--;
        res+=*ms.rbegin();
        for(auto x:adj[i]){
            ms.erase(ms.find(deg[x]-1)); ms.insert(deg[x]);
        }
        ans=max(ans,res);
        adj[i].clear();
        ms.insert(deg[i]);
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