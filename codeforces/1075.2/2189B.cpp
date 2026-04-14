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
    ll x;
    cin>>n>>x;
    vector<ll>a(n),b(n),c(n);
    bool ok=0;
    ll ans=maxll;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
        sum+=a[i]*(b[i]-1);
    }
    if(sum>=x){
        cout<<0;
        return ;
    }
    x-=sum;
    for(int i=0;i<n;i++){
        x+=c[i];
        x-=a[i];
        if(a[i]*b[i]>c[i]||a[i]*(b[i]-1)>=x){
            ok=1;
            if(a[i]*(b[i]-1)>=x||a[i]*b[i]==c[i]){
                cout<<1;
                return ;
            }
            ans=min(ans,max(0LL,1+(x-a[i]*(b[i]-1)+a[i]*b[i]-c[i]-1)/(a[i]*b[i]-c[i])));
        }
        x-=c[i];
        x+=a[i];
    }
    ok?cout<<max(0LL,ans):cout<<-1;
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