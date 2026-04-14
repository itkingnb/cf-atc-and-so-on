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
    ll p,q;
    cin>>p>>q;
    ll ans1=-1,ans2=-1;
    for(ll i=3;i*i<=(2*p+4*q+1);i+=2){
        if((2*p+4*q+1)%i==0){
            ll n=(i-1)/2;
            ll m=((2*p+4*q+1)/i-1)/2;
            if((ans1==-1&&ans2==-1||abs(ans1-ans2)>abs(n-m))&&q<=min(n*(m+1),m*(n+1))){
                ans1=n;
                ans2=m;
            }
        }
    }
    if(ans1==-1&&ans2==-1){
        cout<<-1;
    }else{
        cout<<ans1<<" "<<ans2;
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