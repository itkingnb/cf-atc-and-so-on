#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
// #define ll int
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
std::vector<int> minp, primes, f;

void sieve(int n) {
    minp.assign(n + 1, 0);
    f.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            f[i] = 1;
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                f[i * p] = f[i];
                break;
            }
            f[i * p] = f[i] + 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        f[i] += f[i - 1];
    }
}
void solve(){
    // for(int i=0;i<
    // fill(mp.begin(),mp.end(),0);
    vector<int>mp(4e5+10);
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    // int mx=0;
    int odd=0,even=0;
    ll ans=2e18;
    // map<int,int>mp;
    
    bool ok=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        even+=!(a[i]&1);
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    if(even>=2){
        cout<<0;
        return ;
    }
    for(int i=0;i<n;i++){
        int t=a[i];
        while(t!=1){
            if(mp[minp[t]]){
                cout<<0;
                return ;
            }else{
                mp[minp[t]]=1;
            }
            int p=minp[t];
            while(t%p==0){
                t/=p;
            }
        }
    }
    vector<int>tmp;
    for(int i=2;i<4e5+10;i++){
        int t=i;
        while(t!=1){
            if(mp[minp[t]]){
                tmp.push_back(i);
                break;
            }
            int p=minp[t];
            while(t%p==0){
                t/=p;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(tmp.size()){
            auto x=upper_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin();
            // if()
            while(x<tmp.size()&&(a[i]!=1&&tmp[x]%a[i]==0)){
                x++;
            }
            if(x<tmp.size()){
                ans=min(ans,1LL*b[i]*(tmp[x]-a[i])); 
            }
            
        }
    }
    for(int i=0;i<n;i++){
        if((a[i]&1)==0){
            b[i]=1e9+10;
            break;
        }
    }
    sort(b.begin(),b.end());
    ans=min(ans,(ll)b[0]+b[1]);
    cout<<ans;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    sieve(4e5+10);
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}