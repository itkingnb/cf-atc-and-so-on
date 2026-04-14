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
vector<int> minp, primes;
set<int>ms;
vector<int>ps;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            ms.insert(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                // f[i * p] = f[i];
                break;
            }
        }
    }
    ps=primes;
}
#define lll __int128_t
void solve(){
    // cerr<<ps.size();
    int n;
    cin>>n;
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<ll>t(n);
    int ans=0;
    t[0]=gcd(a[0],a[1]);
    t.back()=gcd(a[n-1],a[n-2]);
    for(int i=1;i<n-1;i++){
        t[i]=lcm(gcd(a[i],a[i-1]),gcd(a[i],a[i+1]));    
    }
    for(int i=0;i<n;i++){
        if(t[i]>b[i]){
            t[i]=a[i];
        }
    }
    ll tmp=t[1]/gcd(t[0],t[1]);
    if(t[0]!=a[0]&&t[0]<=b[0]){
        ans++;
    }else if(t[0]>b[0]){
        ;
    }else{
        if(a[0]!=t[0]&&a[0]%t[0]==0){
            if(find(primes.begin(),primes.end(),a[0]/t[0])!=primes.end()){
                ms.erase(a[0]/t[0]);
            }
        }
        for(int j=0;j<ps.size();j++){
            if(tmp%ps[j]==0&&ms.count(ps[j])){
                ms.erase(ps[j]);
            }
        }
        ll ttt=1;
        if(ms.size()&&(lll)*ms.begin()*t[0]<=b[0]){
            ttt=*ms.begin();
            ans++;
        }
        for(int j=0;j<ps.size();j++){
            if(tmp%ps[j]==0){
                ms.insert(ps[j]);
            }
        }
        if(a[0]!=t[0]&&a[0]%t[0]==0){
            if(find(primes.begin(),primes.end(),a[0]/t[0])!=primes.end()){
                ms.insert(a[0]/t[0]);
            }
        }
        t[0]*=ttt;
    }
    tmp=t[n-2]/gcd(t[n-1],t[n-2]);
    if(t[n-1]!=a[n-1]&&t[n-1]<=b[n-1]){
        ans++;
    }else if(t[n-1]>b[n-1]){
        ;
    }else{
        if(a[n-1]!=t[n-1]&&a[n-1]%t[n-1]==0){
            if(find(primes.begin(),primes.end(),a[n-1]/t[n-1])!=primes.end()){
                ms.erase(a[n-1]/t[n-1]);
            }
        }
        for(int j=0;j<ps.size();j++){
            if(tmp%ps[j]==0&&ms.count(ps[j])){
                ms.erase(ps[j]);
            }
        }
        ll ttt=1;
        if(ms.size()&&(lll)*ms.begin()*t[n-1]<=b[n-1]){
            ttt=*ms.begin();
            ans++;
        }
        for(int j=0;j<ps.size();j++){
            if(tmp%ps[j]==0){
                ms.insert(ps[j]);
            }
        }
        if(a[n-1]!=t[n-1]&&a[n-1]%t[n-1]==0){
            if(find(primes.begin(),primes.end(),a[n-1]/t[n-1])!=primes.end()){
                ms.insert(a[n-1]/t[n-1]);
            }
        }
        t[n-1]*=ttt;
    }


    // int ans=0;
    for(int i=1;i<n-1;i++){
        if(t[i]!=a[i]&&t[i]<=b[i]){
            ans++;
            continue;
        }
        if(t[i]>b[i]){
            continue;
        }
        ll tmp=t[i-1]/gcd(t[i],t[i-1]),tmp2=t[i+1]/gcd(t[i],t[i+1]);
        if(a[i]!=t[i]&&a[i]%t[i]==0){
            if(find(primes.begin(),primes.end(),a[i]/t[i])!=primes.end()){
                ms.erase(a[i]/t[i]);
            }
        }
        for(int j=0;j<ps.size();j++){
            if((tmp%ps[j]==0||tmp2%ps[j]==0)&&ms.count(ps[j])){
                ms.erase(ps[j]);
            }
        }
        ll ttt=1;
        if(ms.size()&&(lll)*ms.begin()*t[i]<=b[i]){
            // t[i]*=*ms.begin();
            ttt=*ms.begin();
            ans++;
        }
        for(int j=0;j<ps.size();j++){
            if(tmp%ps[j]==0||tmp2%ps[j]==0){
                ms.insert(ps[j]);
            }
        }
        if(a[i]!=t[i]&&a[i]%t[i]==0){
            if(find(primes.begin(),primes.end(),a[i]/t[i])!=primes.end()){
                ms.insert(a[i]/t[i]);
            }
        }
        t[i]*=ttt;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        assert(t[i]<=b[i]||t[i]==a[i]);
        if(t[i]!=a[i]){
            cnt++;
        }
    }
    assert(cnt==ans);
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    sieve(1000);
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}