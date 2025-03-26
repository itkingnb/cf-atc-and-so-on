#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#define ll long long
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
vector<ll>cut(ll n){
    vector<ll>ans(2,0);
    ll a=1;
    while (a*2<=n)
    {
        a*=2;
    }
    ans[0]=a;
    ans[1]=n-a;
    return ans;
}
void solve(){
    ll n;
    ll k;
    ll leijia=0;
    cin>>n;
    k=n;
    vector<ll>ans;
    //int cnt1=__builtin_popcountll(n);
    while (1)
    {
        vector<ll>c(2,0);
        c=cut(n);
        if(c[1]==0){
            if(leijia)
        ans.push_back(leijia);
        ans.push_back(k);
        break;
        }
        ans.push_back(leijia+c[1]);
        leijia+=c[0];
        n-=c[0];
    }
    cout<<ans.size()<<'\n';
    for(ll &i:ans)
    cout<<i<<" ";
    
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