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
    int n;
    cin>>n;
    vector<ll>a(n,0);
    vector<ll>b;
    ll mx=0;
    for(int i=0;i<n;i++){
    cin>>a[i];
    mx=max(mx,a[i]);
    }
    int cnt=0;
    while (cnt<40)
    {
        if(mx==0)
        break;
        cnt++;
        ll sub=(mx+1)/2;
        mx=0;
        b.push_back(sub);
        for(int i=0;i<n;i++){
        a[i]=abs(a[i]-sub);
        mx=max(mx,a[i]);            
        }
    }
    if(mx){
        cout<<-1<<'\n';
        return ;
    }
    else{
        cout<<cnt<<'\n';
        for(int i=0;i<b.size();i++)
        cout<<b[i]<<" ";
        cout<<'\n';
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}