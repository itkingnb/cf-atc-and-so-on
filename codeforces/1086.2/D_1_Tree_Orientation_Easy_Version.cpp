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
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        if(s[i][i]!='1'){
            no();
            return ;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j&&s[i][j]=='1'&&s[j][i]=='1'){
                no();
                return ;
            }
        }
    }
    vector<vector<int>>able(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            able[i][j]=s[i][j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(able[j][i]&&able[i][k]){
                    able[j][k]=1;
                    if(s[j][k]!='1'){
                        no();
                        return ;
                    }
                }
            }
        }
    }
    vector<pii>ans;
    vector<vector<int>>adj(n);
    // yes();
    // cout<<'\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j||s[i][j]=='0'){
                continue;
            }
            bool ok=1;
            for(int k=0;k<n;k++){
                if(i!=k&&j!=k&&s[i][k]=='1'&&s[k][j]=='1'){
                    ok=0;
                    break;
                }
            }
            if(ok){
                // cout<<i+1<<" "<<j+1<<'\n';
                adj[i].push_back(j);
                adj[j].push_back(i);
                ans.push_back({i,j});
            }
        }
    }
    bool check=0;
    vector<bool>vis(n);
    auto dfs=[&](auto &&self,int x,int fa)->void{
        for(auto u:adj[x]){
            if(u==fa){
                continue;
            }
            if(vis[u]){
                check=1;
                return ;
            }
            vis[u]=1;
            self(self,u,x);
        }
    };
    vis[0]=1;
    dfs(dfs,0,-1);
    if(check||vis!=vector<bool>(n,1)){
        no();
        return ;
    }
    yes();
    cout<<'\n';
    for(auto x:ans){
        cout<<x.first+1<<" "<<x.second+1<<'\n';
    }
}


/*






Yes
2 1
3 1
3 5
4 3

No

Yes
1 2
1 3
4 2

Yes
2 3
3 1


*/
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