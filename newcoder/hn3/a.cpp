#include<bits/stdc++.h>
using namespace std;
#define ll long long
double dis=0x3f3f3f3f;
#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
ll jc(ll n){
    if(n==1||n==0)
    return (ll)1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
}
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
ll qpow(ll a, ll k, ll p)
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
    ll ans1,ans2;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        double pii=x*1.0/y;
        if(abs(pii-pi)==dis&&x<ans1){
            ans1=x;
            ans2=y;
            continue;
        }
        if(abs(pii-pi)<dis){
        dis=abs(pii-pi);
        ans1=x;
        ans2=y;
        continue;
        }
    }
    cout<<ans1<<" "<<ans2;
}
int main(){
    solve();
    return 0;
}