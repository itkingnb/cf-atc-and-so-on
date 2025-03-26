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
    ll x,y;
    cin>>x>>y;
    if(x==y){
        cout<<-1;
        return ;
    }
    ll ans=0;
    ll mx=0;
    bool flag=false;
    for(int i=0;i<35;i++){
        int na=((x>>i)&1),nb=((y>>i)&1);
        if(na==1&&nb==1){
            if(!flag){
                ans+=(1LL<<i);
                x+=(1LL<<i);
                y+=(1LL<<i);
            }else{
                ans+=((1LL<<i)-mx);
                x+=((1LL<<i)-mx);
                y+=((1LL<<i)-mx);
            }
        }else if(na!=nb){
            flag=true;
        }
        if(flag){
            ll ta=0,tb=0;
            for(int j=0;j<=i;j++){
                ta+=((x>>j)&1LL)<<j;
                tb+=((y>>j)&1LL)<<j;
            }
            mx=max(ta,tb);
        }
    }
    cout<<ans;
}
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
int main(){
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}