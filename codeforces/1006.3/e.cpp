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
    int x=0;
    while(x*(1+x)<=n*2){
        x++;
    }
    x--;
    n-=(x+1)*x/2;
    int left=n;
    vector<pii>anss;
    for(int i=0;i<=x;i++){
        anss.push_back({i,0});
    }
    // int mx=500-x;
    int level=1;
    int now=0;
    while(left>now+level){
        while(level+now<left){
            left-=(now+level);
            anss.push_back({now++,level});
            // mx--;
        }
        level++;
        now=0;
    }
    for(int i=1e9;left>0;i--){
        left--;
        anss.push_back({x--,i});
    }
    cout<<(int)anss.size()<<'\n';
    for(auto x:anss){
        cout<<x.first<<' '<<x.second<<'\n';
    }
    // cerr<<x+1<<'\n';
    // cerr<<n<<'\n';
    // cout<<ans<<'\n';
    /*
    for(int i=0;i<=x;i++){
        cout<<i<<' '<<0<<'\n';
    }
    int nx=0,ny=1;
    for(int i=0;i<n;i++){
        cout<<nx++<<' '<<ny++<<'\n';
    }
        */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';
    }
    return 0;
}