#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pll pair<int,int>
//typedef pair<int, int> pll; 
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
    ll m;
    cin>>n>>m;
    vector<pll> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i].first;
    for(int i=0;i<n;i++)
    cin>>a[i].second;
    sort(a.begin(),a.end());
    ll mx=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(a[i].first*a[i].second>m){
            mx=(m/a[i].first)*a[i].first;
        }
        else
        mx=a[i].first*a[i].second;
        if(i!=n-1&&a[i+1].first-a[i].first==1){
            ll left2=mx/a[i].first;
            ll left=m-mx;
            mx+=min(left/a[i+1].first,a[i+1].second)*a[i+1].first;
            ll left1=a[i+1].second-min(left/a[i+1].first,a[i+1].second);
            left=m-mx;
            mx+=min({left,left1,left2});
        }
        ans=max(mx,ans);
        if(ans==m)
        break;
    }
    cout<<ans;

}

signed main(){
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