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
    vector<vector<ll>>a(n,vector<ll>(m));
    vector<vector<int>>pre(n+1,vector<int>(m+1));
    vector<string>s(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            pre[i+1][j+1]=pre[i][j+1]+pre[i+1][j]-pre[i][j]+(s[i][j]=='1'?1:-1);
            sum+=(s[i][j]=='1'?1:-1)*a[i][j];
        }
    }
    int g=0;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            if(pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k]!=0){
                g=gcd(g,abs(pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k]));
            } 
        }
    }
    if(sum==0||g&&abs(sum)%g==0){
        yes();
    }else{
        no();
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