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
    ll n,s;
    cin>>n>>s;
    vector<ll>a(n);
    ll sum=0;
    // bool ok=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<=s||(n==1&&a[0]>s)||(a[0]>s&&a[1]>s)){
        cout<<0;
        return ;
    }
    vector<ll>pre(n+1,0);
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+a[i];
    }
    int ans=-1;
    int mx=0;
    for(int i=0;i<n;i++){
        if(pre[i]>s){
            break;
        }
        auto x=upper_bound(pre.begin(),pre.end(),pre[i+1]+s-pre[i])-pre.begin();
        x--;
        if(x-1>mx){
            ans=i+1;
            mx=x-1;
        }
    }
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