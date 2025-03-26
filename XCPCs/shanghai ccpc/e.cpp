#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    int a[27]={0};
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if((int)s[i]>=97)
        a[(int)s[i]-97]++;
        else
        a[(int)s[i]-'A']++;
    }
    cout<<min({a['s'-'a'],a['h'-'a']/2,a[0]/2,a['n'-'a'],a['g'-'a'],a['i'-'a']});
}
int main(){
    solve();
    return 0;
}