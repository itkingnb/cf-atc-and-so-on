#include<bits/stdc++.h>
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
    cout<<"Yes";
}
void no(){
    cout<<"No";
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
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    ll ans=-1e18;
    for(int i=0;i<n;i++){
        ll res=0;
        res+=a[i]+b[i];
        for(int j=0;j<n;j++){
            if(j!=i){
                res+=max(a[j],b[j]);
            }
        }
        ans=max(ans,res);
    }

    cout<<ans;

    // int dp[10][5010][2]={0};
    // dp[1][1][0]=a1[1];
    // dp[1][1][1]=mn;
    // for(int i=2;i<=n;i++){
    //     for(int j=1;j<=2;j++){
    //         if(j==1){
    //             dp[j][i][0]=dp[j][i-1][0]+a1[i];

    //         }else{

    //         }
    //     }
    // }

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