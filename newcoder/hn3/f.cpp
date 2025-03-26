#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#define ll long long
using namespace std;
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
    cin>>n;
    for(int i=0;i<n;i++){
    ll ans=0;
    int x,y;
    cin>>x>>y;
    ans+=y;
    ll leijia=0;
    for(int i=1;i<=30;i++){
        ll q=(qpow(2,i,1e60));
        if((x>>(i-1)&1)==0)
        ans+=(y+leijia)/q;
        if((x>>(i-1)&1)==1){
        leijia+=(q/2);
        ans+=(y+leijia)/q;
        }
    }
    cout<<ans<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}