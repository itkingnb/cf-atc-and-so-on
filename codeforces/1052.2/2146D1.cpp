#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
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
ll qpow(ll a, ll k, ll p=maxll)
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
    int l,r;
    cin>>l>>r;
    int n=r-l;
    vector<int>ans(n+1);
    // ans[0]=r;
    // ans[r]=0;
    vector<bool>vis(n+1);
    for(int k=20;k>=0;k--){
        int left=1<<k;
        if(left>n)continue;
        int right=min(n,(1<<(k+1))-1);
        int m=(1<<(k+1))-1;
        for(int j=right;j>=left;j--){
            if(vis[j])continue;
            int p=m-j;
            if(p>=0&&p<=n&&!vis[p]){
                ans[j]=p;ans[p]=j;vis[j]=vis[p]=1;
            }else{
                ans[j]=j;vis[j]=1;
            }
        }
    }
    ll sum=0;
    for(int i=0;i<=n;i++){
        sum+=(i|ans[i]);
        // cout<<ans[i]<<" ";
    }
    cout<<sum<<'\n';
    for(int i=0;i<=n;i++){
        cout<<ans[i]<<" ";
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