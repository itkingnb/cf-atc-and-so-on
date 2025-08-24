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
    ll px,py,qx,qy;
    cin>>px>>py>>qx>>qy;
    vector<ll>a(n);
    ll sum=0;
    ll mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        sum+=a[i];
    }
    if(n==1&&px==qx&&py==qy){
        no();
        return ;
    }
    if(px==qx&&py==qy){
        if(sum-mx>=mx){
            yes();
        }else{
            no();
        }
        return ;
    }
    if((px-qx)*(px-qx)+(py-qy)*(py-qy)<=sum*sum&&sum-mx+(int)sqrt((px-qx)*(px-qx)+(py-qy)*(py-qy))>=mx){
        yes();
    }else{
        no();
    }
    // vector<ll>dp(sum/2+1,0);
    // for(int i=0;i<n;i++){
    //     for(int )
    // }
    // sort(all(a));
    // if((px-qx)*(px-qx)+(py-qy)*(py-qy)<=min(0LL,sum)&&(px-qx)*(px-qx)+(py-qy)*(py-qy)<=sum*sum)
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