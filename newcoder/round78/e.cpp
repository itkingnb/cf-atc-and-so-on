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
const int N =100010;
vector<bool>s(N,false);
vector<bool>vis(N,false);
vector<int>adj[N];
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(k,0);
    for(int i=0;i<k;i++){
        cin>>a[i];
        s[a[i]]=true;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans=1;
    ll mod=1e9+7;
    int ans2=0;
    int cnt=0;
        auto dfs=[&](auto &&dfs,int x)->void{
        if(!s[x]){
            cnt++;
            return ;
        }
        s[x]=false;
        for(auto x:adj[x]){
            if(!vis[x]){
                dfs(dfs,x);
            }
        }
    };
    for(int i=0;i<k;i++){
        if(s[a[i]]){
            ans2++;
            s[a[i]]=false;
        }else{
            continue;
        }
        cnt=0;
        vis[a[i]]=true;
        for(auto x:adj[a[i]]){
            dfs(dfs,x);
            vis[x]=false;
        }
        ans*=cnt;
        ans%=mod;
        //cout<<a[i]<<" "<<cnt<<'\n';
    }
    cout<<ans2<<" "<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}