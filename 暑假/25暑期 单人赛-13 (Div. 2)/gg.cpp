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
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>id(n+1);
    // map<int,vector<int>>mp;
    vector<vector<int>>mp(m+1);
    DSU dsu(m+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        id[i+1]=a[i];
        mp[a[i]].push_back(i+1);
        dsu.siz[a[i]]++;
    }
    int ans=0;
    for(int i=1;i<n;i++){
        if(id[i]!=id[i+1]){
            ans++;
        }
    }
    cout<<ans<<'\n';
    m--;
    while(m--){
        int aa,bb;
        cin>>aa>>bb;
        aa=dsu.find(aa);
        bb=dsu.find(bb);
        // cerr<<aa<<" "<<bb;
        if(dsu.size(aa)<dsu.size(bb)){
            swap(aa,bb);
        }
        // cerr<<aa<<" "<<bb;
        for(auto x:mp[bb]){
            if(x+1<=n&&dsu.find(id[(x+1)])==aa){
                ans--;
            }
            if(x-1>=1&&dsu.find(id[(x-1)])==aa){
                ans--;
            }
            mp[aa].push_back(x);
            id[x]=aa;
        }        
        mp[bb].clear();
        dsu.merge(aa,bb);
        cout<<ans<<'\n';
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