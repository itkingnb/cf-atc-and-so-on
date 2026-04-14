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
std::vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    primes.push_back(0);
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve(){
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
    const int N = primes.size();
    vector<vector<int>>dp(n+1,vector<int>(N+1,0));
    for(int i=0;i<n;i++){
        dp[i+1][0]=*max_element(dp[i].begin(),dp[i].end());
        if(t[i]==a[i]){
            for(int j=1;j<N;j++){
                if(primes[j]*t[i]>b[i]){
                    continue;
                }
                if((i==0||gcd(a[i-1],a[i])==gcd(t[i]*primes[j],t[i-1]))&&(i==n-1||gcd(a[i+1],a[i])==gcd(t[i]*primes[j],t[i+1]))){
                    for(int k=0;k<N;k++){
                        if(j==k)    continue;
                        dp[i+1][j]=max(dp[i+1][j],dp[i][k]+1);
                    }
                }
            }
        }else{
            dp[i+1][0]=*max_element(dp[i].begin(),dp[i].end())+1;
        }
    }
    cout<<*max_element(dp[n].begin(),dp[n].end());
}   

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    sieve(100);
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}