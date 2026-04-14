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
    int n,q;
    cin>>n>>q;
    vector<vector<ll>>a(n+1,vector<ll>(n+1));
    vector<vector<ll>>pre1(n+1,vector<ll>(n+1)),pre2(n+1,vector<ll>(n+1)),pre3(n+1,vector<ll>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            pre1[i][j]=pre1[i-1][j]+pre1[i][j-1]-pre1[i-1][j-1]+a[i][j];
            pre2[i][j]=pre2[i-1][j]+pre2[i][j-1]-pre2[i-1][j-1]+a[i][j]*i;
            pre3[i][j]=pre3[i-1][j]+pre3[i][j-1]-pre3[i-1][j-1]+a[i][j]*j;
        }
    }
    while(q--){
        int x,y,xx,yy;
        cin>>x>>y>>xx>>yy;
        cout<<pre3[xx][yy]-pre3[x-1][yy]-pre3[xx][y-1]+pre3[x-1][y-1]+(yy-y+1)*(pre2[xx][yy]-pre2[x-1][yy]-pre2[xx][y-1]+pre2[x-1][y-1])-(x*(yy-y+1)+y-1)*(pre1[xx][yy]-pre1[x-1][yy]-pre1[xx][y-1]+pre1[x-1][y-1])<<" ";
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