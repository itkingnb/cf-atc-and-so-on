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
    ll h,d;
    cin>>h>>d;
    ll l=d,r=2*d;
    ll ans=0;
    if((1+d)*d/2<h){
        cout<<1;
        return ;
    }
    // 12 
    auto check=[&](ll x)->bool{
        ll rest=x-d;
        ll step=(d+rest)/(rest+1);
        ll left=d%step;
        // if(left==0){
        //     rest++;
        // }
        rest=d/step;
        ll sum=rest*(1+step)*step/2;
        sum+=(1+left)*left/2;
        rest=x-d;
        return sum<h+rest;
    };
    // check(2);
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            // l=mid+1;
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
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