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
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>a(n,vector<int>(m));
    vector<vector<int>>b(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int l=0,r=1e9+1,ans=1e9+10;
    auto check=[&](int x)->bool{
        vector<vector<int>>dp(n,vector<int>(m,1e9+10));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                b[i][j]=(a[i][j]>x);
            }
        }
        dp[0][0]=b[0][0];
        for(int i=1;i<m;i++){
            dp[0][i]=dp[0][i-1]+b[0][i];
        }
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]+b[i][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+b[i][j];
            }
        }
        return dp[n-1][m-1]<=k;
    };
    check(1);
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
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