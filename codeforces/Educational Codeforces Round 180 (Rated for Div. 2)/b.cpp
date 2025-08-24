#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
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
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(abs(a[i]-a[i-1])<=1){
            cout<<0;
            return ;
        }
    }
    auto check=[&](ll mx,ll mn,ll a)->bool{
        return a<=mx&&a>=mn||a+1<=mx&&a+1>=mn||a-1<=mx&&a-1>=mn;
    };
    int ans=1e9;
    for(int i=0;i<n;i++){
        ll mx=-1,mn=1e9;
        for(int j=i+1;j<n;j++){
            mx=max(a[j],mx);
            mn=min(mn,a[j]);
            if(check(mx,mn,a[i])){
                // cout<<j-i-1;
                ans=min(ans,j-i-1);
                // return ;
            }
        }
        mx=-1;mn=1e9;
        for(int j=i-1;j>=0;j--){
            mx=max(a[j],mx);
            mn=min(mn,a[j]);
            if(check(mx,mn,a[i])){
                // cout<<j-i-1;
                ans=min(ans,i-j-1);
                // return ;
            }
        }
    }
    if(ans==(int)1e9)
        cout<<-1;
    else
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