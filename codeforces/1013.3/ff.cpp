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
ll mod=998244353;
void solve(){
    int n,m,d;
    cin>>n>>m>>d;
    vector<vector<ll>>dp(n+10,vector<ll>(m+10,0));
    vector<ll>pre(m+10,0);
    vector<ll>pre1(m+10,0);
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(!i){
            for(int j=0;j<m;j++){
                pre1[j+1]=pre1[j]+(s[i][j]=='X');
            }
            for(int j=0;j<m;j++){
                if(!i&&s[i][j]=='X'){
                    dp[i+1][j+1]++;
                }
                int l=j+1-d,r=j+1+d;
                if(s[i][j]=='X'){
                    dp[i+1][j+1]=(dp[i+1][j+1]+pre1[min(r,m)]-pre1[max(l-1,0)]-1+mod)%mod;
                }
                pre[j+1]=(pre[j]+dp[i+1][j+1]+mod)%mod;
            }
            pre1=pre;
        }else{
            for(int j=0;j<m;j++){
                int l=j+1-d,r=j+1+d;
                if(s[i][j]=='X'){
                    dp[i+1][j+1]=(dp[i+1][j+1]+pre1[min(r-1,m)]-pre1[max(l,0)]+mod)%mod;//+-pre[j+1];
                }
                pre[j+1]=(pre[j]+dp[i+1][j+1]+mod)%mod;
            }
            for(int j=0;j<m;j++){
                if(s[i][j]=='X'){
                    int l=j+1-d,r=j+1+d;
                    dp[i+1][j+1]=(dp[i+1][j+1]+pre[min(r,m)]-pre[max(l-1,0)]-dp[i+1][j+1]+mod)%mod;
                }
            }
            for(int j=0;j<m;j++){
                pre1[j+1]=pre1[j]+dp[i+1][j+1]+mod;
                pre1[j+1]%=mod;
            }
        }
    }
    ll ans=0;
    for(int j=1;j<=m;j++){
        ans+=dp[n][j];
        ans%=mod;
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