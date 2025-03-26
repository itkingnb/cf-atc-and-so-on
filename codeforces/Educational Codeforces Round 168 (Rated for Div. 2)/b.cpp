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
    string s[2];
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<2;i++)
    cin>>s[i];
    for(int i=0;i<n-2;i++){
        if(s[0][i]=='x'&&s[0][i+2]=='x'&&s[1][i+1]=='.'&&s[1][i]=='.'&&s[1][i+2]=='.'&&s[0][i+1]=='.')
            ans++;
        if(s[1][i]=='x'&&s[1][i+2]=='x'&&s[1][i+1]=='.'&&s[0][i+1]=='.'&&s[0][i]=='.'&&s[0][i+2]=='.')
            ans++;
    }
    cout<<ans;
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