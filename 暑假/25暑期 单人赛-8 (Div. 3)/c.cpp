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
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>ans(n);
    ans[0]=a;ans.back()=b;
    int idx=n;
    vector<bool>vis(n+1,0);
    vis[a]=1;vis[b]=1;
    int mn=1e9;
    for(int i=1;i<n/2;i++){
        while(vis[idx]) idx--;
        ans[i]=idx;
        mn=min(mn,ans[i]);
        vis[idx--]=1;
    }
    idx=1;
    int mx=0;
    for(int i=n-2;i>=n/2;i--){
        while(vis[idx]) idx++;
        ans[i]=idx;
        mx=max(mx,ans[i]);
        vis[idx++]=1;
    }
    if(mn<a||mx>b){
        cout<<-1;
    }else{
        for(auto x:ans) cout<<x<<" ";
    }
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