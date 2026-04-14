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
void solve(){
    int n,w;
    cin>>n>>w;
    vector<pii>a(n);
    using ld=long double;
    priority_queue<pair<ld,int>>pq;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        // pq.push({a[i].first,i});
        // pq.push({a[i].second,i});
        pq.push({(ld)sqrtl(1LL*a[i].first*a[i].first+1LL*a[i].second*a[i].second)-(ld)sqrtl(1LL*a[i].first*a[i].first+1LL*(a[i].second-1)*(a[i].second-1)),i});
    }
    while(pq.size()&&w--){
        auto [x,y]=pq.top();pq.pop();
        if(--a[y].second){
            pq.push({(ld)sqrtl(1LL*a[y].first*a[y].first+1LL*a[y].second*a[y].second)-(ld)sqrtl(1LL*a[y].first*a[y].first+1LL*(a[y].second-1)*(a[y].second-1)),y});
        }
    }
    ld ans=0;
    for(int i=0;i<n;i++){
        ans+=(ld)sqrtl(1LL*a[i].first*a[i].first+1LL*a[i].second*a[i].second);
    }
    cout<<fixed<<setprecision(12)<<ans;

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