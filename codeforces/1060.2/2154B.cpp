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
    vector<int>a(n);
    ll ans=0;
    int mx=0;
    vector<int>pre(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(!i){
            pre[i]=a[i];
        }else{
            pre[i]=max(a[i],pre[i-1]);
        }
    }
    for(int i=1;i<n;i+=2){
        a[i]=pre[i];
    }
    for(int i=0;i<n;i+=2){
        if(i!=0&&i+1<n){
            mx=min(a[i-1],a[i+1]);    
        }else if(i==0){
            mx=a[i+1];
        }else{
            mx=a[i-1];
        }
        ans+=max(a[i]-(mx-1),0);
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