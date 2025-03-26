#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define pii pair<ll,ll>
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
ll qdx,qdy,zdx,zdy;
pair<ll,ll>a1;
bool check(ll x,ll y){
    ll d1=(zdy-qdy)*(zdy-qdy)+(zdx-qdx)*(zdx-qdx);
    ll d2=(x-zdx)*(x-zdx)+(y-zdy)*(y-zdy);
    if(d1<d2)
    return true;
    return false;
}
void solve(){
    int n;
    cin>>n;
    vector<pii> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i].first>>a[i].second;
    cin>>qdx>>qdy>>zdx>>zdy;
    a1.first=zdx-qdx;
    a1.second=zdy-qdy;
    for(int i=0;i<n;i++){
        if(check(a[i].first,a[i].second)==false){
            no();
            return;
        }
    }
    yes();
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