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
    int n;
    cin>>n;
    vector<ll>a(2*n);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    // for(int )
    vector<ll>pre2(2*n+1,0);
    vector<vector<ll>>pre(2*n+1,vector<ll>(2,0));
    for(int i=0;i<2*n;i++){
        pre2[i+1]=pre2[i]+a[i];
        pre[i+1]=pre[i-1];
        pre[i+1][(i+1)&1]+=a[i];
    }
    for(int i=1;i<=n;i++){
        if((i+1)&1){
            cout<<pre[2*n][1]-pre[i][1]-(pre[2*n][0]-pre[i][0])+pre2[i]-pre2[0];
        }else{
            cout<<pre[2*n][0]-pre[i][0]-(pre[2*n][1]-pre[i][1])+pre2[i]-pre2[0];
        }
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