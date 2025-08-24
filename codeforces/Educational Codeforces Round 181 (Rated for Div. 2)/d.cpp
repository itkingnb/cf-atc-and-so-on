#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
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
map<int,int>mem;
ll qpow(ll a, ll k, ll p)
{
    if(mem[a]) return mem[a];
    ll res = 1;
    ll aa=a;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return mem[aa]=res;
}
void solve(){
    ll mod=998244353;
    int n,m;
    cin>>n>>m;
    vector<int>p(n),q(n);
    ll ans=0;
    ll pp=1;
    vector<vector<pii>>adj(m+10);
    int l,r;
    for(int i=0;i<n;i++){
        cin>>l>>r>>p[i]>>q[i];
        pp=pp*(q[i]-p[i])%mod;
        pp=pp*qpow(q[i],mod-2,mod);
        pp%=mod;
        adj[l].push_back({r,i});
    }
    vector<ll>mems(m+10,0);
    mems[m+1]=1;
    vector<int>able(m+10,-1);
    able[m+1]=1;
    // vector<bool>vis(m+10,0);
    auto dfs=[&](auto &&self,int xx)->bool{
        if(able[xx]!=-1&&able[xx]){
            ans+=(pp*mems[xx]%mod);
            ans%=mod;
            return 1;
        }else if(!able[xx]){
            return 0;
        }
        able[xx]=0;
        // cerr<<xx<<" "<<pp<<endl;
        if(xx>m){
            ans+=pp;
            ans%=mod;
            return 1;
        }
        bool ok=0;
        for(auto [x,y]:adj[xx]){
            bool f=0;
            if(x>=xx){
                pp*=p[y];
                pp%=mod;
                pp*=qpow(q[y]-p[y],mod-2,mod);
                pp%=mod;
                f=self(self,x+1);
                if(f){
                    ok=1;
                    mems[xx]%=mod;
                    mems[xx]+=((p[y]*mems[x+1]%mod)*qpow((q[y]-p[y]),mod-2,mod))%mod;
                    mems[xx]%=mod;
                }
                pp*=q[y]-p[y];
                pp%=mod;
                pp*=qpow(p[y],mod-2,mod);
                pp%=mod;  
            }
        }
        return able[xx]=ok;
    };
    for(auto [x,y]:adj[1]){
        pp*=p[y];
        pp%=mod;
        pp*=qpow(q[y]-p[y],mod-2,mod);
        pp%=mod;
        dfs(dfs,x+1);
        pp*=q[y]-p[y];
        pp%=mod;
        pp*=qpow(p[y],mod-2,mod);
        pp%=mod;
    }
    cout<<ans;
}

/*
4 5
1 3 1 2
4 5 1 2
4 5 2 5
1 3 1 2

*/

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