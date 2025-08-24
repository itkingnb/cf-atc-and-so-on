#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
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
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<pii>dp(n);
    for(int i=0;i<n;i++){
        if(a[i]<=b[i]){
            dp[i].first=b[i]-a[i];
        }else{
            dp[i].first=b[i]+m-a[i];
        }
        if(a[i]>=b[i]){
            dp[i].second=a[i]-b[i];
        }else{
            dp[i].second=a[i]+m-b[i];
        }
    }
    sort(all(dp));
    ll mx1=0,mx2=0;
    for(int i=0;i<n;i++){
        mx1=max(dp[i].first,mx1);
        mx2=max(dp[i].second,mx2);
    }
    int i;
    for(i=0;i<n;i++){
        if(dp[i].first||dp[i].second){
            break;
        }
    }
    ll ans=maxll;
    if(mx1){
        ans=min(ans,mx1);
    }
    if(mx2){
        ans=min(ans,mx2);
    }
    for(i=i+1;i<n;i++){
        ans=min(ans,dp[i].second+dp[i-1].first);
    }
    cout<<(ans==maxll?0:ans);
    // vector<ll>c(n),d(n);
    // for(int i=0;i<n;i++){
    //     if(a[i]<=b[i]){
    //         c[i]=b[i]-a[i];
    //     }else{
    //         c[i]=b[i]+m-a[i];
    //     }
    //     if(a[i]>=b[i]){
    //         d[i]=a[i]-b[i];
    //     }else{
    //         d[i]=a[i]+m-b[i];
    //     }
    // }
    // vector<vector<ll>>dp(n,vector<ll>(2,0));
    // dp[0][0]=c[0];dp[0][1]=d[0];
    // for(int i=1;i<n;i++){
    //     dp[i][0]=min(max(c[i],dp[i-1][0]),dp[i-1][1]+c[i]);
    //     dp[i][1]=min(max(d[i],dp[i-1][1]),dp[i-1][0]+d[i]);
    // }
    // cout<<min(dp[n-1][0],dp[n-1][1]);
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