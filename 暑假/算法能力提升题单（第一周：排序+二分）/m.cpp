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
    ll n,m,s;
    cin>>n>>m>>s;
    ll left=0,right=0;
    vector<ll>w(n);
    vector<ll>v(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
        right=max(right,w[i]);   
    }
    ll ans=2e18;
    vector<ll>l(m);
    vector<ll>r(m);
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i];
    }
    while (left<=right)
    {
        ll mid=(left+right)>>1;
        vector<ll>pre1(n+1);
        vector<ll>pre2(n+1);
        for(int i=0;i<n;i++){
            pre1[i+1]=pre1[i]+(w[i]>=mid?1:0);
            pre2[i+1]=pre2[i]+(w[i]>=mid?v[i]:0);
        }
        ll res=0;
        for(int i=0;i<m;i++){
            res+=(pre1[r[i]]-pre1[l[i]-1])*(pre2[r[i]]-pre2[l[i]-1]);
        }
        ans=min(ans,abs(res-s));
        if(res>s)
            left=mid+1;
        if(res==s)
            break;
        if(res<s)
            right=mid-1;
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}