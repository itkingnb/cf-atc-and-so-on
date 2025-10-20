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
    int n;
    cin>>n;
    vector<int>c(n);
    vector<ll>a,b;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        if(c[i]){
            b.push_back(x);
        }else{
            a.push_back(x);
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a.size()>b.size()){
        swap(a,b);
    }
    int d=(int)b.size()-(int)a.size();
    ll ans=0;
    for(int i=0;i<d;i++){
        ans+=b[i];
    }
    for(int i=0;i<a.size();i++){
        ans+=2*b[i+d]+2*a[i];
    }
    if(d==0){
        ans-=min(a[0],b[0]);
    }
    cout<<ans;
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