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
    int n;
    cin>>n;
    vector<string>s(n);
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<n;j++){
            if(s[i][j]=='1'){
                adj[i].push_back(j);
            }
        }
    }
    DSU dsu(n);
    vector<vector<int>>ans(n);
    for(int i=0;i<n;i++){
        vector<bool>vis(n);
        vis[i]=1;
        while(1){
            int t=-1;
            for(auto x:adj[i]){
                if(!vis[x]&&(t==-1||adj[x].size()>adj[t].size())){
                    t=x;
                }
            }
            if(t==-1){
                break;
            }
            if(!dsu.merge(i,t)){
                no();
                return ;
            }
            ans[i].push_back(t);
            for(auto x:adj[t]){
                vis[x]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(!dsu.same(0,i)){
            no();
            return ;
        }
    }
    for(int i=0;i<n;i++){
        queue<int>q;
        vector<bool>vis(n);
        q.push(i);
        while(q.size()){
            auto x=q.front();q.pop();
            if(vis[x]){
                continue;
            }
            vis[x]=1;
            for(auto u:ans[x]){
                if(vis[u]){
                    continue;
                }
                q.push(u);
            }
        }
        for(int j=0;j<n;j++){
            if((s[i][j]=='1')!=vis[j]){
                no();
                return ;
            }
        }
    }
    yes();
    cout<<'\n';
    for(int i=0;i<n;i++){
        for(auto x:ans[i]){
            cout<<i+1<<" "<<x+1<<'\n';
        }
    }
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