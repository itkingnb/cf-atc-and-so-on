
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

template <typename T>
struct Fenwick
{
    int n;
    vector <T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 1, T{});
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    void add(int x, const T &v)
    {
        while (x <= n) {
            a[x] += v;
            x += lowbit(x);
        }
    }

    T sum(int x)
    {
        T ans{};
        while (x >= 1) {
            ans += a[x];
            x -= lowbit(x);
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<ll>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    Fenwick<ll>fen(n);
    vector<int>ans(n,0);
    auto check=[&](ll x,int i)->bool{
        return (1+x)*(x)/2-fen.sum(x)>s[i];
    };
    for(int i=n-1;i>=0;i--){
        int l=1,r=n;
        while(l<=r){
            ll mid=l+r>>1;
            if(check(mid,i)){
                ans[i]=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        fen.add(ans[i],ans[i]);
        // update(1,ans[i+1],ans[i+1],ans[i+1]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
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