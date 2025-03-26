#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
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
    ll l,r;
    cin>>l>>r;
    ll ans=0;
    int m=ceil(log(l)/log(3));
    if(l-qpow(3,m,maxll)==0||m==0)
    m++;
    ans+=m;
    l++;
    ll rr=r;
    r*=qpow(3,m,maxll);
    while(1){
    ll k=qpow(3,m,maxll);
    if(rr-1>=k){
        k--;
        ans+=m*(k-l+1);
        l=k+1;
    }
    else{
    ans+=(m)*(rr-l);
    break;
    }
    m++;
    }
    m=ceil(log(r)/log(3));
    if(r-qpow(3,m,maxll)==0)
    m++;
    cout<<ans+m;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}