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
void solve(){
     ll n,a,b;
     cin>>n>>a>>b;
     ll mx=0;
    for(int i=0;i*7<=n;i++){
          for(int j=0;j*8<=n;j++){
               for(int k=0;k*2<=n;k++){
                    if(i*7+j*8+k*2<=n){
                         mx=max(mx,i*a+j*(a+b)+k*b);
                         // if(mx==10360){
                         //      cout<<i<<" "<<j<<" "<<k<<endl;
                         //      goto out;
                         // }
                    }
               }
          }
     }
     cout<<mx;
     out:
     return ;
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