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
    ll n,k;
    cin>>n>>k;
    ll sum=(k+n+k-1)*n/2;
    ll l=k,r=n+k-1,rr=r;
    ll ans=abs(sum-2*r);
    while(rr-l>1){
        ll mid=(l+rr)>>1;
        ll sum1=(mid+r)*(r-mid+1)/2;
        ll res=sum-2*sum1;
        if(res>0)
        rr=mid;
        else if(res<0)
        l=mid;
        else{
            cout<<0;
            return;
        }
        ans=min(ans,abs(res));
    }
        ll mid=l;
        ll sum1=(mid+r)*(r-mid+1)/2;
        ll res=sum-2*sum1;
        ans=min(ans,abs(res));
        mid=rr;
        sum1=(mid+r)*(r-mid+1)/2;
        res=sum-2*sum1;
        ans=min(ans,abs(res));
    cout<<ans;
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