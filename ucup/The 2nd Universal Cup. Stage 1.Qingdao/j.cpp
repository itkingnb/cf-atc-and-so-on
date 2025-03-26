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
    ll a,b,c,d,v,t;
    cin>>a>>b>>c>>d>>v>>t;
    ll tt=t;
    ll gc=lcm(a,c);
    vector<ll>aa;
    for(int i=0;i*c<gc;i++){
        aa.push_back(i*c);
    }
    for(int i=0;i*a<gc;i++){
        aa.push_back(i*a);
    }
    sort(all(aa));
    ll ans_t=0;
    for(int i=2;i<aa.size();i++){
        if(aa[i]%a==0){
            ans_t+=b-1;
        }else{
            ans_t+=d-1;
        }
        ans_t+=(aa[i]-aa[i-1]<=v);
        // ans_t+=(aa[i]-aa[i-1]<v);
    }
    ans_t+=b+d;
    ll ans=0;
    ans+=ans_t*(t/gc);
    t-=t/gc*gc;
    for(int i=2;i<aa.size()&&aa[i]<=t;i++){
        if(aa[i]%a==0){
            ans+=b-1;
        }else{
            ans+=d-1;
        }
        ans+=(aa[i]-aa[i-1]<=v);
    }
    ans+=b+d;
    ans--;
    if(gc-aa[aa.size()-1]>v){
        ans-=tt/gc;
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