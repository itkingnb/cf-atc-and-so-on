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
    vector<ll>a(n);
    ll ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i%2==0){
            ans+=a[i];
        }else{
            ans-=a[i];
        }
    }
    if(n==1){
        cout<<ans;
        return ;
    }
    ll mx=(n%2==0?n-2:n-1);
    ll mn1=1-2*a[0],mn2=1+2*a[1];
    mx=max(mx,1+2*a[1]-2*a[0]);
    for(int i=2;i<n;i++){
        if(i&1){
            mx=max(mx,2*a[i]+mn1);
            mn2+=2;
            mn2=max(mn2,1+2*a[i]);
        }else{
            mx=max(mx,mn2-2*a[i]);
            mn1+=2;
            mn1=max(mn1,1-2*a[i]);
        }
    }
    // mn=1-2*a[1];
    cout<<ans+mx;
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