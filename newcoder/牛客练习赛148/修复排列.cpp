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
        vector<int>p(n);
        DSU dsu(n+1);
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        vector<int>q(n);
        for(int i=0;i<n;i++){
            cin>>q[i];
            q[i]--;
        }
        vector<int>d(n);
        for(int i=0;i<n;i++){
            cin>>d[i];
            dsu.merge(d[i],p[i]);
        }
        vector<bool>vis(n+1);
        int ans=0;
        for(int i=0;i<n;i++){
            int x=dsu.find(p[q[i]]);
            if(!vis[x]){
                ans+=dsu.size(x);
                vis[x]=1;
            }
            cout<<ans<<" ";
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