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
    ll c1,c2,c3;
    cin>>c1>>c2>>c3;
    ll a1,a2,a3,a4,a5;
    cin>>a1>>a2>>a3>>a4>>a5;
    ll mx=min(a1,c1);
    a1-=mx;
    c1-=mx;
    mx=min(a2,c2);
    a2-=mx;
    c2-=mx;
    mx=min(a3,c3);
    a3-=mx;
    c3-=mx;
    if(a1||a2||a3){
        no();
        return ;
    }
    mx=min(c1,a4);
    c1-=mx;
    a4-=mx;
    mx=min(c2,a5);
    c2-=mx;
    a5-=mx;
    mx=min(c3,a4);
    c3-=mx;
    a4-=mx;
    mx=min(c3,a5);
    a5-=mx;
    c3-=mx;
    if(a4||a5){
        no();
    }else{
        yes();
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