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
#define all(x) (x).begin(), (x).end()
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
    int n,k;
    ll mx=0;
    cin>>n>>k;
    vector<ll>a(n);
    vector<ll>d(2*k,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
        if(a[i]%(2*k)>=k){
            d[0]++;
            d[a[i]%(2*k)]++;
            d[(a[i]+k)%(2*k)]--;
        }else{
        d[a[i]%(2*k)]++;
        d[a[i]%(2*k)+k]--;
        }
    }
    int i,flag=0;
    ll ans=maxll;
    if(d[0]==n){
        flag++;
        ll p=mx/(2*k)*2*k+i;
        if(p<mx)
        p+=2*k;
        ans=min(p,ans);
    }
    for(i=1;i<2*k;i++){
        d[i]+=d[i-1];
        if(d[i]==n){
        flag++;
        ll p=mx/(2*k)*2*k+i;
        if(p<mx)
        p+=2*k;
        ans=min(p,ans);
        }
    }
    if(flag)
        cout<<ans;
    else
        cout<<-1;
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