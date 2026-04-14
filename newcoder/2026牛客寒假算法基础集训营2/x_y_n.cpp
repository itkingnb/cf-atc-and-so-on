#include<bits/stdc++.h>
#define ll unsigned long long
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
    ll n;
    cin>>n;
    ll x=-1,y=-1;
    int idx=1;
    ll mn=4e18;
    ll mx=(ll)1<<63;
    while(1){
        ll tx=n<<idx;
        if(tx>=mx){
            break;
        }
        ll ty=(n<<idx)+n;
        ll tty=(n<<idx)-n;
        if((tx^ty)<mn&&ty<mx){
            mn=(tx^ty);
            x=tx;
            y=ty;
        }
        if((tx^tty)<mn){
            mn=(tx^tty);
            x=tx;
            y=tty;
        }
        idx++;
    }
    cout<<x<<" "<<y;
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