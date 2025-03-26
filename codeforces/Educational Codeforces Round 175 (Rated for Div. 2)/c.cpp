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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<ll>a(n);
    ll mn=1e9+10,mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    ll lo=0,hi=mx;
    auto check=[&](ll x)->bool{
        int cnt=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(flag){
                if(a[i]<=x){
                    continue;
                }else if(s[i]=='R'){
                    flag=false;
                }
                continue;
            }
            if(s[i]=='B'){
                if(a[i]>x){
                    flag=true;
                    cnt++;
                }
            }
        }
        return cnt<=k;
    };
    while(lo<hi){
        ll mid=(lo+hi)>>1;
        if(check(mid)){
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    check(hi)?cout<<max(hi,0LL):cout<<hi+1;

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