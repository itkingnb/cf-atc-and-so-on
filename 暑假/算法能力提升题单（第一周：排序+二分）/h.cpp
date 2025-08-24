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
    int n,m;
    cin>>n>>m;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<tuple<ll,int,int>>p(m);
    for(auto &[x,y,z]:p){
        cin>>x>>y>>z;
        y--;z--;
    }
    auto check=[&](int x)->bool{
        vector<ll>pre(n+10,0);
        for(int i=0;i<x-1;i++){
            auto [x,y,z]=p[i];
            pre[y]+=x;
            pre[z+1]-=x;
        }
        for(int i=0;i<n;i++){
            if(i){
                pre[i]+=pre[i-1];
            }
            if(pre[i]>a[i]){
                return 0;
            }
        }
        return 1;
    };
    int ans=0;
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(ans==m){
        cout<<0;
        return ;
    }
    cout<<-1<<'\n';
    cout<<ans;
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