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
//uniform_int_distribution<ll> r1(l, r);
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
struct LinearBasis {
    static const int BITS = 32;
    int basis[BITS];
    bitset<100010>from[BITS];
    void init(){
        for (int i=0;i<BITS;i++) {
            basis[i]=0;
            from[i].reset();
        }
    }
    void insert(int x, int id) {
        bitset<100010>cur;
        cur.reset();
        cur.set(id);
        for (int i=BITS-1;i>=0;i--) {
            if (!(x&(1<<i))) continue;
            if (!basis[i]) {
                basis[i]=x;
                from[i]=cur;
                return;
            }
            x^=basis[i];
            cur^=from[i];
        }
    }
    bool get(int t, bitset<100010>&ans){
        ans.reset();
        for(int i=BITS-1;i>=0;i--) {
            if(!(t&(1<<i))) continue;
            if(!basis[i]) return false;
            t^=basis[i];
            ans^=from[i];
        }
        return true;
    }
}lb;

void solve(){
    lb.init();
    int n;
    cin>>n;
    int t1=0,t2=0;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        t1^=a[i];
    }
    // cerr<<"t="<<t<<endl;
    for(int i=0;i<n;i++){
        cin>>b[i];
        t2^=b[i];
        lb.insert(a[i]^b[i],i);
        // cerr<<(a[i]^b[i])<<endl;
    }
    bitset<100010>ans;
    if(lb.get(t1,ans)){
        for(int i=0;i<n;i++){
            if(ans[i]){
                swap(a[i],b[i]);
            }
            cout<<a[i]<<" ";
        }
    }else if(lb.get(t2,ans)){
        for(int i=0;i<n;i++){
            if(ans[i]){
                swap(a[i],b[i]);
            }
            cout<<b[i]<<" ";
        }
    }else{
        cout<<-1;
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