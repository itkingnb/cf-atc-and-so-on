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
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
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
    ll mod=1e8-3;
    cin>>n;
    vector<pii>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    for(int i=0;i<n;i++){
        cin>>b[i].first;
        b[i].second=i;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<pii>c(n);
    for(int i=0;i<n;i++) c[a[i].second].first=b[i].second,c[i].second=i+1;
    sort(c.begin(),c.end(),[](pii a,pii b)->bool{
        return a.first>b.first;
    });
    auto lowbit=[=](int x)->int{
        return x&-x;
    };
    vector<int>arr(200000,0);
    ll ans=0;
    auto get=[&](int x)->ll{
        ll res=0;
        while(x){
            ans+=arr[x];
            x-=lowbit(x);
        }
        return res;
    };
    auto modify=[&](int x)->void{
        while(x<1e5+10){
            arr[x]++;
            x+=lowbit(x);
        }
    };
    for(int i=0;i<n;i++){
        ans=ans+get(c[i].second);
        ans%=mod;
        modify(c[i].second);
    }
    cout<<ans;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}