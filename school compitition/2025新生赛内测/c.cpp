#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
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
    // cout<<qpow(3,qpow(4,qpow(5,6,10),10),10)<<'\n';
    // cout<<qpow(5,qpow(6,qpow(7,8,10),10),10)<<'\n';
    // cout<<qpow(7,qpow(8,qpow(9,10,10),10),10)<<'\n';
    // cout<<qpow(9,qpow(10,qpow(11,12,10),10),10)<<'\n';
    // cout<<qpow(2,qpow(3,qpow(4,5),10),10)<<'\n';
    // cout<<qpow(4,qpow(5,qpow(6,7),10),10)<<'\n';
    // cout<<qpow(6,qpow(7,qpow(8,9),10),10)<<'\n';
    // cout<<qpow(8,qpow(9,qpow(10,11),10),10)<<'\n';
    ll l,r;
    cin>>l>>r;
    if(l==r){
        cout<<l%10;
    }else if(r==l+1){
        cout<<qpow(l,r,10);
    }else{
        cout<<qpow(l%10,qpow((l+1)%10,(l+2)%10,10),10);
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